#include <iostream>

using namespace std;

int n, m;
int arr[8];
int visited[9];

void recursive(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= n; i++) {
		arr[idx] = i;
		if (visited[i])
			continue;
		visited[i]++;
		recursive(idx + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;

	recursive(0);

	return 0;
}