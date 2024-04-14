#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int			n, m;
int			nums[10001] = {0,};
vector<int>	res;

void init(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums[tmp]++;
	}
}

void print(void) {
	for (unsigned int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << "\n";
}

void rec(int depth) {
	if (depth == m) {
		print();
		return ;
	}

	for (int i = 1; i <= 10000; i++) {
		if (nums[i]) {
			nums[i]--;
			res.push_back(i);
			rec(depth + 1);
			res.pop_back();
			nums[i]++;
		}
	}
}

int main() {
	init();
	rec(0);

	return 0;
}