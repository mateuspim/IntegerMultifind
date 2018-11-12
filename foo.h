#ifndef foo
#define foo

typedef struct intMult
{
    int nSearch;
    int *array;
    long int top;
    long int tam;
}intMulti;

typedef struct intMult2
{
    int nSearch;
    int *array;
    long int ini;
    long int fim;
}vintMulti;


void *integerMultifind(void *s);            // Funcao da thread
void integerMultifinder(vintMulti * a);    // Funcao que a thread executa


intMulti * initArray();                       // Inicializacao da struct que contera o array e metadados do array
void reallocArray(intMulti *a);              // Caso a capacidade seja estourada, realloc + cap valores para a array
void insertInteger(char *v,intMulti *a);    // Funcao para leitura e insercao dos valores dentro do arquivo no array


void printN(intMulti *ini);                  // Funcao para printar os valores do array (usada para debug)
void printNumArray(intMulti *a,char **v);   // Funcao para printar os valores do array apos passarem pelas threads

#endif