#include <iostream>
#include <unistd.h>
#include <cstdio> // For perror
#include <string.h>
using namespace std;

int main() {
    int fd[2];                  // pipe ends
    char message[] = "Hello Child";
    char buffer[50];
    
    if (pipe(fd) == -1) { perror("pipe"); return 1; }                   // create pipe
    pid_t pid = ::fork(); // make child process

    if (pid == 0) {             // child process
        close(fd[1]);           // close write end
        read(fd[0], buffer, sizeof(buffer)); // read message
        cout << "Child received: " << buffer << endl;
        close(fd[0]);
    } else {                    // parent process
        close(fd[0]);           // close read end
        write(fd[1], message, strlen(message)+1); // send message
        close(fd[1]);
    }

    return 0;
}
