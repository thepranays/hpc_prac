#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int shared_variable = 0;
pthread_mutex_t mutex;

void *thread_function(void *arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);

        shared_variable++;
        printf("Thread %d: Shared Variable = %d\n", (int)arg, shared_variable);

        pthread_mutex_unlock(&mutex);

        usleep(1000000);
    }

    pthread_exit(NULL);
}

int main() {
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        return EXIT_FAILURE;
    }

    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, thread_function, (void *)1) != 0 ||
        pthread_create(&thread2, NULL, thread_function, (void *)2) != 0) {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}