#include <iostream>
#include <cmath>

using namespace std;

int main(){
	string serial;
	getline(cin, serial);
	
	int res = 0;
	for(unsigned long i = 0; i < serial.length(); i++)
		if(serial[i] != ' ')
			res += pow((serial[i] - '0'), 2);

	cout << res % 10;

	return 0;
}