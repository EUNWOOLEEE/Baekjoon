#include <iostream>

using namespace std;

int main(){
	int num, res;
	int arr[10] = {0,};

	for(int i = 0; i < 3; i++){
		if(!i)
			cin >> res;
		else{
			cin >> num;
			res *= num;
		}
	}

	while(res){
		arr[res % 10]++;
		res /= 10;
	}

	for(int i = 0; i < 10; i++)
		cout << arr[i] << endl;

	return 0;
}