#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include "loadGUI.h"
#include "trifuncs.h"
using namespace std;


int main(){
	int mode = loadGUI();
	float num = inputNum(mode);	
	calculate(num,mode);
}
