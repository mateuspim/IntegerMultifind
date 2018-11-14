#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#include "foo.h"

#define cap 10000000 //capacidade total do array

//Funcao para procura dos valores dentro do array
void integerMultifinder(vintMulti * a)
{
    register long int i = 0;

    // printf("\nThread: Indo de:%d    ate:%d\n",a->ini,a->fim); // Debug.log(Mostrar os valores de inicio e fim de procura do array da thread atual)

    for(i=a->ini;i<a->fim;i++)
    {
        if (a->array[i]==a->nSearch)
        {
            a->array[i] = -2;
        }
    }
}

//Funcao da thread
void *integerMultifind(void *s){
    
    vintMulti * a = (vintMulti *)s;

    integerMultifinder(a);    

    pthread_exit(NULL);
}

//Funcao para inicializar a struct e o array
intMulti * initArray()
{
    intMulti * a;

    a = (intMulti *) malloc(sizeof(intMulti));
    
    a->array = (int *) calloc(cap,sizeof(int));
    a->top = 0;
    a->tam = cap;

    return a;
}

//Funcao para reallocar o tamanho total do array
void reallocArray(intMulti *a)
{
    a->tam += cap;
    a->array = (int *) realloc(a->array, a->tam * sizeof(int));
}

//Funcao para ler os valores do arquivo e inseri-los no array
void insertInteger(char *v,intMulti *a)
{
    FILE *fp;

    fp = fopen(v,"r");

    if (fp==NULL)
    {
        printf("\nArquivo nao encontrado: %s",v);
    }
    else
    {
        int scanned;

        while(fscanf(fp,"%d ",&scanned)!=EOF)
        {
            if  (a->top==a->tam)
            {
                reallocArray(a);
            }

            a->array[a->top++] = scanned;
        }
    }
    fclose(fp);
}

//Funcao para printar os valores do array
void printN(intMulti *a)
{
    for(register int i=0;i<a->top;i++)
    {
        printf("%d - ",a->array[i]);
    }

}

//Funcao para printar os valores do array apos a execucao das threads
void printNumArray(intMulti *a,char **v)
{
    puts("");

    int found = 0;
    long int lineNumber = 0;
    int file = 3;
    for(register long int i=0;i<a->top;i++)
    {

        if (a->array[i] == -1)                          // Se for -1, quer dizer que passou para um novo arquivo
        {
            printf("\n");
            printf("%s: ",v[file++]);
            lineNumber = 0;
            found = 0;
        }
        else if(a->array[i]== -2)                      // Se for -2, quer dizer que o elemento == elemento de busca                       
        {
            found = 1;
            printf("%d ",lineNumber);
        }
        else if (a->array[i+1]== -1 && found == 0)    // Se o valor do elemento proximo ao atual e nao tenha encontrada nada printa que naquele arquivo na tem o elemento procurado
        {
            printf("not_found");
        }

        lineNumber++;
    }

    if (found==0)               //Como o array nao termina com -1 ele acaba por nao passar no ultimo else if
        printf("not_found");
    
    puts("");
}


