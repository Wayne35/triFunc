#include <iostream>   
#include<Cmath>  //Ϊ���ڶԱȽ����main�����е�����Cmath�еĿ⺯��sin��cos  
using namespace std;  
const double pi=3.141592658;    
double angle;
double rad;
int flag;
float x;

//int main( )  
float cos(float x)
{  
   cout << "����Ƕ�����1�����뻡������2 ";
   cin >> flag;
   if(flag==1)
   {  cout << "������Ƕȣ� ";
   cin >> angle;
   while (angle >= 180)
        angle -= 360;
    while (angle < -180)
        angle += 360;
  
   x=(angle/180.0)*pi;
   }
   
  if(flag==2)
   { cout << "�����뻡�ȣ� ";
   cin >> rad;
   if (rad> pi)
		rad -= 2 * pi;
	else if (rad < -pi)
		rad += 2 * pi;
   x=rad;
   }
   
   double sum=1,x_pow=1,item;  
   int n=0,fact=1,sign=-1; 
  
   if(x>=-pi/2&&x<=pi/2)
    {
   do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             sum+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(item)>0.00001);  
  }
  if(x>=pi/2)
  {
  	x=pi-x;
  	do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             sum+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(item)>0.00001); 
  sum=-sum; 
  }
  if(x<=-pi/2)
  {
  	x=pi+x;
  	do  
   {  
            fact=fact*(n+1)*(n+2);  
             x_pow*=x*x;  
             item =x_pow/fact*sign;  
             sum+=item;  
             sign=-sign;  
             n+=2;  
  }while(abs(item)>0.00001); 
  sum=-sum; 
  }
  
   cout << "��cosֵΪ�� " <<sum<<endl; 
   cout<<"���ÿ⺯�����cos��ֵΪ"<<sum<<endl;  

  
   system("PAUSE");  

}  





