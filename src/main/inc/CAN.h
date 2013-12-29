/* FreeEMS - the open source engine management system
 *
 * Copyright 2013 Peter Johnson
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

#ifndef CAN_H
#define CAN_H
unsigned char initCANT0();
unsigned char handleCANT0Error(unsigned char);
unsigned char sendExtendedMessageOverCANT0(unsigned long *, unsigned char, unsigned long, unsigned char);
unsigned char receiveCANT0(unsigned long *, unsigned char *);
#endif
