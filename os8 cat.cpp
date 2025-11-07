#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {
    char fname[50];
    char buffer[1024];
    int n;

    cout << "Enter file name to display: ";
    cin >> fname;

    int fd = open(fname, O_RDONLY);
    if (fd < 0) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    cout << "\nFile content:\n";
    while ((n = read(fd, buffer, sizeof(buffer))) > 0)
        write(1, buffer, n); // 1 = stdout

    close(fd);
    return 0;
}
