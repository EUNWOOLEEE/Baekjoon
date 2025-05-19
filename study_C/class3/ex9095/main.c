#include <stdio.h>

int main()
{
	int t, n, i;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		int dp[12] = {0,};
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for(i = 4; i <= n; i++)
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		
		printf("%d\n", dp[n]);
	}
	return 0;
}