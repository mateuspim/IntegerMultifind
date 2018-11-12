#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#include "foo.h"

int nThreads = 0;       // number of Threads
int cThreads = 0;      // current Thread
int arrayIndex = 0;   // valor base para inicio e fim da busca pelo array

 //     0       1   2   3       4       5
 // ./multifind 16 123 arq1.in arq2.in arq3.in 
int main (int argc, char *argv[])
{
    
    register int i;

    struct timeval start, stop;                          // VARIAVEIS DE TEMPO
    double secsLeitura,secsThreads,secsPrint,secsTotal; // iniciando variaveis para alocar o tempo

    //Inicio da etapa de leitura dos arquivos

    gettimeofday(&start, NULL); 

    intMulti * ini = initArray(); // Inicializar o intmult e vetor de int com &cap valores
    
    nThreads = atoi(argv[1]);       // numero de Threads
    ini->nSearch = atoi(argv[2]);   // numero de busca

    for (i = 3;i<argc;i++) // Leitura e inserircao os valores
    {
        (ini->array[ini->top]) = -1;    // valor para delimitar os sub-array de cada arquivo de entrada
        ini->top++;
        insertInteger(argv[i],ini);
    }
  
    //printf("\nTOP: %d   TAM:%d\n\n",ini->top,ini->tam); // debug.log(Mostrar tam e o indice do ultimo elemento da struct)

    vintMulti *vInt[nThreads];            // Struct passada a Thread com inicio e fim
    arrayIndex = ini->top/nThreads;       // Valor base para o vetor

    for(i = 0;i<nThreads;i++)       // Criando e passando os valores inicias e finais de busca para as struct struct que, por sua vez, sera passada para a thread
    {
        vInt[i] = (vintMulti *) malloc(sizeof(vintMulti));
        vInt[i]-> nSearch = atoi(argv[2]);
        vInt[i]-> array = ini->array;

        if (i==0)       // Se for o primeiro, inicio = 0 fim = valor base;
        {
            vInt[i]->ini = 0;
            vInt[i]->fim = arrayIndex;
        }
        else if (i==nThreads-1) // Se for o ultimo, inicio = valor base * (valor ultima thread - 1) fim = ultimo indice do vetor
        {
            vInt[i]->ini = (nThreads - 1)*arrayIndex;
            vInt[i]->fim = ini->top;
        }
        else        // Se nao ,para as struct intermediarias, inicio = valor da thread atual * valor o base fim = (valor da thread atual + 1) * valor o base
        {
            vInt[i]->ini = (cThreads)*arrayIndex;
            vInt[i]->fim = (cThreads + 1)*arrayIndex;
        }
        cThreads++;
        //printf("vintMulti[%d]   -> Inicio: %d    fim: %d\n",i,vInt[i]->ini,vInt[i]->fim); // Debug.log(Mostra os valores inicio e fim para cada struct)
    }


	gettimeofday(&stop, NULL);

    secsLeitura = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    
    //Fim da etapa de leitura dos arquivos

    //Inicio da etapa da construcao e execucao das THREADS
	
    gettimeofday(&start, NULL);

    pthread_t threads[nThreads]; // Iniciacao das threads

    for (i=0;i<nThreads;i++)
       pthread_create(&threads[i],NULL,integerMultifind,(void *)vInt[i]); 
          
    for (i=0;i<nThreads;i++)
       pthread_join(threads[i],NULL);

    gettimeofday(&stop, NULL);

    secsThreads = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

    //Fim da etapa da construcao e execucao das THREADS

    //Inicio da etapa final -> printar o resultado na tela

    gettimeofday(&start, NULL);

    printNumArray(ini,argv); //Print final
    
    gettimeofday(&stop, NULL);

    secsPrint = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

    //Fim da etapa final -> printar o resultado na tela

    //Fim da execucao do programa mostrando os valores de tempo para cada etapa do programa
    secsTotal = secsLeitura + secsThreads + secsPrint;
    printf("\n\nTempo total: %fs\n",secsTotal);
    printf("Tempo para leitura: %fs\n",secsLeitura);
    printf("Tempo das threads: %fs\n",secsThreads);
    printf("Tempo para print final: %fs\n",secsPrint);

    pthread_exit(NULL);

    return 0;
}

