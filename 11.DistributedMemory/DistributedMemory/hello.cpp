//Compile:  mpicxx hello.cpp -o hello.x
// Execute: mpirun -np X ./hello.x 

#include <iostream>
#include <mpi.h>

int main(){

  int size;
  int rank;

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  std::cout << "Hello from process: " << rank << " of size: " << size << std::endl;

  MPI_Finalize();

  return 0;
}

// int size;
// Declara una variable entera size que almacenará el número total de procesos que participan en el comunicador (es decir, el número de ranks en MPI_COMM_WORLD).
//
// int rank;
// Declara una variable entera rank que almacenará el identificador (ID) del proceso actual. Los ranks van típicamente de 0 a size-1.
//
// MPI_Init(NULL, NULL);
// - Inicializa el entorno MPI. Debe llamarse antes de cualquier otra función MPI.
// - Los parámetros normalmente son &argc, &argv si quieres que MPI procese argumentos de la línea de comandos; aquí se pasan NULL, NULL porque no se envían argumentos a MPI.
// - Después de esta llamada, las funciones MPI están disponibles.
//
// MPI_Comm_size(MPI_COMM_WORLD, &size);
// - Consulta cuántos procesos hay en el comunicador MPI_COMM_WORLD (el comunicador global que incluye a todos los procesos lanzados con mpirun/mpiexec) y escribe ese número en la variable size.
// - MPI_COMM_WORLD es un objeto que representa el grupo global de todos los procesos.
//
// MPI_Comm_rank(MPI_COMM_WORLD, &rank);
// Obtiene el identificador (rank) del proceso que ejecuta esta línea dentro de MPI_COMM_WORLD y lo guarda en rank. Cada proceso que corre este programa obtiene su propio rank distinto.
//
// MPI_Finalize();
// Finaliza el entorno MPI. Ninguna llamada MPI (excepto quizá funciones de consulta muy básicas) debe hacerse después de MPI_Finalize. Libera recursos internos de MPI y sincroniza la finalización del runtime MPI.
