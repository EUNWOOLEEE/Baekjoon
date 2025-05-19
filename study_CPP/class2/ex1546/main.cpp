#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, tmp, max = 0;

	cin >> n;
	vector<float> grade;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		grade.push_back(tmp);
		max = max < tmp ? tmp : max;
	}

	float res = 0;
	for(int i = 0; i < n; i++)
		res += grade[i] / max * 100;
	
	cout << res / n;
	return 0;
}