#include <iostream>
#include <math.h>
#define PI 3.141592658 
using namespace std;
float arctan(float x)
{
	float e = x;
	float t = 1/x;
	float u = -1/x;
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
		r = x*M_PI/4;
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




