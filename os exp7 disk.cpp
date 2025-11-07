#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void FCFS(vector<int> req, int head) {
    int seek = 0;
    cout << "\nFCFS Order: ";
    for (int r : req) {
        cout << r << " ";
        seek += abs(head - r);
        head = r;
    }
    cout << "\nTotal Seek Time (FCFS): " << seek << endl;
}

void SSTF(vector<int> req, int head) {
    vector<int> temp = req;
    int seek = 0;
    cout << "\nSSTF Order: ";
    while (!temp.empty()) {
        auto nearest = min_element(temp.begin(), temp.end(),
                                   [head](int a, int b) { return abs(a - head) < abs(b - head); });
        cout << *nearest << " ";
        seek += abs(head - *nearest);
        head = *nearest;
        temp.erase(nearest);
    }
    cout << "\nTotal Seek Time (SSTF): " << seek << endl;
}

void SCAN(vector<int> req, int head, int size) {
    vector<int> left, right;
    for (int r : req)
        (r < head ? left : right).push_back(r);
    left.push_back(0);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int seek = 0;
    cout << "\nSCAN Order: ";
    for (int r : right) { cout << r << " "; seek += abs(head - r); head = r; }
    for (int i = left.size() - 1; i >= 0; i--) { cout << left[i] << " "; seek += abs(head - left[i]); head = left[i]; }
    cout << "\nTotal Seek Time (SCAN): " << seek << endl;
}

void CSCAN(vector<int> req, int head, int size) {
    vector<int> left, right;
    for (int r : req)
        (r < head ? left : right).push_back(r);
    left.push_back(0);
    right.push_back(size - 1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int seek = 0;
    cout << "\nCSCAN Order: ";
    for (int r : right) { cout << r << " "; seek += abs(head - r); head = r; }
    seek += abs(head - 0);
    head = 0;
    for (int r : left) { cout << r << " "; seek += abs(head - r); head = r; }
    cout << "\nTotal Seek Time (CSCAN): " << seek << endl;
}

void LOOK(vector<int> req, int head) {
    vector<int> left, right;
    for (int r : req)
        (r < head ? left : right).push_back(r);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int seek = 0;
    cout << "\nLOOK Order: ";
    for (int r : right) { cout << r << " "; seek += abs(head - r); head = r; }
    for (int i = left.size() - 1; i >= 0; i--) { cout << left[i] << " "; seek += abs(head - left[i]); head = left[i]; }
    cout << "\nTotal Seek Time (LOOK): " << seek << endl;
}

int main() {
    int n, head, size;
    cout << "Enter number of requests: ";
    cin >> n;
    vector<int> req(n);
    cout << "Enter request sequence: ";
    for (int i = 0; i < n; i++) cin >> req[i];
    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter disk size: ";
    cin >> size;

    FCFS(req, head);
    SSTF(req, head);
    SCAN(req, head, size);
    CSCAN(req, head, size);
    LOOK(req, head);

    return 0;
}
