#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	string str;
	getline(cin, str);

	istringstream istr(str);
	int arr[2] = {0,};
	int i = 0;
	while(getline(istr, str, ' '))
		arr[i++] = stoi(str);

	if(arr[0] > arr[1])
		cout << ">\n";
	else if(arr[0] < arr[1])
		cout << "<\n";
	else
		cout << "==\n";
	return 0;
}