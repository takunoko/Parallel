#include <stdio.h>
#include <mpi.h>

int main(int argc, const char **argv)
{
	MPI_Init(NULL, NULL);

	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	char prosessor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(prosessor_name, &name_len);

	printf("Hello world from processor %s, rak %d"
			"out of %d processors\n",
			prosessor_name, world_rank, world_size);

	MPI_Finalize();

	return 0;
}
