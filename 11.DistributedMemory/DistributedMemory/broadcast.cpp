// Compile: mpicxx broadcast.cpp -o broadcast.x
// Execute: mpirun -np X ./broadcast.x
//

#include <iostream>
#include <mpi.h>

int main(){

  int size;
  int rank;
  int imesg;

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  imesg = rank;
  std::cout << "Before BCAST I'm: " << rank << " and my message content is: " << imesg << std::endl;

  MPI_Bcast(&imesg, 1, MPI_INT, 0, MPI_COMM_WORLD);
  
  std::cout << "After BCAST I'm: " << rank << " and my message content is: " << imesg << std::endl;

  MPI_Finalize();

  return 0;
}

// int size;
// número total de procesos que están participando en el comunicador (MPI_COMM_WORLD).

// int rank;
// identificador único del proceso (0, 1, 2, …, size - 1).

// int imesg;
// una variable de mensaje que se usará para demostrar la transmisión (broadcast).

// MPI_Init(NULL, NULL);
// Inicializa el entorno MPI. Debe ser la primera llamada en cualquier programa MPI (antes de usar cualquier otra función MPI).
 
// MPI_Comm_size(MPI_COMM_WORLD, &size);
// Determina cuántos procesos están participando en el comunicador MPI_COMM_WORLD.
//Ej: mpirun -np 4 ./programa
//Entonces size = 4

// MPI_Comm_rank(MPI_COMM_WORLD, &rank);
// Cada proceso obtiene su identificador (rank) dentro del comunicador.
//El proceso 0 tiene rank = 0
//El proceso 1 tiene rank = 1
//etc.

// imesg = rank;
// Cada proceso guarda su número de rank en la variable imesg.
// Proceso 0: imesg = 0
// Proceso 1: imesg = 1
// Proceso 2: imesg = 2
// etc.

// Antes del bcast, la impresion sera:
//Before BCAST I'm: 0 and my message content is: 0
//Before BCAST I'm: 1 and my message content is: 1
//Before BCAST I'm: 2 and my message content is: 2
//Before BCAST I'm: 3 and my message content is: 3


// MPI_Bcast(&imesg, 1, MPI_INT, 0, MPI_COMM_WORLD);
// MPI_Bcast  envía el mismo dato desde un proceso raíz a todos los demás.
// &imesg → dirección de la variable que se va a enviar/recibir.
// 1 → cantidad de elementos (aquí 1 entero).
// MPI_INT → tipo de dato (entero MPI).
// 0 → proceso raíz (el que emite el dato).
// MPI_COMM_WORLD → comunicador global (todos los procesos).
// En este caso:
// - El proceso 0 envía su valor de imesg (que es 0)
// - Todos los procesos (incluido el 0) reciben ese valor y lo almacenan en su variable imesg.
// - Después del MPI_Bcast, todas las copias de imesg en todos los procesos tendrán el valor del proceso raíz (0).

// Despues del bcast, la impresion sera:
// After BCAST I'm: 0 and my message content is: 0
// After BCAST I'm: 1 and my message content is: 0
// After BCAST I'm: 2 and my message content is: 0
// After BCAST I'm: 3 and my message content is: 0

// MPI_Finalize();
// Finaliza el entorno MPI, liberando recursos.
//
