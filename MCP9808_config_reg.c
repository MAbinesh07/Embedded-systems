#include <stdio.h>
#include <stdint.h>

int main(){
uint16_t configValue;
uint16_t *configPtr = &configValue;
int clearBit8;

printf("Enter the configuration register value\t");
scanf("%hx",&configValue);

if( (*configPtr & (1<<6)) || (*configPtr & (1<<7)) )
{
  printf("bit 0 cannot be altered and shutdown mode cannot be set.\nbit0_value: %d\nbit8_value:%d\n",(*configPtr & (1<<0)) ? 1:0,(*configPtr & (1<<8))?1:0);


  if (*configPtr & (1<<8)){
   printf("Enter 0 to clear and 1 to keep");
   scanf("%d", &clearBit8);
}
   if(clearBit8 == 0){
    *configPtr &= ~(1<<8);
     printf("The bit 8 is cleared\n");

}

}
else{
printf("bit 0 can be altered and shutdown mode can be set or cleared. value:%d\n", (*configPtr & (1<<0))? 1:0);



int newbit0Value,newbit8Value;
printf("Enter the new bit value for bit 0 and bit 8:");
scanf("%d %d",&newbit0Value,&newbit8Value);

if(newbit0Value == 1){
*configPtr |= 0x0001;
}
else{
*configPtr &= ~0x0001;
}
printf("The new value of bit 0 is: %d\n",(*configPtr & (1<<0))? 1:0);

if(newbit8Value == 1){
*configPtr |= (1<<8);
}
else{
*configPtr &= ~(1<<8);
}
printf("The new value of bit 8 is: %d\n",(*configPtr & (1<<8))? 1:0);
}
printf("The final value in the configuration register is: 0x%04X\n",*configPtr);
return 0;
}

