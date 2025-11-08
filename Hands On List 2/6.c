/*
 ============================================================================
 Name        : 6.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a simple program to create three threads.
 Date        : 21 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void thread_func(void* arg) {
    printf("Thread id is %lu\n", pthread_self());
}

int main() {
    pthread_t threads[3];
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, (void*)thread_func, NULL);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
/* Output : 
 * $ cc 6.c -lpthread
 * $ ./a.out 
 	Thread id is 129990450476736
 	Thread id is 129990433691328
 	Thread id is 129990442084032 
*/
