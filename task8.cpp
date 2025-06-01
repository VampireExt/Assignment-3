#include<iostream>
using namespace std;

const int shelves = 5, books = 5;

void displayStatus(char data[][books]) {

    cout << "\n\nLibrary Book Status (A = Available, I = Issued, M = Missing):\n";

    for (int i = 0; i < shelves; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < books; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void inputData(char data[][books]) {

    cout << "Input status of books (A/I/M): \n\n";

    for (int i = 0; i < shelves; i++) {
        cout << endl;
        for (int j = 0; j < books; j++) {
        Input:
            char status;
            cout << "Enter status of book " << j + 1 << " on shelf " << i + 1 << ": ";
            cin >> status;

            if (status == 'A' || status == 'I' || status == 'M' || status == 'a' || status == 'i' || status == 'm') {
                data[i][j] = toupper(status);
            }
            else {
                cout << "\nInvalid input! Please enter only A, I, or M.\n\n";
                goto Input;
            }
        }
    }
}

void countAndMissingShelves(char data[][books]) {

    int available = 0, issued = 0, missing = 0;

    for (int i = 0; i < shelves; i++) {
        for (int j = 0; j < books; j++) {
            if (data[i][j] == 'A') {
                available++;
            }
            else if (data[i][j] == 'I') {
                issued++;
            }
            else if (data[i][j] == 'M') {
                missing++;
            }
        }
    }

    cout << "\n\nTotal Book Status Count:\n\n";
    cout << "Available: " << available << endl;
    cout << "Issued: " << issued << endl;
    cout << "Missing: " << missing << endl;

    int maxMissing = 0, temp = 0;
    for (int i = 0; i < shelves; i++) {
        int shelfMissing = 0;
        for (int j = 0; j < books; j++) {
            if (data[i][j] == 'M') {
                shelfMissing++;
            }
        }
        if (shelfMissing > maxMissing) {
            maxMissing = shelfMissing;
            temp = i;
        }
    }

    cout << "\nShelf with highest missing books: " << maxMissing << " is: " << temp + 1 << " .\n\n";

}

int main() {

    char data[shelves][books];

    inputData(data);
    displayStatus(data);
    countAndMissingShelves(data);
}
