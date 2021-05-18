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
L Regulator_Switching:LM2575-5.0BT U1
U 1 1 609BE1DC
P 6050 2900
F 0 "U1" H 6050 3267 50  0000 C CNN
F 1 "LM2575-5.0BT" H 6050 3176 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-5_TabPin3" H 6050 2650 50  0001 L CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/lm2575.pdf" H 6050 2900 50  0001 C CNN
	1    6050 2900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J1
U 1 1 609BF151
P 8000 3000
F 0 "J1" H 8028 3026 50  0000 L CNN
F 1 "5V out" H 8028 2935 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.0mm_L10.0mm" H 8000 3000 50  0001 C CNN
F 3 "~" H 8000 3000 50  0001 C CNN
	1    8000 3000
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRFS4310Z Q1
U 1 1 609C1A30
P 3300 3700
F 0 "Q1" H 3504 3746 50  0000 L CNN
F 1 "IRFS4310Z" H 3504 3655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-263-2" H 3500 3625 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/irfb4310zpbf.pdf?fileId=5546d462533600a4015356161b4d1e2d" H 3300 3700 50  0001 L CNN
	1    3300 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 609C440D
P 3700 2450
F 0 "R3" V 3907 2450 50  0000 C CNN
F 1 "680k" V 3816 2450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3630 2450 50  0001 C CNN
F 3 "~" H 3700 2450 50  0001 C CNN
	1    3700 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:L L1
U 1 1 609C4E0D
P 6950 3000
F 0 "L1" V 7140 3000 50  0000 C CNN
F 1 "100uH" V 7049 3000 50  0000 C CNN
F 2 "Inductor_THT:L_Axial_L7.0mm_D3.3mm_P5.08mm_Vertical_Fastron_MICC" H 6950 3000 50  0001 C CNN
F 3 "~" H 6950 3000 50  0001 C CNN
	1    6950 3000
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Schottky D1
U 1 1 609C6277
P 6650 3200
F 0 "D1" V 6604 3280 50  0000 L CNN
F 1 "D_Schottky" V 6695 3280 50  0000 L CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 6650 3200 50  0001 C CNN
F 3 "~" H 6650 3200 50  0001 C CNN
	1    6650 3200
	0    1    1    0   
$EndComp
$Comp
L Device:CP C2
U 1 1 609D1328
P 7250 3200
F 0 "C2" H 7368 3246 50  0000 L CNN
F 1 "330uF" H 7368 3155 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 7288 3050 50  0001 C CNN
F 3 "~" H 7250 3200 50  0001 C CNN
	1    7250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3050 7250 3000
Connection ~ 7250 3000
Wire Wire Line
	7250 3000 7100 3000
Wire Wire Line
	7250 3000 7250 2800
Wire Wire Line
	7250 2800 6550 2800
Wire Wire Line
	6550 3000 6650 3000
Wire Wire Line
	6650 3050 6650 3000
Connection ~ 6650 3000
Wire Wire Line
	6650 3000 6800 3000
Wire Wire Line
	7250 3350 7250 3450
Wire Wire Line
	7250 3450 6650 3450
Wire Wire Line
	6050 3450 6050 3200
Wire Wire Line
	6650 3350 6650 3450
Connection ~ 6650 3450
Wire Wire Line
	6650 3450 6050 3450
Wire Wire Line
	5550 3000 5550 3450
Wire Wire Line
	5550 3450 6050 3450
Connection ~ 6050 3450
$Comp
L Transistor_BJT:BC327 Q2
U 1 1 609DBE91
P 3050 2450
F 0 "Q2" H 3241 2496 50  0000 L CNN
F 1 "BC327" H 3241 2405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 3250 2375 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/BC327-D.PDF" H 3050 2450 50  0001 L CNN
	1    3050 2450
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 609E94F6
P 2950 3000
F 0 "R1" H 3020 3046 50  0000 L CNN
F 1 "680k" H 3020 2955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2880 3000 50  0001 C CNN
F 3 "~" H 2950 3000 50  0001 C CNN
	1    2950 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 609E9CAE
P 2950 4150
F 0 "R2" H 3020 4196 50  0000 L CNN
F 1 "100k" H 3020 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2880 4150 50  0001 C CNN
F 3 "~" H 2950 4150 50  0001 C CNN
	1    2950 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 609F39B2
P 4000 2750
F 0 "R4" H 4070 2796 50  0000 L CNN
F 1 "47k" H 4070 2705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3930 2750 50  0001 C CNN
F 3 "~" H 4000 2750 50  0001 C CNN
	1    4000 2750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC337 Q3
U 1 1 609F468F
P 4100 3150
F 0 "Q3" H 4291 3196 50  0000 L CNN
F 1 "BC337" H 4291 3105 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 4300 3075 50  0001 L CIN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bc337.pdf" H 4100 3150 50  0001 L CNN
	1    4100 3150
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J2
U 1 1 60A01AD4
P 2400 2050
F 0 "J2" H 2428 2076 50  0000 L CNN
F 1 "battery +" H 2428 1985 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.0mm_L10.0mm" H 2400 2050 50  0001 C CNN
F 3 "~" H 2400 2050 50  0001 C CNN
	1    2400 2050
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J6
U 1 1 60A0C850
P 5050 4100
F 0 "J6" H 4942 3775 50  0000 C CNN
F 1 "button" H 4942 3866 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x02_P1.27mm_Vertical" H 5050 4100 50  0001 C CNN
F 3 "~" H 5050 4100 50  0001 C CNN
	1    5050 4100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 60A0D4EF
P 4400 2950
F 0 "R5" V 4607 2950 50  0000 C CNN
F 1 "680k" V 4516 2950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4330 2950 50  0001 C CNN
F 3 "~" H 4400 2950 50  0001 C CNN
	1    4400 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J4
U 1 1 60A0DC60
P 4600 2700
F 0 "J4" H 4628 2726 50  0000 L CNN
F 1 "on/off" H 4628 2635 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.0mm_L10.0mm" H 4600 2700 50  0001 C CNN
F 3 "~" H 4600 2700 50  0001 C CNN
	1    4600 2700
	1    0    0    1   
$EndComp
$Comp
L Transistor_BJT:BC337 Q4
U 1 1 60A2A8A0
P 5800 4200
F 0 "Q4" H 5991 4246 50  0000 L CNN
F 1 "BC337" H 5991 4155 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 6000 4125 50  0001 L CIN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bc337.pdf" H 5800 4200 50  0001 L CNN
	1    5800 4200
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 60A30777
P 6100 4450
F 0 "R6" H 6170 4496 50  0000 L CNN
F 1 "10k" H 6170 4405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6030 4450 50  0001 C CNN
F 3 "~" H 6100 4450 50  0001 C CNN
	1    6100 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 60A314FD
P 6450 4200
F 0 "C1" V 6198 4200 50  0000 C CNN
F 1 "100nF" V 6289 4200 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 6488 4050 50  0001 C CNN
F 3 "~" H 6450 4200 50  0001 C CNN
	1    6450 4200
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 60A32476
P 7350 4200
F 0 "R7" V 7557 4200 50  0000 C CNN
F 1 "10k" V 7466 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7280 4200 50  0001 C CNN
F 3 "~" H 7350 4200 50  0001 C CNN
	1    7350 4200
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J7
U 1 1 60A330AF
P 7950 4200
F 0 "J7" H 7978 4226 50  0000 L CNN
F 1 "charger" H 7978 4135 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.0mm_L10.0mm" H 7950 4200 50  0001 C CNN
F 3 "~" H 7950 4200 50  0001 C CNN
	1    7950 4200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J5
U 1 1 60A42DC6
P 7950 3450
F 0 "J5" H 7978 3476 50  0000 L CNN
F 1 "motor -" H 7978 3385 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.3mm_L11.3mm_W2.8mm_Flat" H 7950 3450 50  0001 C CNN
F 3 "~" H 7950 3450 50  0001 C CNN
	1    7950 3450
	1    0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J3
U 1 1 60A43E39
P 2450 4650
F 0 "J3" H 2478 4676 50  0000 L CNN
F 1 "battery -" H 2478 4585 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.3mm_L11.3mm_W2.8mm_Flat" H 2450 4650 50  0001 C CNN
F 3 "~" H 2450 4650 50  0001 C CNN
	1    2450 4650
	-1   0    0    1   
$EndComp
$Comp
L Device:Buzzer BZ1
U 1 1 60A668ED
P 7350 3800
F 0 "BZ1" V 7308 3952 50  0000 L CNN
F 1 "Buzzer" V 7399 3952 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_Mallory_AST1109MLTRQ" V 7325 3900 50  0001 C CNN
F 3 "~" V 7325 3900 50  0001 C CNN
	1    7350 3800
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J8
U 1 1 60A8ABEA
P 7950 3700
F 0 "J8" H 7978 3726 50  0000 L CNN
F 1 "buzzer" H 7978 3635 50  0000 L CNN
F 2 "Connector_Pin:Pin_D1.0mm_L10.0mm" H 7950 3700 50  0001 C CNN
F 3 "~" H 7950 3700 50  0001 C CNN
	1    7950 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3000 7800 3000
Wire Wire Line
	7450 3700 7750 3700
Wire Wire Line
	7250 3700 7250 3450
Connection ~ 7250 3450
Wire Wire Line
	3400 3500 3400 3450
Wire Wire Line
	3400 3450 4000 3450
Connection ~ 5550 3450
Connection ~ 4000 3450
Wire Wire Line
	4000 3450 5550 3450
Wire Wire Line
	4000 3000 4000 2950
Wire Wire Line
	5550 2050 5550 2800
Connection ~ 2950 4650
Wire Wire Line
	2950 4650 3400 4650
Wire Wire Line
	2950 2850 2950 2650
Wire Wire Line
	2950 2250 2950 2050
Wire Wire Line
	2600 2050 2950 2050
Connection ~ 2950 2050
Wire Wire Line
	2950 2050 5550 2050
Wire Wire Line
	3550 2450 3250 2450
Wire Wire Line
	3850 2450 4000 2450
Wire Wire Line
	4000 2450 4000 2600
Wire Wire Line
	3100 3700 2950 3700
Connection ~ 2950 3700
Wire Wire Line
	2950 3700 2950 3150
Connection ~ 4000 2950
Wire Wire Line
	4000 2950 4000 2900
Wire Wire Line
	4400 2700 4400 2800
Wire Wire Line
	4400 3100 4400 3150
Wire Wire Line
	4400 3150 4300 3150
Wire Wire Line
	4000 2450 5250 2450
Wire Wire Line
	5250 2450 5250 3850
Connection ~ 4000 2450
Wire Wire Line
	5700 4000 5700 3850
Wire Wire Line
	5700 3850 5250 3850
Connection ~ 5250 3850
Wire Wire Line
	5250 3850 5250 4000
Wire Wire Line
	6100 4600 6100 4650
Wire Wire Line
	6100 4650 5700 4650
Connection ~ 3400 4650
Wire Wire Line
	3400 3900 3400 4650
Wire Wire Line
	2950 3700 2950 4000
Wire Wire Line
	2950 4300 2950 4650
Wire Wire Line
	5250 4100 5250 4650
Connection ~ 5250 4650
Wire Wire Line
	5250 4650 3400 4650
Wire Wire Line
	6000 4200 6100 4200
Wire Wire Line
	6100 4300 6100 4200
Connection ~ 6100 4200
Wire Wire Line
	6100 4200 6300 4200
Wire Wire Line
	5700 4400 5700 4650
Connection ~ 5700 4650
Wire Wire Line
	5700 4650 5250 4650
Wire Wire Line
	2650 4650 2950 4650
$Comp
L Device:R R?
U 1 1 60A7270E
P 6850 4450
F 0 "R?" H 6920 4496 50  0000 L CNN
F 1 "1k" H 6920 4405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6780 4450 50  0001 C CNN
F 3 "~" H 6850 4450 50  0001 C CNN
	1    6850 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 4600 6850 4650
Wire Wire Line
	6850 4300 6850 4200
Connection ~ 6850 4200
Wire Wire Line
	6850 4200 7200 4200
Wire Wire Line
	6600 4200 6850 4200
Wire Wire Line
	6100 4650 6850 4650
Connection ~ 6100 4650
Wire Wire Line
	7500 4200 7750 4200
Wire Wire Line
	7750 3450 7250 3450
Wire Wire Line
	4000 3350 4000 3450
$EndSCHEMATC
