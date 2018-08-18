#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *Integer_multifind(void *arg){
    
    FILE *ftread;

    int line_number = 1,scanned;
    int nsearch = 28;
    char buf[12];

    ftread = fopen("rand.txt","r");
        printf("Linha(s): ");
    
        while (fgets(buf, sizeof buf, ftread) != NULL) {
         if (sscanf(buf, "%d", &scanned) != 1) break;
            if (scanned==nsearch){
                printf("%d ",line_number);  
            }
            line_number++;
        }


    return 0;
}

 // ./multifind 16 123 arq1.in arq2.in arq3.in 
int main (int argc, char *argv[]){
    
    //if (argc < 4){puts("Files missing");return 0;}
    
    time_t ini,fim;
    ini = time(NULL);
    
    int i;
    int NUM_THREADS = atoi(argv[1]);
    int nsearch = atoi(argv[2]);
    

    pthread_t threads[NUM_THREADS];

    for (i=0;i<NUM_THREADS;i++){
        pthread_create(&threads[i],NULL,Integer_multifind,NULL);
    }

    for (i=0;i<NUM_THREADS;i++){
        pthread_join(threads[i],NULL);
    }

    fim = time(NULL);

    puts("");
    printf("TEMPO: %ld",fim-ini);
    pthread_exit(NULL);
}