#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main(){

    uint64_t n=1000000000;
    double x, y;
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    uint64_t in = 0;

    double pi;
#pragma omp parallel private(x, y)
{
  printf("Hilo: %d\n", omp_get_thread_num());
#pragma omp for reduction(+:in)

    for(uint64_t i = 0; i<n; i++){

      //x=rand_r(&seed)/(double)RAND_MAX;
      x=0.7;
      y=0.5;
      //y=rand_r(&seed)/(double)RAND_MAX;
      if(((x*x) + (y*y)) <= 1){
        in++;
      }
    }
}
    pi = (4*(double)in)/(double)n;

    printf("Pi = %.16f\n", pi);
}
