#include <iostream>
#include <vector>

using namespace std;

int main() {
	int	n;
	cin >> n;

	vector<int>	a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int	max = 0, ans = 1;
	vector<int>	res(n);
	res[0] = 1;
	for (int i = 1; i < n; i++) {
		max = 0;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				max = res[j] > max ? res[j] : max;

		res[i] = max + 1;
		ans = ans > res[i] ? ans : res[i];
	}

	cout << ans << "\n";

	return 0;
}