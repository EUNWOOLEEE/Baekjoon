#include <iostream>

using namespace std;

int n, res[2];
int paper[128][128];

bool checkColor(int _x, int _y, int size) {
	int color = paper[_x][_y];

	for (int y = _y; y < _y + size; y++)
		for (int x = _x; x < _x + size; x++)
			if (color != paper[x][y])
				return false;
				
	res[color]++;
	return true;
}

void DaQ(int x, int y, int size) {
	if (checkColor(x, y, size) == true)
		return ;

	size /= 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			DaQ(x + (size * j), y + (size * i), size);
}

int main() {
	cin >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> paper[x][y];

	DaQ(0, 0, n);

	cout << res[0] << "\n" << res[1] << "\n";

	return 0;
}