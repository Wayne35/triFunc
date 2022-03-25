#include <iostream>   
#include<Cmath>  //为便于对比结果，main函数中调用了Cmath中的库函数sin和cos  
using namespace std;  
const double pi=3.1415926;  
double mysin(double);   
double mycos(double);  
double myabs(double);   //自定义函数
int main( )  
{  
   cout<<"cos(87°)的值为"<<mycos((87.0/180)*pi)<<endl;           
   cout<<"利用库函数求得cos(87°)的值为"<<cos((87.0/180)*pi)<<endl;  
   system("PAUSE");  
   return 0;  
}  
  

   
//下面定义mycos函数  
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
   
//下面定义myabs函数  
double myabs(double x)  
{  
   return ((x>=0)?x:-x);  
}

