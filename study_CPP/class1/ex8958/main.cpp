#include <iostream>

using namespace std;

int main(){
	int tc;
	string str;

	cin >> tc;
	cin.ignore();
	for(int i = 0; i < tc; i++){
		getline(cin, str);
		int res = 0, cnt = 0;
		
		for(int j = 0; j < str.length(); j++){
			if(str[j] == 'X') cnt = 0;
			else cnt++;
			res += cnt;
		}
		cout << res << endl;
	}

	return 0;
}