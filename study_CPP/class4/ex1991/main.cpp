#include <iostream>
#include <map>

using namespace std;

map < char, pair<char, char> > input;

void preorder(char cur) {
	cout << cur;

	if (input[cur].first != '.')
		preorder(input[cur].first);
	if (input[cur].second != '.')
		preorder(input[cur].second);
}

void inorder(char cur) {
	if (input[cur].first != '.')
		inorder(input[cur].first);

	cout << cur;

	if (input[cur].second != '.')
		inorder(input[cur].second);
}

void postorder(char cur) {
	if (input[cur].first != '.')
		postorder(input[cur].first);

	if (input[cur].second != '.')
		postorder(input[cur].second);

	cout << cur;
}

int main() {
	int node;
	cin >> node;

	for (int i = 0; i < node; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;

		input[parent] = make_pair(left, right);
	}

	preorder('A');
	cout << "\n";

	inorder('A');
	cout << "\n";

	postorder('A');
	cout << "\n";

	return 0;
}