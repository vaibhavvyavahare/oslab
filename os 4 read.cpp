#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t wrt;
pthread_mutex_t mutex;
int readCount = 0, sharedData = 0;  // renamed from 'data' to 'sharedData'

void* writer(void* arg) {
    int id = *(int*)arg;
    sem_wait(&wrt);
    sharedData++;
    cout << "Writer " << id << " wrote data: " << sharedData << endl;
    sem_post(&wrt);
    sleep(1);
    return NULL;
}

void* reader(void* arg) {
    int id = *(int*)arg;
    pthread_mutex_lock(&mutex);
    readCount++;
    if (readCount == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    cout << "Reader " << id << " read data: " << sharedData << endl;
    sleep(1);

    pthread_mutex_lock(&mutex);
    readCount--;
    if (readCount == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t r[3], w[2];
    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    int id1=1, id2=2, id3=3, id4=1, id5=2;

    pthread_create(&r[0], NULL, reader, &id1);
    pthread_create(&w[0], NULL, writer, &id4);
    pthread_create(&r[1], NULL, reader, &id2);
    pthread_create(&w[1], NULL, writer, &id5);
    pthread_create(&r[2], NULL, reader, &id3);

    for (int i = 0; i < 3; i++) pthread_join(r[i], NULL);
    for (int i = 0; i < 2; i++) pthread_join(w[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
