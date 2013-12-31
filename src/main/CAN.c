/* FreeEMS - the open source engine management system
 *
 * Copyright 2012 - 2013 Peter Johnson
 *
 * This file is part of the FreeEMS project.
 *
 * FreeEMS software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FreeEMS software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/
 *
 * We ask that if you make any changes to this file you email them upstream to
 * us at admin(at)diyefi(dot)org or, even better, fork the code on github.com!
 *
 * Thank you for choosing FreeEMS to run your engine!
 */

/** @CAN
 *
 * @ingroup Idk yet
 *
 * @brief CAN Protocol
 *
 * Description about what this file is intended to contain and
 * anything else that is unique and/or notable about it here!
 *
 * To add a C source file to the project :
 * - Copy this file to the source directory with an appropriate name
 * - Change the name to your own at the top of the GPL comment
 * - Change the filename to the correct one at the top of this comment
 * - Change the hash define to the filename uppercased and underscored
 * - Remove or adjust the hash include of the matching CANT0CTL0er
 *
 * @bug THIS DOCUMENTATION IS FAULTY!!
 * @todo REPLACE THIS WITH REAL DOCUMENTATION!!
 * @note SOME LAZY DEVELOPER DIDN'T CUSTOMISE THEIR DOCUMENTATION!!
 * @warning IMAGINE WHAT THEIR CODE MIGHT BE LIKE IF THEIR DOCUMENTATION IS THIS BAD!!
 */

#include "inc/CAN.h"

#define MAX_CODE_TIME 500
#define DONE 0
#define MODULE_ISNT_READY_TO_BE_PROGRAMMED 1
#define MODULE_ISNT_READY_TO_WORK 2
#define NO_MT_TX_BUFFERS 3
#define RX_DATA_OVERFLOW 4
#define MESSAGE_TOO_LONG 5
#define NO_SYNC 6

unsigned char initCANT0(){
	if((CANT0CTL1 & BIT0) == 0){
		CANT0CTL0 |= BIT0;
		return handleCANT0Error(MODULE_ISNT_READY_TO_BE_PROGRAMMED);
	}
	
	CANT0CTL1 |= BIT7;	// Enable module
	
	//CANT0CTL0 |= BIT3; // For time stamping that I don't want to handle right now

	CANT0BTR0 |= (BIT1|BIT0);  // @TODO Need to determine appropriate SJW and prescaler
	CANT0BTR1 |= (BIT5|BIT4|BIT3|BIT1);  // Bit Time = (prescalar value)/(oscillator f) * (1 + TS1 + TS2)

	CANT0IDAC = ZEROS;  // 2 - 32 bit full size extended bit identifier filters.
	
	CANT0CTL1 &= NBIT6;  // Ensure the oscillator is the clock source,

	CANT0IDAR0 = ZEROS;
	CANT0IDMR0 = 0xFF;
	CANT0IDAR1 = ZEROS;
	CANT0IDMR1 = 0xFF;
	CANT0IDAR2 = ZEROS;
	CANT0IDMR2 = 0xFF;
	CANT0IDAR3 = ZEROS;
	CANT0IDMR3 = 0xFF;

	CANT0IDAR4 = ZEROS;
	CANT0IDMR4 = 0xFF;
	CANT0IDAR5 = ZEROS;
	CANT0IDMR5 = 0xFF;
	CANT0IDAR6 = ZEROS;
	CANT0IDMR6 = 0xFF;
	CANT0IDAR7 = ZEROS;
	CANT0IDMR7 = 0xFF;
	
	// Self test 
	CANT0CTL1 |= BIT5;
	// TODO transmit, recieve, and verify here when those blocks are built 
	CANT0CTL1 &= NBIT5;

	// Linsten only to determine the filter requirement for a noisy environment. Should probably happen after the engine starts :-/
	CANT0CTL1 |= BIT4;
	// TODO determine filter requirement? Maybe write a seperate function for this and also call it in the receiveISR function if no data is found in the buffers
	CANT0CTL1 &= NBIT4;

	CANT0CTL0 &= NBIT0; // Exit initialization mode. Should be &= NBIT0; but I'm trying to find a problem, and this is what Freescale does

	return handleCANT0Error(MODULE_ISNT_READY_TO_WORK);
}

unsigned char sendExtendedMessageOverCANT0(unsigned long *data, unsigned char dataLength, unsigned long identifier, unsigned char priorityByte){
	if(CANT0TFLG & (BIT0|BIT1|BIT2)){  // pg 437 for detailed explnation of why this and the next line are correct
		CANT0TBSEL = CANT0TFLG;  // Sets pointer to appropriate buffer pg 458
		
		// *((unsigned long *)&CANT0TXIDREG0) = identifier;
		
		CANT0TXIDREG0 = ((identifier & 0xFF000000) >> 24);  // Might not need the & operation?
		CANT0TXIDREG1 = ((identifier & 0x00FF0000) >> 16);
		CANT0TXIDREG2 = ((identifier & 0x0000FF00) >> 8);
		CANT0TXIDREG3 =  (identifier & 0x000000FF);

		CANT0TXIDREG0 = 0x18;
		CANT0TXIDREG1 = 0xFE;
		CANT0TXIDREG2 = 0XDF;
		CANT0TXIDREG3 = 0x00;

		unsigned long n = 0;
		unsigned char flag;
		flag = CANT0TBSEL;
		while(n < dataLength){
			if(n < 8){
				*(&CANT0TXDATASEG0 + n) = data[n];
			}
			n++;
		}
		CANT0TXDATALENGTH = dataLength;
		CANT0TXPRIORITY = priorityByte;
		CANT0TFLG = flag;  // Clear buffer for transmission
		while(((CANT0TFLG & flag) != flag) && n <= MAX_CODE_TIME){  // Waiting for it to send seems dumb, but it fails otherwise :-/
			n++;
		}
		return DONE;
	}
	return NO_MT_TX_BUFFERS;
	
}

unsigned char receiveCANT0(unsigned long *identifier, unsigned long *data){
	unsigned char dataLength;
	unsigned char n;	
	dataLength = CANT0RXDATALENGTH & 0x0F;
	n = 0;
	while(n < dataLength){
		if(n == 0){
			*identifier = ((((unsigned long) CANT0RXIDREG3) << 24) + (((unsigned long) CANT0RXIDREG2) << 16) + (((unsigned long) CANT0RXIDREG1) << 8) + CANT0RXIDREG0);
		}
		if(n < 4){ //Needs 8
			data[n] = *(&CANT0RXDATASEG0 + n);
		}
		n++;
	}
	CANT0RFLG = BIT0;
	return DONE;
}

unsigned char handleCANT0Error(unsigned char errorID){
	unsigned long n;
	if(errorID == 0){
		//Handling all cases. This would also be handled properly by the last else
		return DONE;
	}else if((errorID == 1) && (!(CANT0CTL1 & BIT0))){
		n = 0;
		while(((CANT0CTL1 & BIT0) == 0) && (n <= MAX_CODE_TIME)){  // Wait for module to enter initialization mode
			n++;
		}
		if((CANT0CTL1 & BIT0) == 0){
			return MODULE_ISNT_READY_TO_BE_PROGRAMMED;
		}
		return initCANT0();
	}else if((errorID == 2) && (CANT0CTL1 & BIT0)){
		n = 0;
		while((CANT0CTL1 & BIT0) && (n <= MAX_CODE_TIME)){  // Wait for module
			n++;
		}
		if(CANT0CTL1 & BIT0){
			return MODULE_ISNT_READY_TO_WORK;
		}
		return handleCANT0Error(NO_SYNC);
	}else if((errorID == 3) && (!(CANT0TFLG & (BIT0|BIT1|BIT2)))){
		return NO_MT_TX_BUFFERS;
	}else if(errorID == 4){
		// TODO pass this up to a logged variable so that it can be seen that the RX needs read more often. zsp10 or similar
	}else if(errorID == 5){
		// There's nothing to do about this except clear it. Maybe throw an error for the user to see?
	}else if((errorID == 6) && (!(CANT0CTL0 & BIT4))){
		n = 0;
		while(((CANT0CTL0 & BIT4) == 0) && (n <= MAX_CODE_TIME)){
			n++;
		}
		if(!(CANT0CTL0 & BIT4)){
			return NO_SYNC;
		}
	}else{
		// TODO pass this up to a logged variable so that it can be seen. zsp10 or similar
		return errorID; // Undefined error, probably added an error code without much thought put into properly handling it
	}
	return DONE;
}

/*
unsigned char sendExtendedMessageOverCANT0(unsigned long *data, unsigned char dataLengthInBytes, unsigned long thirtyTwoBitIdentifier, unsigned char priorityByte){
	if(CANT0TFLG & (BIT0|BIT1|BIT2)){  // pg 437 for detailed explnation of why this and the next line are correct
		CANT0TBSEL = CANT0TFLG;  // Sets pointer to appropriate buffer pg 458
		//CANXTXFG = identifier <- control bits <- data; // Only place you can write data, with the help of TBSEL it's pointing to the right buffer
		if(dataLengthInBytes > 8){
			return MESSAGE_TOO_LONG;
		}
		unsigned long *eightBitPointer = (unsigned long*)&thirtyTwoBitIdentifier;
		CANT0TXIDREG0 = eightBitPointer[0];
		CANT0TXIDREG1 = eightBitPointer[1];
		CANT0TXIDREG2 = eightBitPointer[2];
		CANT0TXIDREG3 = eightBitPointer[3];
		
		// My original implementation that makes sense to me, but is probably really slow.
	
		//(CANT0CTL0 + TXIDREG0) = ((thirtyTwoBitIdentifier & 0xFF000000) >> 24);  // Might not need the & operation?
		//(CANT0CTL0 + TXIDREG1) = ((thirtyTwoBitIdentifier & 0x00FF0000) >> 16);
		//(CANT0CTL0 + TXIDREG2) = ((thirtyTwoBitIdentifier & 0x0000FF00) >> 8);
		//(CANT0CTL0 + TXIDREG3) =  (thirtyTwoBitIdentifier & 0x000000FF);

		eightBitPointer = data;
		CANT0TXDATASEG0 = eightBitPointer[0];
		CANT0TXDATASEG1 = eightBitPointer[1];
		CANT0TXDATASEG2 = eightBitPointer[2];
		CANT0TXDATASEG3 = eightBitPointer[3];
		CANT0TXDATASEG4 = eightBitPointer[4];
		CANT0TXDATASEG5 = eightBitPointer[5];
		CANT0TXDATASEG6 = eightBitPointer[6];
		CANT0TXDATASEG7 = eightBitPointer[7];
		CANT0TXDATALENGTH = dataLengthInBytes;
		CANT0TXPRIORITY = priorityByte;

		// the remaining two bytes are time stamps TSRH-TSRL. Not enabled at the time of writing
		CANT0TFLG = CANT0TBSEL;  // Clear buffer for transmission
		return DONE;
	}
	return NO_MT_TX_BUFFERS;
}
*/

































unsigned char highPriorityTransmission(){  // Two options I think, kick a low priority message out of the buffer, or throw an interrupt when a reg becomes avaliable. Used for a code 2 from the transmit function.
	//CAN1TIER for interrupt enable
	//CAN1TARQ for abort request
	//CAN1TAAK Abort Ack
	return DONE;
}
/*
unsigned char receiveCANISR(unsigned char *data){
	if(CANT0RFLG & BIT1){  // Throw the interrupt away if no data was stored due to overflow
		CANT0RFLG |= BIT1;
		return RX_DATA_OVERFLOW;
	}
	// You can only read when (CANXRFLG + CANT0CTL0) BIT0 is 1 pg430 & 450
	if(CANT0CTL0 &= BIT7){  // A valid message has been recieved since last clearing this flag
		CANT0CTL0 |= BIT7;
	}else{
		return DONE;
	}

	// Determine the data we're looking at. I'm not quite sure how to do this.
	if(CANT0IDAC & 0x30){
		// Filter closed, :-/ ... No data? 
	}else if(CANT0IDAC & 0x20){
		// eight 8-bit acceptence filters
	}else if(CANT0IDAC & 0x10){
		// four 16-bit filters
	}else{
		// two 32-bit filters
	}

	CANT0RFLG |= BIT0;  // Clear flag
	return DONE;
}
*/












