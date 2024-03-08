#include <iostream>

using namespace std;

int main() {
	int cities;
	int distance[100001] = {0};
	unsigned long long cost[100001] = {0};
	
	cin >> cities;
	for (int i = 0; i < cities - 1; i++)
		cin >> distance[i];
	for (int i = 0; i < cities; i++)
		cin >> cost[i];
		
	unsigned long long res = cost[0] * distance[0];
	unsigned long long prev_min_cost = cost[0];
	
	for (int i = 1; i < cities; i++) {
		prev_min_cost = prev_min_cost < cost[i] ? prev_min_cost : cost[i];

		res += prev_min_cost * distance[i];
	}

	cout << res << "\n";

	return 0;
}