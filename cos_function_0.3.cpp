#include <iostream>   
#include<Cmath>  //为便于对比结果，main函数中调用了Cmath中的库函数sin和cos  
using namespace std;  
const double pi=3.141592658;    

//int main( )  
float cos(int mode,float input)
{  
	float input;
	int mode;
   if(mode==1)
   {  
   while (input >= 180)
        input -= 360;
    while (input < -180)
        input += 360;//cos的周期性 [-180,180]
  
   x=(input/180.0)*pi;//转换成弧度制，方便用泰勒公式 
   }
   
  if(mode==2)
   { 
   if (input> pi)
		input -= 2 * pi;
	else if (input < -pi)
		input += 2 * pi;//周期性 [-pi,pi]
   x=input;
   }
   
   double r=1,x_pow=1,item;  
   int n=0,fact=1,sign=-1; 
  
   if(x>=-pi/2&&x<=pi/2)//这个范围[-pi/2,pi/2]内泰勒公式精度高计算快 
    {
   do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             r+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(r-cos(x))>0.00001);  //误差 
  }
  
  if(x>=pi/2)//转换到[-pi/2,pi/2]范围，cos(pi-x)=-cosx 
  {
  	x=pi-x;
  	do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             r+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(-r-cos(pi-x))>0.00001); 
  r=-r; 
  }
  
  if(x<=-pi/2)//转换到[-pi/2,pi/2]范围，cos(pi+x)=-cosx
  {
  	x=pi+x;
  	do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             r+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(-r-cos(x-pi))>0.00001); 
 r=-r; 
  }
  
  // system("PAUSE");  

}  





