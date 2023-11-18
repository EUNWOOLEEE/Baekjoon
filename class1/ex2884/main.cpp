#include <iostream>

using namespace std;

#define hour_sec 3600
#define min_sec 60

int main(){
	string alarm;
	getline(cin, alarm);

	int h, m, idx;
	h = m = idx = 0;
	while(alarm[idx] != ' ')
		h = h * 10 + (alarm[idx++] - '0');
	idx++;
	while(alarm[idx] != '\0')
		m = m * 10 + (alarm[idx++] - '0');

	int time = h * hour_sec;
	time += m * min_sec;

	int fourty_five = 45 * min_sec;
	if (time - fourty_five < 0)
		time = (23 * hour_sec) + (60 * min_sec) - (fourty_five - time);
	else
		time -= fourty_five;
	
	h = time / hour_sec;
	time %= hour_sec;
	m = time / min_sec;

	cout << h << " " << m << endl;
	
	return 0;
}