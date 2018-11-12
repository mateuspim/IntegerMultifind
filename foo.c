#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#include "foo.h"

#define cap 1000000 //capacidade total do array

void integerMultifinder(vintMulti * a)
{
    register int i = 0;

    printf("\nIndo de:%d    ate:%d\n",a->ini,a->fim);

    for(i=a->ini;i<a->fim;i++)
    {
        if (a->array[i]==a->nSearch)
        {
            a->array[i] = -2;
        }
    }
}

void *integerMultifind(void *s){
    
    vintMulti * a = (vintMulti *)s;

    integerMultifinder(a);    

    pthread_exit(NULL);
}

intMulti * initArray()
{
    intMulti * a;

    a = (intMulti *) malloc(sizeof(intMulti));
    
    a->array = (int *) calloc(cap,sizeof(int));
    a->top = 0;
    a->tam = cap;

    return a;
}

void reallocArray(intMulti *a)
{
    a->tam += cap;
    a->array = (int *) realloc(a->array, a->tam * sizeof(int));
}

void insertInteger(char *v,intMulti *a)
{
    FILE *fp;
    fp = fopen(v,"r");

    int scanned;

    while(fscanf(fp,"%d ",&scanned)!=EOF)
    {
        if  (a->top==a->tam)
        {
            reallocArray(a);
        }

        a->array[a->top++] = scanned;
    }

    fclose(fp);
}


void printN(intMulti *a)
{
    for(register int i=0;i<a->top;i++)
    {
        printf("%d - ",a->array[i]);
    }

}

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


