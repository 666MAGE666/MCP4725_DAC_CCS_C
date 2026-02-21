#include <16F1938.h>
#device ADC=10

#FUSES NOMCLR                	//Master Clear pin used for I/O
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_A2,rcv=PIN_A3,bits=8,stream=PORT1)
#use i2c(Master,Fast,sda=PIN_C4,scl=PIN_C3)

