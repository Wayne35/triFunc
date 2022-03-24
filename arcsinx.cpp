#include <iostream>
using namespace std;
#include "stdio.h" 
#include "stdlib.h"  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define PI        3.14159265358979323846

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




int main(float x) {
		cin>>x;
    cout<<arcsin(x);
	return 0;
}
