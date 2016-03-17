#include "mpi.h"

int main(int argc, char **argv)
{
	MPI_Init(&argc,&argv);

 	int rank,size;
	MPI_Status status;
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	//status=
	

	int message1,message = 120;

	if (rank==0)
	{
		MPI_Send(&message, 1, MPI_INT, 1,0,MPI_COMM_WORLD);

      	}
	else if(rank==1)
	{
		MPI_Recv(&message1, 1,MPI_INT,0,0,MPI_COMM_WORLD, &status);
		printf("Message %d", message1);
	}

	MPI_Finalize();
        return 0;
}
	
