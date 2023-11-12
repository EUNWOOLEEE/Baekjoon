#include <iostream>
#include <sstream>

using namespace std;

#define size 1000001

int main(){
	char buf[size];
	cin.getline(buf, size);

	istringstream istr(buf);
	string token;
	int cnt = 0;

	while (getline(istr, token, ' '))
		if (token.length()) cnt++;

	cout << cnt << endl;
	return 0;
}