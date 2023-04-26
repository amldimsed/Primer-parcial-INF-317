#include "stdio.h"
#include "mpi.h"
  
void main() 
 { 
     int N=100;
     int size, rank; 
     int i, j, k, contador=1; 
     int numero_procesadores, procesador_activo;
     long a[N][N], b[N][N], c[N][N];
      
  
      
     MPI_Init(NULL,NULL); 
  
     MPI_Comm_rank(MPI_COMM_WORLD, &procesador_activo); 
  //inicializa la matriz 'a' y la matriz 'b' desde 1 a 100
     if (procesador_activo == 1) { 
        for (i = 0; i < N; i++) { 
             for (j = 0; j < N; j++) { 
                 a[i][j] = contador; 
                 b[i][j] = contador;
                 contador++; 
             } 
         }
         MPI_Send(a,N*N,MPI_LONG,2,0,MPI_COMM_WORLD);
         MPI_Send(b,N*N,MPI_LONG,2,0,MPI_COMM_WORLD);
     } 
    
    if (procesador_activo == 2) { 
    MPI_Recv(a,N*N,MPI_LONG,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    MPI_Recv(b,N*N,MPI_LONG,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
         for (k = 0; k < N; k++) {
      
        for (i = 0; i < N; i++) {
            int suma = 0;
     
            for (j = 0; j < N; j++) {
             
                suma += a[i][j] * b[j][k];
            }
       
            c[i][k] = suma;
        }
        
    	}
    	MPI_Send(c,N*N,MPI_LONG,0,0,MPI_COMM_WORLD);
    }
         
     if (procesador_activo == 0) { 
         MPI_Recv(c,N*N,MPI_LONG,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
         for (i = 0; i < N; i++) { 
             for (j = 0; j < N; j++) { 
                 printf("%ld ", c[i][j]); 
             } 
             printf("\n"); 
         } 
     } 
  
     MPI_Finalize(); // finalización de MPI 
 }
 /*
 mpicc mpi_matrz.c -o mpi_matrz
 mpirun -np 4 mpi_matrz
 */
 
 
