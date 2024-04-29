/* Inclusao de bibliotecas */
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

/* Definicao de variaveis */
#define MASTER 0

int main(int argc, char *argv[]) {
    int numtasks, rank, dest, source, valor, tag = 1;
    MPI_Status Stat;
    FILE *pt_a;

    MPI_Init(&argc, &argv); // inicia prog paralelo
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks); // numtasks = quantidade de processos disparados
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // rank = identificacao do processo

    if (rank == MASTER) {
        // le valor da linha de comando
        valor = atoi(argv[1]);
        printf("valor de entrada = %d \n", valor);
        // abrir arquivo de saida
        if ((pt_a = fopen(argv[2], "w")) == NULL) {
            printf("Nao conseguiu abrir arquivo para escrita  \n");
            exit(1);
        }
        // escreve no arquivo
        fprintf(pt_a, "identificacao = %d valor = %d \n", rank, valor);

        // envia valor
        MPI_Send(&valor, 1, MPI_INTEGER, rank + 1, tag, MPI_COMM_WORLD);

        // recebe valor
        for (int i = 1; i < numtasks; i++) {
            MPI_Recv(&valor, 1, MPI_INTEGER, i, tag, MPI_COMM_WORLD, &Stat);
            fprintf(pt_a, "identificacao = %d valor = %d \n", i, valor);
        }
    } else {
        if (rank < numtasks - 1) {
            // valor + rank
            MPI_Recv(&valor, 1, MPI_INTEGER, rank - 1, tag, MPI_COMM_WORLD, &Stat);
            valor = valor + rank;
            // print teste
            printf("valor de saida %d = %d\n", rank, valor);
            MPI_Send(&valor, 1, MPI_INTEGER, rank + 1, tag, MPI_COMM_WORLD);
            MPI_Send(&valor, 1, MPI_INTEGER, MASTER, tag, MPI_COMM_WORLD);
        } else {
            MPI_Recv(&valor, 1, MPI_INTEGER, rank - 1, tag, MPI_COMM_WORLD, &Stat);
            valor = valor + rank;
            MPI_Send(&valor, 1, MPI_INTEGER, MASTER, tag, MPI_COMM_WORLD);
            printf("valor de saida %d = %d\n", rank, valor);
        }
    }

    printf("Identificação = %d valor %d\n", rank, valor);
    MPI_Finalize(); // termina prog paralelo
}
