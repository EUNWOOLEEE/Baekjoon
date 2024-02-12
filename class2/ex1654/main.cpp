#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int checkCableCnt(vector<size_t> cable, size_t len) {
	int cnt = 0;

	for (unsigned long i = 0; i < cable.size(); i++)
		cnt += floor(cable[i] / len);

	return cnt;
}

int main() {
	int K, N;
	cin >> K >> N;

	size_t max_len = 0;
	vector<size_t> cable(K, 0);
	for (int i = 0; i < K; i++) {
		cin >> cable[i];
		max_len = cable[i] > max_len ? cable[i] : max_len;
	}

	size_t res = 0;
	size_t left = 1, right = max_len;
	while (left <= right) {
		size_t mid = (left + right) / 2;

		if (checkCableCnt(cable, mid) < N)
			right = mid - 1;
		else {
			res = mid;
			left = mid + 1;
		}
	}

	cout << res << endl;

	return 0;
}