#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int res[1001] = {0,};

	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i <= n; i++)
		res[i] = (res[i - 2] + res[i - 1]) % 10007;

	cout << res[n] << "\n";
	return 0;
}