#include <iostream>

using namespace std;

int main(){
	int t;
	string str[1001];

	cin >> t;
	cin.ignore();

	for(int i = 0; i < t; i++)
		getline(cin, str[i]);
		
	for(int i = 0; i < t; i++){
		int j, times;
		j = times = 0;

		for(; str[i][j] != ' '; j++)
			times = times * 10 + (str[i][j] - '0');
		j++;

		for(; str[i][j] != '\0'; j++)
			for(int k = 0; k < times; k++)
				cout << str[i][j];

		cout << endl;
	}
	
	return 0;
}