#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define dx 0.000001

int main()
{
	int i;
	int t = 1 / dx;
	double x, f;
	double pi = 0.0;
	double init, fin;

	init = omp_get_wtime();
	for(i = 0; i < t; i++)
	{
		x = (i + 0.5) * dx;
		f = 4.0 / (1.0 + x * x);
		pi = pi + f;
	}
	fin = omp_get_wtime();
	
	pi *= dx;
	printf("El valor de pi es %.13f, calculado en %fs.\n", pi, fin - init);
}

