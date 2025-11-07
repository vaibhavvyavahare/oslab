#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n=== Linux Commands Menu ===\n";
        cout << "1. List files (ls)\n";
        cout << "2. Show current directory (pwd)\n";
        cout << "3. Display file content (cat)\n";
        cout << "4. Search text in file (grep)\n";
        cout << "5. Sort file (sort)\n";
        cout << "6. Show top lines of file (head)\n";
        cout << "7. Show bottom lines of file (tail)\n";
        cout << "8. Show date (date)\n";
        cout << "9. Show system info (uname)\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("ls -l");
                break;
            case 2:
                system("pwd");
                break;
            case 3:
                system("cat sample.txt");
                break;
            case 4:
                system("grep 'main' sample.txt");
                break;
            case 5:
                system("sort sample.txt");
                break;
            case 6:
                system("head -5 sample.txt");
                break;
            case 7:
                system("tail -5 sample.txt");
                break;
            case 8:
                system("date");
                break;
            case 9:
                system("uname -a");
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 10);

    return 0;
}
