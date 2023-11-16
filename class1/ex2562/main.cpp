#include <iostream>

using namespace std;

int main(){
	int cur, max, idx;
	cur = max = idx = 0;

	for(int i = 1; i <= 9; i++){
		cin >> cur;
		if(cur > max){
			max = cur;
			idx = i;
		}
	}
	cout << max << endl << idx << endl;

	return 0;
}