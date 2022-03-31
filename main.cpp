#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include "loadGUI.h"
#include "trifuncs.h"
#include <math.h>
#define PI 3.141592658
using namespace std;


int main(){
	int mode = loadGUI();
	float num = inputNum(mode);	
	calculate(num,mode);
		system("PAUSE");
	system("cls");
	main();
}
