#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

const int NUM_PHILOSOPHERS = 5;
mutex forks[NUM_PHILOSOPHERS]; // one mutex per fork

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    // Thinking
    cout << "Philosopher " << id << " is thinking.\n";
    this_thread::sleep_for(chrono::milliseconds(1000));

    // Hungry
    cout << "Philosopher " << id << " is hungry.\n";

    // Pick up forks (avoid deadlock by ordering)
    if (id % 2 == 0) {
        forks[left].lock();
        forks[right].lock();
    } else {
        forks[right].lock();
        forks[left].lock();
    }

    // Eating
    cout << "Philosopher " << id << " is eating.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Put down forks
    forks[left].unlock();
    forks[right].unlock();

    cout << "Philosopher " << id << " finished eating.\n";
}

int main() {
    thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
        philosophers[i] = thread(philosopher, i);

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
        philosophers[i].join();

    cout << "\nAll philosophers have eaten. Simulation complete!\n";
    return 0;
}
