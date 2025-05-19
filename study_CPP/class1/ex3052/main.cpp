#include <iostream>

using namespace std;

int main(){
	int arr[42] = {0,};

	for(int i = 0; i < 10; i++){
		int num;
		cin >> num;
		arr[num % 42]++;
	}

	int res = 0;
	for(int i = 0; i < 42; i++)
		if(arr[i]) res++;
	
	cout << res << endl;

	return 0;
}