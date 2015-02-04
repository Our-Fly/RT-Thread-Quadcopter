#ifndef EASY_TRACER_H
#define EASY_TRACER_H
#include "head.h"

#define IMG_X 0	  //ͼƬx����
#define IMG_Y 0	  //ͼƬy����
#define IMG_W 320 //ͼƬ���
#define IMG_H 240 //ͼƬ�߶�

#define ALLOW_FAIL_PER 2 //�ݴ��ʣ�û1<<ALLOW_FAIL_PER�����������һ������㣬�ݴ���Խ��Խ����ʶ�𣬵�������Խ��
#define ITERATE_NUM    10 //������������������Խ��ʶ��Խ��ȷ����������Խ��

#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //��ɫ
#define BRRED 			 0XFC07 //�غ�ɫ
#define GRAY  			 0X8430 //��ɫ

typedef struct{
    unsigned char  H_MIN;//Ŀ����Сɫ��
    unsigned char  H_MAX;//Ŀ�����ɫ��	
    
	unsigned char  S_MIN;//Ŀ����С���Ͷ�  
    unsigned char  S_MAX;//Ŀ����󱥺Ͷ�
	
	unsigned char  L_MIN;//Ŀ����С����  
    unsigned char  L_MAX;//Ŀ���������
	
	unsigned int  WIDTH_MIN;//Ŀ����С���
	unsigned int  HIGHT_MIN;//Ŀ����С�߶�

	unsigned int  WIDTH_MAX;//Ŀ�������
	unsigned int  HIGHT_MAX;//Ŀ�����߶�

}TARGET_CONDI;//�ж�Ϊ��Ŀ������

typedef struct{
	 uint16_t x;//Ŀ���x����
	 uint16_t y;//Ŀ���y����
	 uint16_t w;//Ŀ��Ŀ��
	 uint16_t h;//Ŀ��ĸ߶�
}RESULT;//ʶ����

typedef struct{
    unsigned char  red;             // [0,255]
    unsigned char  green;           // [0,255]
    unsigned char  blue;            // [0,255]
}COLOR_RGB;//RGB��ʽ��ɫ

typedef struct{
    unsigned char hue;              // [0,240]
    unsigned char saturation;       // [0,240]
    unsigned char luminance;        // [0,240]
}COLOR_HSL;//HSL��ʽ��ɫ

typedef struct{
    unsigned int X_Start;              
    unsigned int X_End;
	unsigned int Y_Start;              
    unsigned int Y_End;
}SEARCH_AREA;//����

typedef enum{
	TS_FIND_IN_FULL_FRAME,//full frame 
	TS_FIND_IN_LAST_FRAME,//last frame
	TS_TRACING,// trace
}TRACE_STATE;

//Ψһ��API���û���ʶ������д��Conditionָ��Ľṹ���У��ú���������Ŀ���x��y����ͳ���
//����1ʶ��ɹ�������1ʶ��ʧ��
int Trace(const TARGET_CONDI *Condition,RESULT *Resu);
uint16_t  GUI_ReadBit16Point(unsigned int x,unsigned int y);

void RGBtoHSL(const COLOR_RGB *Rgb, COLOR_HSL *Hsl);
void ReadColor(unsigned int x,unsigned int y,COLOR_RGB *Rgb);
int ColorMatch(const COLOR_HSL *Hsl,const TARGET_CONDI *Condition);
#endif
