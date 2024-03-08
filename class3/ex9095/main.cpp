#include <iostream>

using namespace std;

int main() {
	int t, n, res[12] = {0,};

	cin >> t;

	res[1] = 1;
	res[2] = 2;
	res[3] = 4;
	for (int i = 4; i <= 11; i++)
		res[i] = res[i - 3] + res[i - 2] + res[i - 1];

	while (t--){
		cin >> n;

		cout << res[n] << "\n";
	}
	return 0;
}