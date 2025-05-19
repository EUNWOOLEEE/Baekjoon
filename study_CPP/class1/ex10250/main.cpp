#include <iostream>

using namespace std;

int main(){
	int t, h, w, n;
	cin >> t;

	while(t--){
		int floor, room;
		cin >> h >> w >> n;

		for(room = 1; room <= w; room++){
			for(floor = 1; floor <= h; floor++)
				if(!--n) break;
			if(!n) break;
		}

		if(room < 10) cout << floor << "0" << room << endl;
		else cout << floor << room << endl;
	}
	return 0;
}