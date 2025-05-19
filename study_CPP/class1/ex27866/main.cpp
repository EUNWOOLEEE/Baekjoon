#include <iostream>

using namespace std;

int main(){
	string str;
	int i;

	getline(cin, str);
	cin >> i;

	cout << str[i - 1];
	return 0;
}