#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

void init(int& n, vector<pair<int, int> >& line) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);

		line.push_back(make_pair(tmp1, tmp2));
	}
}

int main() {
	int n;
	vector<pair<int, int> > line;

	init(n, line);
	sort(line.begin(), line.end(), compare);

	unsigned long long res = line[0].second - line[0].first;
	int end = line[0].second;

	for (int i = 1 ; i < n; i++) {
		if (end > line[i].first) {
			if (end < line[i].second) {
				res += line[i].second - end;
				end = line[i].second;
			}
		}
		else {
			res += line[i].second - line[i].first;
			end = line[i].second;
		}
	}

	cout << res << "\n";
		
	return 0;
}