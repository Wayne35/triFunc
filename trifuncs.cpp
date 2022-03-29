#include <iostream>
#include<Cmath>
#include "trifuncs.h"
#define PI        3.14159265358979323846
using namespace std;

//黄春志同学做的arctan函数部分 
float arctan(float x)
{
	float e = x;
	float sqr = x * x;
	float r = 0;
	int i = 1;
	while ((e / i > 1e-15)||(e / i < -1e-15))
	{
		float f = e / i;
		r = (i % 4 == 1) ? r + f : r - f;
		e = e * sqr;
		i += 2;
	}
	return r;
}

//冯文娟同学做的cos函数  部分 

//下面定义myabs函数  
double myabs(double x)  
{  
   return ((x>=0)?x:-x);  
}
double mycos(double x)  
{  
   double sum=1,x_pow=1,item;  
   int n=0,fact=1,sign=-1;  
   do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             sum+=item;  
             sign=-sign;  
             n+=2;  
  }while(myabs(item)>0.00001);  
   return sum;  
}  
   

//李豪同学做的arcsin函数部分 
//角度转弧度
double deg2rad(double deg)
{
    return (deg*PI)/180.0;
}
double rad2deg(double rad)
{
    return rad*180/PI;
}

double fabs(double x)
{
	if (x < 0)
		return -x;
	return x;
}


//牛顿迭代法求开方
double k_sqrt(double a,double x0)
{ 
	
	double x1,y;
	x1=(x0+a/x0)/2.0;  
	if(fabs(x1-x0)>=10e-15)
		y = k_sqrt(a,x1);
	else  y=x1;
  return y;
}
double sqrt(double x)
{ 
	return k_sqrt(x, 1.0);
}


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
	return	result;
}

