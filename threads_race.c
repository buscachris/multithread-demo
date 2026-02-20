#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10
#define NUM_INCREMENTS 1000

int shared_counter = 0;
pthread_mutex_t counter_mutex;

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < NUM_INCREMENTS; i++) {int temp = shared_counter;
        usleep(10000);
        shared_counter = temp + 1;

        printf("Thread %d incremented shared_counter to %d\n",
               thread_id, shared_counter);usleep(15000);
    }

    printf("--> Thread %d has terminated.\n", thread_id);
    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    if (pthread_mutex_init(&counter_mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        return 1;
    }

    printf("Main process starting %d threads...\n\n", NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        int* thread_id = malloc(sizeof(int));
        *thread_id = i + 1;

        if (pthread_create(&threads[i], NULL,
                           thread_function, thread_id) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&counter_mutex);

    int expected_value = NUM_THREADS * NUM_INCREMENTS;

    printf("\nAll threads terminated.\n");
    printf("Final shared_counter value: %d (Expected: %d)\n",
           shared_counter, expected_value);

    return 0;
}
