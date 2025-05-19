#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string str1, string str2){
	if(str1.length() < str2.length())
		return true;
	else if(str1.length() == str2.length())
		if(str1 < str2)
			return true;
	return false;
}

int main(){
	int n;
	cin >> n;
	cin.ignore();

	vector<string> strs(n);
	for(int i = 0; i < n; i++)
		getline(cin, strs[i]);

	sort(strs.begin(), strs.end(), compare);

	for(int i = 0; i < n; i++)
		if(!i || (i && strs[i] != strs[i - 1]))
			cout << strs[i] << endl;
	return 0;
}