#include <iostream>

using namespace std;

int main(){
	string str;
	getline(cin, str);

	int alpha[27] = {0,};
	for(int i = 0; i < 26; i++)
		alpha[i] = -1;
	for(int i = 0; i < str.length(); i++)
		if(alpha[str[i] - 'a'] == -1) alpha[str[i] - 'a'] = i;
	for(int i = 0; i < 26; i++)
		cout << alpha[i] << endl;
	return 0;
}