#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int			t, w, h, k;
int			cabbage[51][51];
queue<pii>	q;
int			dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool checkPosValid(pii next) {
	if (next.first < 0 || h <= next.first || next.second < 0 || w <= next.second)
		return false;
	return true;
}

int bfs(pii start) {
	q.push(start);
	cabbage[start.first][start.second] = 0;

	while (q.size()) {
		pii cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pii next(cur.first + dir[i][0], cur.second + dir[i][1]);

			if (checkPosValid(next) == true && cabbage[next.first][next.second]) {
				q.push(next);
				cabbage[next.first][next.second] = 0;
			}
		}
	}
	
	return 1;
}

int main() {
	cin >> t;

	while (t--) {
		int res = 0;

		cin >> w >> h >> k;

		for (int i = 0; i < h; i++)
			memset(cabbage[i], 0, sizeof(int) * w);

		while (k--) {
			int row, col;
			cin >> col >> row;

			cabbage[row][col]++;
		}

		for (int row = 0; row < h; row++)
			for (int col = 0; col < w; col++)
				if (cabbage[row][col])
					res += bfs(make_pair(row, col));
		
		cout << res << "\n";
	}

	return 0;
}