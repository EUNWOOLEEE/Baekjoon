#include <stdio.h>
#define min(a, b) a < b ? a : b

int main()
{
	int n;
	scanf("%d", &n);

	int dp[50001] = {0,};
	dp[1] = 1;

	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[1] + dp[i - 1];

		for(int j = 2; j * j <= i; j++)
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
	}

	printf("%d\n", dp[n]);
	return 0;
}