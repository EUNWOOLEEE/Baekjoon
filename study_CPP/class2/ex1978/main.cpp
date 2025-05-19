#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init(int& n, vector<int>& input_nums) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		input_nums.push_back(tmp);
	}
}

bool isPrime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	int n, cnt = 0;
	vector<int> input_nums;

	init(n, input_nums);

	for (int i = 0; i < n; i++)
		if (isPrime(input_nums[i]) == true)
			cnt++;

	cout << cnt << "\n";

	return 0;
}