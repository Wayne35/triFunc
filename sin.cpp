#include <iostream>
using namespace std;
#define PI 3.141592658

//�ȶ���һ���׳˺���
float fac(float n) {
	float f = 0;
	if (n == 1 || n == 0) f = 1; else f = fac(n - 1) * n;
	return f;
}
//һ��ָ������(�η�)
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
	if (mode == 1){               //�Ƕȼ���
		cout << "angle = ";
		cin >> input;
		if (abs(input) > 360) input = abs(input - (int)(input / 360) * 360);               //����Ƕ���������ж�
		result = sinus(input/180.0 * PI);
		if ((result - sin(input/180.0 * PI)) > 0.000001)result = 0;   //��⺯������Աȣ�������0.000001�����0����ʾerror
	}
	else if (mode == 2){          //���ȼ���
		cout << "rad = ";
		cin >> input;		
		if (abs(input) > (2 * PI))input = abs(input - ((int)(input / (2 * PI))) * 2 * PI); //����Ƕ���������ж�
		result = sinus(input);
		if ((result - sin(input)) > 0.000001)  result = 0;
	}
	else{                         //ģʽ������������
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

