#include "stm32f10x.h"
#include "Dio.h"
#include "delay.h"
#include "setjmp.h"
volatile  uint16_t dem = 0;
jmp_buf buf;

void delay_10_ms(int n);
void blinkled(uint8_t number);
void stopled();
void sangduoi(uint8_t number);

int main(void ){
	config_output();
	int temp;
	temp= setjmp(buf);
	DelayInit();
	while(1){
		if(dem==0){
			if(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW){
				while(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW);
				dem++;
				blinkled(6);
			}
		}
		else if(dem== 1){
			if(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW){
				while(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW);
				dem++;
				sangduoi(3);
			}
		}
		else if(dem== 2){
			if(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW){
				while(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW);
				dem=0;
				stopled();
			}
		}
	}
}

void delay_10_ms(int n){
	uint32_t i;
	for(i = 0; i < n; i++){
		
		if(dem==0){
			if(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW){
				while(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW);
				dem++;
				blinkled(6);
			}
		}
		else if(dem== 1){
			if(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW){
				while(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW);
				dem++;
				sangduoi(3);
			}
		}
		else if(dem== 2){
			if(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW){
				while(Dio_ReadChannel(DIO_CHANNEL_PA8)==STD_LOW);
				dem=0;
				stopled();
			}
		}
		DelayMs(10);
	}
}
void blinkled(uint8_t number){
	uint8_t i;
	uint8_t temp=0x00;
	for(i=0;i<2*number;i++){
			Dio_WriteChannel(DIO_CHANNEL_PA0,setLevel(temp,GPIO_Pin_0));
			Dio_WriteChannel(DIO_CHANNEL_PA1,setLevel(temp,GPIO_Pin_1));
			Dio_WriteChannel(DIO_CHANNEL_PA2,setLevel(temp,GPIO_Pin_2));
			Dio_WriteChannel(DIO_CHANNEL_PA3,setLevel(temp,GPIO_Pin_3));
			Dio_WriteChannel(DIO_CHANNEL_PA4,setLevel(temp,GPIO_Pin_4));
			Dio_WriteChannel(DIO_CHANNEL_PA5,setLevel(temp,GPIO_Pin_5));
			Dio_WriteChannel(DIO_CHANNEL_PA6,setLevel(temp,GPIO_Pin_6));
			Dio_WriteChannel(DIO_CHANNEL_PA7,setLevel(temp,GPIO_Pin_7));
			delay_10_ms(100);
			temp=~temp;
	}
	longjmp(buf,2);
}
void stopled(){
	uint8_t temp=0x00;
			Dio_WriteChannel(DIO_CHANNEL_PA0,setLevel(temp,GPIO_Pin_0));
			Dio_WriteChannel(DIO_CHANNEL_PA1,setLevel(temp,GPIO_Pin_1));
			Dio_WriteChannel(DIO_CHANNEL_PA2,setLevel(temp,GPIO_Pin_2));
			Dio_WriteChannel(DIO_CHANNEL_PA3,setLevel(temp,GPIO_Pin_3));
			Dio_WriteChannel(DIO_CHANNEL_PA4,setLevel(temp,GPIO_Pin_4));
			Dio_WriteChannel(DIO_CHANNEL_PA5,setLevel(temp,GPIO_Pin_5));
			Dio_WriteChannel(DIO_CHANNEL_PA6,setLevel(temp,GPIO_Pin_6));
			Dio_WriteChannel(DIO_CHANNEL_PA7,setLevel(temp,GPIO_Pin_7));
	longjmp(buf,2);
}
void sangduoi(uint8_t number){
	uint8_t i,j;
	uint8_t temp;
	for(i=0;i<number;i++){
		temp=0x1;
		for(j=0;j<8;j++){
			Dio_WriteChannel(DIO_CHANNEL_PA0,setLevel(temp,GPIO_Pin_0));
			Dio_WriteChannel(DIO_CHANNEL_PA1,setLevel(temp,GPIO_Pin_1));
			Dio_WriteChannel(DIO_CHANNEL_PA2,setLevel(temp,GPIO_Pin_2));
			Dio_WriteChannel(DIO_CHANNEL_PA3,setLevel(temp,GPIO_Pin_3));
			Dio_WriteChannel(DIO_CHANNEL_PA4,setLevel(temp,GPIO_Pin_4));
			Dio_WriteChannel(DIO_CHANNEL_PA5,setLevel(temp,GPIO_Pin_5));
			Dio_WriteChannel(DIO_CHANNEL_PA6,setLevel(temp,GPIO_Pin_6));
			Dio_WriteChannel(DIO_CHANNEL_PA7,setLevel(temp,GPIO_Pin_7));
			delay_10_ms(100);
			temp=temp<<1;
		}
	}
	longjmp(buf,2);
}
