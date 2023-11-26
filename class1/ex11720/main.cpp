#include <iostream>

using namespace std;

int main(){
	int n, res = 0;
	string str;

	cin >> n;
	cin.ignore();
	getline(cin, str);

	for(int i = 0; i < str.length(); i++)
		res += str[i] - '0';
	cout << res;
	
	return 0;
}