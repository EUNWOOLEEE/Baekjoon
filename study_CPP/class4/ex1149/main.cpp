#include <iostream>

using namespace std;

int calLessCost(int *costs, int idx) {
	if (idx == 0) {
		if (costs[1] < costs[2])
			return costs[1];
		return costs[2];
	}
	else if (idx == 1) {
		if (costs[0] < costs[2])
			return costs[0];
		return costs[2];
	}
	else {
		if (costs[0] < costs[1])
			return costs[0];
		return costs[1];
	}
}

void printMinCost(int *costs) {
	int min = costs[0];

	if (costs[1] < min)
		min = costs[1];
	if (costs[2] < min)
		min = costs[2];

	cout << min << "\n";
}

int main() {
	int n;
	int cost[1001][3] = {{0}};
	int res[1001][3] = {{0}};

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	res[1][0] = cost[1][0];
	res[1][1] = cost[1][1];
	res[1][2] = cost[1][2];

	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 3; j++)
			res[i][j] = calLessCost(res[i - 1], j) + cost[i][j];

	printMinCost(res[n]);

	return 0;
}