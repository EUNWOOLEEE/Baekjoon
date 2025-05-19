#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int n, idx = 0;
int ans[MAX * MAX] = {0,};
int map[MAX][MAX] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void dfs(int row, int col, int idx)
{
	if(row < 0 || col < 0 || row >= n || col >= n)
		return ;

	if(map[row][col])
	{
		ans[idx]++;
		map[row][col] = 0;

		for(int i = 0; i < 4; i++)
			dfs(row + dx[i], col + dy[i], idx);
	}
}

void init()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);
}

int main()
{
	init();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(map[i][j])
				dfs(i, j, idx++);

	qsort(ans, idx, sizeof(ans[0]), cmp);

	printf("%d\n", idx);
	for(int i = 0; i < idx; i++)
		printf("%d\n", ans[i]);

	return 0;
}