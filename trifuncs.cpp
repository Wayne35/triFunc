#include <iostream>
#include <Cmath>
#include <math.h>
#include "stdio.h" 
#include "stdlib.h" 
#include "trifuncs.h"
#define PI    3.14159265358979323846
using namespace std;

//�ƴ�־ͬѧ����arctan�������� 
float arctan(float x)
{
	float e = x;
	float t = 1/x;
	float sqr = x * x;
	float r = 0;
	float y = 0;
	int i = 1;
	if ((x>0)&&(x<1)) // 0<x<1ʱ����̩��չ������arctan��ֵ�� 
	{
		while ((e / i > 1e-15)||(e / i < -1e-15)) //���Ƽ���ľ��� 
	  {
		float f = e / i;
		r = (i % 4 == 1) ? r + f : r - f;
		e = e * sqr;
		i += 2;
	  }
	}
	
	else if (x==1) //x=1ʱ��ֱ�������� 
	{
		r = x*PI/4;
	}
	
	else if (x>1) // x>1ʱ����������ֵ��ɢ���õȼ�ת����ʽarctan(1/x) = Pi/2 - arctan(x)���� 
	{
		
	while ((t / i > 1e-15)||(t / i < -1e-15))
	  {
		float f = t / i;
		y = (i % 4 == 1) ? y + f : y - f;
		t = t / sqr;
		i += 2;
	  }
	  r = PI/2 - y;
	}
	if(x<0) //arctan(x)Ϊ�溯����ȡ������ 
	{
		return -arctan(-x);
	}

	if(abs(r - atan(x)) < 1e-6) //��⺯������Ľ�����жԱȣ������С��10�ĸ����η�ʱ���������� 
	{
		return r;
	}
	else
	{
		return 0;
	}	
	
}

//���ľ�ͬѧ����cos����  ���� 

float cos(int mode,float input)
{  
	float x;
   if(mode==1)
   {  
   while (input >= 180)
        input -= 360;
    while (input < -180)
        input += 360;//cos�������� [-180,180]
  
   x=(input/180.0)*PI;//ת���ɻ����ƣ�������̩�չ�ʽ 
   }
   
  if(mode==2)
   { 
   if (input> PI)
		input -= 2 * PI;
	else if (input < -PI)
		input += 2 * PI;//������ [-pi,pi]
   x=input;
   }
   
   double r=1,x_pow=1,item;  
   int n=0,fact=1,sign=-1; 
  
   if(x>=-PI/2&&x<=PI/2)//�����Χ[-pi/2,pi/2]��̩�չ�ʽ���ȸ߼���� 
    {
   do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             r+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(r-cos(x))>0.00001);  //��� 
  }
  
  if(x>=PI/2)//ת����[-pi/2,pi/2]��Χ��cos(pi-x)=-cosx 
  {
  	x=PI-x;
  	do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             r+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(-r-cos(PI-x))>0.00001); 
  r=-r; 
  }
  
  if(x<=-PI/2)//ת����[-pi/2,pi/2]��Χ��cos(pi+x)=-cosx
  {
  	x=PI+x;
  	do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             r+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(-r-cos(x-PI))>0.00001); 
 r=-r; 
  }
return r;

}  

//������ͬѧ����sin��������
//�ȶ���һ���׳˺���
float fac(float n) {
	float f = 0;
	if (n == 1 || n == 0) f = 1; else f = fac(n - 1) * n;
	return f;
}
//һ��ָ������(�η�)
float kvat(float n, float ci) {
	float chengf = 1;
	for (int i = 1; i <= ci; i++) chengf = chengf * n;
	return chengf;
}
float sinus(float x) {
	int z = -1,j = 1;
	float sin = x;
	for (j = 3; fabs(kvat(x, j) / fac(j)) > 0.000001; j += 2) {
		sin = sin + z * (kvat(x, j) / fac(j));
		z = -z;
	}
	return sin;
}


float Sin(int mode, float input) {
	float result = 0;
	if (mode == 1){               //�Ƕȼ���
		if (abs(input) > 360) input = abs(input - (int)(input / 360) * 360);               //����Ƕ���������ж�
		result = sinus(input/180.0 * PI);
		if ((result - sin(input/180.0 * PI)) > 0.000001)result = 0;   //��⺯������Աȣ�������0.000001�����0����ʾerror
	}
	else if (mode == 2){          //���ȼ���	
		if (abs(input) > (2 * PI))input = abs(input - ((int)(input / (2 * PI))) * 2 * PI); //����Ƕ���������ж�
		result = sinus(input);
		if ((result - sin(input)) > 0.000001)  result = 0;
	}
	else{                         //ģʽ������������
		result = Sin(mode, input);
	}
	return result;
} 

//���ͬѧ����arcsin�������� 

double pow(double x, int n)
{
	double result = 1;
	if (n == 0)
		return 1;
	for (int i = 0; i < n; i++)
	{
		result*=x;
	}

	return result;
}

long factorial(int x)
{
	long result = 1;
	for (int i = 1; i <= x; i++)
		result *= i;

	return result;
}
float arcsin(float x)
{
	
	float result=0;
	float temp=x;
	
	int n=1;


	while((temp>1e-15)||(temp<-1e-15))        
	{
		result += temp;
		temp = factorial(2*n) / (pow(2, 2*n) * pow(factorial(n), 2)) * pow(x, 2*n+1) / (2*n+1);
		n++;
	}
	if(abs(result - asin(x)) < 1e-6)
	{
		return	result;
	}
	else
	{
	   return 0;
	}
	
	
}
