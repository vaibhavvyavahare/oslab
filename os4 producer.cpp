#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t emptySlots, full, mutexSem;
int buffer[5], in = 0, out = 0, item = 1;

void* producer(void*) {
    while (item <= 5) {
        sem_wait(&emptySlots);
        sem_wait(&mutexSem);
        buffer[in] = item;
        cout << "Produced item: " << item << endl;
        in = (in + 1) % 5;
        item++;
        sem_post(&mutexSem);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void* consumer(void*) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&full);
        sem_wait(&mutexSem);
        cout << "Consumed item: " << buffer[out] << endl;
        out = (out + 1) % 5;
        sem_post(&mutexSem);
        sem_post(&emptySlots);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t p, c;
    sem_init(&emptySlots, 0, 5);
    sem_init(&full, 0, 0);
    sem_init(&mutexSem, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}
