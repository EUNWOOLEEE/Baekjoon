#include <iostream>

using namespace std;

int main(){
	int min = 1000000, max = -min;
	int n, num;
	cin >> n;

	while(n--){
		cin >> num;
		min = min > num ? num : min;
		max = max < num ? num : max;
	}
	cout << min << " " << max << endl;

	return 0;
}