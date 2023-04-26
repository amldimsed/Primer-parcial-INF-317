#include "stdio.h"
#include "omp.h"
#include "math.h"

void main(){
	
     int N=100;
     int size, rank; 
     int i, j, k, contador=1; 
     int numero_procesadores, procesador_activo;
     long a[N][N], b[N][N], c[N][N];
 
    #pragma omp parallel for shared( c )
    //preparacion de la matriz
    for (i = 0; i < N; i++) { 
             for (j = 0; j < N; j++) { 
                 a[i][j] = contador; 
                 b[i][j] = contador;
                 contador++; 
             } 
         }

    //multiplicacion de la matriz
     for (k = 0; k < N; k++) {
      
        for (i = 0; i < N; i++) {
            int suma = 0;
     
            for (j = 0; j < N; j++) {
             
                suma += a[i][j] * b[j][k];
            }
       
            c[i][k] = suma;
        }
        
    }
    //mostrar matriz
    for (i = 0; i < N; i++) { 
             for (j = 0; j < N; j++) { 
                 printf("%ld ", c[i][j]); 
             } 
             printf("\n"); 
         } 	
}
/*
gcc omp_pi_matriz.c -o omp_pi_matriz -fopenmp
./omp_pi_matriz
*/
