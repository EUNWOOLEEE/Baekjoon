#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int res[1001] = {0};
	for (int i = 1; i <= n; i++) {
		int cost;
		cin >> cost;

		if (i == 1)
			for (int j = 1; j <= n; j++)
				res[j] = cost * j;

		else {
			for (int j = i; j <= n; j++) {
				if ((j % i) == 0)
					res[j] = cost * (j / i) > res[j] ? cost * (j / i) : res[j];

				else
					res[j] = cost + res[j - i] > res[j] ? cost + res[j - i] : res[j];
			}
		}
	}

	cout << res[n] << "\n";

	return 0;
}