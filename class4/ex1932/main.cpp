#include <iostream>

using namespace std;

int getBiggerRes(int *res, int idx, int end) {
	if (idx == 1)
		return res[idx];
	if (idx == end)
		return res[idx - 1];
	if (res[idx - 1] > res[idx])
		return res[idx - 1];
	return res[idx];
}

int main() {
	int n;
	int triangle[501][501] = {{0}};
	int res[501][501] = {{0}};

	cin >> n;
	for (int i = 1; i <= 500; i++)
		for (int j = 1; j <= i; j++)
			cin >> triangle[i][j];

	res[1][1] = triangle[1][1];

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			res[i][j] = getBiggerRes(res[i - 1], j, i) + triangle[i][j];

	int max = 0;
	for (int i = 1; i <= n; i++)
		max = res[n][i] > max ? res[n][i] : max;

	cout << max << "\n";

	return 0;
}