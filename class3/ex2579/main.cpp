#include <iostream>

using namespace std;

int checkBiggerScore(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int stairs[301] = {0,};
	int score[301] = {0,};
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];

	score[1] = stairs[1];
	score[2] = stairs[1] + stairs[2];

	for (int i = 3; i <= n; i++)
		score[i] = checkBiggerScore(score[i - 3] + stairs[i - 1],
									score[i - 2])
									+ stairs[i];

	cout << score[n] << "\n";

	return 0;
}