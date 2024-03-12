#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int, string> pis;

int			visited[10000];
queue<pis>	q;

void toDouble(pis& cur) {
	int next = (cur.first * 2) % 10000;

	if (visited[next] == false) {
		q.push(make_pair(next, cur.second + 'D'));
		visited[next] = true;
	}
}

void toMinus(pis& cur) {
	int	next = cur.first == 0 ? 9999 : cur.first - 1;

	// if (cur.first == 0)
	// 	next = 9999;
	// else
	// 	next = cur.first - 1;
	
	if (visited[next] == false) {
		q.push(make_pair(next, cur.second + 'S'));
		visited[next] = true;
	}
}

void toLeft(pis& cur) {
	int i = cur.first / 1000;
	int next = cur.first * 10 + i;
	
	if (visited[next] == false) {
		q.push(make_pair(next, cur.second + 'L'));
		visited[next] = true;
	}
}

void toRight(pis& cur) {
	int i = (cur.first % 10) * 1000;
	int next = cur.first / 10 + i;
	
	if (visited[next] == false) {
		q.push(make_pair(next, cur.second + 'R'));
		visited[next] = true;
	}
}

void bfs(int a, int b) {
	q.push(make_pair(a, ""));
	visited[a] = true;

	while (q.size()) {
		pis cur = q.front();
		q.pop();

		if (cur.first == b) {
			cout << cur.second << "\n";
			break;
		}

		toDouble(cur);
		toMinus(cur);
		toLeft(cur);
		toRight(cur);
	}
}

int main() {
	int tc;
	int a, b;
	cin >> tc;

	while (tc--) {
		memset(visited, 0, sizeof(int) * 10000);

		while (q.size())
			q.pop();

		cin >> a >> b;

		bfs(a, b);
	}

	return 0;
}