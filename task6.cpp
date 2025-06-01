#include<iostream>
using namespace std;

const int rows = 6, coloumn = 4;

void displayChart(char seats[][coloumn]) {
    cout << "\nSeating Chart:\n\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < coloumn; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

void bookSeat(char seats[][coloumn]) {
    int row, col;
    cout << "\nEnter row 1-6: ";
    cin >> row;
    cout << "Enter coloumn 1-4: ";
    cin >> col;

    if (row < 1 || row > 6 || col < 1 || col > 4) {
        cout << "Invalid seat position!\n";
        return;
    }

    if (seats[row - 1][col - 1] == 'B' || seats[row - 1][col - 1] == 'b') {
        cout << "Seat already booked!\n";
    }
    else {
        seats[row - 1][col - 1] = 'B';
        cout << "Seat booked successfully.\n";
    }
}

void countAvailableSeats(char seats[][coloumn]) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coloumn; j++) {
            if (seats[i][j] == 'E' || seats[i][j] == 'e') {
                count++;
            }
        }
    }
    cout << "\nTotal available seats: " << count << endl;
}

void rowWithMostEmptySeats(char seats[][coloumn]) {
    int maxEmpty = 0, rowIndex = 0;

    for (int i = 0; i < rows; i++) {
        int rowEmpty = 0;
        for (int j = 0; j < coloumn; j++) {
            if (seats[i][j] == 'E' || seats[i][j] == 'e') {
                rowEmpty++;
            }
        }

        if (rowEmpty > maxEmpty) {
            maxEmpty = rowEmpty;
            rowIndex = i;
        }
    }

    cout << "\nRow with most empty seats is Row " << rowIndex + 1 << " with " << maxEmpty << " empty seats.\n";
}

int main() {

    char seats[rows][coloumn];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coloumn; j++) {
            seats[i][j] = 'E';
        }
    }

    int choice;

Menu:

    cout << "\nFlight Seat Reservation Menu:\n";
    cout << "1. Display Seating Chart\n";
    cout << "2. Book a Seat\n";
    cout << "3. Count Available Seats\n";
    cout << "4. Row with Most Empty Seats\n";
    cout << "5. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 5) {
        cout << "Exiting...\n";
        return 0;
    }

    switch (choice) {
    case 1:
        displayChart(seats);
        break;
    case 2:
        bookSeat(seats);
        break;
    case 3:
        countAvailableSeats(seats);
        break;
    case 4:
        rowWithMostEmptySeats(seats);
        break;
    default:
        cout << "Invalid choice!\n";
    }

    goto Menu;
}
