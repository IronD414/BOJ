#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sum(int* a, int n);
int rounding(double x);
int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
	int n, i, cut, result;
	int *a, *b; 

	// input field
	scanf(" %d", &n);
	if (n == 0)
	{
		printf("0");
		return 0;
	}
	a = (int*) malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf(" %d", &a[i]);
	qsort(a, n, sizeof(int), cmpfunc);

	// cut 30%
	cut = rounding(n*0.15);
	n -= 2*cut;
	b = (int*) malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		b[i] = a[i+cut];
	free(a);

	// calculate mean
	result = rounding(sum(b, n)/n);
	printf("%d", result);
	free(b);
	return 0;
}

double sum(int* a, int n)
{
	double result = 0;
	for (int i = 0; i < n; ++i)
	{
		result += a[i];
	}
	return result;
}

int rounding(double x)
{
	double y = 10*(x - floor(x));
	if (y < 5) return floor(x);
	else return ceil(x);
}