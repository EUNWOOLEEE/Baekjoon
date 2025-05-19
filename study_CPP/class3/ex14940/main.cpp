#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> iii;

int w, h;
int map[1001][1001];
int res[1001][1001];
queue<iii> q;
iii goal;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool checkPosValid(int row, int col) {
	if (row < 0 || h <= row || col < 0 || w <= col		\
		|| (get<0>(goal) == row && get<1>(goal) == col)	\
		|| res[row][col])
		return false;
	return true;
}

void bfs() {
	q.push(goal);

	while (q.size()) {
		iii cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			iii next(get<0>(cur) + dir[i][0], get<1>(cur) + dir[i][1], get<2>(cur) + 1);

			if (checkPosValid(get<0>(next), get<1>(next)) == true) {
				q.push(next);
				res[get<0>(next)][get<1>(next)] = get<2>(next);
			}
		}
	}
}

int main() {
	cin >> h >> w;

	for (int row = 0; row < h; row++)
		for (int col = 0; col < w; col++) {
			cin >> map[row][col];
			if (map[row][col] == 0)
				res[row][col] = -1;
			if (map[row][col] == 2)
				goal = make_tuple(row, col, 0);
		}

	bfs();

	for (int row = 0; row < h; row++)
		for (int col = 0; col < w; col++) {
			if (get<0>(goal) == row && get<1>(goal) == col)
				continue;
			if (res[row][col] == 0)
				res[row][col] = -1;
			else if (res[row][col] == -1)
				res[row][col] = 0;
		}

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++)
			cout << res[row][col] << " ";
		cout << "\n";
	}

	return 0;
}