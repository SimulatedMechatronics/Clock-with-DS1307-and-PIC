#include <soft.h>

#define RTC_SDA  PIN_C4
#define RTC_SCL  PIN_C3

#include "ds1307.c"

#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

int sec=17, min=17, hora=17, dia=17, mes=7, ano=17, dow=6;
char data[4];

void main(){
   enable_interrupts(GLOBAL);
   //ds1307_set_date_time(dia, mes, ano, dow, hora, min, sec);
   while(TRUE){
      ds1307_get_date(dia,mes,ano,dow);
      ds1307_get_time(hora,min,sec);
      ds1307_get_day_of_week(data);
      printf("%d/%d/%d  %d:%d:%d %s \r\n", dia,mes,ano,hora,min,sec,data);
      delay_ms(1000);
   }
}
