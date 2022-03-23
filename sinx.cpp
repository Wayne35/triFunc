

#include <iostream>
#include <math.h>
using namespace std;

#define Pi (3.141592658)

float D2R(float deg) {
	return deg / 180.0 * Pi;
}


int main()
{
	int mode = 0;
	float rad, angle;
    cout << "mode: angle = 1, rad = 2. \n";
	cout << "mode = ";
	cin >> mode;
	if (mode == 1) {
		cout << "angle = ";
		cin >> angle;
		cout <<"sin("<<angle<<") = "<< sin(D2R(angle));
	}
	else
	{
		cout << "rad = ";
		cin >> rad;
		cout << "sin(" << rad << ") = " <<sin(rad);
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单


