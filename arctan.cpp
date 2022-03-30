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
	if ((x>0)&&(x<1)) // 0<x<1时，用泰勒展开计算arctan的值。 
	{
		while ((e / i > 1e-15)||(e / i < -1e-15)) //限制计算的精度 
	  {
		float f = e / i;
		r = (i % 4 == 1) ? r + f : r - f;
		e = e * sqr;
		i += 2;
	  }
	}
	
	else if (x==1) //x=1时，直接输出结果 
	{
		r = x*M_PI/4;
	}
	
	else if (x>1) // x>1时，级数绝对值发散，用等价转换公式arctan(1/x) = Pi/2 - arctan(x)计算 
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
	if(x<0) //arctan(x)为奇函数，取反即可 
	{
		return -arctan(-x);
	}

	if(abs(r - atan(x)) < 1e-6) //与库函数计算的结果进行对比，当误差小于10的负六次方时，输出结果。 
	{
		return r;
	}
	else
	{
		return 0;
	}
	
	
}




