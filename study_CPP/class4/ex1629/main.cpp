#include <iostream>
#include <vector>

using namespace std;

int main() {
	size_t	a, b, c;
	cin >> a >> b >> c;

	vector<int>	memo;
	size_t		res = a;

	if (b == 1) {
		cout << a % c << "\n";
		return 0;
	}

	memo.push_back(res);
	for (size_t i = 0; i < b - 1; i++) {
		res = (res * a) % c;

		// cout << res << "\n";
		memo.push_back(res);

		if (res == a)
			break;
	}
	// cout << "\n";

	for (unsigned int i = 2; i <= memo.size(); i++) {
		// cout << i << ": " << memo[i - 1] << "\n";
		if (b % i == 0) {
			cout << memo[i - 1] << "\n";
			break;
		}
	}

	return 0;
}
