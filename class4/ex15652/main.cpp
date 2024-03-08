#include <iostream>

using namespace std;

int n, m;
int arr[8];

void recursive(int idx, int cur) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return ;
	}

	for (int i = cur; i <= n; i++) {
		arr[idx] = i;
		recursive(idx + 1, i);
	}
}

int main() {
	cin >> n >> m;

	recursive(0, 1);

	return 0;
}