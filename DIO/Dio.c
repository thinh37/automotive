#include "Dio.h"
GPIO_InitTypeDef GPIO_InitStructure;
volatile  uint16_t dem = 0;
jmp_buf buf;
void config_output(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
}
void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level){
	uint16_t gpiopin;
	GPIO_TypeDef *gpioport;
	switch(ChannelId){
		CHANNEL(A,0);
		CHANNEL(A,1);
		CHANNEL(A,2);
		CHANNEL(A,3);
		CHANNEL(A,4);
		CHANNEL(A,5);
		CHANNEL(A,6);
		CHANNEL(A,7);
		CHANNEL(A,8);
		CHANNEL(A,9);
		CHANNEL(A,10);
		CHANNEL(A,11);
		CHANNEL(A,12);
		CHANNEL(A,13);
		CHANNEL(A,14);
		CHANNEL(A,15);
		CHANNEL(B,0);
		CHANNEL(B,1);
		CHANNEL(B,2);
		CHANNEL(B,3);
		CHANNEL(B,4);
		CHANNEL(B,5);
		CHANNEL(B,6);
		CHANNEL(B,7);
		CHANNEL(B,8);
		CHANNEL(B,9);
		CHANNEL(B,10);
		CHANNEL(B,11);
		CHANNEL(B,12);
		CHANNEL(B,13);
		CHANNEL(B,14);
		CHANNEL(B,15);
		CHANNEL(C,13);
		CHANNEL(C,14);
		CHANNEL(C,15);
	}
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = gpiopin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(gpioport, &GPIO_InitStructure);
	if(Level==STD_LOW){
		GPIO_ResetBits(gpioport,gpiopin);
	}
	else{
		GPIO_SetBits(gpioport,gpiopin);
	}
}
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId){
	uint16_t gpiopin;
	GPIO_TypeDef *gpioport;
	switch(ChannelId){
		CHANNEL(A,0);
		CHANNEL(A,1);
		CHANNEL(A,2);
		CHANNEL(A,3);
		CHANNEL(A,4);
		CHANNEL(A,5);
		CHANNEL(A,6);
		CHANNEL(A,7);
		CHANNEL(A,8);
		CHANNEL(A,9);
		CHANNEL(A,10);
		CHANNEL(A,11);
		CHANNEL(A,12);
		CHANNEL(A,13);
		CHANNEL(A,14);
		CHANNEL(A,15);
		CHANNEL(B,0);
		CHANNEL(B,1);
		CHANNEL(B,2);
		CHANNEL(B,3);
		CHANNEL(B,4);
		CHANNEL(B,5);
		CHANNEL(B,6);
		CHANNEL(B,7);
		CHANNEL(B,8);
		CHANNEL(B,9);
		CHANNEL(B,10);
		CHANNEL(B,11);
		CHANNEL(B,12);
		CHANNEL(B,13);
		CHANNEL(B,14);
		CHANNEL(B,15);
		CHANNEL(C,13);
		CHANNEL(C,14);
		CHANNEL(C,15);
	}
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = gpiopin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(gpioport, &GPIO_InitStructure);
	if(GPIO_ReadInputDataBit(gpioport,gpiopin)==Bit_SET){
		return STD_HIGH;
	}else{
		return STD_LOW;
	}
}
void delay(int n){
	uint32_t i;
	for(i = 0; i < n; i++);
}

Dio_LevelType setLevel(uint16_t value,uint16_t PIN){
	if((value & PIN) == PIN)
		return STD_HIGH;
	else
		return STD_LOW;
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
		delay(10);
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
			delay_10_ms(100000);
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
			delay_10_ms(100000);
			temp=temp<<1;
		}
	}
	longjmp(buf,2);
}
void Program(){
	int temp;
	temp= setjmp(buf);
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