#include <MCP4725_DAC_16f1938.h>
#include <math.h>
#include <stdlib.h>

/// degiskenler 
int32 sinus_degeri[100];
int i ;
 
// pi sayisi tanýmlama  
#define PI 3.1415926


void dac_yazdir(unsigned int16 dac_deger)
{
   i2c_start();                           // i2c haberlesmesi baslatiliyor . 
   i2c_write(0b11000000);                // cihaz adresi 
   i2c_write(0b1000000);                 // dahili adres  
   i2c_write((dac_deger & 0xFF0) >> 4);     // yuksek degerlikli bitler kaydiriliyor  8bit (D11.D10.D9.D8.D7.D6.D5.D4)
   i2c_write((dac_deger & 0xF) << 4);       //dusuk degerlikli bitler kaydýrýlýyor 4bit    (D3.D2.D1.D0) 
   i2c_stop();                           // i2c haberlesmesi durduruldu.
} 


void sinus_hesapla()
{
   for (i=0; i<100; i++)
   {
      delay_ms(100);
      sinus_degeri[i] = ((sin(i*2*PI/100) + 1)*(4096/2));
   }
}

void main()
{

   while(TRUE)
   {

      sinus_hesapla();
      dac_yazdir(sinus_degeri[i]);

   }

}
