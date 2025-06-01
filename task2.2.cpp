#include<iostream>
using namespace std;

const int items = 4, days =7;
const int coloumns = days + 1;
void inputData(float data[][coloumns], int items) {


	for (int i = 0; i < items; i++) {
		cout << "\nEnter serial number of item: " << i + 1 << " : ";
		cin >> data[i][0];
		cout << endl;
		for (int j = 1; j < coloumns; j++) {
			cout << "Enter sale of item: " << i + 1 << " on day: " << j << " : ";
			cin >> data[i][j];
		}
	}

	cout << "\n\nCalculating Sales Per day and per item: ";
	cout << endl << endl;

	float itemSum = 0, mostSoldItem = data[0][0], max = 0;

	for (int i = 0; i < items; i++) {
		itemSum = 0;
		for (int j = 1; j < coloumns; j++) {
			itemSum += data[i][j];
		}
		cout << "Serial number " << data[i][0] << " has total sale of: " << itemSum << endl;

		if (itemSum > max) {
			max = itemSum;
			mostSoldItem = data[i][0];
		}
	}

	cout << endl;
	float daySum = 0, mostDaySales, max2 = 0;

	for (int i = 1; i < coloumns; i++) {
		daySum = 0;
		for (int j = 0; j < items; j++) {
			daySum += data[j][i];
		}
		cout << "Day " << i << " has total sale of: " << daySum << endl;

		if (daySum > max2) {
			max2 = daySum;
			mostDaySales = i;
		}
	}

	cout << "\nThe most sold item was serial number: " << mostSoldItem << endl;
	cout << "\nThe day with the most sales was: " << mostDaySales << endl;



}

int main() {


	float data[items][coloumns];

	inputData(data, items);

}