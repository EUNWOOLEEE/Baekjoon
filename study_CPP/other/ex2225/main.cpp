#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int arr[201] = {0};

	for (int i = 0; i <= n; i++)
		arr[i] = 1;

	for (int i = k - 1; i > 0; i--)
		for (int j = 1; j <= n; j++)
			arr[j] = (arr[j - 1] + arr[j]) % 1000000000;

	cout << arr[n] << "\n";

	return 0;
}