#include <iostream>
#include <vector>

using namespace std;

void push(vector<int>& stack, vector<string>& res, int num) {
	stack.push_back(num);
	res.push_back("+\n");
}

void pop(vector<int>& stack, vector<string>& res) {
	stack.pop_back();
	res.push_back("-\n");
}

void init(int& n, vector<int>& num) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
}

int main() {
	int				n;
	vector<int>		num;
	vector<int>		stack;
	vector<string>	res;

	init(n, num);

	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur < num[i]) {
			while (++cur <= num[i])
				push(stack, res, cur);
			pop(stack, res);
			cur--;
		}

		else {
			if (num[i] != stack.back()) {
				cout << "NO\n";
				return 0;
			}
			pop(stack, res);
		}
	}

	for (unsigned int i = 0; i < res.size(); i++)
		cout << res[i];

	return 0;
}