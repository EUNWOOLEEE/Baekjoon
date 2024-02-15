#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void init(int& n, int& m, int& cnt, deque<int>& doc, int* level) {
	cnt = 0;
	doc.clear();
	fill(level, level + 10, 0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		doc.push_back(tmp);
		level[tmp]++;
	}
}

bool checkHighLevel(int cur, int* level) {
	for (int i = cur + 1; i <= 9; i++)
		if (level[i])
			return true;
	return false;
}

int main() {
	int tc, n, m, cnt;
	deque<int> doc;
	int level[10] = {0,};

	cin >> tc;

	while (tc--) {
		init(n, m, cnt, doc, level);

		while (true) {
			if (checkHighLevel(doc.front(), level) == false) {
				if (m == 0) {
					cout << ++cnt << endl;
					break;
				}
				level[doc.front()]--;
				cnt++;
			}
			else {
				if (m == 0)
					m = doc.size();
				doc.push_back(doc.front());
			}
			doc.pop_front();
			m--;
		}
	}

	return 0;
}