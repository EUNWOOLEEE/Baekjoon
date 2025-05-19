#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef pair<string, int> p;

void bfs(string input, int n, int k) {
	string answer = input;
	map<string, bool> visited;
	queue<p> q;

	sort(answer.begin(), answer.end());
	q.push(make_pair(input, 0));

	while (q.size()) {
		p cur = q.front();
		q.pop();

		if (answer == cur.first) {
			cout << cur.second << "\n";
			return;
		}

		for (int i = 0; i <= n - k; i++) {
			string rev = cur.first.substr(i, k);
			reverse(rev.begin(), rev.end());

			string tmp = cur.first;
			tmp.erase(i, k);
			tmp.insert(i, rev);

			if (visited[tmp] == false) {
				q.push(make_pair(tmp, cur.second + 1));
				visited[tmp] = true;
			}
		}
	}

	cout << -1 << "\n";
	return;
}

int main() {
	int n, k;
	cin >> n >> k;

	string input;
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;

		input += tmp;
	}
	
	bfs(input, n, k);

	return 0;
}