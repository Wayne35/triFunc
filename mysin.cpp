#include<stdio.h>
#include<math.h>

double mysin(double x)
{
	int n;
	int sign;
	double res, item;
	const double epsilon = 0.0001;
	res = x;
	item = x * x * x / 6;
	sign = -1;
	n = 2;
	while (item > epsilon)
	{
		res = res + item * sign;
		item = item * x * x / ((2 * n) * (2 * n + 1));
		sign = -sign;
		n++;
	}
	return res;
}
