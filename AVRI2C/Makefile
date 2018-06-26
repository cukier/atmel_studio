MCU    = atmega328p
F_CPU  = 16000000ULL
TARGET = AVRI2C

CC      = avr-gcc
OBJCOPY = avr-objcopy

INCLUDES = -I.

DEFINES  =	-D__AVR_ATmega328P__
DEFINES  +=	-DI2C_SLAVE
#DEFINES  +=	-DI2C_MASTER
DEFINES  +=	-DF_CPU=$(F_CPU)

CFLAGS   = -std=c99 -g -Wall -mmcu=$(MCU) $(INCLUDES) $(DEFINES) -Os 

LDFLAGS  = -Wl,-gc-sections -Wl,-relax 

OBJECT_FILES = src/main.o src/uart.o src/i2c.o

all: $(TARGET).hex size

size:
	@if [ -f $(TARGET).elf ]; then avr-size -C --mcu=$(MCU) $(TARGET).elf; fi

clean: 
	rm -rf *.o *.hex *.elf
	rm -rf Debug/*.o Debug/*.hex Debug/*.elf

%.hex: %.elf 
	$(OBJCOPY) -R .eeprom -O ihex $< $@
	[ -d Debug ] || mkdir Debug
	mv $(TARGET).hex Debug

%.elf: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@ 
