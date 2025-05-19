#include <iostream>
#include <map>

int sticker[2][100001];
int res[2][100001];

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &sticker[i][j]);

		res[0][0] = sticker[0][0];
		res[0][1] = sticker[0][1] + sticker[1][0];
		res[1][0] = sticker[1][0];
		res[1][1] = sticker[1][1] + sticker[0][0];

		for (int i = 2; i < n; i++) {
			int first = res[0][i - 2] + sticker[0][i];
			int second = res[1][i - 2] + sticker[0][i];
			int third = res[1][i - 1] + sticker[0][i];

			res[0][i] = first > second ? first : second;
			res[0][i] = res[0][i] > third ? res[0][i] : third;

			first = res[0][i - 2] + sticker[1][i];
			second = res[1][i - 2] + sticker[1][i];
			third = res[0][i - 1] + sticker[1][i];

			res[1][i] = first > second ? first : second;
			res[1][i] = res[1][i] > third ? res[1][i] : third;
		}

		std::cout << (res[0][n - 1] > res[1][n - 1] ? res[0][n - 1] : res[1][n - 1]) << "\n";
	}

	return 0;
}