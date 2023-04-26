#include "stdio.h"
#include "mpi.h"
#include "math.h"

void main(){
	int numero_procesadores, procesador_activo;
	long long contador,n=1000;
	double fac=1.0, sum=0.0;
	
	MPI_Init(NULL, NULL);
    
    	MPI_Comm_size(MPI_COMM_WORLD, &numero_procesadores);
    	MPI_Comm_rank(MPI_COMM_WORLD, &procesador_activo);
    	
    	if(procesador_activo==0){
    		MPI_Recv(&sum,1,MPI_DOUBLE,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		
    			printf("%f\n",sum);

    	}
    	
    	if(procesador_activo==1){
    		for (contador=0; contador<n; contador++){
    			sum+=pow(-1,contador) / (2 * contador + 1);
    		}
    		sum*=4.0;
    		MPI_Send(&sum,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
    	
    	}
    	
    	
    	MPI_Finalize();

}
/*
mpicc pi_numero.c -o pi_numero -lm
mpirun -np 2 pi_numero


gcc pi_numero.c -o pi_numero.c -lm
./fibonacci

*/
