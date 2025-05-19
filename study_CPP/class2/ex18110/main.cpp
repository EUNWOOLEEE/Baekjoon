#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void init(int& n, double& total, vector<int>& level) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		double tmp;
		cin >> tmp;
		total += tmp;

		level.push_back(tmp);
	}
	sort(level.begin(), level.end());
}

int main() {
	int n;
	vector<int> level;
	double total = 0;

	init(n, total, level);

	if (n == 0) {
		cout << total << "\n";
		return 0;
	}

	int exclude = round(n * 0.15);

	for (int i = 0; i < exclude; i++) {
		total -= level[i];
		total -= level[n - i - 1];
	}

	int res = round(total / (n - exclude * 2));
	cout << res << "\n";

	return 0;
}