#include <iostream>
#include <queue>
#include <climits>

using namespace std;

long long						a, b, res = 0;
queue< pair<long long, int> >	q;

bool check_num(long long cur_cnt, long long next) {
	if (next == b) {
		res = cur_cnt + 1;
		return true;
	}

	if (next <= b / 2)
		q.push(make_pair(next, cur_cnt + 1));

	return false;
}

void bfs() {
	pair<long long, int>	cur;
	
	q.push(make_pair(a, 1));

	while (q.size()) {
		cur = q.front();
		q.pop();

		if (check_num(cur.second, cur.first * 2) == true)
			return ;

		if (check_num(cur.second, cur.first * 10 + 1) == true)
			return ;
	}
}

int main() {
	cin >> a >> b;
	bfs();
	
	if (res)
		cout << res << "\n";
	else
		cout << "-1\n";

	return 0;
}