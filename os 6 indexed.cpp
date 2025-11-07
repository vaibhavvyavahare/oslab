#include <iostream>
using namespace std;

int main() {
    int n, indexBlock, files, block;
    int blocks[50] = {0};

    cout << "Enter total number of disk blocks: ";
    cin >> n;

    cout << "Enter index block number: ";
    cin >> indexBlock;

    if (blocks[indexBlock] == 1) {
        cout << "Index block already allocated!" << endl;
        return 0;
    }

    blocks[indexBlock] = 1;

    cout << "Enter number of files linked with index block: ";
    cin >> files;

    cout << "Enter block numbers: ";
    for (int i = 0; i < files; i++) {
        cin >> block;
        if (blocks[block] == 0) {
            blocks[block] = 1;
        } else {
            cout << "Block " << block << " already allocated!" << endl;
            return 0;
        }
    }

    cout << "\nFile allocated using index block " << indexBlock << endl;
    cout << "Blocks allocated: ";
    for (int i = 0; i < n; i++)
        if (blocks[i] == 1)
            cout << i << " ";
    cout << endl;
    return 0;
}
