#include <iostream>
using namespace std;
float arctan(float x)
{
	float e = x;
	float sqr = x * x;
	float r = 0;
	int i = 1;
	while ((e / i > 1e-15)||(e / i < -1e-15))
	{
		float f = e / i;
		r = (i % 4 == 1) ? r + f : r - f;
		e = e * sqr;
		i += 2;
	}
	return r;
}



int main(float x)
{
	cin>>x;
    cout<<arctan(x);
    return 0;
}

