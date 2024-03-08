#include <stdio.h>

int n, m;
int arr[8];
int check[9];

void dfs(int depth)
{
	int i;

	if(depth == m)
	{
		for(i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return ;
	}

	else
	{
		for(i = 1; i <= n; i++)
		{
			check[i]++;
			if(check[i] > 1)
				continue ;
			arr[depth] = i;
			dfs(depth + 1);
			check[i] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0);
}
