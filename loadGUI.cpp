#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include "loadGUI.h"
#include "trifuncs.h"
#define PI        3.14159265358979323846
#define X "    ��ѡ������Ҫ����:"
#define A " >> ���Ҽ���sin"
#define B " >> ���Ҽ���cos"
#define C " >> �����Ҽ���arcsin"
#define D " >> �����м���arctan"
#define E "    ���Ҽ���sin"
#define F "    ���Ҽ���cos"
#define G "    �����Ҽ���arcsin"
#define H "    �����м���arctan"
#define I "    ��������Ƕ�ֵ���ǻ���ֵ��"
#define J " >> �Ƕ�"
#define K " >> ����"
#define M "    �Ƕ�"
#define N "    ����"
using namespace std;
void  selection_func(short tv)
{
	switch (tv)//�г����п���
	{
	case 1://ѡ��1
		cout << X << endl << A << endl << F << endl << G << endl << H << endl;
		break;
	case 2://ѡ��2
		cout << X << endl << E << endl << B << endl << G << endl << H << endl;
			break;
	case 3://ѡ��3
		cout << X << endl << E << endl << F << endl << C << endl << H << endl;
		break;
	case 4://ѡ��4
		cout << X << endl << E << endl << F << endl << G << endl << D << endl;
		break;
	}
}
void  selection_unit(short tv)
{
	switch (tv)//�г����п���
	{
	case 1://ѡ��1
		cout << I << endl << J << endl << N << endl;
		break;
	case 2://ѡ��2
		cout << I << endl << M << endl << K << endl;
			break;
	}
}
void clean() { system("cls"); }//����system()ʵ����Ļˢ�£���cls"�ǡ�����������
int loadGUI(){
	
	int mode = 1;
	cout << "    ��ѡ������Ҫ����:" << endl; 
	cout << " >> ���Ҽ���sin " << endl;
	cout << "    ���Ҽ���cos " << endl;
	cout << "    �����Ҽ���arcsin " << endl;
	cout << "    �����м���arctan " << endl;
	bool selectedFunc = false;
	bool arcNeeded = false;
	int tc; 
	short tr_func = 1;
	while (!selectedFunc)
	{
		tc = _getch();
		clean();
		switch (tc)
		{
		case 72:
			while (tr_func == 1)//��δ������ü�ͷ�ڵ�һ��ʱ��ת��������
				tr_func = 5;
			tr_func--;
			selection_func(tr_func);
			break;
		case 80:
			while (tr_func == 4)//��δ������ü�ͷ�ڵ����һ��ʱ��ת����һ��
				tr_func = 0;
			tr_func++; 
			selection_func(tr_func);
			break;
		case 13:
			selectedFunc = true;
			if((tr_func == 1)||(tr_func == 2)){
				arcNeeded = true;
			}
			if(tr_func == 3){
				mode = 5;
			}
			if(tr_func == 4){
				mode = 6;
			}
			break;
		default://��ǿ�仯���Ӿ�Ч��
			selection_func(tr_func);
			break;
		}
	}
	
	if(arcNeeded){
	cout << "    ��������Ƕ�ֵ���ǻ���ֵ��" << endl; 
	cout << " >> �Ƕ�" << endl;
	cout << "    ����" << endl;
	}else{
		cout << "������ֵ�󰴻س�ȷ�ϣ�"<< endl; 
	}
	
	bool selectedUnit = false;
	short tr_unit = 1;
	
	while (!selectedUnit&&arcNeeded)
	{
		tc = _getch();
		clean();
		switch (tc)
		{
		case 72:
			while (tr_unit == 1)//��δ������ü�ͷ�ڵ�һ��ʱ��ת��������
				tr_unit = 3;
			tr_unit--;
			selection_unit(tr_unit);
			break;
		case 80:
			while (tr_unit == 2)//��δ������ü�ͷ�ڵ����һ��ʱ��ת����һ��
				tr_unit = 0;
			tr_unit++; 
			selection_unit(tr_unit);
			break;
		case 13:
			selectedUnit = true;
			if((tr_func == 1)&&(tr_unit == 1)){
				mode = 1;
			}else if((tr_func == 1)&&(tr_unit == 2)){
				mode = 2;
			}else if((tr_func == 2)&&(tr_unit == 1)){
				mode = 3;
			}else{
				mode = 4;
			}
			break;
		default://��ǿ�仯���Ӿ�Ч��
			selection_unit(tr_unit);
			break;
		}
	}
	return mode;
} 

//���ݲ�ͬģʽȷ�������ֵ 
float inputNum(int mode){
	float num;
	switch(mode){
		case 1://��ģʽ�û�ѡ����ǽǶ���ʽ�����sin 
			cout << "������Ƕȣ�" ;
			cin >> num ;	
			break;
		case 2://��ģʽ�û�ѡ����ǻ�����ʽ�����sin 
			cout << "�����뻡�ȣ�" ;
			cin >> num ; 
			break;
		case 3://��ģʽ�û�ѡ����ǽǶ���ʽ�����cos
			cout << "������Ƕȣ�" ;
			cin >> num ;
			break;
		case 4://��ģʽ�û�ѡ����ǻ�����ʽ�����cos
			cout << "�����뻡�ȣ�" ;
			cin >> num ;
			break;
		case 5://��ģʽ�û�ѡ�����arcsin
			cout << "�����뷴����ֵ(��ֵӦ��λ��-1��1֮��)��" ;
			cin >> num ;			
			break;
		case 6://��ģʽ�û�ѡ�����arctan
			cout << "�����뷴����ֵ��";
			cin >> num ;
			break;
	}
	return num;
}
//���� 
void calculate(float num, int mode){
	float result = 0;
	switch(mode){
		case 1://���sin��� 
			result = Sin(1,num);
			cout << endl<< "sin"<<num<<"��= "<<result<<endl;	
			break;
		case 2://���sin��� 
			result = Sin(2,num);
			cout << endl << " " << num << " rad = " << (num/PI)*180 << "��" ;
			cout << endl <<" sin"<<(num/PI)*180<<"��= "<<result<<endl;		
			break;
		case 3://���cos��� 
			result = cos(1,num);
			cout << endl <<" cos"<<num<<"��= "<<result<<endl;			
			break;
		case 4://���cos��� 
			result = cos(2,num);
			cout << endl <<  " " << num << " rad = " << (num/PI)*180 << "��" ;
			cout << endl <<" cos"<<(num/PI)*180<<"��= "<<result<<endl;		
			break;
		case 5://���artsin��� 
			result = arcsin(num);
			cout << endl <<" artsin"<<num<<" = "<<result<<endl;				
			break;
		case 6://���arctan��� 
			result = arctan(num);
			cout << endl <<" arctan"<<num<<" = "<<result<<endl;	
			break;
	}
	cout<< endl; 
	system("PAUSE");
	exit(0);
}
