/*
 ============================================================================
 Name        : 7.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a simple program to print the created thread ids.
 Date        : 22 Sep, 2025
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
 * $ cc 7.c -lpthread
 * $ ./a.out
    Thread id is 138508639401664
    Thread id is 138508622616256
    Thread id is 138508631008960
*/
