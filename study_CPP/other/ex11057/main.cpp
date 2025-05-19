#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[1001][10] = {{0}};

	for (int i = 0; i < 10; i++)
		arr[0][i] = 1;

	for (int i = 1; i <= n; i++) {
		arr[i][9] = 1;
		for (int j = 8; j >= 0; j--)
			arr[i][j] = (arr[i][j + 1] + arr[i - 1][j]) % 10007;
	}

	cout << arr[n][0]<< "\n";
	return 0;
}