#include <iostream>
using namespace std;

int main() {
    int n, f;

    cout << "Enter number of pages: ";
    cin >> n;
    int pages[n];
    cout << "Enter page numbers: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;
    int frame[f];
    for (int i = 0; i < f; i++) frame[i] = -1;

    int faults = 0;

    // ---------------- FIFO ----------------
    int pos = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            frame[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }
    cout << "\nFIFO Page Faults: " << faults << endl;

    // ---------------- LRU ----------------
    int count[10] = {0};
    faults = 0;
    for (int i = 0; i < f; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                count[j] = i + 1;
                break;
            }
        }
        if (!found) {
            int min = 0;
            for (int j = 1; j < f; j++)
                if (count[j] < count[min]) min = j;
            frame[min] = pages[i];
            count[min] = i + 1;
            faults++;
        }
    }
    cout << "LRU Page Faults: " << faults << endl;

    // ---------------- OPTIMAL ----------------
    faults = 0;
    for (int i = 0; i < f; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            int replace = -1, farthest = i + 1;
            for (int j = 0; j < f; j++) {
                int k;
                for (k = i + 1; k < n; k++)
                    if (frame[j] == pages[k]) break;
                if (k == n) { replace = j; break; }
                if (k > farthest) { farthest = k; replace = j; }
            }
            if (replace == -1) replace = 0;
            frame[replace] = pages[i];
            faults++;
        }
    }
    cout << "OPTIMAL Page Faults: " << faults << endl;

    return 0;
}
