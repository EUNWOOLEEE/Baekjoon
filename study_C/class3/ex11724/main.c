#include <stdio.h>

int n, m;
int link[1001][1001] = {0,};
int visited[1001] = {0,};

void dfs(int num)
{
	visited[num]++;

	for(int i = 1; i <= n; i++)
		if(link[num][i] && !visited[i])
			dfs(i);
	
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++)
	{
		int x, y;

		scanf("%d %d", &x ,&y);
		link[x][y]++;
		link[y][x]++;
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			cnt++;
			dfs(i);
		}
	}

	printf("%d\n", cnt);
	return 0;
}