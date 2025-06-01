#include<iostream>
using namespace std;

const int products = 5, users = 10;

void inputRatings(int data[][users]) {

    cout << "Input the user ratings for each product (1 to 5): \n\n";

    for (int i = 0; i < products; i++) {
        cout << endl;
        for (int j = 0; j < users; j++) {
        Input:
            int rating;
            cout << "Enter rating by User " << j + 1 << " for Product " << i + 1 << ": ";
            cin >> rating;

            if (rating >= 1 && rating <= 5) {
                data[i][j] = rating;
            }
            else {
                cout << "\nInvalid rating! Please enter a value between 1 and 5.\n\n";
                goto Input;
            }
        }
    }

}

void calculations(int data[][users]) {

    float sum = 0, avg;
    float minAvg = INT_MAX;
    int perfectCount = 0, temp = 0;

    cout << "\n\nCalculating average ratings and perfect 5 ratings for each product:\n\n";

    for (int i = 0; i < products; i++) {
        sum = 0;
        perfectCount = 0;

        for (int j = 0; j < users; j++) {
            sum += data[i][j];
            if (data[i][j] == 5) {
                perfectCount++;
            }
        }

        avg = sum / users;
        cout << "Product " << i + 1 << " has average rating: " << avg << endl;
        cout << "Product " << i + 1 << " got perfect rating (5) from " << perfectCount << " users.\n\n";

        if (avg < minAvg) {
            minAvg = avg;
            temp = i;
        }
    }

    cout << "\nProduct with the worst average rating of: " << minAvg << " is product " << temp + 1<<" .\n";

}


int main() {

    int data[products][users];

    inputRatings(data);
    calculations(data);

    system("pause");
    return 0;
}
