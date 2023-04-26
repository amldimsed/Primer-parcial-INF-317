#include "stdio.h"
#include "omp.h"
#include "math.h"

void main(){
	
    long contador,n=1000;
    double sum = 0.0,fac=1.0;
 
    #pragma omp parallel for shared( sum )
    for (contador=0; contador<n; contador++){
	   sum+=pow(-1,contador) / (2 * contador + 1);
    	}
    	sum*=4.0;

    printf("%f\n", sum);	
}
/*
gcc omp_pi_numero.c -o omp_pi_numero -fopenmp -lm
./omp_pi_numero


*/
