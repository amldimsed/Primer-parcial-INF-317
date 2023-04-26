#include "stdio.h"
#include "mpi.h"
#include "math.h"

void main(){
	int numero_procesadores, procesador_activo;
	unsigned long long fibo1[1000], contador;
	
	MPI_Init(NULL, NULL);
    
    	MPI_Comm_size(MPI_COMM_WORLD, &numero_procesadores);
    	MPI_Comm_rank(MPI_COMM_WORLD, &procesador_activo);
    	
    	if(procesador_activo==0){
    		MPI_Recv(fibo1,1000,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		
    		for(contador=0;contador<1000;contador++)
    			printf("%llu ",fibo1[contador]);

    	}
    	
    	if(procesador_activo==1){
    		for(contador=0;contador<1000;contador++){
    			fibo1[contador]=(pow((1+sqrt(5))/2,contador) - pow((1-sqrt(5))/2,contador))/sqrt(5);
    		}
    		MPI_Send(fibo1,1000,MPI_INT,0,0,MPI_COMM_WORLD);
    	
    	}
    	
    	
    	MPI_Finalize();

}
/*
mpicc fibonacci.c -o fibonacci -lm
mpirun -np 2 fibonacci


gcc fibonacci.c -o fibonacci -lm
./fibonacci

*/
