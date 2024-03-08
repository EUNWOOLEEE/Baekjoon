#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int score = 0, cur = 0;
		string quiz;
		cin >> quiz;

		for (unsigned int i = 0; i < quiz.size(); i++) {
			if (quiz[i] == 'O') {
				cur++;
				score += cur;
			}
			else
				cur = 0;
		}
		cout << score << "\n";
	}

	return 0;
}