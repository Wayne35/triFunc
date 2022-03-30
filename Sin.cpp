/*
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int mode = 0;
	float input = 0.0, result;
	float D2R(float deg);
	float Sin(int mode, float input);
	cout << "Please enter a mode number: \n If you want to calculate function of sin(angle),please enter '1'.\n If sin(rad), please enter '2'. \n";
	cout << "mode = ";
	cin >> mode;
	result = Sin(mode, input);
	cout << result;
}
*/

/******Radian and Angle conversion function*********/
float D2R(float deg) {
	float result, Pi = 3.1415926;
	result = (deg / 180.0) * Pi;
	return result;
}

/******Sinx function*********/
float Sin(int mode, float input) {
	float result = 0;
	if (mode == 1)         //mode=1,sin(Angle)
	{
		float angle;
		cout << "angle = ";
		cin >> input;
		angle = input;
		result = sin(D2R(angle));
	}
	else if (mode == 2)    //mode=2,sin(Radian)
	{
		float rad;
		cout << "rad = ";
		cin >> input;
		rad = input;
		result = sin(rad);
	}
	else                   //mode=others,again
	{
		cout << "It's a wrong mode.Please enter '1' or '2'.\n";
		cin >> mode;
		result = Sin(mode, input);
	}
	return result;
}