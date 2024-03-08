#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int calDistance(string a, string b) {
	int res = 0;
	for (int i = 0; i < 4; i++)
		if (a[i] != b[i])
			res++;
	return res;
}

int main() {
	int t, n;
	cin >> t;

	vector<string> mbti(33);
	
	while (t--) {
		cin >> n;

		if (n > 32) {
			for (int i = 0; i < n; i++) {
				string tmp;
				cin >> tmp;
			}

			cout << 0 << "\n";
			continue;
		}

		for (int i = 0; i < n; i++)
			cin >> mbti[i];

		int min = 100000;
		for (int first = 0; first < n; first++) {
			for (int second = first + 1; second < n; second++) {
				for (int third = second + 1; third < n; third++) {
					int	res = calDistance(mbti[first], mbti[second])
								+ calDistance(mbti[second], mbti[third])
								+ calDistance(mbti[first], mbti[third]);
					min = min < res ? min : res;
				}
			}
		}

		cout << min << "\n";

		mbti.clear();
	}
	return 0;
}