#include <iostream>
using namespace std;
#include "stdio.h" 
#include "stdlib.h"  
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 #define PI  3.141592658




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

