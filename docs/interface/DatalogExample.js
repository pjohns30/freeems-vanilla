{
	"FreeEMSStructuredDataLog": {
		"MetaData": {
			"DateTimeStarted":					"2008/11/22 07:22:57 GMT",
			"DateTimeLastWritten":				"2008/11/22 07:22:58 GMT",
			"FirmwareVersionUniqueIdentifier":	"FreeEMS Vanilla 0.0.17 pre-alpha",
			"TuningToolName":					"FreeEMS-Tuner",
			"TuningToolVersion":				"0.1 build 200811220726r",
			"VehicleProfileIdentifier":			"SweetHBCosmo1",
			"UserNotes":						"This wxPython app rocks!"
		},
		"Columns": [
			{"Name": "AppSeq",	"Unit": "Logs",		"Description": "The index of a particular log entry as the application received them."},
			{"Name": "EMSSeq",	"Unit": "Logs",		"Description": "The index of a particular log entry as FreeEMS sent them."},
			{"Name": "RPM",		"Unit": "RPM",		"Description": "Revolutions Per Minute - The rotational speed of the engine."},
			{"Name": "MAP",		"Unit": "kPa",		"Description": "Manifold Absolute Pressure - The pressure in the intake manifold in kilo Pascals."},
			{"Name": "CHT",		"Unit": "*C",		"Description": "Coolant/Head Temperature - The temperature of the engine itself."},
			{"Name": "IAT",		"Unit": "*C",		"Description": "Inlet Air Temperature - The temperature of the air the engine was breathing."},
			{"Name": "TPS",		"Unit": "%",		"Description": "Throttle Position Sensor - The proportion that the thottle plates are open."},
			{"Name": "EGO",		"Unit": "Lambda",	"Description": "Exhaust Gas Oxygen - How rich or lean the exhaust gas stream is."},
			{"Name": "AAP",		"Unit": "kPa",		"Description": "Absolute Atmospheric Pressure - An indicator of exhaust scavenging efficiency."},
			{"Name": "BRV",		"Unit": "V",		"Description": "Battery Reference Voltage - The current voltage at the battery reference sense wire."},
			{"Name": "MAT",		"Unit": "*C",		"Description": "Manifold Air Temperature - What temperature the air is inside the intake manifold."},
			{"Name": "EGO2",	"Unit": "Lambda",	"Description": "Exhaust Gas Oxygen - How rich or lean the exhaust gas stream is."},
			{"Name": "IAP",		"Unit": "kPa",		"Description": "Intercooler Absolute Pressure - The pressure in the intake before the throttle."},
			{"Name": "MAF",		"Unit": "Flow",		"Description": "Mass Air Flow - A direct measurement of air flow through the engine."},
			{"Name": "DMAP",	"Unit": "DkPa",		"Description": "Delta MAP - The rate of change of MAP."},
			{"Name": "DTPS",	"Unit": "D%",		"Description": "Delta TPS - The rate of change of TPS."},
			{"Name": "DRPM",	"Unit": "DRPM",		"Description": "Delta RPM - The rate of change of RPM."},
			{"Name": "DDRPM",	"Unit": "DDRPM",	"Description": "Delta Delta RPM - The rate of change of the rate of change of RPM."},
			{"Name": "LoadMain","Unit": "%",		"Description": "Engine Load - Usually configured to be the same as MAP."},
			{"Name": "Boost",	"Unit": "PSI",		"Description": "Boost Presssure - Pressure in the manifold in Pounds per Square Inch."},
			{"Name": "VEMain",	"Unit": "%",		"Description": "Volumetric Efficiency - The proportion of cylinder filling occurring."},
			{"Name": "Lambda",	"Unit": "Lambda",	"Description": "Lambda Target - The Lambda we are aiming to achieve."},
			{"Name": "BasePW",	"Unit": "ms",		"Description": "Base Pulse Width - Fuel injection pulse width before applying corrections."},
			{"Name": "IDT",		"Unit": "ms",		"Description": "Injector Dead Time - How long per pulse the injector spends powered up and closed."},
			{"Name": "ETE",		"Unit": "ms/%",		"Description": "Engine Temperature Enrichment - Fuel added to assist warm up or cool when hot."},
			{"Name": "TFCTotal","Unit": "ms/%",		"Description": "Transient Fuel Correction - Fuel added to ensure Lambda during rapid changes."},
			{"Name": "FinalPW",	"Unit": "ms",		"Description": "Final Pulse Width - Fuel injection pulse width before individual cylinder trims."},
			{"Name": "RefPW",	"Unit": "ms",		"Description": "Reference Pulse Width - Currently Base + Dead Time."},
			{"Name": "IgnAdv",	"Unit": "*BTDC",	"Description": "Ignition Advance - Degrees Before Top Dead Centre"},
			{"Name": "Dwell",	"Unit": "ms",		"Description": "Dwell - How long the coil has battery voltage applied to it before the spark event."},
			{"Name": "Time",	"Unit": "s",		"Description": "How long since the device started up it has been."}
		],
		"Data": [
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7},
			{3.14159,8,7,23,5,5,6,8,11,8,76,54,22,3,44,33,45,6,7,8,66,8,76,5,4,3,77,3,4,56,7}
		]
	}
}