#include <PWN_SINUS.h>
int i ;
unsigned int sin_table[48]=
{
0,
10,20,30,40,50,60,70, 80,90,100,
110,120,130,140,150,160,170,180,190,200,
210,220,230,240,230,220,210,
200,190,180,170,160,150,140,130,120,110,
100,90,80,70,60,50,40,30,20,10};


void main()
{
   setup_timer_2(T2_DIV_BY_16,249,1);      //4,0 ms overflow, 4,0 ms interrupt

   setup_ccp1(CCP_PWM);
   set_pwm1_duty(0);

   while(TRUE)
   {
      
         for(i=0 ; i<=47 ; i++)
         {
            delay_us(380);
            setup_ccp1(CCP_PWM);
            set_pwm1_duty(sin_table[i]);
         
         
                        if(i>=0 && i<=23)
               {  
                  output_high(pin_a6);
                  output_low(pin_a7);                  
               }

               if(i>=24 && i<=47)
               {  
                  output_low(pin_a6);
                  output_high(pin_a7);                  
               }
         }



      //TODO: User Code
   }

}
