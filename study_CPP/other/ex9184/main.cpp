#include <iostream>
#include <cmath>

using namespace std;

int arr[51][51][51];

int recursive(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (arr[a][b][c] != 0)
		return arr[a][b][c];
	if (a > 20 || b > 20 || c > 20)
		return 1048576;
	if ((a < b && b < c) || (a == b && b == c))
		return arr[a][b][c] = pow(2, a);

	return arr[a][b][c] = recursive(a - 1, b, c) + recursive(a - 1, b - 1, c)
			+ recursive(a - 1, b, c - 1) - recursive(a - 1, b - 1, c - 1);
}

int main() {
	int a, b, c;

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			return 0;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << recursive(a, b, c) << "\n";
	}
	return 0;
}