#include <iostream>
#include <queue>
#include <array>

using namespace std;

int main() {
	int n, k;
	array<int, 1000001> map;
	queue<int> q;

	cin >> n >> k;

	q.push(n);

	while (q.size()) {
		int cur = q.front();
		q.pop();

		if (cur == k)
			break;

		if (cur - 1 >= 0 && map[cur - 1] == 0) {
			q.push(cur - 1);
			map[cur - 1] = map[cur] + 1;
		}
		if (cur + 1 <= 100000 && map[cur + 1] == 0) {
			q.push(cur + 1);
			map[cur + 1] = map[cur] + 1;
		}
		if (cur * 2 <= 100000 && map[cur * 2] == 0) {
			q.push(cur * 2);
			map[cur * 2] = map[cur] + 1;
		}
	}

	cout << map[k] << "\n";

	return 0;
}