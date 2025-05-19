#include <iostream>
#include <queue>
#include <map>
#include <cstdlib>

using namespace std;

typedef pair<string, string> pis;

map<string, bool>	visited;
queue<pis>			q;

void toDouble(pis& cur) {
	int		next_i = (atoi(cur.first.c_str()) * 2) % 10000;
	string	next_s = to_string(next_i);
	string	res;

	for (unsigned int i = 0; i < 4 - next_s.size(); i++)
		res += '0';
	res += next_s;

	if (visited[res] == false) {
		q.push(make_pair(res, cur.second + 'D'));
		visited[res] = true;
	}
}

void toMinus(pis& cur) {
	int		next_i = atoi(cur.first.c_str());
	string	next_s = to_string(next_i);
	string	res;

	if (next_i == 0)
		next_i = 9999;
	else
		next_i -= 1;

	for (unsigned int i = 0; i < 4 - next_s.size(); i++)
		res += '0';
	res += next_s;
	
	if (visited[res] == false) {
		q.push(make_pair(res, cur.second + 'S'));
		visited[res] = true;
	}
}

void toLeft(pis& cur) {
	string	c(cur.first, 0, 1);
	string	next(cur.first, 1, 3);

	next += c;
	
	if (visited[next] == false) {
		q.push(make_pair(next, cur.second + 'L'));
		visited[next] = true;
	}
}

void toRight(pis& cur) {
	string	c(cur.first, 3, 1);
	string	next(cur.first, 0, 3);

	next = c + next;
	
	if (visited[next] == false) {
		q.push(make_pair(next, cur.second + 'R'));
		visited[next] = true;
	}
}

void bfs(string a, string b) {
	q.push(make_pair(a, ""));
	visited[a] = true;

	while (q.size()) {
		pis cur = q.front();
		q.pop();

		if (cur.first == b) {
			cout << cur.second << "\n";
			break;
		}

		toDouble(cur);
		toMinus(cur);
		toLeft(cur);
		toRight(cur);
	}
}

int main() {
	int tc;
	string a, b;
	cin >> tc;

	while (tc--) {
		visited.clear();
		while (q.size())
			q.pop();

		string zero_a, zero_b;

		cin >> a >> b;

		for (unsigned int i = 0; i < 4 - a.size(); i++)
			zero_a += '0';
		for (unsigned int i = 0; i < 4 - b.size(); i++)
			zero_b += '0';

		bfs(zero_a + a, zero_b + b);
	}

	return 0;
}