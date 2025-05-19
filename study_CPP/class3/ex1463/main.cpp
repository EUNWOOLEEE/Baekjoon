#include <iostream>

using namespace std;

int main() {
	int n, min = 0;
	int arr[1000001] = {0,};

	cin >> n;

	for (int i = 2; i <= n; i++) {
		min = arr[i - 1] + 1;

		if ((i % 2) == 0)
			min = arr[i / 2] + 1 < min ? arr[i / 2] + 1 : min;
		
		if ((i % 3) == 0)
			min = arr[i / 3] + 1 < min ? arr[i / 3] + 1 : min;

		arr[i] = min;
	}

	cout << arr[n] << "\n";
	return 0;
}