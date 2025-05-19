#include <iostream>

using namespace std;

//내 코드
int main(){
	int scale, pre = 0;
	bool a = true, d = true;

	for(int i = 0; i < 8; i++){
		cin >> scale;
		if(!pre) pre = scale;
		else{
			if(scale - pre != 1) a = false;
			if(pre - scale != 1) d = false;
			pre = scale;
		}
	}

	if(a == true) cout << "ascending\n";
	else if(d == true) cout << "descending\n";
	else cout << "mixed\n";
}

//더 좋은 코드
int main(){
	int scale, a, d;
	a = d = 0;

	for(int i = 0; i < 8; i++){
		cin >> scale;
		if(scale == i + 1) a++;
		if(scale == 8 - i) d++;
	}

	if(a == 8) cout << "ascending\n";
	else if(d == 8) cout << "descending\n";
	else cout << "mixed\n";

	return 0;
}

	