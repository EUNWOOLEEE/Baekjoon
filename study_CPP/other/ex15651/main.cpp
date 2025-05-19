#include <iostream>

using namespace std;

int n, m;
int arr[8];

void recursive(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= n; i++) {
		arr[idx] = i;
		recursive(idx + 1);
	}
}

int main() {
	cin >> n >> m;

	recursive(0);

	return 0;
}