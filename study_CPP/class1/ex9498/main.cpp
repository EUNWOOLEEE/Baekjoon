#include <iostream>

using namespace std;

int main(){
	int grade;
	cin >> grade;

	if(90 <= grade && grade <= 100) cout << "A\n";
	else if(80 <= grade && grade < 90) cout << "B\n";
	else if(70 <= grade && grade < 80) cout << "C\n";
	else if(60 <= grade && grade < 70) cout << "D\n";
	else cout << "F\n";
	
	return 0;
}