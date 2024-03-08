#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;
int map[25][25];
vector<int> res;

void dfs(array<pair<int, int>, 4>& dir, pair<int, int> cur) {
	if (map[cur.first][cur.second] == 0)
		return ;

	if (map[cur.first][cur.second]) {
		map[cur.first][cur.second] = 0;
		cnt++;

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(cur.first + dir[i].first, cur.second + dir[i].second);

			if (next.first < 0 || 25 <= next.first || next.second < 0 || 25 <= next.second)
				continue;
			if (map[next.first][next.second])
				dfs(dir, next);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++)
			map[i][j] = tmp[j] - '0';
	}

	array<pair<int, int>, 4> dir = {make_pair(-1, 0),
    								make_pair(1, 0),
    								make_pair(0, -1),
    								make_pair(0, 1)};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j]) {
				cnt = 0;
				dfs(dir, make_pair(i, j));
				res.push_back(cnt);
			}

	sort(res.begin(), res.end());

	cout << res.size() << "\n";
	for (unsigned int i = 0; i < res.size(); i++)
		cout << res[i] << "\n";

	return 0;
}