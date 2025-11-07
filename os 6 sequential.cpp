#include <iostream>
using namespace std;

int main() {
    int n, start, len;
    int blocks[50] = {0};  // 0 = free, 1 = allocated

    cout << "Enter total number of disk blocks: ";
    cin >> n;

    cout << "Enter starting block and length of file: ";
    cin >> start >> len;

    if (start + len > n) {
        cout << "File cannot be allocated (out of range)!" << endl;
        return 0;
    }

    for (int i = start; i < start + len; i++) {
        if (blocks[i] == 1) {
            cout << "Block " << i << " already allocated!" << endl;
            return 0;
        }
    }

    for (int i = start; i < start + len; i++)
        blocks[i] = 1;

    cout << "\nFile allocated from block " << start << " to " << start + len - 1 << endl;

    cout << "\nBlock status:\n";
    for (int i = 0; i < n; i++)
        cout << i << ":" << blocks[i] << "  ";

    cout << endl;
    return 0;
}
