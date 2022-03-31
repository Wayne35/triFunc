#include <iostream>
using namespace std;
#define PI 3.141592658

//先定义一个阶乘函数
float fac(float n) {
	float f = 0;
	if (n == 1 || n == 0) f = 1; else f = fac(n - 1) * n;
	return f;
}
//一个指数函数(次方)
float kvat(float n, float ci) {
	float chengf = 1;
	for (int i = 1; i <= ci; i++) chengf = chengf * n;
	return chengf;
}
float sinus(float x) {
	int z = -1,j = 1;
	float sin = x;
	for (j = 3; fabs(kvat(x, j) / fac(j)) > 0.000001; j += 2) {
		sin = sin + z * (kvat(x, j) / fac(j));
		z = -z;
	}
	return sin;
}


float Sin(int mode, float input) {
	float result = 0;
	if (mode == 1){               //角度计算
		cout << "angle = ";
		cin >> input;
		if (abs(input) > 360) input = abs(input - (int)(input / 360) * 360);               //输入角度周期溢出判断
		result = sinus(input/180.0 * PI);
		if ((result - sin(input/180.0 * PI)) > 0.000001)result = 0;   //与库函数结果对比，误差大于0.000001，输出0，表示error
	}
	else if (mode == 2){          //弧度计算
		cout << "rad = ";
		cin >> input;		
		if (abs(input) > (2 * PI))input = abs(input - ((int)(input / (2 * PI))) * 2 * PI); //输入角度周期溢出判断
		result = sinus(input);
		if ((result - sin(input)) > 0.000001)  result = 0;
	}
	else{                         //模式错误，重新输入
		cout << "It's a wrong mode.Please enter '1' or '2'.\n ";
		cin >> mode;
		result = Sin(mode, input);
	}
	return result;
}
/*
int main() {
	int mode;
	float input=0,result = 0.0;
	cout << "This is the calculation of sin(x) function.\n";
	cout << "If you want to enter a angle, please enter '1'.\n";
	cout << "If you want to enter a radian, please enter '2'. \n";
	cin >> mode;
	result = Sin(mode, input);
	cout << "result = " << result << "\n";
	return 0;
}
*/

