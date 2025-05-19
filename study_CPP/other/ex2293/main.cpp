#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coin;
	int res[10001] = {0};

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
	}
	
	sort(coin.begin(), coin.end());

	for (int i = 1; i * coin.front() <= k; i++)
		res[i * coin.front()] = 1;

	for (unsigned int i = 1; i < coin.size(); i++) {
		if (coin[i] > k)
			break;

		res[coin[i]]++;
		for (int cur = coin[i]; cur <= k; cur++)
			res[cur] += res[cur - coin[i]];
	}
	
	cout << res[k] << "\n";

	return 0;
}