#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define fname "final.in"

typedef struct intMult{
    int nsearch;
    char v[100];
    FILE * fp;
    struct intMult * prox;
}intMulti;


int Inserir_fim_LS     (intMulti **inicio, char * v,int n);
int Listar_LS          (intMulti *inicio,intMulti *v[]);
void *Integer_multifind(void *s);
void writeList();
void iniList();



void *Integer_multifind(void *s){
    
    FILE *ftread;

    register int lineNumber = 1;
    register int nScanned = 0;
    int scanned;

    intMulti * a = (intMulti *)s;
    
    FILE * fp;
    fp = fopen(fname,"a");
    printf("%s: ",a->v);
    fprintf(fp,"%s: ",a->v);

    while (fscanf(a->fp,"%d ",&scanned)!=EOF)
    {
        if (scanned==(int)(a->nsearch))
        {
            fprintf(fp,"%d ",lineNumber);
            nScanned++;
        }
        lineNumber++; 
    }
    
    if (nScanned==0)
        fprintf(fp,"not_found");
    fprintf(fp,"\n");

    fclose(fp);
    fclose(a->fp);
    free(a);        

    pthread_exit(EXIT_SUCCESS);
}

    
 //     0       1   2   3       4       5
 // ./multifind 16 123 arq1.in arq2.in arq3.in 
int main (int argc, char *argv[])
{
    
    //if (argc < 4){puts("Files missing");return 0;}
    iniList();

    time_t inicial,fim;
    
    register int i = 0;

    intMulti * ini = NULL;
    intMulti * v[argc-3];

    for (i = 3;i<argc;i++)
       Inserir_fim_LS (&ini, argv[i],atoi(argv[2]));
     
    Listar_LS (ini,v);

    pthread_t threads[atoi(argv[1])];
    
    puts("");
    puts("Threads: ");
    puts("");

    inicial = time(NULL);

   // printf("\n\n%d\n\n",argc-3);

    for (i=0;i<atoi(argv[1]);i++)
    {
       pthread_create(&threads[i],NULL,Integer_multifind,(void *)v[i]); 
          
    }

    for (i=0;i<atoi(argv[1]);i++)
    {
       pthread_join(threads[i],NULL);
    }

    fim = time(NULL);

    puts("");
    writeList();
    puts("");
    printf("TEMPO total: %lds   ini: %lds   fim: %lds",fim-inicial,inicial,fim);
    
    
    return 0;
}


int Inserir_fim_LS (intMulti **inicio, char * v,int n)
{
    intMulti *no_novo, *percorre;
    FILE * fp;

    fp = fopen(v,"r");
    if (fp == NULL)
    {
        printf("\nArquivo nao encontrado ou com falhas: %s\n",v);
        return 0;
    }
    else
    {

    no_novo = (intMulti *) malloc(sizeof(intMulti));

    strcpy(no_novo->v,v);
    no_novo -> fp = fp;
    no_novo -> prox = NULL;
    no_novo -> nsearch = n;
            
    if (*inicio==NULL)
	{ 
	    *inicio = no_novo;
	}
	else 
    { 
	     percorre = *inicio;
	     while (percorre->prox != NULL)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}

    }
	return 0;
}

int Listar_LS (intMulti *inicio,intMulti *v[])
{
	int i = 0;
	if (inicio == NULL)
	{
        return 1;  
	}
    printf("LISTANDO ::  ");
	while (inicio != NULL) {

        v[i] = inicio;
		printf("%s  ",v[i]->v);
        //printf("%d  ",v[i]->fp);
		inicio = inicio->prox;
        i++;
    }
    printf("\n");
	return 0; 
} 

void writeList()
{
    char ch;
    FILE * fp;
    fp = fopen(fname,"r");

    while (fscanf(fp,"%c",&ch)!=EOF)
        putchar(ch);
    fclose(fp);
}

void iniList()
{
    FILE * fp;
    fp = fopen(fname,"w");
    fclose(fp);

}
