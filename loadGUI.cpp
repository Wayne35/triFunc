#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include "loadGUI.h"
#include "trifuncs.h"
#define PI        3.14159265358979323846
#define X "    请选择你需要功能:"
#define A " >> 正弦计算sin"
#define B " >> 余弦计算cos"
#define C " >> 反正弦计算arcsin"
#define D " >> 反正切计算arctan"
#define E "    正弦计算sin"
#define F "    余弦计算cos"
#define G "    反正弦计算arcsin"
#define H "    反正切计算arctan"
#define I "    您是输入角度值还是弧度值？"
#define J " >> 角度"
#define K " >> 弧度"
#define M "    角度"
#define N "    弧度"
using namespace std;
void  selection_func(short tv)
{
	switch (tv)//列出所有可能
	{
	case 1://选项1
		cout << X << endl << A << endl << F << endl << G << endl << H << endl;
		break;
	case 2://选项2
		cout << X << endl << E << endl << B << endl << G << endl << H << endl;
			break;
	case 3://选项3
		cout << X << endl << E << endl << F << endl << C << endl << H << endl;
		break;
	case 4://选项4
		cout << X << endl << E << endl << F << endl << G << endl << D << endl;
		break;
	}
}
void  selection_unit(short tv)
{
	switch (tv)//列出所有可能
	{
	case 1://选项1
		cout << I << endl << J << endl << N << endl;
		break;
	case 2://选项2
		cout << I << endl << M << endl << K << endl;
			break;
	}
}
void clean() { system("cls"); }//调用system()实现屏幕刷新，“cls"是”清屏“命令
int loadGUI(){
	
	int mode = 1;
	cout << "    请选择你需要功能:" << endl; 
	cout << " >> 正弦计算sin " << endl;
	cout << "    余弦计算cos " << endl;
	cout << "    反正弦计算arcsin " << endl;
	cout << "    反正切计算arctan " << endl;
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
			while (tr_func == 1)//这段代码是让箭头在第一项时跳转到第四项
				tr_func = 5;
			tr_func--;
			selection_func(tr_func);
			break;
		case 80:
			while (tr_func == 4)//这段代码是让箭头在第最后一项时跳转到第一项
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
		default://增强变化的视觉效果
			selection_func(tr_func);
			break;
		}
	}
	
	if(arcNeeded){
	cout << "    您是输入角度值还是弧度值？" << endl; 
	cout << " >> 角度" << endl;
	cout << "    弧度" << endl;
	}else{
		cout << "请输入值后按回车确认："<< endl; 
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
			while (tr_unit == 1)//这段代码是让箭头在第一项时跳转到第四项
				tr_unit = 3;
			tr_unit--;
			selection_unit(tr_unit);
			break;
		case 80:
			while (tr_unit == 2)//这段代码是让箭头在第最后一项时跳转到第一项
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
		default://增强变化的视觉效果
			selection_unit(tr_unit);
			break;
		}
	}
	return mode;
} 

//根据不同模式确定输入的值 
float inputNum(int mode){
	float num;
	switch(mode){
		case 1://该模式用户选择的是角度形式输入的sin 
			cout << "请输入角度：" ;
			cin >> num ;	
			break;
		case 2://该模式用户选择的是弧度形式输入的sin 
			cout << "请输入弧度：" ;
			cin >> num ; 
			break;
		case 3://该模式用户选择的是角度形式输入的cos
			cout << "请输入角度：" ;
			cin >> num ;
			break;
		case 4://该模式用户选择的是弧度形式输入的cos
			cout << "请输入弧度：" ;
			cin >> num ;
			break;
		case 5://该模式用户选择的是arcsin
			cout << "请输入反正弦值(该值应该位于-1到1之间)：" ;
			cin >> num ;			
			break;
		case 6://该模式用户选择的是arctan
			cout << "请输入反正切值：";
			cin >> num ;
			break;
	}
	return num;
}
//计算 
void calculate(float num, int mode){
	float result = 0;
	switch(mode){
		case 1://输出sin结果 
			result = Sin(1,num);
			cout << endl<< "sin"<<num<<"°= "<<result<<endl;	
			break;
		case 2://输出sin结果 
			result = Sin(2,num);
			cout << endl << " " << num << " rad = " << (num/PI)*180 << "°" ;
			cout << endl <<" sin"<<(num/PI)*180<<"°= "<<result<<endl;		
			break;
		case 3://输出cos结果 
			result = cos(1,num);
			cout << endl <<" cos"<<num<<"°= "<<result<<endl;			
			break;
		case 4://输出cos结果 
			result = cos(2,num);
			cout << endl <<  " " << num << " rad = " << (num/PI)*180 << "°" ;
			cout << endl <<" cos"<<(num/PI)*180<<"°= "<<result<<endl;		
			break;
		case 5://输出artsin结果 
			result = arcsin(num);
			cout << endl <<" artsin"<<num<<" = "<<result<<endl;				
			break;
		case 6://输出arctan结果 
			result = arctan(num);
			cout << endl <<" arctan"<<num<<" = "<<result<<endl;	
			break;
	}
	cout<< endl; 
	system("PAUSE");
	exit(0);
}
