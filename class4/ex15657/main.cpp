#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;

void init() {
	cin >> n >> m;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
}

void recursive(string str, int cur, int depth) {
	if (depth == m) {
		cout << str << "\n";
		return ;
	}

	for (int i = cur; i < n; i++) {
		string tmp = str + to_string(arr[i]) + " ";

		recursive(tmp, i, depth + 1);
	}
}

int main() {
	init();
	recursive("", 0, 0);
	return 0;
}