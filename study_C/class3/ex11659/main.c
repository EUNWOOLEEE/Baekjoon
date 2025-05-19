#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int arr[100001] = {0,};
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	int sum[100001] = {0,};
	sum[0] = 0;
	for(int j = 1; j <= n; j++)
		sum[j] += sum[j - 1] + arr[j];

	int a, b;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);

		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}