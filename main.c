#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <omp.h>
#define SEED 123456
unsigned int seed = 676767676 ;

//Random number generator with linear congruential generator
double randUint( long i ){

    seed = seed * 1103515245 + 123456;

    return seed / (double)UINT_MAX ;
}


int main()
{
    int N=0;
    long count=0;
    double pi;
    printf("Enter number of interactions used to estimation Pi :  ");
    scanf("%d",&N);
    //Init Parallelazation with reduction techinue
#pragma omp parallel for reduction(+: count)
    for (long i=0; i<N; i++) {


        //Getting the coordinates y,x ε [0,1]
        double x,y;
        x = randUint(i);
        y = randUint(i);

        //Checking if in unit circle
        if (x*x+y*y <= 1) count++;


    }

    //Calcuting the ratio and as a result the pi
    pi=(double)count/N * 4.0;

    printf("OpenMP : # of trials = %14ld , estimate of pi is %1.16f AND an absolute error of %g\n",N,pi,fabs(pi - M_PI));

    return 0;
}
