#include <stdio.h>
#include <omp.h>

static long num_steps = 1000000000;
double step;

//https://www.youtube.com/watch?v=FQ1k_YpyG_A&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG&index=6
int main ()
{
	  int i;
	  double x, pi, sum = 0.0;
	  double inicio, fin;

	  step = 1.0/(double) num_steps;

        	 
	  inicio = omp_get_wtime();

	  for (i=1;i<= num_steps; i++){
		  x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }

	  pi = step * sum;
	  fin = omp_get_wtime() - inicio;
	  printf("\n valor de pi con %ld pasos es %lf y corrio en %lf segundos \n ",num_steps,pi,fin);
}	  





