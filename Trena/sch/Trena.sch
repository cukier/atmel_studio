EESchema Schematic File Version 2
LIBS:Trena-rescue
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
LIBS:Trena-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Trena Serial"
Date "2018-02-09"
Rev "3"
Comp ""
Comment1 "Mauricio Cukier"
Comment2 "mauricio@gmail.com"
Comment3 "Daniel Losada"
Comment4 "dainel.losada@gmail.com"
$EndDescr
$Comp
L ATMEGA328P-AU U1
U 1 1 5A39475F
P 4950 3700
F 0 "U1" H 4200 4950 50  0000 L BNN
F 1 "ATMEGA328P-AU" H 5350 2300 50  0000 L BNN
F 2 "w_smd_lqfp:lqfp32" H 4950 3700 50  0001 C CIN
F 3 "" H 4950 3700 50  0001 C CNN
F 4 "microcontrolador atmega328p smd qfp32" H 4950 3700 60  0001 C CNN "Desc"
	1    4950 3700
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F1
U 1 1 5A3948FA
P 1550 1250
F 0 "F1" V 1450 1250 50  0000 C CNN
F 1 "500ma" V 1650 1250 50  0000 C CNN
F 2 "w_smd_resistors:r_1210" H 1600 1050 50  0001 L CNN
F 3 "" H 1550 1250 50  0001 C CNN
F 4 "fusivel rapido 500ma 63v smd 1206" V 1550 1250 60  0001 C CNN "Desc"
	1    1550 1250
	0    1    1    0   
$EndComp
$Comp
L D_ALT D1
U 1 1 5A394AC3
P 1950 1250
F 0 "D1" H 1950 1350 50  0000 C CNN
F 1 "D_ALT" H 1950 1150 50  0000 C CNN
F 2 "w_smd_diode:do219ab" H 1950 1250 50  0001 C CNN
F 3 "" H 1950 1250 50  0001 C CNN
F 4 "diodo 1n4007 smd do-214aac (smb)" H 1950 1250 60  0001 C CNN "Desc"
	1    1950 1250
	-1   0    0    1   
$EndComp
$Comp
L CP C6
U 1 1 5A394C68
P 2300 1550
F 0 "C6" H 2325 1650 50  0000 L CNN
F 1 "470uF" H 2325 1450 50  0000 L CNN
F 2 "w_capacitors:CP_8x11.5mm" H 2338 1400 50  0001 C CNN
F 3 "" H 2300 1550 50  0001 C CNN
F 4 "capacitor eletrolitico 470uF 25V" H 2300 1550 60  0001 C CNN "Desc"
	1    2300 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5A394CAD
P 2300 1800
F 0 "#PWR01" H 2300 1550 50  0001 C CNN
F 1 "GND" H 2300 1650 50  0000 C CNN
F 2 "" H 2300 1800 50  0001 C CNN
F 3 "" H 2300 1800 50  0001 C CNN
	1    2300 1800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5A394EB5
P 2750 1800
F 0 "#PWR02" H 2750 1550 50  0001 C CNN
F 1 "GND" H 2750 1650 50  0000 C CNN
F 2 "" H 2750 1800 50  0001 C CNN
F 3 "" H 2750 1800 50  0001 C CNN
	1    2750 1800
	1    0    0    -1  
$EndComp
$Comp
L LM1117-5.0-RESCUE-Trena U2
U 1 1 5A3950E9
P 3200 1250
F 0 "U2" H 3300 1000 50  0000 C CNN
F 1 "LM1117-5.0" H 3200 1500 50  0000 C CNN
F 2 "w_smd_trans:sot223" H 3200 1250 50  0001 C CNN
F 3 "" H 3200 1250 50  0001 C CNN
F 4 "regulador de tensao lm1117-5.0 smd sot223" H 3200 1250 60  0001 C CNN "Desc"
	1    3200 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5A3951A7
P 3200 1650
F 0 "#PWR03" H 3200 1400 50  0001 C CNN
F 1 "GND" H 3200 1500 50  0000 C CNN
F 2 "" H 3200 1650 50  0001 C CNN
F 3 "" H 3200 1650 50  0001 C CNN
	1    3200 1650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5A395465
P 3650 1750
F 0 "#PWR04" H 3650 1500 50  0001 C CNN
F 1 "GND" H 3650 1600 50  0000 C CNN
F 2 "" H 3650 1750 50  0001 C CNN
F 3 "" H 3650 1750 50  0001 C CNN
	1    3650 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5A395651
P 4000 1750
F 0 "#PWR05" H 4000 1500 50  0001 C CNN
F 1 "GND" H 4000 1600 50  0000 C CNN
F 2 "" H 4000 1750 50  0001 C CNN
F 3 "" H 4000 1750 50  0001 C CNN
	1    4000 1750
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 5A39588B
P 4000 1200
F 0 "#PWR06" H 4000 1050 50  0001 C CNN
F 1 "+5V" H 4000 1340 50  0000 C CNN
F 2 "" H 4000 1200 50  0001 C CNN
F 3 "" H 4000 1200 50  0001 C CNN
	1    4000 1200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 5A395B85
P 3950 2550
F 0 "#PWR07" H 3950 2400 50  0001 C CNN
F 1 "+5V" H 3950 2690 50  0000 C CNN
F 2 "" H 3950 2550 50  0001 C CNN
F 3 "" H 3950 2550 50  0001 C CNN
	1    3950 2550
	1    0    0    -1  
$EndComp
NoConn ~ 4050 3200
NoConn ~ 4050 3950
NoConn ~ 4050 4050
$Comp
L GND #PWR08
U 1 1 5A39605C
P 3950 5000
F 0 "#PWR08" H 3950 4750 50  0001 C CNN
F 1 "GND" H 3950 4850 50  0000 C CNN
F 2 "" H 3950 5000 50  0001 C CNN
F 3 "" H 3950 5000 50  0001 C CNN
	1    3950 5000
	1    0    0    -1  
$EndComp
NoConn ~ 5950 2800
Text Label 6250 2900 2    60   ~ 0
MOSI
Text Label 6250 3000 2    60   ~ 0
MISO
Text Label 6250 3100 2    60   ~ 0
SCK
Text Label 6250 4050 2    60   ~ 0
RESET
Text Label 6250 4200 2    60   ~ 0
RX
Text Label 6250 4300 2    60   ~ 0
TX
Text Label 6250 2700 2    60   ~ 0
INT2
NoConn ~ 5950 4700
NoConn ~ 5950 4600
NoConn ~ 5950 4500
NoConn ~ 5950 4400
$Comp
L GND #PWR09
U 1 1 5A398EAA
P 1900 3050
F 0 "#PWR09" H 1900 2800 50  0001 C CNN
F 1 "GND" H 1900 2900 50  0000 C CNN
F 2 "" H 1900 3050 50  0001 C CNN
F 3 "" H 1900 3050 50  0001 C CNN
	1    1900 3050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 5A39910C
P 1900 2650
F 0 "#PWR010" H 1900 2500 50  0001 C CNN
F 1 "+5V" H 1900 2790 50  0000 C CNN
F 2 "" H 1900 2650 50  0001 C CNN
F 3 "" H 1900 2650 50  0001 C CNN
	1    1900 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5A399329
P 1600 3050
F 0 "#PWR011" H 1600 2800 50  0001 C CNN
F 1 "GND" H 1600 2900 50  0000 C CNN
F 2 "" H 1600 3050 50  0001 C CNN
F 3 "" H 1600 3050 50  0001 C CNN
	1    1600 3050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 5A399330
P 1600 2650
F 0 "#PWR012" H 1600 2500 50  0001 C CNN
F 1 "+5V" H 1600 2790 50  0000 C CNN
F 2 "" H 1600 2650 50  0001 C CNN
F 3 "" H 1600 2650 50  0001 C CNN
	1    1600 2650
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5A399362
P 1300 2850
F 0 "C1" H 1325 2950 50  0000 L CNN
F 1 "100n" H 1325 2750 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 1338 2700 50  0001 C CNN
F 3 "" H 1300 2850 50  0001 C CNN
F 4 "capacitor ceramico smd 0805" H 1300 2850 60  0001 C CNN "Desc"
	1    1300 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5A399368
P 1300 3050
F 0 "#PWR013" H 1300 2800 50  0001 C CNN
F 1 "GND" H 1300 2900 50  0000 C CNN
F 2 "" H 1300 3050 50  0001 C CNN
F 3 "" H 1300 3050 50  0001 C CNN
	1    1300 3050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 5A39936F
P 1300 2650
F 0 "#PWR014" H 1300 2500 50  0001 C CNN
F 1 "+5V" H 1300 2790 50  0000 C CNN
F 2 "" H 1300 2650 50  0001 C CNN
F 3 "" H 1300 2650 50  0001 C CNN
	1    1300 2650
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5A399711
P 1650 4150
F 0 "Y1" H 1650 4300 50  0000 C CNN
F 1 "Crystal" H 1650 4000 50  0000 C CNN
F 2 "w_crystal:crystal_hc-49%2fsmd" H 1650 4150 50  0001 C CNN
F 3 "" H 1650 4150 50  0001 C CNN
F 4 "cristal 16MHz smd hc-49sm" H 1650 4150 60  0001 C CNN "Desc"
	1    1650 4150
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5A399865
P 1350 4400
F 0 "C2" H 1375 4500 50  0000 L CNN
F 1 "22p" H 1375 4300 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 1388 4250 50  0001 C CNN
F 3 "" H 1350 4400 50  0001 C CNN
F 4 "capacitor ceramico 22pF smd 0805" H 1350 4400 60  0001 C CNN "Desc"
	1    1350 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5A399921
P 1350 4650
F 0 "#PWR015" H 1350 4400 50  0001 C CNN
F 1 "GND" H 1350 4500 50  0000 C CNN
F 2 "" H 1350 4650 50  0001 C CNN
F 3 "" H 1350 4650 50  0001 C CNN
	1    1350 4650
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 5A3999BA
P 2000 4400
F 0 "C5" H 2025 4500 50  0000 L CNN
F 1 "22p" H 2025 4300 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 2038 4250 50  0001 C CNN
F 3 "" H 2000 4400 50  0001 C CNN
F 4 "capacitor ceramico 22pF smd 0805" H 2000 4400 60  0001 C CNN "Desc"
	1    2000 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5A3999C1
P 2000 4650
F 0 "#PWR016" H 2000 4400 50  0001 C CNN
F 1 "GND" H 2000 4500 50  0000 C CNN
F 2 "" H 2000 4650 50  0001 C CNN
F 3 "" H 2000 4650 50  0001 C CNN
	1    2000 4650
	1    0    0    -1  
$EndComp
Text Label 1850 4150 0    60   ~ 0
XTAL2
Text Label 1450 4150 2    60   ~ 0
XTAL1
Text Label 6250 3200 2    60   ~ 0
XTAL1
Text Label 6250 3300 2    60   ~ 0
XTAL2
$Comp
L CONN_02X03 J1
U 1 1 5A39C28D
P 1850 5850
F 0 "J1" H 1850 6050 50  0000 C CNN
F 1 "ICSP" H 1850 5650 50  0000 C CNN
F 2 "w_pin_strip:pin_strip_3x2" H 1850 4650 50  0001 C CNN
F 3 "" H 1850 4650 50  0001 C CNN
F 4 "barra de pinos 2x3 vias" H 1850 5850 60  0001 C CNN "Desc"
	1    1850 5850
	1    0    0    -1  
$EndComp
Text Label 1350 5750 0    60   ~ 0
MISO
Text Label 2400 5850 2    60   ~ 0
MOSI
$Comp
L GND #PWR017
U 1 1 5A39DA27
P 2200 6000
F 0 "#PWR017" H 2200 5750 50  0001 C CNN
F 1 "GND" H 2200 5850 50  0000 C CNN
F 2 "" H 2200 6000 50  0001 C CNN
F 3 "" H 2200 6000 50  0001 C CNN
	1    2200 6000
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR018
U 1 1 5A39DD0E
P 2150 5700
F 0 "#PWR018" H 2150 5550 50  0001 C CNN
F 1 "+5V" H 2150 5840 50  0000 C CNN
F 2 "" H 2150 5700 50  0001 C CNN
F 3 "" H 2150 5700 50  0001 C CNN
	1    2150 5700
	1    0    0    -1  
$EndComp
Text Label 1350 5850 0    60   ~ 0
SCK
Text Label 1350 5950 0    60   ~ 0
RESET
$Comp
L +5V #PWR019
U 1 1 5A39FCEA
P 2300 2650
F 0 "#PWR019" H 2300 2500 50  0001 C CNN
F 1 "+5V" H 2300 2790 50  0000 C CNN
F 2 "" H 2300 2650 50  0001 C CNN
F 3 "" H 2300 2650 50  0001 C CNN
	1    2300 2650
	1    0    0    -1  
$EndComp
Text Label 2650 3150 2    60   ~ 0
RESET
$Comp
L Q_NPN_BCE Q2
U 1 1 5A3A0F37
P 7950 1700
F 0 "Q2" H 8150 1775 50  0000 L CNN
F 1 "BC817-40" H 8150 1700 50  0000 L CNN
F 2 "w_smd_trans:sot23" H 8150 1625 50  0001 L CIN
F 3 "" H 7950 1700 50  0001 L CNN
F 4 "transistor npn bc817-25 smd sot23" H 7950 1700 60  0001 C CNN "Desc"
	1    7950 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 5A3A1670
P 8050 2000
F 0 "#PWR020" H 8050 1750 50  0001 C CNN
F 1 "GND" H 8050 1850 50  0000 C CNN
F 2 "" H 8050 2000 50  0001 C CNN
F 3 "" H 8050 2000 50  0001 C CNN
	1    8050 2000
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR021
U 1 1 5A3A1FF2
P 8050 1000
F 0 "#PWR021" H 8050 850 50  0001 C CNN
F 1 "+5V" H 8050 1140 50  0000 C CNN
F 2 "" H 8050 1000 50  0001 C CNN
F 3 "" H 8050 1000 50  0001 C CNN
	1    8050 1000
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q1
U 1 1 5A3A36F7
P 7800 5250
F 0 "Q1" H 8000 5325 50  0000 L CNN
F 1 "PN2222A" H 8000 5250 50  0000 L CNN
F 2 "w_smd_trans:sot23" H 8000 5175 50  0001 L CIN
F 3 "" H 7800 5250 50  0001 L CNN
F 4 "transistor npn 2n2222 smd sot23" H 7800 5250 60  0001 C CNN "Desc"
	1    7800 5250
	1    0    0    -1  
$EndComp
Text Label 6250 2600 2    60   ~ 0
INT1
NoConn ~ 5950 4800
NoConn ~ 5950 4900
Text Label 7100 1700 0    60   ~ 0
INT1
$Comp
L GND #PWR022
U 1 1 5A3A5480
P 8050 2900
F 0 "#PWR022" H 8050 2650 50  0001 C CNN
F 1 "GND" H 8050 2750 50  0000 C CNN
F 2 "" H 8050 2900 50  0001 C CNN
F 3 "" H 8050 2900 50  0001 C CNN
	1    8050 2900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR023
U 1 1 5A3A581B
P 8300 1950
F 0 "#PWR023" H 8300 1800 50  0001 C CNN
F 1 "+5V" H 8300 2090 50  0000 C CNN
F 2 "" H 8300 1950 50  0001 C CNN
F 3 "" H 8300 1950 50  0001 C CNN
	1    8300 1950
	1    0    0    -1  
$EndComp
Text Label 7800 2350 0    60   ~ 0
INT2
Text Label 6850 5250 0    60   ~ 0
TX
$Comp
L GND #PWR024
U 1 1 5A3A7C65
P 7900 5500
F 0 "#PWR024" H 7900 5250 50  0001 C CNN
F 1 "GND" H 7900 5350 50  0000 C CNN
F 2 "" H 7900 5500 50  0001 C CNN
F 3 "" H 7900 5500 50  0001 C CNN
	1    7900 5500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR025
U 1 1 5A3A84E5
P 7900 4600
F 0 "#PWR025" H 7900 4450 50  0001 C CNN
F 1 "+5V" H 7900 4740 50  0000 C CNN
F 2 "" H 7900 4600 50  0001 C CNN
F 3 "" H 7900 4600 50  0001 C CNN
	1    7900 4600
	1    0    0    -1  
$EndComp
$Comp
L SP3485CN U3
U 1 1 5A3A8A65
P 9300 4900
F 0 "U3" H 9000 5250 50  0000 L CNN
F 1 "SP3485CN" H 9400 5250 50  0000 L CNN
F 2 "w_smd_dil:so-8" H 10350 4550 50  0001 C CIN
F 3 "" H 9300 4900 50  0001 C CNN
F 4 "circuito integrado max485 smd so-8" H 9300 4900 60  0001 C CNN "Desc"
	1    9300 4900
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5A3A93CB
P 8650 4700
F 0 "R13" V 8730 4700 50  0000 C CNN
F 1 "360R" V 8650 4700 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 8580 4700 50  0001 C CNN
F 3 "" H 8650 4700 50  0001 C CNN
F 4 "resisotor 360R smd 0805" V 8650 4700 60  0001 C CNN "Desc"
	1    8650 4700
	0    1    1    0   
$EndComp
Text Label 8350 5100 0    60   ~ 0
TX
Text Label 8300 4700 0    60   ~ 0
RX
$Comp
L GND #PWR026
U 1 1 5A3AA9BE
P 9300 5400
F 0 "#PWR026" H 9300 5150 50  0001 C CNN
F 1 "GND" H 9300 5250 50  0000 C CNN
F 2 "" H 9300 5400 50  0001 C CNN
F 3 "" H 9300 5400 50  0001 C CNN
	1    9300 5400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR027
U 1 1 5A3AAF3F
P 9300 4400
F 0 "#PWR027" H 9300 4250 50  0001 C CNN
F 1 "+5V" H 9300 4540 50  0000 C CNN
F 2 "" H 9300 4400 50  0001 C CNN
F 3 "" H 9300 4400 50  0001 C CNN
	1    9300 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 5A3AC0C0
P 9700 3950
F 0 "#PWR028" H 9700 3700 50  0001 C CNN
F 1 "GND" H 9700 3800 50  0000 C CNN
F 2 "" H 9700 3950 50  0001 C CNN
F 3 "" H 9700 3950 50  0001 C CNN
	1    9700 3950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR029
U 1 1 5A3AC0C7
P 9700 3550
F 0 "#PWR029" H 9700 3400 50  0001 C CNN
F 1 "+5V" H 9700 3690 50  0000 C CNN
F 2 "" H 9700 3550 50  0001 C CNN
F 3 "" H 9700 3550 50  0001 C CNN
	1    9700 3550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR030
U 1 1 5A3B043A
P 10050 4250
F 0 "#PWR030" H 10050 4100 50  0001 C CNN
F 1 "+5V" H 10050 4390 50  0000 C CNN
F 2 "" H 10050 4250 50  0001 C CNN
F 3 "" H 10050 4250 50  0001 C CNN
	1    10050 4250
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 5A3B096E
P 10350 4900
F 0 "R20" V 10430 4900 50  0000 C CNN
F 1 "120R" V 10350 4900 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 10280 4900 50  0001 C CNN
F 3 "" H 10350 4900 50  0001 C CNN
F 4 "resisotor 120R smd 0805" V 10350 4900 60  0001 C CNN "Desc"
	1    10350 4900
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR031
U 1 1 5A3B0D0D
P 10050 5500
F 0 "#PWR031" H 10050 5250 50  0001 C CNN
F 1 "GND" H 10050 5350 50  0000 C CNN
F 2 "" H 10050 5500 50  0001 C CNN
F 3 "" H 10050 5500 50  0001 C CNN
	1    10050 5500
	1    0    0    -1  
$EndComp
Text Label 9850 4800 0    60   ~ 0
A
Text Label 9850 5000 0    60   ~ 0
B
Text Label 6250 3450 2    60   ~ 0
LED1
Text Label 6250 3550 2    60   ~ 0
LED2
Text Label 5050 7100 0    60   ~ 0
LED1
$Comp
L LED_ALT D7
U 1 1 5A3C2E43
P 8850 5550
F 0 "D7" H 8850 5650 50  0000 C CNN
F 1 "TX" H 8850 5450 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 8850 5550 50  0001 C CNN
F 3 "" H 8850 5550 50  0001 C CNN
F 4 "led azul smd 0805" H 8850 5550 60  0001 C CNN "Desc"
	1    8850 5550
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR032
U 1 1 5A3C40EC
P 8250 3550
F 0 "#PWR032" H 8250 3400 50  0001 C CNN
F 1 "+5V" H 8250 3690 50  0000 C CNN
F 2 "" H 8250 3550 50  0001 C CNN
F 3 "" H 8250 3550 50  0001 C CNN
	1    8250 3550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR033
U 1 1 5A3C4C10
P 9100 3800
F 0 "#PWR033" H 9100 3650 50  0001 C CNN
F 1 "+5V" H 9100 3940 50  0000 C CNN
F 2 "" H 9100 3800 50  0001 C CNN
F 3 "" H 9100 3800 50  0001 C CNN
	1    9100 3800
	1    0    0    -1  
$EndComp
$Comp
L LED_ALT D6
U 1 1 5A3C639E
P 8250 4200
F 0 "D6" H 8250 4300 50  0000 C CNN
F 1 "RX" H 8250 4100 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 8250 4200 50  0001 C CNN
F 3 "" H 8250 4200 50  0001 C CNN
F 4 "led vermelho smd 0805" H 8250 4200 60  0001 C CNN "Desc"
	1    8250 4200
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR034
U 1 1 5A3DFC4C
P 8300 5650
F 0 "#PWR034" H 8300 5500 50  0001 C CNN
F 1 "+5V" H 8300 5790 50  0000 C CNN
F 2 "" H 8300 5650 50  0001 C CNN
F 3 "" H 8300 5650 50  0001 C CNN
	1    8300 5650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR035
U 1 1 5A3E46B8
P 7100 4750
F 0 "#PWR035" H 7100 4600 50  0001 C CNN
F 1 "+5V" H 7100 4890 50  0000 C CNN
F 2 "" H 7100 4750 50  0001 C CNN
F 3 "" H 7100 4750 50  0001 C CNN
	1    7100 4750
	1    0    0    -1  
$EndComp
$Comp
L RJ45 J6
U 1 1 5A3E658B
P 10400 1150
F 0 "J6" H 10600 1650 50  0000 C CNN
F 1 "RJ45" H 10250 1650 50  0000 C CNN
F 2 "w_conn_pc:rj45-shield" H 10400 1150 50  0001 C CNN
F 3 "" H 10400 1150 50  0001 C CNN
F 4 "conector RJ45 90 graus" H 10400 1150 60  0001 C CNN "Desc"
	1    10400 1150
	1    0    0    -1  
$EndComp
Text Label 10350 1900 1    60   ~ 0
A
Text Label 10450 1900 1    60   ~ 0
B
$Comp
L GND #PWR036
U 1 1 5A3EA008
P 10050 1700
F 0 "#PWR036" H 10050 1450 50  0001 C CNN
F 1 "GND" H 10050 1550 50  0000 C CNN
F 2 "" H 10050 1700 50  0001 C CNN
F 3 "" H 10050 1700 50  0001 C CNN
	1    10050 1700
	1    0    0    -1  
$EndComp
Text Label 1100 1250 0    60   ~ 0
PIN
Text Label 9850 2000 0    60   ~ 0
PIN
NoConn ~ 10250 1600
NoConn ~ 10550 1600
NoConn ~ 10650 1600
NoConn ~ 10750 1600
$Comp
L LED_ALT D5
U 1 1 5A3ED0FC
P 6500 1050
F 0 "D5" H 6500 1150 50  0000 C CNN
F 1 "PWR" H 6500 950 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 6500 1050 50  0001 C CNN
F 3 "" H 6500 1050 50  0001 C CNN
F 4 "led verde smd 0805" H 6500 1050 60  0001 C CNN "Desc"
	1    6500 1050
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 5A3EE5AB
P 6500 1450
F 0 "R5" V 6580 1450 50  0000 C CNN
F 1 "1k" V 6500 1450 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 6430 1450 50  0001 C CNN
F 3 "" H 6500 1450 50  0001 C CNN
F 4 "resisotor 1k smd 0805" V 6500 1450 60  0001 C CNN "Desc"
	1    6500 1450
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR037
U 1 1 5A3EEA0F
P 6500 1700
F 0 "#PWR037" H 6500 1450 50  0001 C CNN
F 1 "GND" H 6500 1550 50  0000 C CNN
F 2 "" H 6500 1700 50  0001 C CNN
F 3 "" H 6500 1700 50  0001 C CNN
	1    6500 1700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR038
U 1 1 5A3EED1B
P 6500 800
F 0 "#PWR038" H 6500 650 50  0001 C CNN
F 1 "+5V" H 6500 940 50  0000 C CNN
F 2 "" H 6500 800 50  0001 C CNN
F 3 "" H 6500 800 50  0001 C CNN
	1    6500 800 
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 J5
U 1 1 5A71B6EF
P 9300 2350
F 0 "J5" H 9300 2600 50  0000 C CNN
F 1 "HC-SR04" V 9400 2350 50  0000 C CNN
F 2 "w_pin_strip:pin_socket_4" H 9300 2350 50  0001 C CNN
F 3 "" H 9300 2350 50  0001 C CNN
F 4 "barra de pinos 1x4 vias" H 9300 2350 60  0001 C CNN "Desc"
	1    9300 2350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR039
U 1 1 5A71BA6C
P 9000 2150
F 0 "#PWR039" H 9000 2000 50  0001 C CNN
F 1 "+5V" H 9000 2290 50  0000 C CNN
F 2 "" H 9000 2150 50  0001 C CNN
F 3 "" H 9000 2150 50  0001 C CNN
	1    9000 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR040
U 1 1 5A71BE32
P 9000 2600
F 0 "#PWR040" H 9000 2350 50  0001 C CNN
F 1 "GND" H 9000 2450 50  0000 C CNN
F 2 "" H 9000 2600 50  0001 C CNN
F 3 "" H 9000 2600 50  0001 C CNN
	1    9000 2600
	1    0    0    -1  
$EndComp
NoConn ~ 10950 800 
NoConn ~ 5950 3950
NoConn ~ 5950 3850
NoConn ~ 5950 3750
NoConn ~ 5950 3650
$Comp
L GND #PWR041
U 1 1 5A7B8816
P 6050 7400
F 0 "#PWR041" H 6050 7150 50  0001 C CNN
F 1 "GND" H 6050 7250 50  0000 C CNN
F 2 "" H 6050 7400 50  0001 C CNN
F 3 "" H 6050 7400 50  0001 C CNN
	1    6050 7400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR042
U 1 1 5A7B9D8D
P 6050 6350
F 0 "#PWR042" H 6050 6200 50  0001 C CNN
F 1 "+5V" H 6050 6490 50  0000 C CNN
F 2 "" H 6050 6350 50  0001 C CNN
F 3 "" H 6050 6350 50  0001 C CNN
	1    6050 6350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR043
U 1 1 5A7BD7AB
P 3850 7300
F 0 "#PWR043" H 3850 7050 50  0001 C CNN
F 1 "GND" H 3850 7150 50  0000 C CNN
F 2 "" H 3850 7300 50  0001 C CNN
F 3 "" H 3850 7300 50  0001 C CNN
	1    3850 7300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR044
U 1 1 5A7C6B7A
P 3850 6250
F 0 "#PWR044" H 3850 6100 50  0001 C CNN
F 1 "+5V" H 3850 6390 50  0000 C CNN
F 2 "" H 3850 6250 50  0001 C CNN
F 3 "" H 3850 6250 50  0001 C CNN
	1    3850 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1250 1100 1250
Wire Wire Line
	1700 1250 1800 1250
Wire Wire Line
	2300 1400 2300 1250
Wire Wire Line
	2100 1250 2900 1250
Wire Wire Line
	2300 1800 2300 1700
Wire Wire Line
	2750 1800 2750 1700
Wire Wire Line
	2750 1250 2750 1400
Connection ~ 2300 1250
Wire Wire Line
	3200 1650 3200 1550
Connection ~ 2750 1250
Wire Wire Line
	3650 1750 3650 1650
Wire Wire Line
	3650 1350 3650 1250
Wire Wire Line
	3500 1250 4000 1250
Wire Wire Line
	4000 1750 4000 1650
Wire Wire Line
	4000 1200 4000 1350
Connection ~ 3650 1250
Connection ~ 4000 1250
Wire Wire Line
	3950 2700 4050 2700
Wire Wire Line
	3950 2550 3950 2900
Wire Wire Line
	4050 2600 3950 2600
Connection ~ 3950 2600
Wire Wire Line
	3950 2900 4050 2900
Connection ~ 3950 2700
Wire Wire Line
	3950 4700 3950 5000
Wire Wire Line
	3950 4700 4050 4700
Wire Wire Line
	4050 4800 3950 4800
Connection ~ 3950 4800
Wire Wire Line
	4050 4900 3950 4900
Connection ~ 3950 4900
Wire Wire Line
	6250 2900 5950 2900
Wire Wire Line
	6250 3000 5950 3000
Wire Wire Line
	6250 3100 5950 3100
Wire Wire Line
	6250 4050 5950 4050
Wire Wire Line
	6250 4200 5950 4200
Wire Wire Line
	6250 4300 5950 4300
Wire Wire Line
	1900 3050 1900 3000
Wire Wire Line
	1900 2700 1900 2650
Wire Wire Line
	1600 3050 1600 3000
Wire Wire Line
	1600 2700 1600 2650
Wire Wire Line
	1300 3050 1300 3000
Wire Wire Line
	1300 2700 1300 2650
Wire Wire Line
	1350 4250 1350 4150
Wire Wire Line
	1350 4150 1500 4150
Wire Wire Line
	1350 4650 1350 4550
Wire Wire Line
	2000 4250 2000 4150
Wire Wire Line
	2000 4650 2000 4550
Wire Wire Line
	2000 4150 1800 4150
Wire Wire Line
	6250 3200 5950 3200
Wire Wire Line
	6250 3300 5950 3300
Wire Wire Line
	1350 5750 1600 5750
Wire Wire Line
	1350 5850 1600 5850
Wire Wire Line
	1350 5950 1600 5950
Wire Wire Line
	2400 5850 2100 5850
Wire Wire Line
	2200 6000 2200 5950
Wire Wire Line
	2200 5950 2100 5950
Wire Wire Line
	2150 5700 2150 5750
Wire Wire Line
	2150 5750 2100 5750
Wire Wire Line
	2300 2650 2300 2700
Wire Wire Line
	2300 3000 2300 3150
Wire Wire Line
	2300 3150 2650 3150
Wire Wire Line
	7750 1700 7650 1700
Wire Wire Line
	8050 2000 8050 1900
Wire Wire Line
	8050 1350 8050 1500
Wire Wire Line
	8050 1000 8050 1050
Wire Wire Line
	7100 1700 7350 1700
Wire Wire Line
	5950 2600 6250 2600
Wire Wire Line
	6250 2700 5950 2700
Connection ~ 8050 1450
Wire Wire Line
	8050 2900 8050 2800
Wire Wire Line
	8300 1950 8300 2000
Wire Wire Line
	7600 5250 7500 5250
Wire Wire Line
	6850 5250 7200 5250
Wire Wire Line
	7900 5500 7900 5450
Wire Wire Line
	7900 4950 7900 5050
Wire Wire Line
	7900 4600 7900 4650
Wire Wire Line
	7900 5000 8900 5000
Connection ~ 7900 5000
Wire Wire Line
	8900 4800 8800 4800
Wire Wire Line
	8800 4800 8800 5000
Connection ~ 8800 5000
Wire Wire Line
	8800 4700 8900 4700
Wire Wire Line
	8900 5100 8800 5100
Wire Wire Line
	8300 4700 8500 4700
Wire Wire Line
	8350 5100 8500 5100
Wire Wire Line
	9300 5400 9300 5300
Wire Wire Line
	9300 4400 9300 4500
Wire Wire Line
	9700 3950 9700 3900
Wire Wire Line
	9700 3600 9700 3550
Wire Wire Line
	9700 4800 10200 4800
Wire Wire Line
	10050 4800 10050 4650
Wire Wire Line
	10050 4250 10050 4350
Wire Wire Line
	10350 4750 10350 4700
Wire Wire Line
	10350 4700 10200 4700
Wire Wire Line
	10200 4700 10200 4800
Connection ~ 10050 4800
Wire Wire Line
	10350 5050 10350 5100
Wire Wire Line
	10350 5100 10200 5100
Wire Wire Line
	10200 5100 10200 5000
Wire Wire Line
	10200 5000 9700 5000
Wire Wire Line
	10050 5100 10050 5000
Connection ~ 10050 5000
Wire Wire Line
	10050 5500 10050 5400
Wire Wire Line
	8450 2600 8350 2600
Wire Wire Line
	8750 2600 8850 2600
Wire Wire Line
	6250 3450 5950 3450
Wire Wire Line
	6250 3550 5950 3550
Wire Wire Line
	8250 4350 8250 4450
Wire Wire Line
	8250 4450 9100 4450
Wire Wire Line
	8250 3550 8250 3650
Wire Wire Line
	8250 3950 8250 4050
Wire Wire Line
	9100 4450 9100 4200
Wire Wire Line
	8850 4450 8850 4700
Connection ~ 8850 4700
Wire Wire Line
	9100 3800 9100 3900
Wire Wire Line
	8850 5700 8850 5750
Wire Wire Line
	8850 5750 8700 5750
Wire Wire Line
	8300 5750 8400 5750
Wire Wire Line
	8300 5650 8300 5750
Connection ~ 8850 4450
Wire Wire Line
	8450 5100 8450 5300
Wire Wire Line
	8450 5300 8850 5300
Wire Wire Line
	8850 5300 8850 5400
Connection ~ 8450 5100
Wire Wire Line
	7100 4750 7100 4800
Wire Wire Line
	7100 5100 7100 5250
Connection ~ 7100 5250
Wire Wire Line
	10350 1600 10350 1900
Wire Wire Line
	10450 1600 10450 1900
Wire Wire Line
	10050 1700 10050 1600
Wire Wire Line
	9850 2000 10150 2000
Wire Wire Line
	10150 2000 10150 1600
Wire Wire Line
	6500 1700 6500 1600
Wire Wire Line
	6500 1300 6500 1200
Wire Wire Line
	6500 800  6500 900 
Wire Wire Line
	9000 2150 9000 2200
Wire Wire Line
	9000 2200 9100 2200
Wire Wire Line
	9100 2300 8850 2300
Wire Wire Line
	8850 2300 8850 1450
Wire Wire Line
	9000 2600 9000 2500
Wire Wire Line
	9000 2500 9100 2500
Wire Wire Line
	7800 2350 8300 2350
Wire Wire Line
	8050 2350 8050 2400
Wire Wire Line
	9100 2400 8850 2400
Wire Wire Line
	8850 2400 8850 2600
Wire Wire Line
	6050 7400 6050 7300
Wire Wire Line
	5650 7100 5750 7100
Wire Wire Line
	5050 7100 5350 7100
Wire Wire Line
	3850 7300 3850 7200
Wire Wire Line
	3450 7000 3550 7000
Wire Wire Line
	6050 6350 6050 6450
Wire Wire Line
	6050 6750 6050 6900
Wire Wire Line
	5700 6700 5450 6700
Wire Wire Line
	5700 6000 5700 6850
Wire Wire Line
	5700 6850 6050 6850
Connection ~ 6050 6850
Wire Wire Line
	5450 6350 5700 6350
Connection ~ 5700 6700
Wire Wire Line
	5450 6000 5700 6000
Connection ~ 5700 6350
Wire Wire Line
	3850 6250 3850 6350
Wire Wire Line
	3850 6650 3850 6800
Text Label 2850 7000 0    60   ~ 0
LED2
Wire Wire Line
	2850 7000 3150 7000
$Comp
L +5V #PWR045
U 1 1 5A7CEB66
P 5000 5900
F 0 "#PWR045" H 5000 5750 50  0001 C CNN
F 1 "+5V" H 5000 6040 50  0000 C CNN
F 2 "" H 5000 5900 50  0001 C CNN
F 3 "" H 5000 5900 50  0001 C CNN
	1    5000 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 5900 5000 6700
Wire Wire Line
	5000 6700 5150 6700
Wire Wire Line
	5150 6350 5000 6350
Connection ~ 5000 6350
Wire Wire Line
	5150 6000 5000 6000
Connection ~ 5000 6000
Wire Wire Line
	3500 6600 3250 6600
Wire Wire Line
	3500 5900 3500 6750
Wire Wire Line
	3250 6250 3500 6250
Connection ~ 3500 6600
Wire Wire Line
	3250 5900 3500 5900
Connection ~ 3500 6250
$Comp
L +5V #PWR046
U 1 1 5A7CF6D8
P 2800 5800
F 0 "#PWR046" H 2800 5650 50  0001 C CNN
F 1 "+5V" H 2800 5940 50  0000 C CNN
F 2 "" H 2800 5800 50  0001 C CNN
F 3 "" H 2800 5800 50  0001 C CNN
	1    2800 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 5800 2800 6600
Wire Wire Line
	2800 6600 2950 6600
Wire Wire Line
	2950 6250 2800 6250
Connection ~ 2800 6250
Wire Wire Line
	2950 5900 2800 5900
Connection ~ 2800 5900
Wire Wire Line
	3500 6750 3850 6750
Connection ~ 3850 6750
$Comp
L LED_ALT D3
U 1 1 5A7DC932
P 3100 5900
F 0 "D3" H 3100 6000 50  0000 C CNN
F 1 "LED VERMELHO" H 3100 5750 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 3100 5900 50  0001 C CNN
F 3 "" H 3100 5900 50  0001 C CNN
F 4 "led vermelho smd 0805" H 3100 5900 60  0001 C CNN "Desc"
	1    3100 5900
	-1   0    0    1   
$EndComp
$Comp
L C C3
U 1 1 5A99D598
P 1600 2850
F 0 "C3" H 1625 2950 50  0000 L CNN
F 1 "100n" H 1625 2750 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 1638 2700 50  0001 C CNN
F 3 "" H 1600 2850 50  0001 C CNN
F 4 "capacitor ceramico smd 0805" H 1600 2850 60  0001 C CNN "Desc"
	1    1600 2850
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5A99D654
P 1900 2850
F 0 "C4" H 1925 2950 50  0000 L CNN
F 1 "100n" H 1925 2750 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 1938 2700 50  0001 C CNN
F 3 "" H 1900 2850 50  0001 C CNN
F 4 "capacitor ceramico smd 0805" H 1900 2850 60  0001 C CNN "Desc"
	1    1900 2850
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 5A99DC3A
P 2750 1550
F 0 "C7" H 2775 1650 50  0000 L CNN
F 1 "100n" H 2775 1450 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 2788 1400 50  0001 C CNN
F 3 "" H 2750 1550 50  0001 C CNN
F 4 "capacitor ceramico smd 0805" H 2750 1550 60  0001 C CNN "Desc"
	1    2750 1550
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 5A99DD10
P 3650 1500
F 0 "C8" H 3675 1600 50  0000 L CNN
F 1 "100n" H 3675 1400 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 3688 1350 50  0001 C CNN
F 3 "" H 3650 1500 50  0001 C CNN
F 4 "capacitor ceramico smd 0805" H 3650 1500 60  0001 C CNN "Desc"
	1    3650 1500
	1    0    0    -1  
$EndComp
$Comp
L CP C9
U 1 1 5A395558
P 4000 1500
F 0 "C9" H 4025 1600 50  0000 L CNN
F 1 "470uF" H 4025 1400 50  0000 L CNN
F 2 "w_capacitors:CP_5x7mm" H 4038 1350 50  0001 C CNN
F 3 "" H 4000 1500 50  0001 C CNN
F 4 "capacitor eletrolitico 470uF 6V" H 4000 1500 60  0001 C CNN "Desc"
	1    4000 1500
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5A9A4A72
P 5500 7100
F 0 "R8" V 5580 7100 50  0000 C CNN
F 1 "1k" V 5500 7100 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 5430 7100 50  0001 C CNN
F 3 "" H 5500 7100 50  0001 C CNN
F 4 "resisotor 1k smd 0805" V 5500 7100 60  0001 C CNN "Desc"
	1    5500 7100
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 5A9A4DD5
P 3300 7000
F 0 "R3" V 3380 7000 50  0000 C CNN
F 1 "1k" V 3300 7000 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 3230 7000 50  0001 C CNN
F 3 "" H 3300 7000 50  0001 C CNN
F 4 "resisotor 1k smd 0805" V 3300 7000 60  0001 C CNN "Desc"
	1    3300 7000
	0    -1   -1   0   
$EndComp
$Comp
L R R21
U 1 1 5A9A501D
P 8600 2600
F 0 "R21" V 8680 2600 50  0000 C CNN
F 1 "1k" V 8600 2600 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 8530 2600 50  0001 C CNN
F 3 "" H 8600 2600 50  0001 C CNN
F 4 "resisotor 1k smd 0805" V 8600 2600 60  0001 C CNN "Desc"
	1    8600 2600
	0    -1   -1   0   
$EndComp
$Comp
L R R16
U 1 1 5A9A6146
P 7500 1700
F 0 "R16" V 7580 1700 50  0000 C CNN
F 1 "1k" V 7500 1700 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 7430 1700 50  0001 C CNN
F 3 "" H 7500 1700 50  0001 C CNN
F 4 "resisotor 1k smd 0805" V 7500 1700 60  0001 C CNN "Desc"
	1    7500 1700
	0    -1   -1   0   
$EndComp
$Comp
L Q_NPN_BCE Q3
U 1 1 5A9A6AD9
P 8150 2600
F 0 "Q3" H 8350 2675 50  0000 L CNN
F 1 "BC817-40" H 8350 2600 50  0000 L CNN
F 2 "w_smd_trans:sot23" H 8350 2525 50  0001 L CIN
F 3 "" H 8150 2600 50  0001 L CNN
F 4 "transistor npn bc817-25 smd sot23" H 8150 2600 60  0001 C CNN "Desc"
	1    8150 2600
	-1   0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5A9A90F5
P 2300 2850
F 0 "R1" V 2380 2850 50  0000 C CNN
F 1 "10k" V 2300 2850 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 2230 2850 50  0001 C CNN
F 3 "" H 2300 2850 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 2300 2850 60  0001 C CNN "Desc"
	1    2300 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1450 8050 1450
$Comp
L R R2
U 1 1 5A9AD1ED
P 3850 6500
F 0 "R2" V 3930 6500 50  0000 C CNN
F 1 "10k" V 3850 6500 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 3780 6500 50  0001 C CNN
F 3 "" H 3850 6500 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 3850 6500 60  0001 C CNN "Desc"
	1    3850 6500
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5A9AD4C5
P 6050 6600
F 0 "R4" V 6130 6600 50  0000 C CNN
F 1 "10k" V 6050 6600 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 5980 6600 50  0001 C CNN
F 3 "" H 6050 6600 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 6050 6600 60  0001 C CNN "Desc"
	1    6050 6600
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5A9AD584
P 7100 4950
F 0 "R6" V 7180 4950 50  0000 C CNN
F 1 "10k" V 7100 4950 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 7030 4950 50  0001 C CNN
F 3 "" H 7100 4950 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 7100 4950 60  0001 C CNN "Desc"
	1    7100 4950
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5A9AD876
P 7900 4800
F 0 "R9" V 7980 4800 50  0000 C CNN
F 1 "10k" V 7900 4800 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 7830 4800 50  0001 C CNN
F 3 "" H 7900 4800 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 7900 4800 60  0001 C CNN "Desc"
	1    7900 4800
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 5A9AD93F
P 9100 4050
F 0 "R17" V 9180 4050 50  0000 C CNN
F 1 "10k" V 9100 4050 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 9030 4050 50  0001 C CNN
F 3 "" H 9100 4050 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 9100 4050 60  0001 C CNN "Desc"
	1    9100 4050
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 5A9ADD6F
P 8300 2150
F 0 "R12" V 8380 2150 50  0000 C CNN
F 1 "10k" V 8300 2150 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 8230 2150 50  0001 C CNN
F 3 "" H 8300 2150 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 8300 2150 60  0001 C CNN "Desc"
	1    8300 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 2350 8300 2300
Connection ~ 8050 2350
$Comp
L R R10
U 1 1 5A9AE3D7
P 8050 1200
F 0 "R10" V 8130 1200 50  0000 C CNN
F 1 "10k" V 8050 1200 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 7980 1200 50  0001 C CNN
F 3 "" H 8050 1200 50  0001 C CNN
F 4 "resisotor 10k smd 0805" V 8050 1200 60  0001 C CNN "Desc"
	1    8050 1200
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 5A9B15E8
P 10050 4500
F 0 "R18" V 10130 4500 50  0000 C CNN
F 1 "560R" V 10050 4500 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 9980 4500 50  0001 C CNN
F 3 "" H 10050 4500 50  0001 C CNN
F 4 "resisotor 560R smd 0805" V 10050 4500 60  0001 C CNN "Desc"
	1    10050 4500
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 5A9B331A
P 10050 5250
F 0 "R19" V 10130 5250 50  0000 C CNN
F 1 "560R" V 10050 5250 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 9980 5250 50  0001 C CNN
F 3 "" H 10050 5250 50  0001 C CNN
F 4 "resisotor 560R smd 0805" V 10050 5250 60  0001 C CNN "Desc"
	1    10050 5250
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 5A9B34EE
P 8550 5750
F 0 "R14" V 8630 5750 50  0000 C CNN
F 1 "560R" V 8550 5750 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 8480 5750 50  0001 C CNN
F 3 "" H 8550 5750 50  0001 C CNN
F 4 "resisotor 560R smd 0805" V 8550 5750 60  0001 C CNN "Desc"
	1    8550 5750
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5A9B3674
P 8250 3800
F 0 "R11" V 8330 3800 50  0000 C CNN
F 1 "560R" V 8250 3800 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 8180 3800 50  0001 C CNN
F 3 "" H 8250 3800 50  0001 C CNN
F 4 "resisotor 560R smd 0805" V 8250 3800 60  0001 C CNN "Desc"
	1    8250 3800
	-1   0    0    1   
$EndComp
$Comp
L R R15
U 1 1 5A9C1C96
P 8650 5100
F 0 "R15" V 8730 5100 50  0000 C CNN
F 1 "360R" V 8650 5100 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 8580 5100 50  0001 C CNN
F 3 "" H 8650 5100 50  0001 C CNN
F 4 "resisotor 360R smd 0805" V 8650 5100 60  0001 C CNN "Desc"
	1    8650 5100
	0    1    1    0   
$EndComp
$Comp
L LED_ALT D2
U 1 1 5A9CA72C
P 3100 6250
F 0 "D2" H 3100 6350 50  0000 C CNN
F 1 "LED VERMELHO" H 3100 6100 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 3100 6250 50  0001 C CNN
F 3 "" H 3100 6250 50  0001 C CNN
F 4 "led vermelho smd 0805" H 3100 6250 60  0001 C CNN "Desc"
	1    3100 6250
	-1   0    0    1   
$EndComp
$Comp
L LED_ALT D4
U 1 1 5A9CA7E7
P 3100 6600
F 0 "D4" H 3100 6700 50  0000 C CNN
F 1 "LED VERMELHO" H 3100 6450 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 3100 6600 50  0001 C CNN
F 3 "" H 3100 6600 50  0001 C CNN
F 4 "led vermelho smd 0805" H 3100 6600 60  0001 C CNN "Desc"
	1    3100 6600
	-1   0    0    1   
$EndComp
$Comp
L LED_ALT D8
U 1 1 5A9CB208
P 5300 6000
F 0 "D8" H 5300 6100 50  0000 C CNN
F 1 "LED VERDE" H 5300 5850 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 5300 6000 50  0001 C CNN
F 3 "" H 5300 6000 50  0001 C CNN
F 4 "led verde smd 0805" H 5300 6000 60  0001 C CNN "Desc"
	1    5300 6000
	-1   0    0    1   
$EndComp
$Comp
L LED_ALT D9
U 1 1 5A9CB3B2
P 5300 6350
F 0 "D9" H 5300 6450 50  0000 C CNN
F 1 "LED VERDE" H 5300 6200 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 5300 6350 50  0001 C CNN
F 3 "" H 5300 6350 50  0001 C CNN
F 4 "led verde smd 0805" H 5300 6350 60  0001 C CNN "Desc"
	1    5300 6350
	-1   0    0    1   
$EndComp
$Comp
L LED_ALT D10
U 1 1 5A9CB46D
P 5300 6700
F 0 "D10" H 5300 6800 50  0000 C CNN
F 1 "LED VERDE" H 5300 6550 50  0000 C CNN
F 2 "w_smd_leds:Led_0805" H 5300 6700 50  0001 C CNN
F 3 "" H 5300 6700 50  0001 C CNN
F 4 "led verde smd 0805" H 5300 6700 60  0001 C CNN "Desc"
	1    5300 6700
	-1   0    0    1   
$EndComp
$Comp
L Q_NPN_BCE Q5
U 1 1 5A9CC7AB
P 5950 7100
F 0 "Q5" H 6150 7175 50  0000 L CNN
F 1 "BC817-40" H 6150 7100 50  0000 L CNN
F 2 "w_smd_trans:sot23" H 6150 7025 50  0001 L CIN
F 3 "" H 5950 7100 50  0001 L CNN
F 4 "transistor npn bc817-25 smd sot23" H 5950 7100 60  0001 C CNN "Desc"
	1    5950 7100
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q4
U 1 1 5A9CCA29
P 3750 7000
F 0 "Q4" H 3950 7075 50  0000 L CNN
F 1 "BC817-40" H 3950 7000 50  0000 L CNN
F 2 "w_smd_trans:sot23" H 3950 6925 50  0001 L CIN
F 3 "" H 3750 7000 50  0001 L CNN
F 4 "transistor npn bc817-25 smd sot23" H 3750 7000 60  0001 C CNN "Desc"
	1    3750 7000
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5A99614B
P 9700 3750
F 0 "C10" H 9725 3850 50  0000 L CNN
F 1 "100n" H 9725 3650 50  0000 L CNN
F 2 "w_smd_cap:c_0805" H 9738 3600 50  0001 C CNN
F 3 "" H 9700 3750 50  0001 C CNN
F 4 "capacitor ceramico smd 0805" H 9700 3750 60  0001 C CNN "Desc"
	1    9700 3750
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5A996863
P 7350 5250
F 0 "R7" V 7430 5250 50  0000 C CNN
F 1 "1k" V 7350 5250 50  0000 C CNN
F 2 "w_smd_resistors:r_0805" V 7280 5250 50  0001 C CNN
F 3 "" H 7350 5250 50  0001 C CNN
F 4 "resisotor 1k smd 0805" V 7350 5250 60  0001 C CNN "Desc"
	1    7350 5250
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
