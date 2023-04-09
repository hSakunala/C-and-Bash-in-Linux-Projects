#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

unsigned long long trmThrdRatio;
long threadCount;
long double *singleThrd;


void *thrdWrkings(void *arg)
{
    unsigned long rank = (unsigned long) arg;
    unsigned long long begg = trmThrdRatio * rank;
    unsigned long long fin = trmThrdRatio * rank + trmThrdRatio;

    for (unsigned long long x = begg; x < fin; ++x) {
        long double num= (1.0 / ((2.0 * x) + 1));
        if (x % 2 == 0) 
            singleThrd[rank] = singleThrd[rank] + num;
         else 
            singleThrd[rank] = singleThrd[rank] - num;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Need to specify both the number of threads and number of terms\n");
        return 0;
    }
    threadCount = strtol(argv[1], NULL, 10);
    unsigned long long terms = strtoull(argv[2], NULL, 10);

    singleThrd = malloc(threadCount * sizeof(long double));
    pthread_t *threads = malloc(threadCount * sizeof(pthread_t));
    trmThrdRatio = terms / threadCount;
    for (int x = 0; x < threadCount; ++x)
        pthread_create(&threads[x],NULL,thrdWrkings,((void *) (unsigned long) x));
    
    long double threadedPI = 0.0;
    for (int x = 0; x < threadCount; ++x) {
        pthread_join(threads[x], NULL);
        threadedPI += singleThrd[x];
    }
    threadedPI = threadedPI * 4;

    printf("                       Actual Number for PI : 3.14159265358979323846\n");
    printf("Resulting PI with %ld thread(s) and %llu term(s) : %.20Lf\n", threadCount, terms, threadedPI);
}
