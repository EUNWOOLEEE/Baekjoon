#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int			h, w;
char		map[601][601];
int			visited[601][601];
queue<pii>	q;
int			dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pii			start;

bool checkPosValid(int row, int col) {
	if (row < 0 || h <= row || col < 0 || w <= col		\
		|| visited[row][col] || map[row][col] == 'X')
		return false;
	return true;
}

void bfs() {
	int res = 0;

	q.push(start);
	visited[start.first][start.second]++;
	
	while (q.size()) {
		pii cur = q.front();
		q.pop();

		if (map[cur.first][cur.second] == 'P')
			res++;

		for (int i = 0; i < 4; i++) {
			pii next(cur.first + dir[i][0], cur.second + dir[i][1]);
			if (checkPosValid(next.first, next.second) == true) {
				visited[next.first][next.second]++;
				q.push(make_pair(next.first, next.second));
			}
		}
	}

	if (res)
		cout << res << "\n";
	else
		cout << "TT\n";
}

int main() {
	cin >> h >> w;
	
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I')
				start = make_pair(i, j);
		}

	bfs();

	return 0;
}