#include <iostream>

using namespace std;

#define alpha 26

int main(){
	string str;
	cin >> str;

	int arr[alpha] = {0,};
	for(int i = 0; i < str.size(); i++){
		if(str[i] >= 'a')
			arr[str[i] - 'A' - 32]++;
		else
			arr[str[i] - 'A']++;
	}

	int max = 0;
	bool flag = false;
	for(int i = 1; i < alpha; i++){
		if(arr[i] > arr[max]){
			max = i;
			flag = false;
		}
		else if(arr[i] == arr[max])
			flag = true;
	}

	if (flag == true)
		cout << "?\n";
	else
		cout << (char)(max + 'A');

	return 0;
}