#include <stdio.h>
#include <stdlib.h>

void dfs(int depth, int cur, int n, int m, int *arr)
{
	if (depth >= m || cur > n)
		return ;
	arr[depth] = cur;
	if(depth == m - 1)
	{
		for(int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}

	dfs(depth + 1, cur + 1, n, m, arr);
	dfs(depth, cur + 1, n, m, arr);
}

int main()
{
	int N, M;
	int *arr;

	scanf("%d %d", &N, &M);

	arr = (int *)malloc(sizeof(int) * M);
	dfs(0, 1, N, M, arr);
	return 0;
}
