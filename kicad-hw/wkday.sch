EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74xx:74HC595 U1
U 1 1 5DFEABB3
P 3400 1700
F 0 "U1" H 3650 2250 50  0000 C CNN
F 1 "74HC595" H 3150 2250 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 3400 1700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 3400 1700 50  0001 C CNN
	1    3400 1700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U2
U 1 1 5DFEB916
P 3400 3400
F 0 "U2" H 3650 3950 50  0000 C CNN
F 1 "74HC595" H 3150 3950 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 3400 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 3400 3400 50  0001 C CNN
	1    3400 3400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U3
U 1 1 5DFEC8B0
P 3400 5100
F 0 "U3" H 3650 5650 50  0000 C CNN
F 1 "74HC595" H 3150 5650 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 3400 5100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 3400 5100 50  0001 C CNN
	1    3400 5100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U4
U 1 1 5DFEE7CD
P 3400 6800
F 0 "U4" H 3650 7350 50  0000 C CNN
F 1 "74HC595" H 3150 7350 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 3400 6800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 3400 6800 50  0001 C CNN
	1    3400 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5DFF9E2E
P 3400 7500
F 0 "#PWR09" H 3400 7250 50  0001 C CNN
F 1 "GND" H 3400 7350 50  0000 C CNN
F 2 "" H 3400 7500 50  0001 C CNN
F 3 "" H 3400 7500 50  0001 C CNN
	1    3400 7500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5DFFABAC
P 3400 4100
F 0 "#PWR05" H 3400 3850 50  0001 C CNN
F 1 "GND" H 3400 3950 50  0000 C CNN
F 2 "" H 3400 4100 50  0001 C CNN
F 3 "" H 3400 4100 50  0001 C CNN
	1    3400 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5DFFAFD7
P 3400 2400
F 0 "#PWR03" H 3400 2150 50  0001 C CNN
F 1 "GND" H 3400 2250 50  0000 C CNN
F 2 "" H 3400 2400 50  0001 C CNN
F 3 "" H 3400 2400 50  0001 C CNN
	1    3400 2400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR02
U 1 1 5E000742
P 3400 1100
F 0 "#PWR02" H 3400 950 50  0001 C CNN
F 1 "VCC" H 3400 1250 50  0000 C CNN
F 2 "" H 3400 1100 50  0001 C CNN
F 3 "" H 3400 1100 50  0001 C CNN
	1    3400 1100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR04
U 1 1 5E001158
P 3400 2800
F 0 "#PWR04" H 3400 2650 50  0001 C CNN
F 1 "VCC" H 3400 2950 50  0000 C CNN
F 2 "" H 3400 2800 50  0001 C CNN
F 3 "" H 3400 2800 50  0001 C CNN
	1    3400 2800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR06
U 1 1 5E004A94
P 3400 4500
F 0 "#PWR06" H 3400 4350 50  0001 C CNN
F 1 "VCC" H 3400 4650 50  0000 C CNN
F 2 "" H 3400 4500 50  0001 C CNN
F 3 "" H 3400 4500 50  0001 C CNN
	1    3400 4500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR08
U 1 1 5E005473
P 3400 6200
F 0 "#PWR08" H 3400 6050 50  0001 C CNN
F 1 "VCC" H 3400 6350 50  0000 C CNN
F 2 "" H 3400 6200 50  0001 C CNN
F 3 "" H 3400 6200 50  0001 C CNN
	1    3400 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3000 2900 3000
Wire Wire Line
	2900 3000 2900 2600
Wire Wire Line
	2900 2600 3900 2600
Wire Wire Line
	3900 2600 3900 2200
Wire Wire Line
	3900 2200 3800 2200
Wire Wire Line
	3800 3900 3900 3900
Wire Wire Line
	3900 3900 3900 4300
Wire Wire Line
	3900 4300 2900 4300
Wire Wire Line
	2900 4300 2900 4700
Wire Wire Line
	2900 4700 3000 4700
Wire Wire Line
	3800 5600 3900 5600
Wire Wire Line
	3900 5600 3900 6000
Wire Wire Line
	3900 6000 2900 6000
Wire Wire Line
	2900 6000 2900 6400
Wire Wire Line
	2900 6400 3000 6400
$Comp
L power:VCC #PWR01
U 1 1 5E0081D8
P 2800 900
F 0 "#PWR01" H 2800 750 50  0001 C CNN
F 1 "VCC" H 2800 1050 50  0000 C CNN
F 2 "" H 2800 900 50  0001 C CNN
F 3 "" H 2800 900 50  0001 C CNN
	1    2800 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 900  2800 950 
Wire Wire Line
	2800 1600 3000 1600
Wire Wire Line
	2800 1600 2800 3300
Wire Wire Line
	2800 3300 3000 3300
Connection ~ 2800 1600
Wire Wire Line
	2800 3300 2800 5000
Wire Wire Line
	2800 5000 3000 5000
Connection ~ 2800 3300
Wire Wire Line
	2800 5000 2800 6700
Wire Wire Line
	2800 6700 3000 6700
Connection ~ 2800 5000
Wire Wire Line
	3000 1300 1950 1300
Wire Wire Line
	3000 1500 2500 1500
Text Label 1950 1300 0    50   ~ 0
MOSI
Text Label 1950 1500 0    50   ~ 0
CLK
Wire Wire Line
	3000 1800 2600 1800
Text Label 1950 1800 0    50   ~ 0
SPICS
Text Label 1950 1900 0    50   ~ 0
~DISP_ON
Wire Wire Line
	3000 1900 2700 1900
$Comp
L Device:R_Small R1
U 1 1 5E010399
P 2700 1100
F 0 "R1" H 2450 1150 50  0000 L CNN
F 1 "100k" H 2400 1050 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2700 1100 50  0001 C CNN
F 3 "~" H 2700 1100 50  0001 C CNN
	1    2700 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 1900 2700 1200
Connection ~ 2700 1900
Wire Wire Line
	2700 1900 1950 1900
Wire Wire Line
	2700 1000 2700 950 
Wire Wire Line
	2700 950  2800 950 
Connection ~ 2800 950 
Wire Wire Line
	2800 950  2800 1600
Wire Wire Line
	2700 1900 2700 3600
Wire Wire Line
	2700 3600 3000 3600
Wire Wire Line
	2700 3600 2700 5300
Wire Wire Line
	2700 5300 3000 5300
Connection ~ 2700 3600
Wire Wire Line
	2700 5300 2700 7000
Wire Wire Line
	2700 7000 3000 7000
Connection ~ 2700 5300
Wire Wire Line
	2600 1800 2600 3500
Wire Wire Line
	2600 3500 3000 3500
Connection ~ 2600 1800
Wire Wire Line
	2600 1800 1950 1800
Wire Wire Line
	2600 3500 2600 5200
Wire Wire Line
	2600 5200 3000 5200
Connection ~ 2600 3500
Wire Wire Line
	2600 5200 2600 6900
Wire Wire Line
	2600 6900 3000 6900
Connection ~ 2600 5200
Wire Wire Line
	2500 1500 2500 3200
Wire Wire Line
	2500 3200 3000 3200
Connection ~ 2500 1500
Wire Wire Line
	2500 1500 1950 1500
Wire Wire Line
	2500 3200 2500 4900
Wire Wire Line
	2500 4900 3000 4900
Connection ~ 2500 3200
Wire Wire Line
	2500 4900 2500 6600
Wire Wire Line
	2500 6600 3000 6600
Connection ~ 2500 4900
Text Label 2900 2600 0    50   ~ 0
SC1
Text Label 2900 4300 0    50   ~ 0
SC2
Text Label 2900 6000 0    50   ~ 0
SC3
$Comp
L Connector_Generic:Conn_01x10 J1
U 1 1 5E029FF0
P 6700 2450
F 0 "J1" V 6800 2850 50  0000 C CNN
F 1 "DISP1_1_10" V 6800 2150 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 6700 2450 50  0001 C CNN
F 3 "~" H 6700 2450 50  0001 C CNN
	1    6700 2450
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x09 J3
U 1 1 5E02C128
P 6800 2100
F 0 "J3" V 6900 1600 50  0000 C CNN
F 1 "DISP1_11_20" V 6900 2300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 6800 2100 50  0001 C CNN
F 3 "~" H 6800 2100 50  0001 C CNN
	1    6800 2100
	0    1    1    0   
$EndComp
Wire Notes Line
	7300 1900 7500 1900
Wire Notes Line
	7300 2650 7500 2650
Text Notes 7250 2300 0    50   ~ 0
62 mm
Wire Notes Line
	7400 2650 7400 2350
Wire Notes Line
	7400 2200 7400 1900
Text Notes 6300 1900 1    50   ~ 0
20 No Pin
Wire Notes Line
	6300 1900 6300 2100
Text Notes 7150 1850 0    50   ~ 0
11
$Comp
L Connector_Generic:Conn_01x10 J2
U 1 1 5E043F65
P 6700 4000
F 0 "J2" V 6800 4400 50  0000 C CNN
F 1 "DISP2_1_10" V 6800 3700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 6700 4000 50  0001 C CNN
F 3 "~" H 6700 4000 50  0001 C CNN
	1    6700 4000
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x09 J4
U 1 1 5E043F6F
P 6800 3650
F 0 "J4" V 6900 3150 50  0000 C CNN
F 1 "DISP2_11_20" V 6900 3850 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 6800 3650 50  0001 C CNN
F 3 "~" H 6800 3650 50  0001 C CNN
	1    6800 3650
	0    1    1    0   
$EndComp
Wire Notes Line
	7300 3450 7500 3450
Wire Notes Line
	7300 4200 7500 4200
Text Notes 7250 3850 0    50   ~ 0
62 mm
Wire Notes Line
	7400 4200 7400 3900
Wire Notes Line
	7400 3750 7400 3450
Text Notes 6300 3450 1    50   ~ 0
20 No Pin
Wire Notes Line
	6300 3450 6300 3650
Text Notes 7150 3400 0    50   ~ 0
11
$Comp
L power:GND #PWR011
U 1 1 5E051E53
P 6200 4300
F 0 "#PWR011" H 6200 4050 50  0001 C CNN
F 1 "GND" H 6200 4150 50  0000 C CNN
F 2 "" H 6200 4300 50  0001 C CNN
F 3 "" H 6200 4300 50  0001 C CNN
	1    6200 4300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5E0521C8
P 7400 3200
F 0 "#PWR014" H 7400 2950 50  0001 C CNN
F 1 "GND" H 7400 3050 50  0000 C CNN
F 2 "" H 7400 3200 50  0001 C CNN
F 3 "" H 7400 3200 50  0001 C CNN
	1    7400 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5E052780
P 7400 1650
F 0 "#PWR013" H 7400 1400 50  0001 C CNN
F 1 "GND" H 7400 1500 50  0000 C CNN
F 2 "" H 7400 1650 50  0001 C CNN
F 3 "" H 7400 1650 50  0001 C CNN
	1    7400 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5E052F6A
P 6200 2750
F 0 "#PWR010" H 6200 2500 50  0001 C CNN
F 1 "GND" H 6200 2600 50  0000 C CNN
F 2 "" H 6200 2750 50  0001 C CNN
F 3 "" H 6200 2750 50  0001 C CNN
	1    6200 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 1900 7200 1550
Wire Wire Line
	7200 1550 7400 1550
Wire Wire Line
	7400 1550 7400 1650
Wire Wire Line
	7200 3450 7200 3100
Wire Wire Line
	7200 3100 7400 3100
Wire Wire Line
	7400 3100 7400 3200
$Comp
L Device:R_Small R2
U 1 1 5E05963F
P 7400 2750
F 0 "R2" V 7500 2750 50  0000 L CNN
F 1 "560" V 7500 2550 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7400 2750 50  0001 C CNN
F 3 "~" H 7400 2750 50  0001 C CNN
	1    7400 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 2650 7200 2750
Wire Wire Line
	7200 2750 7300 2750
Wire Wire Line
	7500 2750 7750 2750
Text Label 7750 2750 2    50   ~ 0
DP1
$Comp
L Device:R_Small R3
U 1 1 5E063A60
P 7400 4300
F 0 "R3" V 7500 4300 50  0000 L CNN
F 1 "560" V 7500 4100 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7400 4300 50  0001 C CNN
F 3 "~" H 7400 4300 50  0001 C CNN
	1    7400 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 4200 7200 4300
Wire Wire Line
	7200 4300 7300 4300
Wire Wire Line
	7500 4300 7750 4300
Text Label 7750 4300 2    50   ~ 0
DP2
Wire Wire Line
	3800 1300 4200 1300
Wire Wire Line
	3800 1400 4200 1400
Wire Wire Line
	3800 1500 4200 1500
Wire Wire Line
	3800 1600 4200 1600
Wire Wire Line
	4200 2250 3950 2250
Wire Wire Line
	3950 2250 3950 2000
Wire Wire Line
	3950 2000 3800 2000
Wire Wire Line
	4200 2150 4000 2150
Wire Wire Line
	4000 2150 4000 1900
Wire Wire Line
	4000 1900 3800 1900
Wire Wire Line
	4200 2050 4050 2050
Wire Wire Line
	4050 2050 4050 1800
Wire Wire Line
	4050 1800 3800 1800
Wire Wire Line
	3800 1700 4100 1700
Wire Wire Line
	4100 1700 4100 1950
Wire Wire Line
	4100 1950 4200 1950
$Comp
L Device:R_Pack04 RN7
U 1 1 5E07C151
P 5050 3700
F 0 "RN7" V 4633 3700 50  0000 C CNN
F 1 "100" V 4724 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 5325 3700 50  0001 C CNN
F 3 "~" H 5050 3700 50  0001 C CNN
	1    5050 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 3000 4200 3000
Wire Wire Line
	3800 3100 4200 3100
Wire Wire Line
	3800 3200 4200 3200
Wire Wire Line
	3800 3300 4200 3300
$Comp
L Device:R_Pack04 RN5
U 1 1 5E08D6DF
P 4400 5550
F 0 "RN5" V 3983 5550 50  0000 C CNN
F 1 "100" V 4074 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 4675 5550 50  0001 C CNN
F 3 "~" H 4400 5550 50  0001 C CNN
	1    4400 5550
	0    1    1    0   
$EndComp
$Comp
L Device:R_Pack04 RN4
U 1 1 5E0978A3
P 4400 4900
F 0 "RN4" V 3983 4900 50  0000 C CNN
F 1 "100" V 4074 4900 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 4675 4900 50  0001 C CNN
F 3 "~" H 4400 4900 50  0001 C CNN
	1    4400 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 4700 4200 4700
Wire Wire Line
	3800 4800 4200 4800
Wire Wire Line
	3800 4900 4200 4900
Wire Wire Line
	3800 5000 4200 5000
$Comp
L Device:R_Pack04 RN8
U 1 1 5E0A4EAB
P 5050 4350
F 0 "RN8" V 4633 4350 50  0000 C CNN
F 1 "220" V 4724 4350 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 5325 4350 50  0001 C CNN
F 3 "~" H 5050 4350 50  0001 C CNN
	1    5050 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 5650 3950 5650
Wire Wire Line
	3950 5650 3950 5400
Wire Wire Line
	3950 5400 3800 5400
Wire Wire Line
	4200 5550 4000 5550
Wire Wire Line
	4000 5550 4000 5300
Wire Wire Line
	4000 5300 3800 5300
Wire Wire Line
	4200 5450 4050 5450
Wire Wire Line
	4050 5450 4050 5200
Wire Wire Line
	4050 5200 3800 5200
Wire Wire Line
	4200 5350 4100 5350
Wire Wire Line
	4100 5350 4100 5100
Wire Wire Line
	4100 5100 3800 5100
$Comp
L Device:R_Pack04 RN6
U 1 1 5E0B449C
P 4400 6600
F 0 "RN6" V 3983 6600 50  0000 C CNN
F 1 "220" V 4074 6600 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 4675 6600 50  0001 C CNN
F 3 "~" H 4400 6600 50  0001 C CNN
	1    4400 6600
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 6400 4200 6400
Wire Wire Line
	3800 6500 4200 6500
Wire Wire Line
	3800 6600 4200 6600
Wire Wire Line
	3800 6700 4200 6700
NoConn ~ 3800 7300
Text Notes 8000 2050 0    50   ~ 0
A1
Text Notes 8250 2050 0    50   ~ 0
A2
Text Notes 8350 2200 0    50   ~ 0
B
Text Notes 8350 2400 0    50   ~ 0
C
Text Notes 8000 2500 0    50   ~ 0
D1
Text Notes 8250 2500 0    50   ~ 0
D2
Text Notes 7950 2400 0    50   ~ 0
E
Text Notes 7950 2200 0    50   ~ 0
F
Text Notes 8000 2300 0    50   ~ 0
G1
Text Notes 8250 2300 0    50   ~ 0
G2
Text Notes 8050 2200 0    50   ~ 0
H\J/K
Text Notes 8050 2400 0    50   ~ 0
N/M\L
Text Label 6400 2650 3    50   ~ 0
D1_G1
Wire Wire Line
	6200 2750 6300 2750
Wire Wire Line
	6300 2750 6300 2650
Text Label 6500 2650 3    50   ~ 0
D1_E
Text Label 6600 2650 3    50   ~ 0
D1_D1
Text Label 6700 2650 3    50   ~ 0
D1_N
Text Label 6800 2650 3    50   ~ 0
D1_M
Text Label 6900 2650 3    50   ~ 0
D1_D2
Text Label 7000 2650 3    50   ~ 0
D1_L
Text Label 7100 2650 3    50   ~ 0
D1_C
Text Label 7100 1900 1    50   ~ 0
D1_G2
Text Label 7000 1900 1    50   ~ 0
D1_B
Text Label 6900 1900 1    50   ~ 0
D1_A2
Text Label 6800 1900 1    50   ~ 0
D1_K
Text Label 6700 1900 1    50   ~ 0
D1_J
Text Label 6600 1900 1    50   ~ 0
D1_A1
Text Label 6500 1900 1    50   ~ 0
D1_H
Text Label 6400 1900 1    50   ~ 0
D1_F
Text Label 6400 3450 1    50   ~ 0
D2_F
Text Label 6500 3450 1    50   ~ 0
D2_H
Text Label 6600 3450 1    50   ~ 0
D2_A1
Text Label 6700 3450 1    50   ~ 0
D2_J
Text Label 6800 3450 1    50   ~ 0
D2_K
Text Label 6900 3450 1    50   ~ 0
D2_A2
Text Label 7000 3450 1    50   ~ 0
D2_B
Text Label 7100 3450 1    50   ~ 0
D2_G2
Text Label 6400 4200 3    50   ~ 0
D2_G1
Wire Wire Line
	6200 4300 6300 4300
Wire Wire Line
	6300 4300 6300 4200
Text Label 6500 4200 3    50   ~ 0
D2_E
Text Label 6600 4200 3    50   ~ 0
D2_D1
Text Label 6700 4200 3    50   ~ 0
D2_N
Text Label 6800 4200 3    50   ~ 0
D2_M
Text Label 6900 4200 3    50   ~ 0
D2_D2
Text Label 7000 4200 3    50   ~ 0
D2_L
Text Label 7100 4200 3    50   ~ 0
D2_C
Text Notes 8400 2550 0    50   ~ 0
DP
Text Notes 2900 3000 1    50   ~ 0
Serial Cascade
Text Label 4600 1300 0    50   ~ 0
D1_F
Text Label 4600 1400 0    50   ~ 0
D1_H
Text Label 4600 1500 0    50   ~ 0
D1_J
Text Label 4600 1600 0    50   ~ 0
D1_K
Text Label 4600 1950 0    50   ~ 0
D1_C
Text Label 4600 2050 0    50   ~ 0
D1_L
Text Label 4600 2150 0    50   ~ 0
D1_M
Text Label 4600 2250 0    50   ~ 0
D1_N
Text Label 4600 3000 0    50   ~ 0
D1_A1
Text Label 4600 3100 0    50   ~ 0
D1_A2
Text Label 4600 3300 0    50   ~ 0
D1_D2
Text Label 4600 3200 0    50   ~ 0
D1_D1
Text Label 5250 3600 0    50   ~ 0
D1_B
Text Label 5250 3500 0    50   ~ 0
D1_E
Text Label 5250 3800 0    50   ~ 0
D2_B
Text Label 5250 3700 0    50   ~ 0
D2_E
Text Label 5250 4150 0    50   ~ 0
D1_G1
Text Label 5250 4250 0    50   ~ 0
D1_G2
Text Label 5250 4350 0    50   ~ 0
D2_G1
Text Label 5250 4450 0    50   ~ 0
D2_G2
Text Label 4600 4700 0    50   ~ 0
D2_F
Text Label 4600 4800 0    50   ~ 0
D2_H
Text Label 4600 4900 0    50   ~ 0
D2_J
Text Label 4600 5000 0    50   ~ 0
D2_K
Text Label 4600 5350 0    50   ~ 0
D2_C
Text Label 4600 5450 0    50   ~ 0
D2_L
Text Label 4600 5550 0    50   ~ 0
D2_M
Text Label 4600 5650 0    50   ~ 0
D2_N
Text Label 4600 6400 0    50   ~ 0
D2_A1
Text Label 4600 6500 0    50   ~ 0
D2_A2
Text Label 4600 6600 0    50   ~ 0
D2_D1
Text Label 4600 6700 0    50   ~ 0
D2_D2
Text Label 3850 1300 0    50   ~ 0
X0B0
Text Label 3850 1400 0    50   ~ 0
X0B1
Text Label 3850 1500 0    50   ~ 0
X0B2
Text Label 3850 1600 0    50   ~ 0
X0B3
Text Label 3850 1700 0    50   ~ 0
X0B4
Text Label 3850 1800 0    50   ~ 0
X0B5
Text Label 3850 1900 0    50   ~ 0
X0B6
Text Label 3850 2000 0    50   ~ 0
X0B7
Text Label 3850 3000 0    50   ~ 0
X1B0
Text Label 3850 3100 0    50   ~ 0
X1B1
Text Label 3850 3200 0    50   ~ 0
X1B2
Text Label 3850 3300 0    50   ~ 0
X1B3
Text Label 4050 3400 2    50   ~ 0
X1B4
Text Label 4050 3500 2    50   ~ 0
X1B5
Text Label 4050 3600 2    50   ~ 0
X1B6
Text Label 4050 3700 2    50   ~ 0
X1B7
Wire Wire Line
	3800 3400 4050 3400
Wire Wire Line
	4050 3500 3800 3500
Wire Wire Line
	4050 3600 3800 3600
Wire Wire Line
	4050 3700 3800 3700
Text Label 3850 4700 0    50   ~ 0
X2B0
Text Label 3850 4800 0    50   ~ 0
X2B1
Text Label 3850 4900 0    50   ~ 0
X2B2
Text Label 3850 5000 0    50   ~ 0
X2B3
Text Label 3850 5100 0    50   ~ 0
X2B4
Text Label 3850 5200 0    50   ~ 0
X2B5
Text Label 3850 5300 0    50   ~ 0
X2B6
Text Label 3850 5400 0    50   ~ 0
X2B7
Text Label 3850 6400 0    50   ~ 0
X3B0
Text Label 3850 6500 0    50   ~ 0
X3B1
Text Label 3850 6600 0    50   ~ 0
X3B2
Text Label 3850 6700 0    50   ~ 0
X3B3
Text Label 4050 6800 2    50   ~ 0
X3B4
Text Label 4050 6900 2    50   ~ 0
X3B5
Text Label 4050 7000 2    50   ~ 0
X3B6
Text Label 4050 7100 2    50   ~ 0
X3B7
Wire Wire Line
	3800 6800 4050 6800
Wire Wire Line
	3800 6900 4050 6900
Wire Wire Line
	3800 7000 4050 7000
Wire Wire Line
	3800 7100 4050 7100
Text Label 4850 4250 2    50   ~ 0
X1B4
Text Label 4850 4150 2    50   ~ 0
X1B5
Text Label 4850 3600 2    50   ~ 0
X1B6
Text Label 4850 3500 2    50   ~ 0
X1B7
Text Label 4850 4450 2    50   ~ 0
X3B4
Text Label 4850 4350 2    50   ~ 0
X3B5
Text Label 4850 3800 2    50   ~ 0
X3B6
Text Label 4850 3700 2    50   ~ 0
X3B7
$Comp
L Switch:SW_Push SW1
U 1 1 5E20B691
P 6250 5800
F 0 "SW1" H 6250 6085 50  0000 C CNN
F 1 "BTN" H 6250 5994 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6250 6000 50  0001 C CNN
F 3 "~" H 6250 6000 50  0001 C CNN
	1    6250 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5E20D71D
P 6550 6300
F 0 "#PWR012" H 6550 6050 50  0001 C CNN
F 1 "GND" H 6550 6150 50  0000 C CNN
F 2 "" H 6550 6300 50  0001 C CNN
F 3 "" H 6550 6300 50  0001 C CNN
	1    6550 6300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5E20E4C2
P 6250 6200
F 0 "SW2" H 6250 6485 50  0000 C CNN
F 1 "BTN" H 6250 6394 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6250 6400 50  0001 C CNN
F 3 "~" H 6250 6400 50  0001 C CNN
	1    6250 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 6200 6550 6200
Wire Wire Line
	6550 6200 6550 6300
Wire Wire Line
	6450 5800 6550 5800
Wire Wire Line
	6550 5800 6550 6200
Connection ~ 6550 6200
Text Label 6050 5800 2    50   ~ 0
BTN1
Text Label 6050 6200 2    50   ~ 0
BTN2
NoConn ~ 9800 1850
NoConn ~ 9800 1350
$Comp
L power:GND #PWR016
U 1 1 5E22E34C
P 9900 1950
F 0 "#PWR016" H 9900 1700 50  0001 C CNN
F 1 "GND" H 9900 1800 50  0000 C CNN
F 2 "" H 9900 1950 50  0001 C CNN
F 3 "" H 9900 1950 50  0001 C CNN
	1    9900 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 1650 9900 1650
Wire Wire Line
	9900 1650 9900 1750
Wire Wire Line
	9800 1750 9900 1750
Connection ~ 9900 1750
Wire Wire Line
	9900 1750 9900 1950
NoConn ~ 9800 1450
$Comp
L power:VCC #PWR015
U 1 1 5E23FB1B
P 9900 1300
F 0 "#PWR015" H 9900 1150 50  0001 C CNN
F 1 "VCC" H 9900 1450 50  0000 C CNN
F 2 "" H 9900 1300 50  0001 C CNN
F 3 "" H 9900 1300 50  0001 C CNN
	1    9900 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 1550 9900 1550
Wire Wire Line
	9900 1550 9900 1350
$Comp
L Device:C_Small C1
U 1 1 5E244C08
P 10050 1550
F 0 "C1" H 10142 1596 50  0000 L CNN
F 1 ".1u" H 10142 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10050 1550 50  0001 C CNN
F 3 "~" H 10050 1550 50  0001 C CNN
	1    10050 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5E2454B1
P 10350 1550
F 0 "C2" H 10442 1596 50  0000 L CNN
F 1 ".1u" H 10442 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10350 1550 50  0001 C CNN
F 3 "~" H 10350 1550 50  0001 C CNN
	1    10350 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5E2456FE
P 10650 1550
F 0 "C3" H 10742 1596 50  0000 L CNN
F 1 ".1u" H 10742 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10650 1550 50  0001 C CNN
F 3 "~" H 10650 1550 50  0001 C CNN
	1    10650 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5E245A56
P 10950 1550
F 0 "C4" H 11042 1596 50  0000 L CNN
F 1 ".1u" H 11042 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10950 1550 50  0001 C CNN
F 3 "~" H 10950 1550 50  0001 C CNN
	1    10950 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 1750 10050 1750
Wire Wire Line
	10950 1750 10950 1650
Wire Wire Line
	9900 1350 10050 1350
Wire Wire Line
	10950 1350 10950 1450
Connection ~ 9900 1350
Wire Wire Line
	9900 1350 9900 1300
Wire Wire Line
	10650 1350 10650 1450
Connection ~ 10650 1350
Wire Wire Line
	10650 1350 10950 1350
Wire Wire Line
	10350 1350 10350 1450
Connection ~ 10350 1350
Wire Wire Line
	10350 1350 10650 1350
Wire Wire Line
	10050 1350 10050 1450
Connection ~ 10050 1350
Wire Wire Line
	10050 1350 10200 1350
Wire Wire Line
	10050 1650 10050 1750
Connection ~ 10050 1750
Wire Wire Line
	10050 1750 10200 1750
Wire Wire Line
	10350 1650 10350 1750
Connection ~ 10350 1750
Wire Wire Line
	10350 1750 10650 1750
Connection ~ 10650 1750
Wire Wire Line
	10650 1750 10950 1750
$Comp
L Connector_Generic:Conn_01x06 J6
U 1 1 5E276723
P 9600 2750
F 0 "J6" H 9518 2225 50  0000 C CNN
F 1 "ARD_ANALOG" H 9518 2316 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 9600 2750 50  0001 C CNN
F 3 "~" H 9600 2750 50  0001 C CNN
	1    9600 2750
	-1   0    0    1   
$EndComp
NoConn ~ 9800 2950
NoConn ~ 9800 2850
NoConn ~ 9800 2550
NoConn ~ 9800 2450
Text Label 10050 2650 2    50   ~ 0
BTN1
Text Label 10050 2750 2    50   ~ 0
BTN2
Wire Wire Line
	9800 2650 10050 2650
Wire Wire Line
	9800 2750 10050 2750
Text Notes 10050 2450 2    50   ~ 0
A0
$Comp
L Connector_Generic:Conn_01x08 J7
U 1 1 5E298A6A
P 9600 3850
F 0 "J7" H 9518 3225 50  0000 C CNN
F 1 "ARD_DIG1" H 9518 3316 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 9600 3850 50  0001 C CNN
F 3 "~" H 9600 3850 50  0001 C CNN
	1    9600 3850
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J8
U 1 1 5E299490
P 9600 4950
F 0 "J8" H 9518 4325 50  0000 C CNN
F 1 "ARD_DIG2" H 9518 4416 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 9600 4950 50  0001 C CNN
F 3 "~" H 9600 4950 50  0001 C CNN
	1    9600 4950
	-1   0    0    1   
$EndComp
NoConn ~ 9800 4150
NoConn ~ 9800 4050
NoConn ~ 9800 3450
NoConn ~ 9800 3950
NoConn ~ 9800 3850
NoConn ~ 9800 3750
Text Label 10000 3550 2    50   ~ 0
DP1
Text Label 10000 3650 2    50   ~ 0
DP2
Wire Wire Line
	10000 3550 9800 3550
Wire Wire Line
	10000 3650 9800 3650
NoConn ~ 9800 4550
$Comp
L power:GND #PWR07
U 1 1 5DFFA818
P 3400 5800
F 0 "#PWR07" H 3400 5550 50  0001 C CNN
F 1 "GND" H 3400 5650 50  0000 C CNN
F 2 "" H 3400 5800 50  0001 C CNN
F 3 "" H 3400 5800 50  0001 C CNN
	1    3400 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5E2D8F03
P 9950 4600
F 0 "#PWR017" H 9950 4350 50  0001 C CNN
F 1 "GND" H 9950 4450 50  0000 C CNN
F 2 "" H 9950 4600 50  0001 C CNN
F 3 "" H 9950 4600 50  0001 C CNN
	1    9950 4600
	-1   0    0    1   
$EndComp
Wire Wire Line
	9800 4650 9950 4650
Wire Wire Line
	9950 4650 9950 4600
Text Label 10200 5150 2    50   ~ 0
~DISP_ON
Text Label 10200 5050 2    50   ~ 0
SPICS
Text Label 10200 4950 2    50   ~ 0
MOSI
NoConn ~ 9800 4850
NoConn ~ 9800 5250
Text Label 10200 4750 2    50   ~ 0
CLK
Wire Wire Line
	9800 5150 10200 5150
Wire Wire Line
	10200 5050 9800 5050
Wire Wire Line
	10200 4950 9800 4950
Wire Wire Line
	10200 4750 9800 4750
Text Notes 6550 1450 0    50   ~ 0
WxH: 48x70mm
$Comp
L Connector_Generic:Conn_01x06 J5
U 1 1 5E32AE42
P 9600 1650
F 0 "J5" H 9518 1125 50  0000 C CNN
F 1 "ARD_PWR" H 9518 1216 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 9600 1650 50  0001 C CNN
F 3 "~" H 9600 1650 50  0001 C CNN
	1    9600 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	10650 1650 10650 1750
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E36550C
P 10200 1300
F 0 "#FLG0101" H 10200 1375 50  0001 C CNN
F 1 "PWR_FLAG" H 10200 1473 50  0000 C CNN
F 2 "" H 10200 1300 50  0001 C CNN
F 3 "~" H 10200 1300 50  0001 C CNN
	1    10200 1300
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E365E67
P 10200 1900
F 0 "#FLG0102" H 10200 1975 50  0001 C CNN
F 1 "PWR_FLAG" H 10200 2073 50  0000 C CNN
F 2 "" H 10200 1900 50  0001 C CNN
F 3 "~" H 10200 1900 50  0001 C CNN
	1    10200 1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	10200 1300 10200 1350
Connection ~ 10200 1350
Wire Wire Line
	10200 1350 10350 1350
Wire Wire Line
	10200 1900 10200 1750
Connection ~ 10200 1750
Wire Wire Line
	10200 1750 10350 1750
$Comp
L Device:R_Pack04 RN3
U 1 1 5E0C45EE
P 4400 3200
F 0 "RN3" V 3983 3200 50  0000 C CNN
F 1 "220" V 4074 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 4675 3200 50  0001 C CNN
F 3 "~" H 4400 3200 50  0001 C CNN
	1    4400 3200
	0    1    1    0   
$EndComp
$Comp
L Device:R_Pack04 RN1
U 1 1 5E069EFE
P 4400 1500
F 0 "RN1" V 3983 1500 50  0000 C CNN
F 1 "100" V 4074 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 4675 1500 50  0001 C CNN
F 3 "~" H 4400 1500 50  0001 C CNN
	1    4400 1500
	0    1    1    0   
$EndComp
$Comp
L Device:R_Pack04 RN2
U 1 1 5E0738EA
P 4400 2150
F 0 "RN2" V 3983 2150 50  0000 C CNN
F 1 "100" V 4074 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 4675 2150 50  0001 C CNN
F 3 "~" H 4400 2150 50  0001 C CNN
	1    4400 2150
	0    1    1    0   
$EndComp
$EndSCHEMATC
