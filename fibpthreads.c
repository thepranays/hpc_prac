#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int n;                          // size of fibonacci sequence.
int *fibseq;                    // array holds the value of each fibonacci term.
int i;                          // counter for the threads.

void *runn(void *arg);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("format is:./a.out <intgervalue>\n");
        return -1;
    }                         

    if (atoi(argv[1]) < 0)
    {
        printf("%d must be>=0\n", atoi(argv[1]));
        return -1;
    }                          

    n = atoi(argv[1]);
    fibseq = (int *)malloc(n * sizeof(int));
    pthread_t *threads = (pthread_t *) malloc(n * sizeof(pthread_t));
    pthread_attr_t attr;        // set of thread attribute

    pthread_attr_init(&attr);

    for (i = 0; i < n; i++)
    {
        pthread_create(&threads[i], &attr, runn, NULL);// creating threads.
         pthread_join(threads[i], NULL); //Waiting the threads to exit.

    }                           

   
    printf("Fibonacci sequence is:");
    int k;

    for (k = 0; k < n; k++)
    {
        printf("%d,", fibseq[k]);
    }                        
    return 0;
}                               

void *runn(void *arg)
{
    if (i == 0)
    {
        fibseq[i] = 0;
        pthread_exit(0);
    }                           
    if (i == 1)
    {
        fibseq[i] = 1;
        pthread_exit(0);
    }                         
    else
    {
       
        int p, pp, fibp, fibpp;

        fibseq[i] = fibseq[i - 1] + fibseq[i - 2];
      
        pthread_exit(0);      
    }                          
} 