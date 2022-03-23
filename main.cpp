#include<iostream>
#include "loadGUI.h"
using namespace std;

int main(){
	int mode = loadGUI();
	float num = inputNum(mode);
	cout << num;
}
