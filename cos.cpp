#include <iostream>   
#include<Cmath>  //Ϊ���ڶԱȽ����main�����е�����Cmath�еĿ⺯��sin��cos  
using namespace std;  
const double pi=3.1415926;  
double mysin(double);   
double mycos(double);  
double myabs(double);   //�Զ��庯��
int main( )  
{  
   cout<<"cos(87��)��ֵΪ"<<mycos((87.0/180)*pi)<<endl;           
   cout<<"���ÿ⺯�����cos(87��)��ֵΪ"<<cos((87.0/180)*pi)<<endl;  
   system("PAUSE");  
   return 0;  
}  
  

   
//���涨��mycos����  
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
   
//���涨��myabs����  
double myabs(double x)  
{  
   return ((x>=0)?x:-x);  
}

