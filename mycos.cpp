#include<stdio.h>
#include<math.h>
//#include<mycos.h>

double mycos(double x)
{
	int n;
	int sign;
	double deno, nume, term;
	double sum;
	sum = 1;
	nume = x * x;
	deno = 2;
	term = -nume / deno;
	sign = -1;
	n = 2;
	while (fabs(term) >= 1e-3)
	{
		sum += term;
		n += 2;
		sign = -sign;
		nume *= x * x;
		deno *= n * (n - 1);
		term = sign * nume / deno;
	}
	return sum;
}
