#include <iostream>
#include <mpi.h>

int main(){

  int size, rank; // parametros comunicador
  int sendbuff, recvbuff;

  int tag = 0; // es como ponerle un numero a cada 'carta'. Es tag es como un ID

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  sendbuff = rank;
  MPI_Status stat; // para mantener ordenados los protocolos de recepcion de mensajes

  if(size != 2) MPI_Abort(MPI_COMM_WORLD, 1); // no solamente trabajar con 2 procesos

  if(rank == 0){
    MPI_Ssend(&sendbuff, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
    MPI_Recv(&recvbuff, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &stat);
  }
  else if(rank == 1){
    // Este es el orden correcto
    MPI_Recv(&recvbuff, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &stat);
    MPI_Ssend(&sendbuff, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
  }

  std::cout << "I'm: " << rank << " and my recv is: " << recvbuff << std::endl;

  MPI_Finalize();

  return 0;
}

// int size;
// número total de procesos en el comunicador (MPI_COMM_WORLD).

// int rank;
// identificador (número) de este proceso dentro del comunicador — va de 0 a size-1.

// int sendbuff;
//int sendbuff, recvbuff;

// int recvbuff;
// variable local donde se almacenará el dato recibido.

// int tag = 0;
// ID del  mensaje. Permite etiquetar distintos tipos de mensajes para diferenciarlos al recibir.

// MPI_Init(NULL, NULL);
// Inicializa el entorno MPI. Debes llamar a esto antes de cualquier otra función MPI.
// Los argumentos NULL indican que no se pasan argumentos de línea de comando a MPI (otra forma es MPI_Init(&argc,&argv)).

// MPI_Comm_size(MPI_COMM_WORLD, &size);
// escribe en size el número total de procesos del comunicador MPI_COMM_WORLD.

// MPI_Comm_rank(MPI_COMM_WORLD, &rank);
// escribe en rank el identificador de este proceso dentro de MPI_COMM_WORLD.

// sendbuff = rank;
// Se asigna sendbuff = rank; para que cada proceso envíe su propio rank (simple ejemplo).

// MPI_Status stat;
// objeto usado en las recepciones (MPI_Recv) para conocer detalles del mensaje recibido (fuente, tag, tamaño real, etc.).

//
//
//
//
//
//
