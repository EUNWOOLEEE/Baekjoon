#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1001

int n, m, v;
int link[MAX][MAX];
int visited[MAX];

void dfs(int point) {
	visited[point]++;
	cout << point << " ";

	for (int i = 0; i <= n; i++)
		if (link[point][i] && visited[i] == 0)
			dfs(i);
	return ;
}

void bfs() {
	queue<int> q;
	int next;

	memset(visited, 0, MAX * sizeof(int));

	q.push(v);

	while (q.size()) {
		next = q.front();
		q.pop();

		visited[next]++;
		if (visited[next] == 1)
			cout << next << " ";

		for (int i = 0; i <= n; i++)
			if (link[next][i] && visited[i] == 0)
				q.push(i);
	}

}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		link[x][y]++;
		link[y][x]++;
	}

	dfs(v);
	cout << "\n";

	bfs();

	return 0;
}