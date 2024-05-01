#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the total number of processes and the rank of the current process
    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Print "Hello World" from each process
    printf("Hello World from process %d of %d\n", world_rank, world_size);

    // Finalize MPI
    MPI_Finalize();

    return 0;
}