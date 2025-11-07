#include <iostream>
using namespace std;

struct Block {
    int next;
};

int main() {
    int n, start, len;
    Block disk[50];
    int used[50] = {0};

    cout << "Enter total number of blocks: ";
    cin >> n;
    cout << "Enter starting block and length of file: ";
    cin >> start >> len;

    int prev = start;
    used[start] = 1;

    for (int i = 1; i < len; i++) {
        int nextBlock;
        cout << "Enter next block number for block " << prev << ": ";
        cin >> nextBlock;

        if (nextBlock < 0 || nextBlock >= n || used[nextBlock]) {
            cout << "Invalid or already used block!" << endl;
            return 0;
        }

        disk[prev].next = nextBlock;
        used[nextBlock] = 1;
        prev = nextBlock;
    }

    disk[prev].next = -1; // end of file

    cout << "\nFile allocation (linked):\n";
    int current = start;
    while (current != -1) {
        cout << current << " -> ";
        current = disk[current].next;
    }
    cout << "NULL" << endl;

    return 0;
}
