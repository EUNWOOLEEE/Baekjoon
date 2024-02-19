#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void printMean(double n, double all) {
	int tmp;

	if (all > 0)
		tmp = round(all / n);
	else
		tmp = -round((all * -1) / n);
	cout << tmp << "\n";
}

void printMedian(int n, vector<int>& nums) {
	cout << nums[n / 2] << "\n";
}

void printMode(int* times, int max_times, int times_cnt) {
	for (int i = 0; i < 8001; i++) {
		if (times[i] == max_times) {
			if (times_cnt > 1)
				times_cnt = 1;
			else {
				cout << i - 4000 << "\n";
				break;
			}
		}
	}
}

void printRange(int max, int min) {
	cout << max - min << "\n";
}

int main() {
	int n;
	vector<int> nums;
	int times[8001] = {0,};

	long long max = -4000;
	long long min = 4000;
	long long all = 0;
	int max_times = 0;
	int times_cnt = 0;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);

		all += tmp;
		max = tmp > max ? tmp : max;
		min = tmp < min ? tmp : min;

		times[tmp + 4000]++;
		if (times[tmp + 4000] > max_times) {
			max_times = times[tmp + 4000];
			times_cnt = 1;
		}
		else if (times[tmp + 4000] == max_times)
			times_cnt++;
	}

	sort(nums.begin(), nums.end());

	printMean(static_cast<double>(n), static_cast<double>(all));
	printMedian(n, nums);
	printMode(times, max_times, times_cnt);
	printRange(max, min);

	return 0;
}