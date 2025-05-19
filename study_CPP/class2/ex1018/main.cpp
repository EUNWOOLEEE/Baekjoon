#include <iostream>

using namespace std;

#define MODULAR(i,j) ((i - j) % 2)
#define EVEN 0
#define ODD 1

int res = INT32_MAX;

void check_map(string map[], int row, int col, char first, char second){
	int cnt = 0;

	for(int i = row; i < row + 8; i++){
		for(int j = col; j < col + 8; j++){
			if(MODULAR(i, row) == EVEN){
				if((MODULAR(j, col) == EVEN && map[i][j] != first)
					|| (MODULAR(j, col) == ODD && map[i][j] != second))
					cnt++;
			}
			else{
				if((MODULAR(j, col) == EVEN && map[i][j] != second)
					|| (MODULAR(j, col) == ODD && map[i][j] != first))
					cnt++;
			}
		}
	}
	res = res > cnt ? cnt : res;
}

int main(){
	int N, M;
	cin >> N >> M;
	cin.ignore();

	string map[N];
	for(int i = 0; i < N; i++)
		getline(cin, map[i]);

	for(int i = 0; i <= N - 8; i++){
		for(int j = 0; j <= M - 8; j++){
			check_map(map, i, j, 'B', 'W');
			check_map(map, i, j, 'W', 'B');
		}
	}

	cout << res;
	return 0;
}