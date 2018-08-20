#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct intMult{
    int nsearch;
    int NUM_THREADS;
    char txt[100];
}intMulti;

void prints(int x){
/*
    switch(x){
        case 1:
            puts("");
            puts("MAIN");
            printf("%s\n",a->txt);
            printf("%d\n",a->NUM_THREADS);
            printf("%d\n",a->nsearch);  
        break;
        case 2:
            puts("");
            puts("THREAD");
            printf("%s\n", ((intMulti *)s)->txt);
            printf("%d\n", ((intMulti *)s)->NUM_THREADS);
            printf("%d\n", ((intMulti *)s)->nsearch); 
        break;
        case default:
        break;
        
    }
    */
}

void *Integer_multifind(void *s){
    
    FILE *ftread;

    int line_number = 1,scanned;
    char buf[12];
    
    //prints(2);

    ftread = fopen(((intMulti *)s)->txt,"r");
        printf("%s: ", ((intMulti *)s)->txt);
        while (fgets(buf, sizeof buf, ftread) != NULL) {
         if (sscanf(buf, "%d", &scanned) != 1) break;
            if (scanned==((intMulti *)s)->nsearch){
                printf("%d ",line_number);  
            }
            line_number++;
        }

        puts(" ");

    return 0;
}


 //     0       1   2   3       4       5
 // ./multifind 16 123 arq1.in arq2.in arq3.in 
int main (int argc, char *argv[]){
    
    if (argc < 4){puts("Files missing");return 0;}
    
    time_t ini,fim;
    ini = time(NULL);
    int i;

    pthread_t threads[atoi(argv[1])];

    puts("Threads:");

    for (i=0;i<atoi(argv[1]);i++){
        
        printf("THREAD %d: \n",i);

        intMulti * a = (intMulti *) malloc(sizeof(intMulti));

        a-> NUM_THREADS = atoi(argv[1]);
        a-> nsearch = atoi(argv[2]);
        strcpy(a->txt,argv[i+3]);

        pthread_create(&threads[i],NULL,Integer_multifind,(void *)a);      
    }

    for (i=0;i<atoi(argv[1]);i++){
        pthread_join(threads[i],NULL);
    }

    fim = time(NULL);

    puts("");
    printf("TEMPO: %lds",fim-ini);
    //pthread_exit(NULL);

    return 0;
}
