#include <iostream>
#include <cmath>

using namespace std;

int n;
int res;
int board[16];

bool checkValidPos(int row, int col) {
	for (int i = 1; i <= row; i++) {
		if (board[i] == col)
			return false;
		if (row - i == abs(board[i] - col))
			return false;
	}
	return true;
}

void recursive(int row) {
	if (row == n + 1) {
		res++;
		return ;
	}

	for (int col = 1; col <= n; col++) {
		if (checkValidPos(row, col) == true) {
			board[row] = col;
			recursive(row + 1);
			board[row] = 0;
		}
	}

}

int main() {
	cin >> n;

	recursive(1);
	cout << res << "\n";

	return 0;
}