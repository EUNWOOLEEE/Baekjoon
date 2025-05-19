#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void initNums(int& n, vector<int>& target) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		target.push_back(tmp);
	}
}

int main() {
	int n, m;
	vector<int> target;
	vector<int> nums;

	initNums(n, nums);
	initNums(m, target);
	
	sort(nums.begin(), nums.end());

	for (int i = 0; i < m; i++) {
		if (binary_search(nums.begin(), nums.end(), target[i]) == true)
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}