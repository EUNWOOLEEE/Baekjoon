#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int			n, m;
vector<int>	arr;
int			visited[10001];

void recursive(string str, int depth) {
	if (depth == m) {
		cout << str << "\n";
		return ;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;

		string tmp = str;
		tmp += to_string(arr[i]) + " ";

		visited[i] = 1;
		recursive(tmp, depth + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());

	recursive("", 0);

	return 0;
}