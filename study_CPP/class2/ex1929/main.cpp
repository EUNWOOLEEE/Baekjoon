#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int m, n;
	int arr[1000001] = {0,};

	cin >> m >> n;

	arr[1] = true;
	for (int i = 2; i <= sqrt(n); i++)
		if (arr[i] == 0)
			for (int j = 2; i * j <= n; j++)
				arr[i * j] = true;

	while (m <= n) {
		if (arr[m] == false)
			cout << m << "\n";
		m++;
	}

	return 0;
}