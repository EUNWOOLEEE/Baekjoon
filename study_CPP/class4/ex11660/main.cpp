#include <iostream>

#define MAX 1025

long long table[MAX][MAX];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int row = 1; row <= n; row++)
		for (int col = 1; col <= n; col++) {
			scanf("%lld", &table[row][col]);
			table[row][col] += table[row][col - 1];
		}

	while (m--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		long long res = 0;

		for (int row = x1; row <= x2; row++)
			res += table[row][y2] - table[row][y1 - 1];

		std::cout << res << "\n";
	}

	return 0;
}