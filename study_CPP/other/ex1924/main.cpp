#include <iostream>

using namespace std;

int checkEndOfMonth(int month) {
	if (month == 4 \
		|| month == 6 \
		|| month == 9 \
		|| month == 11)
		return 30;
	if (month == 2)
		return 28;
	return 31;
}

void printDay(int day) {
	if (day == 1)
		cout << "MON\n";
	else if (day == 2)
		cout << "TUE\n";
	else if (day == 3)
		cout << "WED\n";
	else if (day == 4)
		cout << "THU\n";
	else if (day == 5)
		cout << "FRI\n";
	else if (day == 6)
		cout << "SAT\n";
	else
		cout << "SUN\n";
}

int main() {
	int month, date, day = 1;
	cin >> month >> date;

	for (int i = 1; i <= month; i++) {
		int end = checkEndOfMonth(i);
		
		for (int j = 1; j <= end; j++) {
			if (i == month && j == date)
				break;
			day = (day + 1) % 7;
		}
	}

	printDay(day);
	
	return 0;
}