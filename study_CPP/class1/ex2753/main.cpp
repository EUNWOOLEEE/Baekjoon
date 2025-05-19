#include <iostream>

using namespace std;

int main(){
	int year;
	cin >> year;

	if(!(year % 4) && ((year % 100) || !(year % 400)))
		cout << 1;
	else
		cout << 0;
	return 0;
}