#include <iostream>

using namespace std;

int main(){
	int n, x, num;
	cin >> n >> x;

	while(n--){
		cin >> num;
		if(num < x) cout << num << " ";
	}
	cout << endl;
	
	return 0;
}