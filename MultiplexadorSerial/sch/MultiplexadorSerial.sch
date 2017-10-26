EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino_shieldsNCL
LIBS:m_led
LIBS:MultiplexadorSerial-cache
EELAYER 25 0
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
L ARDUINO_SHIELD SHIELD1
U 1 1 59F1D7C7
P 8750 1600
F 0 "SHIELD1" H 8400 2550 60  0000 C CNN
F 1 "ARDUINO_SHIELD" H 8800 650 60  0000 C CNN
F 2 "arduino_shields:ARDUINO SHIELD" H 8750 1600 60  0001 C CNN
F 3 "" H 8750 1600 60  0001 C CNN
	1    8750 1600
	1    0    0    -1  
$EndComp
$Comp
L 4052 U5
U 1 1 59F1D85D
P 8800 3550
F 0 "U5" H 8900 3550 50  0000 C CNN
F 1 "4052" H 8900 3350 50  0000 C CNN
F 2 "w_pth_circuits:dil_16-300_socket" H 8800 3550 60  0001 C CNN
F 3 "" H 8800 3550 60  0001 C CNN
	1    8800 3550
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 59F1DCD9
P 9500 2750
F 0 "C5" H 9525 2850 50  0000 L CNN
F 1 "100nF" H 9525 2650 50  0000 L CNN
F 2 "w_capacitors:cnp_6mm_disc" H 9538 2600 50  0001 C CNN
F 3 "" H 9500 2750 50  0001 C CNN
	1    9500 2750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR01
U 1 1 59F1E27D
P 9850 2750
F 0 "#PWR01" H 9850 2500 50  0001 C CNN
F 1 "GND" H 9850 2600 50  0000 C CNN
F 2 "" H 9850 2750 50  0001 C CNN
F 3 "" H 9850 2750 50  0001 C CNN
	1    9850 2750
	1    0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 59F1E836
P 5300 2800
F 0 "R23" V 5380 2800 50  0000 C CNN
F 1 "560R" V 5300 2800 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 5230 2800 50  0001 C CNN
F 3 "" H 5300 2800 50  0001 C CNN
	1    5300 2800
	1    0    0    -1  
$EndComp
$Comp
L SP3481CP U3
U 1 1 59F1ED2A
P 5850 3250
F 0 "U3" H 5550 3600 50  0000 L CNN
F 1 "SP3481CP" H 5950 3600 50  0000 L CNN
F 2 "w_pth_circuits:dil_8-300_socket" H 5850 3250 50  0001 C CIN
F 3 "" H 5850 3250 50  0001 C CNN
	1    5850 3250
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 59F1EFE2
P 6150 2650
F 0 "C3" H 6175 2750 50  0000 L CNN
F 1 "100nF" H 6175 2550 50  0000 L CNN
F 2 "w_capacitors:cnp_6mm_disc" H 6188 2500 50  0001 C CNN
F 3 "" H 6150 2650 50  0001 C CNN
	1    6150 2650
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR02
U 1 1 59F1F03E
P 6400 2750
F 0 "#PWR02" H 6400 2500 50  0001 C CNN
F 1 "GND" H 6400 2600 50  0000 C CNN
F 2 "" H 6400 2750 50  0001 C CNN
F 3 "" H 6400 2750 50  0001 C CNN
	1    6400 2750
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 59F1F541
P 5100 2800
F 0 "R21" V 5180 2800 50  0000 C CNN
F 1 "10k" V 5100 2800 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 5030 2800 50  0001 C CNN
F 3 "" H 5100 2800 50  0001 C CNN
	1    5100 2800
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 59F1F9F6
P 4900 2800
F 0 "R19" V 4980 2800 50  0000 C CNN
F 1 "560R" V 4900 2800 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 4830 2800 50  0001 C CNN
F 3 "" H 4900 2800 50  0001 C CNN
	1    4900 2800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 59F1FB71
P 5850 3750
F 0 "#PWR03" H 5850 3500 50  0001 C CNN
F 1 "GND" H 5850 3600 50  0000 C CNN
F 2 "" H 5850 3750 50  0001 C CNN
F 3 "" H 5850 3750 50  0001 C CNN
	1    5850 3750
	1    0    0    -1  
$EndComp
$Comp
L R R28
U 1 1 59F201AD
P 6450 3650
F 0 "R28" V 6530 3650 50  0000 C CNN
F 1 "560R" V 6450 3650 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 6380 3650 50  0001 C CNN
F 3 "" H 6450 3650 50  0001 C CNN
	1    6450 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 59F20200
P 6450 3900
F 0 "#PWR04" H 6450 3650 50  0001 C CNN
F 1 "GND" H 6450 3750 50  0000 C CNN
F 2 "" H 6450 3900 50  0001 C CNN
F 3 "" H 6450 3900 50  0001 C CNN
	1    6450 3900
	1    0    0    -1  
$EndComp
$Comp
L R R27
U 1 1 59F20373
P 6450 3250
F 0 "R27" V 6530 3250 50  0000 C CNN
F 1 "120R" V 6450 3250 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 6380 3250 50  0001 C CNN
F 3 "" H 6450 3250 50  0001 C CNN
	1    6450 3250
	1    0    0    -1  
$EndComp
$Comp
L R R31
U 1 1 59F203B1
P 6700 2850
F 0 "R31" V 6780 2850 50  0000 C CNN
F 1 "560R" V 6700 2850 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 6630 2850 50  0001 C CNN
F 3 "" H 6700 2850 50  0001 C CNN
	1    6700 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 59F215E7
P 9250 4550
F 0 "#PWR05" H 9250 4300 50  0001 C CNN
F 1 "GND" H 9250 4400 50  0000 C CNN
F 2 "" H 9250 4550 50  0001 C CNN
F 3 "" H 9250 4550 50  0001 C CNN
	1    9250 4550
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q3
U 1 1 59F228FE
P 4650 3650
F 0 "Q3" H 4850 3700 50  0000 L CNN
F 1 "Q_NPN_CBE" H 4850 3600 50  0000 L CNN
F 2 "" H 4850 3750 50  0001 C CNN
F 3 "" H 4650 3650 50  0001 C CNN
	1    4650 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 59F22AFE
P 4750 3950
F 0 "#PWR06" H 4750 3700 50  0001 C CNN
F 1 "GND" H 4750 3800 50  0000 C CNN
F 2 "" H 4750 3950 50  0001 C CNN
F 3 "" H 4750 3950 50  0001 C CNN
	1    4750 3950
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 59F22B80
P 4350 3350
F 0 "R17" V 4430 3350 50  0000 C CNN
F 1 "10k" V 4350 3350 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 4280 3350 50  0001 C CNN
F 3 "" H 4350 3350 50  0001 C CNN
	1    4350 3350
	-1   0    0    1   
$EndComp
$Comp
L R R36
U 1 1 59F24845
P 10000 2400
F 0 "R36" V 10080 2400 50  0000 C CNN
F 1 "330R" V 10000 2400 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 9930 2400 50  0001 C CNN
F 3 "" H 10000 2400 50  0001 C CNN
	1    10000 2400
	0    1    1    0   
$EndComp
$Comp
L R R38
U 1 1 59F24A44
P 10400 2300
F 0 "R38" V 10480 2300 50  0000 C CNN
F 1 "330R" V 10400 2300 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 10330 2300 50  0001 C CNN
F 3 "" H 10400 2300 50  0001 C CNN
	1    10400 2300
	0    1    1    0   
$EndComp
$Comp
L R R35
U 1 1 59F25528
P 7350 2350
F 0 "R35" V 7430 2350 50  0000 C CNN
F 1 "330R" V 7350 2350 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 7280 2350 50  0001 C CNN
F 3 "" H 7350 2350 50  0001 C CNN
	1    7350 2350
	-1   0    0    1   
$EndComp
$Comp
L R R34
U 1 1 59F2587C
P 7200 2700
F 0 "R34" V 7280 2700 50  0000 C CNN
F 1 "330R" V 7200 2700 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 7130 2700 50  0001 C CNN
F 3 "" H 7200 2700 50  0001 C CNN
	1    7200 2700
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR07
U 1 1 59F26F62
P 10100 1000
F 0 "#PWR07" H 10100 750 50  0001 C CNN
F 1 "GND" H 10100 850 50  0000 C CNN
F 2 "" H 10100 1000 50  0001 C CNN
F 3 "" H 10100 1000 50  0001 C CNN
	1    10100 1000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 59F27359
P 7650 1700
F 0 "#PWR08" H 7650 1450 50  0001 C CNN
F 1 "GND" H 7650 1550 50  0000 C CNN
F 2 "" H 7650 1700 50  0001 C CNN
F 3 "" H 7650 1700 50  0001 C CNN
	1    7650 1700
	1    0    0    -1  
$EndComp
$Comp
L R R24
U 1 1 59F28074
P 5300 5500
F 0 "R24" V 5380 5500 50  0000 C CNN
F 1 "560R" V 5300 5500 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 5230 5500 50  0001 C CNN
F 3 "" H 5300 5500 50  0001 C CNN
	1    5300 5500
	1    0    0    -1  
$EndComp
$Comp
L SP3481CP U4
U 1 1 59F2807B
P 5850 5950
F 0 "U4" H 5550 6300 50  0000 L CNN
F 1 "SP3481CP" H 5950 6300 50  0000 L CNN
F 2 "w_pth_circuits:dil_8-300_socket" H 5850 5950 50  0001 C CIN
F 3 "" H 5850 5950 50  0001 C CNN
	1    5850 5950
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 59F28082
P 6150 5350
F 0 "C4" H 6175 5450 50  0000 L CNN
F 1 "100nF" H 6175 5250 50  0000 L CNN
F 2 "w_capacitors:cnp_6mm_disc" H 6188 5200 50  0001 C CNN
F 3 "" H 6150 5350 50  0001 C CNN
	1    6150 5350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 59F28089
P 6400 5450
F 0 "#PWR09" H 6400 5200 50  0001 C CNN
F 1 "GND" H 6400 5300 50  0000 C CNN
F 2 "" H 6400 5450 50  0001 C CNN
F 3 "" H 6400 5450 50  0001 C CNN
	1    6400 5450
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 59F28099
P 5100 5500
F 0 "R22" V 5180 5500 50  0000 C CNN
F 1 "10k" V 5100 5500 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 5030 5500 50  0001 C CNN
F 3 "" H 5100 5500 50  0001 C CNN
	1    5100 5500
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 59F280A5
P 4900 5500
F 0 "R20" V 4980 5500 50  0000 C CNN
F 1 "560R" V 4900 5500 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 4830 5500 50  0001 C CNN
F 3 "" H 4900 5500 50  0001 C CNN
	1    4900 5500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 59F280AE
P 5850 6450
F 0 "#PWR010" H 5850 6200 50  0001 C CNN
F 1 "GND" H 5850 6300 50  0000 C CNN
F 2 "" H 5850 6450 50  0001 C CNN
F 3 "" H 5850 6450 50  0001 C CNN
	1    5850 6450
	1    0    0    -1  
$EndComp
$Comp
L R R30
U 1 1 59F280B5
P 6450 6350
F 0 "R30" V 6530 6350 50  0000 C CNN
F 1 "560R" V 6450 6350 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 6380 6350 50  0001 C CNN
F 3 "" H 6450 6350 50  0001 C CNN
	1    6450 6350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 59F280BC
P 6450 6600
F 0 "#PWR011" H 6450 6350 50  0001 C CNN
F 1 "GND" H 6450 6450 50  0000 C CNN
F 2 "" H 6450 6600 50  0001 C CNN
F 3 "" H 6450 6600 50  0001 C CNN
	1    6450 6600
	1    0    0    -1  
$EndComp
$Comp
L R R29
U 1 1 59F280C3
P 6450 5950
F 0 "R29" V 6530 5950 50  0000 C CNN
F 1 "120R" V 6450 5950 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 6380 5950 50  0001 C CNN
F 3 "" H 6450 5950 50  0001 C CNN
	1    6450 5950
	1    0    0    -1  
$EndComp
$Comp
L R R32
U 1 1 59F280CA
P 6700 5550
F 0 "R32" V 6780 5550 50  0000 C CNN
F 1 "560R" V 6700 5550 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 6630 5550 50  0001 C CNN
F 3 "" H 6700 5550 50  0001 C CNN
	1    6700 5550
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q4
U 1 1 59F280E2
P 4650 6350
F 0 "Q4" H 4850 6400 50  0000 L CNN
F 1 "Q_NPN_CBE" H 4850 6300 50  0000 L CNN
F 2 "" H 4850 6450 50  0001 C CNN
F 3 "" H 4650 6350 50  0001 C CNN
	1    4650 6350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 59F280E9
P 4750 6650
F 0 "#PWR012" H 4750 6400 50  0001 C CNN
F 1 "GND" H 4750 6500 50  0000 C CNN
F 2 "" H 4750 6650 50  0001 C CNN
F 3 "" H 4750 6650 50  0001 C CNN
	1    4750 6650
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 59F280F0
P 4350 6050
F 0 "R18" V 4430 6050 50  0000 C CNN
F 1 "10k" V 4350 6050 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 4280 6050 50  0001 C CNN
F 3 "" H 4350 6050 50  0001 C CNN
	1    4350 6050
	-1   0    0    1   
$EndComp
$Comp
L R R25
U 1 1 59F29C49
P 5400 3800
F 0 "R25" V 5480 3800 50  0000 C CNN
F 1 "10k" V 5400 3800 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 5330 3800 50  0001 C CNN
F 3 "" H 5400 3800 50  0001 C CNN
	1    5400 3800
	1    0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 59F2A2A3
P 5400 6450
F 0 "R26" V 5480 6450 50  0000 C CNN
F 1 "10k" V 5400 6450 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 5330 6450 50  0001 C CNN
F 3 "" H 5400 6450 50  0001 C CNN
	1    5400 6450
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 59F2BE5F
P 1750 5700
F 0 "R7" V 1830 5700 50  0000 C CNN
F 1 "560R" V 1750 5700 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1680 5700 50  0001 C CNN
F 3 "" H 1750 5700 50  0001 C CNN
	1    1750 5700
	1    0    0    -1  
$EndComp
$Comp
L SP3481CP U1
U 1 1 59F2BE66
P 2300 6150
F 0 "U1" H 2000 6500 50  0000 L CNN
F 1 "SP3481CP" H 2400 6500 50  0000 L CNN
F 2 "w_pth_circuits:dil_8-300_socket" H 2300 6150 50  0001 C CIN
F 3 "" H 2300 6150 50  0001 C CNN
	1    2300 6150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59F2BE6D
P 2600 5550
F 0 "C1" H 2625 5650 50  0000 L CNN
F 1 "100nF" H 2625 5450 50  0000 L CNN
F 2 "w_capacitors:cnp_6mm_disc" H 2638 5400 50  0001 C CNN
F 3 "" H 2600 5550 50  0001 C CNN
	1    2600 5550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 59F2BE74
P 2850 5650
F 0 "#PWR013" H 2850 5400 50  0001 C CNN
F 1 "GND" H 2850 5500 50  0000 C CNN
F 2 "" H 2850 5650 50  0001 C CNN
F 3 "" H 2850 5650 50  0001 C CNN
	1    2850 5650
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 59F2BE84
P 1550 5700
F 0 "R5" V 1630 5700 50  0000 C CNN
F 1 "10k" V 1550 5700 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1480 5700 50  0001 C CNN
F 3 "" H 1550 5700 50  0001 C CNN
	1    1550 5700
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 59F2BE90
P 1350 5700
F 0 "R3" V 1430 5700 50  0000 C CNN
F 1 "560R" V 1350 5700 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1280 5700 50  0001 C CNN
F 3 "" H 1350 5700 50  0001 C CNN
	1    1350 5700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 59F2BE99
P 2300 6650
F 0 "#PWR014" H 2300 6400 50  0001 C CNN
F 1 "GND" H 2300 6500 50  0000 C CNN
F 2 "" H 2300 6650 50  0001 C CNN
F 3 "" H 2300 6650 50  0001 C CNN
	1    2300 6650
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 59F2BEA0
P 2900 6550
F 0 "R12" V 2980 6550 50  0000 C CNN
F 1 "560R" V 2900 6550 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 2830 6550 50  0001 C CNN
F 3 "" H 2900 6550 50  0001 C CNN
	1    2900 6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 59F2BEA7
P 2900 6800
F 0 "#PWR015" H 2900 6550 50  0001 C CNN
F 1 "GND" H 2900 6650 50  0000 C CNN
F 2 "" H 2900 6800 50  0001 C CNN
F 3 "" H 2900 6800 50  0001 C CNN
	1    2900 6800
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 59F2BEAE
P 2900 6150
F 0 "R11" V 2980 6150 50  0000 C CNN
F 1 "120R" V 2900 6150 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 2830 6150 50  0001 C CNN
F 3 "" H 2900 6150 50  0001 C CNN
	1    2900 6150
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 59F2BEB5
P 3150 5750
F 0 "R15" V 3230 5750 50  0000 C CNN
F 1 "560R" V 3150 5750 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 3080 5750 50  0001 C CNN
F 3 "" H 3150 5750 50  0001 C CNN
	1    3150 5750
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q1
U 1 1 59F2BECC
P 1100 6550
F 0 "Q1" H 1300 6600 50  0000 L CNN
F 1 "Q_NPN_CBE" H 1300 6500 50  0000 L CNN
F 2 "" H 1300 6650 50  0001 C CNN
F 3 "" H 1100 6550 50  0001 C CNN
	1    1100 6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 59F2BED3
P 1200 6850
F 0 "#PWR016" H 1200 6600 50  0001 C CNN
F 1 "GND" H 1200 6700 50  0000 C CNN
F 2 "" H 1200 6850 50  0001 C CNN
F 3 "" H 1200 6850 50  0001 C CNN
	1    1200 6850
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59F2BEDA
P 800 6250
F 0 "R1" V 880 6250 50  0000 C CNN
F 1 "10k" V 800 6250 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 730 6250 50  0001 C CNN
F 3 "" H 800 6250 50  0001 C CNN
	1    800  6250
	-1   0    0    1   
$EndComp
$Comp
L R R9
U 1 1 59F2BEEC
P 1850 6650
F 0 "R9" V 1930 6650 50  0000 C CNN
F 1 "10k" V 1850 6650 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1780 6650 50  0001 C CNN
F 3 "" H 1850 6650 50  0001 C CNN
	1    1850 6650
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 59F2EB9A
P 1850 2450
F 0 "R8" V 1930 2450 50  0000 C CNN
F 1 "560R" V 1850 2450 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1780 2450 50  0001 C CNN
F 3 "" H 1850 2450 50  0001 C CNN
	1    1850 2450
	1    0    0    -1  
$EndComp
$Comp
L SP3481CP U2
U 1 1 59F2EBA1
P 2400 2900
F 0 "U2" H 2100 3250 50  0000 L CNN
F 1 "SP3481CP" H 2500 3250 50  0000 L CNN
F 2 "w_pth_circuits:dil_8-300_socket" H 2400 2900 50  0001 C CIN
F 3 "" H 2400 2900 50  0001 C CNN
	1    2400 2900
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 59F2EBA8
P 2700 2300
F 0 "C2" H 2725 2400 50  0000 L CNN
F 1 "100nF" H 2725 2200 50  0000 L CNN
F 2 "w_capacitors:cnp_6mm_disc" H 2738 2150 50  0001 C CNN
F 3 "" H 2700 2300 50  0001 C CNN
	1    2700 2300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR017
U 1 1 59F2EBAF
P 2950 2400
F 0 "#PWR017" H 2950 2150 50  0001 C CNN
F 1 "GND" H 2950 2250 50  0000 C CNN
F 2 "" H 2950 2400 50  0001 C CNN
F 3 "" H 2950 2400 50  0001 C CNN
	1    2950 2400
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 59F2EBBF
P 1650 2450
F 0 "R6" V 1730 2450 50  0000 C CNN
F 1 "10k" V 1650 2450 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1580 2450 50  0001 C CNN
F 3 "" H 1650 2450 50  0001 C CNN
	1    1650 2450
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 59F2EBCB
P 1450 2450
F 0 "R4" V 1530 2450 50  0000 C CNN
F 1 "560R" V 1450 2450 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1380 2450 50  0001 C CNN
F 3 "" H 1450 2450 50  0001 C CNN
	1    1450 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 59F2EBD4
P 2400 3400
F 0 "#PWR018" H 2400 3150 50  0001 C CNN
F 1 "GND" H 2400 3250 50  0000 C CNN
F 2 "" H 2400 3400 50  0001 C CNN
F 3 "" H 2400 3400 50  0001 C CNN
	1    2400 3400
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 59F2EBDB
P 3000 3300
F 0 "R14" V 3080 3300 50  0000 C CNN
F 1 "560R" V 3000 3300 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 2930 3300 50  0001 C CNN
F 3 "" H 3000 3300 50  0001 C CNN
	1    3000 3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 59F2EBE2
P 3000 3550
F 0 "#PWR019" H 3000 3300 50  0001 C CNN
F 1 "GND" H 3000 3400 50  0000 C CNN
F 2 "" H 3000 3550 50  0001 C CNN
F 3 "" H 3000 3550 50  0001 C CNN
	1    3000 3550
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 59F2EBE9
P 3000 2900
F 0 "R13" V 3080 2900 50  0000 C CNN
F 1 "120R" V 3000 2900 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 2930 2900 50  0001 C CNN
F 3 "" H 3000 2900 50  0001 C CNN
	1    3000 2900
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 59F2EBF0
P 3250 2500
F 0 "R16" V 3330 2500 50  0000 C CNN
F 1 "560R" V 3250 2500 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 3180 2500 50  0001 C CNN
F 3 "" H 3250 2500 50  0001 C CNN
	1    3250 2500
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q2
U 1 1 59F2EC07
P 1200 3300
F 0 "Q2" H 1400 3350 50  0000 L CNN
F 1 "Q_NPN_CBE" H 1400 3250 50  0000 L CNN
F 2 "" H 1400 3400 50  0001 C CNN
F 3 "" H 1200 3300 50  0001 C CNN
	1    1200 3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 59F2EC0E
P 1300 3600
F 0 "#PWR020" H 1300 3350 50  0001 C CNN
F 1 "GND" H 1300 3450 50  0000 C CNN
F 2 "" H 1300 3600 50  0001 C CNN
F 3 "" H 1300 3600 50  0001 C CNN
	1    1300 3600
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 59F2EC15
P 900 3000
F 0 "R2" V 980 3000 50  0000 C CNN
F 1 "10k" V 900 3000 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 830 3000 50  0001 C CNN
F 3 "" H 900 3000 50  0001 C CNN
	1    900  3000
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 59F2EC24
P 1950 3400
F 0 "R10" V 2030 3400 50  0000 C CNN
F 1 "10k" V 1950 3400 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 1880 3400 50  0001 C CNN
F 3 "" H 1950 3400 50  0001 C CNN
	1    1950 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2900 8800 2750
Wire Wire Line
	7550 2750 9350 2750
Wire Wire Line
	7550 550  7550 2750
Wire Wire Line
	5850 1400 7800 1400
Connection ~ 8800 2750
Wire Wire Line
	9850 2750 9650 2750
Wire Wire Line
	8100 4050 7200 4050
Wire Wire Line
	7200 1900 7800 1900
Wire Wire Line
	8100 4150 7350 4150
Wire Wire Line
	7350 2000 7800 2000
Wire Wire Line
	6400 2750 6400 2650
Wire Wire Line
	6400 2650 6300 2650
Wire Wire Line
	5850 2650 6000 2650
Wire Wire Line
	5850 1350 5850 2850
Connection ~ 7550 1400
Connection ~ 5850 2650
Wire Wire Line
	5450 3050 5300 3050
Wire Wire Line
	5300 3050 5300 2950
Wire Wire Line
	5450 3150 5400 3150
Wire Wire Line
	5400 3150 5400 3350
Wire Wire Line
	5400 3350 5450 3350
Wire Wire Line
	5100 2950 5100 3250
Connection ~ 5400 3250
Wire Wire Line
	5100 2650 5100 2350
Wire Wire Line
	5100 2350 6700 2350
Connection ~ 5850 2350
Wire Wire Line
	4900 2950 4900 3450
Wire Wire Line
	4900 3450 5450 3450
Wire Wire Line
	5850 3750 5850 3650
Wire Wire Line
	6450 3900 6450 3800
Wire Wire Line
	6450 3400 6450 3500
Wire Wire Line
	6250 3350 6350 3350
Wire Wire Line
	6350 3350 6350 3450
Wire Wire Line
	6350 3450 6450 3450
Connection ~ 6450 3450
Wire Wire Line
	6250 3150 6350 3150
Wire Wire Line
	6350 3150 6350 3000
Wire Wire Line
	6350 3000 6450 3000
Wire Wire Line
	6450 3000 6450 3100
Wire Wire Line
	6700 3000 6700 3050
Wire Wire Line
	6700 3050 6450 3050
Connection ~ 6450 3050
Wire Wire Line
	6700 2350 6700 2700
Wire Wire Line
	9250 4300 9250 4550
Wire Wire Line
	9250 4300 9500 4300
Wire Wire Line
	9500 4300 9500 4050
Wire Wire Line
	8800 4200 8800 4350
Wire Wire Line
	8800 4350 9250 4350
Connection ~ 9250 4350
Wire Wire Line
	8100 2950 7000 2950
Wire Wire Line
	7000 2950 7000 2150
Wire Wire Line
	7000 2150 4350 2150
Wire Wire Line
	4900 2150 4900 2650
Wire Wire Line
	8100 3350 6900 3350
Wire Wire Line
	6900 3350 6900 2250
Wire Wire Line
	6900 2250 5300 2250
Wire Wire Line
	5300 2250 5300 2650
Wire Wire Line
	4750 3950 4750 3850
Wire Wire Line
	4450 3650 4350 3650
Wire Wire Line
	4350 3650 4350 3500
Wire Wire Line
	4350 2150 4350 3200
Connection ~ 4900 2150
Wire Wire Line
	5100 3250 5400 3250
Wire Wire Line
	4750 3450 4750 3150
Wire Wire Line
	4750 3150 5100 3150
Connection ~ 5100 3150
Wire Wire Line
	9850 2400 9700 2400
Wire Wire Line
	10250 2300 9700 2300
Wire Wire Line
	9500 3350 10300 3350
Wire Wire Line
	10300 3350 10300 2400
Wire Wire Line
	10300 2400 10150 2400
Wire Wire Line
	9500 2950 10600 2950
Wire Wire Line
	10600 2950 10600 2300
Wire Wire Line
	10600 2300 10550 2300
Wire Wire Line
	7350 4150 7350 2500
Wire Wire Line
	7350 2200 7350 2000
Wire Wire Line
	7200 2550 7200 1900
Wire Wire Line
	7200 4050 7200 2850
Wire Wire Line
	10100 1000 10100 900 
Wire Wire Line
	10100 900  9700 900 
Wire Wire Line
	7650 1500 7650 1700
Wire Wire Line
	7650 1500 7800 1500
Wire Wire Line
	7800 1600 7650 1600
Connection ~ 7650 1600
Wire Wire Line
	6400 5450 6400 5350
Wire Wire Line
	6400 5350 6300 5350
Wire Wire Line
	5850 5350 6000 5350
Wire Wire Line
	5850 4400 5850 5550
Connection ~ 5850 5350
Wire Wire Line
	5450 5750 5300 5750
Wire Wire Line
	5300 5750 5300 5650
Wire Wire Line
	5450 5850 5400 5850
Wire Wire Line
	5400 5850 5400 6050
Wire Wire Line
	5400 6050 5450 6050
Wire Wire Line
	5100 5650 5100 5950
Connection ~ 5400 5950
Wire Wire Line
	5100 5350 5100 5050
Wire Wire Line
	5100 5050 6700 5050
Connection ~ 5850 5050
Wire Wire Line
	4900 5650 4900 6150
Wire Wire Line
	4900 6150 5450 6150
Wire Wire Line
	5850 6450 5850 6350
Wire Wire Line
	6450 6600 6450 6500
Wire Wire Line
	6450 6100 6450 6200
Wire Wire Line
	6250 6050 6350 6050
Wire Wire Line
	6350 6050 6350 6150
Wire Wire Line
	6350 6150 6450 6150
Connection ~ 6450 6150
Wire Wire Line
	6250 5850 6350 5850
Wire Wire Line
	6350 5850 6350 5700
Wire Wire Line
	6350 5700 6450 5700
Wire Wire Line
	6450 5700 6450 5800
Wire Wire Line
	6700 5700 6700 5750
Wire Wire Line
	6700 5750 6450 5750
Connection ~ 6450 5750
Wire Wire Line
	6700 5050 6700 5400
Wire Wire Line
	4350 4850 7000 4850
Wire Wire Line
	4900 4850 4900 5350
Wire Wire Line
	5300 4650 5300 5350
Wire Wire Line
	4750 6650 4750 6550
Wire Wire Line
	4450 6350 4350 6350
Wire Wire Line
	4350 6350 4350 6200
Wire Wire Line
	4350 4850 4350 5900
Connection ~ 4900 4850
Wire Wire Line
	5100 5950 5400 5950
Wire Wire Line
	4750 6150 4750 5850
Wire Wire Line
	4750 5850 5100 5850
Connection ~ 5100 5850
Wire Wire Line
	5850 1900 3850 1900
Wire Wire Line
	3850 1900 3850 4400
Wire Wire Line
	3850 4400 5850 4400
Connection ~ 5850 1900
Wire Wire Line
	8100 3050 7000 3050
Wire Wire Line
	7000 3050 7000 4850
Wire Wire Line
	8100 3450 6850 3450
Wire Wire Line
	6850 3450 6850 4650
Wire Wire Line
	6850 4650 5300 4650
Wire Wire Line
	5400 3650 5400 3450
Connection ~ 5400 3450
Wire Wire Line
	5400 3950 5400 4400
Connection ~ 5400 4400
Wire Wire Line
	5400 6300 5400 6150
Connection ~ 5400 6150
Wire Wire Line
	5400 6600 5400 6950
Wire Wire Line
	5400 6950 4050 6950
Wire Wire Line
	4050 6950 4050 4400
Connection ~ 4050 4400
Wire Wire Line
	2850 5650 2850 5550
Wire Wire Line
	2850 5550 2750 5550
Wire Wire Line
	2300 5550 2450 5550
Wire Wire Line
	2300 4600 2300 5750
Connection ~ 2300 5550
Wire Wire Line
	1900 5950 1750 5950
Wire Wire Line
	1750 5950 1750 5850
Wire Wire Line
	1900 6050 1850 6050
Wire Wire Line
	1850 6050 1850 6250
Wire Wire Line
	1850 6250 1900 6250
Wire Wire Line
	1550 5850 1550 6150
Connection ~ 1850 6150
Wire Wire Line
	1550 5550 1550 5250
Wire Wire Line
	1550 5250 3150 5250
Connection ~ 2300 5250
Wire Wire Line
	1350 5850 1350 6350
Wire Wire Line
	1350 6350 1900 6350
Wire Wire Line
	2300 6650 2300 6550
Wire Wire Line
	2900 6800 2900 6700
Wire Wire Line
	2900 6300 2900 6400
Wire Wire Line
	2700 6250 2800 6250
Wire Wire Line
	2800 6250 2800 6350
Wire Wire Line
	2800 6350 2900 6350
Connection ~ 2900 6350
Wire Wire Line
	2700 6050 2800 6050
Wire Wire Line
	2800 6050 2800 5900
Wire Wire Line
	2800 5900 2900 5900
Wire Wire Line
	2900 5900 2900 6000
Wire Wire Line
	3150 5900 3150 5950
Wire Wire Line
	3150 5950 2900 5950
Connection ~ 2900 5950
Wire Wire Line
	3150 5250 3150 5600
Wire Wire Line
	800  5050 1350 5050
Wire Wire Line
	1350 4500 1350 5550
Wire Wire Line
	1750 4350 1750 5550
Wire Wire Line
	1200 6850 1200 6750
Wire Wire Line
	900  6550 800  6550
Wire Wire Line
	800  6550 800  6400
Wire Wire Line
	800  5050 800  6100
Connection ~ 1350 5050
Wire Wire Line
	1550 6150 1850 6150
Wire Wire Line
	1200 6350 1200 6050
Wire Wire Line
	1200 6050 1550 6050
Connection ~ 1550 6050
Wire Wire Line
	1850 6500 1850 6350
Connection ~ 1850 6350
Wire Wire Line
	1850 6800 1850 7150
Wire Wire Line
	1850 7150 3550 7150
Wire Wire Line
	3550 7150 3550 5150
Wire Wire Line
	3550 5150 2300 5150
Connection ~ 2300 5150
Wire Wire Line
	2300 4600 4050 4600
Connection ~ 4050 4600
Wire Wire Line
	1750 4350 7500 4350
Wire Wire Line
	7500 4350 7500 3550
Wire Wire Line
	7500 3550 8100 3550
Wire Wire Line
	8100 3150 7700 3150
Wire Wire Line
	7700 3150 7700 4500
Wire Wire Line
	7700 4500 1350 4500
Wire Wire Line
	2950 2400 2950 2300
Wire Wire Line
	2950 2300 2850 2300
Wire Wire Line
	2400 2300 2550 2300
Wire Wire Line
	2400 1350 2400 2500
Connection ~ 2400 2300
Wire Wire Line
	2000 2700 1850 2700
Wire Wire Line
	1850 2700 1850 2600
Wire Wire Line
	2000 2800 1950 2800
Wire Wire Line
	1950 2800 1950 3000
Wire Wire Line
	1950 3000 2000 3000
Wire Wire Line
	1650 2600 1650 2900
Connection ~ 1950 2900
Wire Wire Line
	1650 2300 1650 2000
Wire Wire Line
	1650 2000 3250 2000
Connection ~ 2400 2000
Wire Wire Line
	1450 2600 1450 3100
Wire Wire Line
	1450 3100 2000 3100
Wire Wire Line
	2400 3400 2400 3300
Wire Wire Line
	3000 3550 3000 3450
Wire Wire Line
	3000 3050 3000 3150
Wire Wire Line
	2800 3000 2900 3000
Wire Wire Line
	2900 3000 2900 3100
Wire Wire Line
	2900 3100 3000 3100
Connection ~ 3000 3100
Wire Wire Line
	2800 2800 2900 2800
Wire Wire Line
	2900 2800 2900 2650
Wire Wire Line
	2900 2650 3000 2650
Wire Wire Line
	3000 2650 3000 2750
Wire Wire Line
	3250 2650 3250 2700
Wire Wire Line
	3250 2700 3000 2700
Connection ~ 3000 2700
Wire Wire Line
	3250 2000 3250 2350
Wire Wire Line
	900  1800 1450 1800
Wire Wire Line
	1450 1500 1450 2300
Wire Wire Line
	1850 1600 1850 2300
Wire Wire Line
	1300 3600 1300 3500
Wire Wire Line
	1000 3300 900  3300
Wire Wire Line
	900  3300 900  3150
Wire Wire Line
	900  1800 900  2850
Connection ~ 1450 1800
Wire Wire Line
	1650 2900 1950 2900
Wire Wire Line
	1300 3100 1300 2800
Wire Wire Line
	1300 2800 1650 2800
Connection ~ 1650 2800
Wire Wire Line
	1950 3250 1950 3100
Connection ~ 1950 3100
Wire Wire Line
	1950 3550 1950 3900
Wire Wire Line
	1950 3900 3650 3900
Wire Wire Line
	3650 3900 3650 1900
Wire Wire Line
	3650 1900 2400 1900
Connection ~ 2400 1900
Wire Wire Line
	2400 1350 5850 1350
Connection ~ 5850 1400
Wire Wire Line
	1850 1600 7450 1600
Wire Wire Line
	7450 1600 7450 3650
Wire Wire Line
	7450 3650 8100 3650
Wire Wire Line
	8100 3250 6850 3250
Wire Wire Line
	6850 3250 6850 1500
Wire Wire Line
	6850 1500 1450 1500
NoConn ~ 7800 1200
NoConn ~ 7800 1300
NoConn ~ 7800 1700
NoConn ~ 7800 2100
NoConn ~ 7800 2200
NoConn ~ 7800 2300
NoConn ~ 7800 2400
NoConn ~ 9700 2200
NoConn ~ 9700 2100
NoConn ~ 9700 2000
NoConn ~ 9700 1900
NoConn ~ 9700 1800
NoConn ~ 9700 1700
NoConn ~ 9700 1500
NoConn ~ 9700 1400
NoConn ~ 9700 1300
NoConn ~ 9700 1200
NoConn ~ 9700 1100
NoConn ~ 9700 1000
NoConn ~ 9700 800 
$Comp
L R R37
U 1 1 59F39129
P 10100 1450
F 0 "R37" V 10180 1450 50  0000 C CNN
F 1 "1k2" V 10100 1450 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 10030 1450 50  0001 C CNN
F 3 "" H 10100 1450 50  0001 C CNN
	1    10100 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 1600 10100 1700
Wire Wire Line
	10100 2000 10100 2150
Wire Wire Line
	10100 2150 9800 2150
Wire Wire Line
	9800 2150 9800 2400
Connection ~ 9800 2400
Wire Wire Line
	10100 1300 10100 1250
Wire Wire Line
	10100 1250 10300 1250
Wire Wire Line
	10300 1250 10300 550 
Wire Wire Line
	10300 550  7550 550 
$Comp
L M_LED D2
U 1 1 59F3F352
P 10100 1850
F 0 "D2" H 10100 1950 50  0000 C CNN
F 1 "TX" H 10100 1750 50  0000 C CNN
F 2 "w_indicators:led_3mm_red" H 10100 1850 50  0001 C CNN
F 3 "" H 10100 1850 50  0001 C CNN
	1    10100 1850
	0    -1   -1   0   
$EndComp
$Comp
L M_LED D3
U 1 1 59F40C56
P 10650 1850
F 0 "D3" H 10650 1950 50  0000 C CNN
F 1 "RX" H 10650 1750 50  0000 C CNN
F 2 "w_indicators:led_3mm_clear" H 10650 1850 50  0001 C CNN
F 3 "" H 10650 1850 50  0001 C CNN
	1    10650 1850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10650 2000 10650 2400
Wire Wire Line
	10650 2400 10600 2400
Connection ~ 10600 2400
$Comp
L R R39
U 1 1 59F4173B
P 10650 1450
F 0 "R39" V 10730 1450 50  0000 C CNN
F 1 "560R" V 10650 1450 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 10580 1450 50  0001 C CNN
F 3 "" H 10650 1450 50  0001 C CNN
	1    10650 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 1700 10650 1600
Wire Wire Line
	10650 1300 10650 1100
Wire Wire Line
	10650 1100 10300 1100
Connection ~ 10300 1100
$Comp
L M_LED D1
U 1 1 59F442D0
P 7050 1150
F 0 "D1" H 7050 1250 50  0000 C CNN
F 1 "PWR" H 7050 1050 50  0000 C CNN
F 2 "w_indicators:led_3mm_red" H 7050 1150 50  0001 C CNN
F 3 "" H 7050 1150 50  0001 C CNN
	1    7050 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 1400 7050 1300
Connection ~ 7050 1400
$Comp
L R R33
U 1 1 59F44F07
P 6750 900
F 0 "R33" V 6830 900 50  0000 C CNN
F 1 "1k2" V 6750 900 50  0000 C CNN
F 2 "w_pth_resistors:rc05_vert" V 6680 900 50  0001 C CNN
F 3 "" H 6750 900 50  0001 C CNN
	1    6750 900 
	0    1    1    0   
$EndComp
$Comp
L GND #PWR021
U 1 1 59F4549D
P 6550 1050
F 0 "#PWR021" H 6550 800 50  0001 C CNN
F 1 "GND" H 6550 900 50  0000 C CNN
F 2 "" H 6550 1050 50  0001 C CNN
F 3 "" H 6550 1050 50  0001 C CNN
	1    6550 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 1000 7050 900 
Wire Wire Line
	7050 900  6900 900 
Wire Wire Line
	6550 1050 6550 900 
Wire Wire Line
	6550 900  6600 900 
$Comp
L GND #PWR022
U 1 1 59F4914C
P 7950 4250
F 0 "#PWR022" H 7950 4000 50  0001 C CNN
F 1 "GND" H 7950 4100 50  0000 C CNN
F 2 "" H 7950 4250 50  0001 C CNN
F 3 "" H 7950 4250 50  0001 C CNN
	1    7950 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4250 7950 3850
Wire Wire Line
	7950 3850 8100 3850
$EndSCHEMATC
