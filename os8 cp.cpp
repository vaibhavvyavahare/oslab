#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {
    char src[50], dest[50];
    char buffer[1024];
    int n;

    cout << "Enter source file name: ";
    cin >> src;
    cout << "Enter destination file name: ";
    cin >> dest;

    int fd1 = open(src, O_RDONLY);
    if (fd1 < 0) {
        cout << "Cannot open source file!" << endl;
        return 1;
    }

    int fd2 = open(dest, O_WRONLY | O_CREAT, 0644);
    if (fd2 < 0) {
        cout << "Cannot open/create destination file!" << endl;
        close(fd1);
        return 1;
    }

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
        write(fd2, buffer, n);

    cout << "File copied successfully!" << endl;

    close(fd1);
    close(fd2);
    return 0;
}
