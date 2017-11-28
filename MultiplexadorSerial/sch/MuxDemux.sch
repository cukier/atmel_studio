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
Sheet 3 3
Title "Multiplexador serial rs485"
Date "2017-11-28"
Rev "0"
Comp "Krebsfer Industrial LTDA."
Comment1 ""
Comment2 "mauricio@krebs.com.br"
Comment3 "Engenheiro Eletrico"
Comment4 "Mauricio Cukier"
$EndDescr
$Comp
L 4052 U1
U 1 1 5A1FBFC5
P 5950 3850
F 0 "U1" H 6050 3850 50  0000 C CNN
F 1 "4052" H 6050 3650 50  0000 C CNN
F 2 "w_smd_dil:so-16" H 5950 3850 60  0001 C CNN
F 3 "" H 5950 3850 60  0001 C CNN
	1    5950 3850
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5A1FBFCC
P 4500 3600
F 0 "C1" H 4525 3700 50  0000 L CNN
F 1 "100nF" H 4525 3500 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 4538 3450 50  0001 C CNN
F 3 "" H 4500 3600 50  0001 C CNN
	1    4500 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5A1FBFD3
P 4500 3850
F 0 "#PWR08" H 4500 3600 50  0001 C CNN
F 1 "GND" H 4500 3700 50  0000 C CNN
F 2 "" H 4500 3850 50  0001 C CNN
F 3 "" H 4500 3850 50  0001 C CNN
	1    4500 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5A1FBFD9
P 5950 4600
F 0 "#PWR09" H 5950 4350 50  0001 C CNN
F 1 "GND" H 5950 4450 50  0000 C CNN
F 2 "" H 5950 4600 50  0001 C CNN
F 3 "" H 5950 4600 50  0001 C CNN
	1    5950 4600
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5A1FBFDF
P 6850 3250
F 0 "R7" V 6930 3250 50  0000 C CNN
F 1 "330R" V 6850 3250 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 6780 3250 50  0001 C CNN
F 3 "" H 6850 3250 50  0001 C CNN
	1    6850 3250
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5A1FBFE6
P 7000 3650
F 0 "R8" V 7080 3650 50  0000 C CNN
F 1 "330R" V 7000 3650 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 6930 3650 50  0001 C CNN
F 3 "" H 7000 3650 50  0001 C CNN
	1    7000 3650
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5A1FBFED
P 4800 4550
F 0 "R4" V 4880 4550 50  0000 C CNN
F 1 "330R" V 4800 4550 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 4730 4550 50  0001 C CNN
F 3 "" H 4800 4550 50  0001 C CNN
	1    4800 4550
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 5A1FBFF4
P 4800 4350
F 0 "R3" V 4880 4350 50  0000 C CNN
F 1 "330R" V 4800 4350 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 4730 4350 50  0001 C CNN
F 3 "" H 4800 4350 50  0001 C CNN
	1    4800 4350
	0    -1   -1   0   
$EndComp
$Comp
L M_LED D3
U 1 1 5A1FBFFB
P 7000 3900
F 0 "D3" H 7000 4000 50  0000 C CNN
F 1 "RX" H 7000 3800 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 7000 3900 50  0001 C CNN
F 3 "" H 7000 3900 50  0001 C CNN
	1    7000 3900
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5A1FC002
P 7400 3900
F 0 "R9" V 7480 3900 50  0000 C CNN
F 1 "560R" V 7400 3900 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 7330 3900 50  0001 C CNN
F 3 "" H 7400 3900 50  0001 C CNN
	1    7400 3900
	0    1    1    0   
$EndComp
$Comp
L GND #PWR010
U 1 1 5A1FC009
P 5050 4100
F 0 "#PWR010" H 5050 3850 50  0001 C CNN
F 1 "GND" H 5050 3950 50  0000 C CNN
F 2 "" H 5050 4100 50  0001 C CNN
F 3 "" H 5050 4100 50  0001 C CNN
	1    5050 4100
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5A1FC00F
P 5300 4850
F 0 "R6" V 5380 4850 50  0000 C CNN
F 1 "10k" V 5300 4850 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 5230 4850 50  0001 C CNN
F 3 "" H 5300 4850 50  0001 C CNN
	1    5300 4850
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR011
U 1 1 5A1FC016
P 5950 3050
F 0 "#PWR011" H 5950 2900 50  0001 C CNN
F 1 "+5V" H 5950 3190 50  0000 C CNN
F 2 "" H 5950 3050 50  0001 C CNN
F 3 "" H 5950 3050 50  0001 C CNN
	1    5950 3050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 5A1FC01C
P 4500 3400
F 0 "#PWR012" H 4500 3250 50  0001 C CNN
F 1 "+5V" H 4500 3540 50  0000 C CNN
F 2 "" H 4500 3400 50  0001 C CNN
F 3 "" H 4500 3400 50  0001 C CNN
	1    4500 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5A1FC022
P 6750 4400
F 0 "#PWR013" H 6750 4150 50  0001 C CNN
F 1 "GND" H 6750 4250 50  0000 C CNN
F 2 "" H 6750 4400 50  0001 C CNN
F 3 "" H 6750 4400 50  0001 C CNN
	1    6750 4400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 5A1FC02A
P 7650 3850
F 0 "#PWR014" H 7650 3700 50  0001 C CNN
F 1 "+5V" H 7650 3990 50  0000 C CNN
F 2 "" H 7650 3850 50  0001 C CNN
F 3 "" H 7650 3850 50  0001 C CNN
	1    7650 3850
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5A1FC044
P 5050 4850
F 0 "R5" V 5130 4850 50  0000 C CNN
F 1 "10k" V 5050 4850 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 4980 4850 50  0001 C CNN
F 3 "" H 5050 4850 50  0001 C CNN
	1    5050 4850
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR015
U 1 1 5A1FC04B
P 5300 5050
F 0 "#PWR015" H 5300 4800 50  0001 C CNN
F 1 "GND" H 5300 4900 50  0000 C CNN
F 2 "" H 5300 5050 50  0001 C CNN
F 3 "" H 5300 5050 50  0001 C CNN
	1    5300 5050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5A1FC051
P 5050 5050
F 0 "#PWR016" H 5050 4800 50  0001 C CNN
F 1 "GND" H 5050 4900 50  0000 C CNN
F 2 "" H 5050 5050 50  0001 C CNN
F 3 "" H 5050 5050 50  0001 C CNN
	1    5050 5050
	1    0    0    -1  
$EndComp
Text HLabel 5150 3250 0    60   Output ~ 0
TX1
Text HLabel 5150 3350 0    60   Output ~ 0
TX2
Text HLabel 5150 3450 0    60   Output ~ 0
TX3
Text HLabel 5150 3550 0    60   Output ~ 0
TX4
Text HLabel 5150 3650 0    60   Input ~ 0
RX1
Text HLabel 5150 3750 0    60   Input ~ 0
RX2
Text HLabel 5150 3850 0    60   Input ~ 0
RX3
Text HLabel 5150 3950 0    60   Input ~ 0
RX4
Text HLabel 7250 3650 2    60   Output ~ 0
RX
Text HLabel 7100 3250 2    60   Input ~ 0
TX
Text HLabel 4550 4350 0    60   Input ~ 0
ADR0
Text HLabel 4550 4550 0    60   Input ~ 0
ADR1
Wire Wire Line
	5950 4500 5950 4600
Wire Wire Line
	7150 3900 7250 3900
Wire Wire Line
	6700 3250 6650 3250
Wire Wire Line
	4500 3850 4500 3750
Wire Wire Line
	4500 3400 4500 3450
Wire Wire Line
	5950 3050 5950 3200
Wire Wire Line
	6750 4400 6700 4350
Wire Wire Line
	6700 4350 6650 4350
Wire Wire Line
	6650 3650 6850 3650
Wire Wire Line
	7100 3250 7000 3250
Wire Wire Line
	7250 3650 7150 3650
Connection ~ 6750 3650
Wire Wire Line
	7650 3850 7600 3900
Wire Wire Line
	7600 3900 7550 3900
Wire Wire Line
	4950 4350 5250 4350
Wire Wire Line
	4950 4550 5150 4550
Wire Wire Line
	5150 4450 5150 4600
Wire Wire Line
	5150 4450 5250 4450
Wire Wire Line
	5050 5050 5050 5000
Wire Wire Line
	5300 5050 5300 5000
Wire Wire Line
	5300 4700 5300 4600
Wire Wire Line
	5300 4600 5150 4600
Connection ~ 5150 4550
Wire Wire Line
	4650 4350 4550 4350
Wire Wire Line
	4650 4550 4550 4550
Wire Wire Line
	5250 4150 5200 4150
Wire Wire Line
	5200 4150 5150 4050
Wire Wire Line
	5150 4050 5100 4050
Wire Wire Line
	5100 4050 5050 4100
Wire Wire Line
	5150 3250 5250 3250
Wire Wire Line
	5150 3350 5250 3350
Wire Wire Line
	5150 3450 5250 3450
Wire Wire Line
	5150 3550 5250 3550
Wire Wire Line
	5150 3650 5250 3650
Wire Wire Line
	5150 3750 5250 3750
Wire Wire Line
	5150 3850 5250 3850
Wire Wire Line
	5150 3950 5250 3950
Wire Wire Line
	6750 3650 6750 3850
Wire Wire Line
	6750 3850 6800 3900
Wire Wire Line
	6800 3900 6850 3900
Wire Wire Line
	5050 4700 5050 4350
Connection ~ 5050 4350
$EndSCHEMATC
