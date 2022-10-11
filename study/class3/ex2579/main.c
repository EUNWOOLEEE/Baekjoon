#include <stdio.h>

#define MAX(a,b) a > b ? a : b

int main()
{
	int n;
	int stairs[301] = {0,};
	int score[301] = {0,};

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &stairs[i]);

	score[0] = 0;
	score[1] = stairs[1];
	score[2] = stairs[1] + stairs[2];
	
	for(int i = 3; i <= n; i++)
		score[i] = stairs[i] + (MAX(score[i - 2], score[i - 3] + stairs[i - 1]));

	printf("%d\n", score[n]);
	return 0;
}