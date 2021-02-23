#ifndef __DHT11_H_
#define __DHT11_H_

#ifndef _DHT11_C_
#define _DHT11_C_ extern
#else
#define _DHT11_C_
#endif
#include "main.h"
#include "System.h"
  
										   
#define	DHT11_DQ_OUT PBout(5) 
#define	DHT11_DQ_IN  PBin(5)



_DHT11_C_ u8 DHT11Data[4];//��ʪ������(�¶ȸ�λ,�¶ȵ�λ,ʪ�ȸ�λ,ʪ�ȵ�λ)
_DHT11_C_ u32 RendTHCnt;//��ʱ�ɼ���ʪ������

void DHT11_start(void);
void DHT11_Receive(void);     //����40λ������


u8 DHT11_Init(void);//???DHT11
void DHT11_Read_Data(void); 
u8 DHT11_Read_Byte(void);//??????
u8 DHT11_Read_Bit(void);//?????
u8 DHT11_Check(void);//??????DHT11
void DHT11_Rst(void);//??DHT11  



#endif
