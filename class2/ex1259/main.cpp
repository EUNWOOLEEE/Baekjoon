#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string str, tmp;

	while(getline(cin, str)){
		if(str.length() == 1 && str[0] == '0')
			break;
		tmp = str;
		reverse(tmp.begin(), tmp.end());
		if(str == tmp)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}