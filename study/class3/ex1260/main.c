#include <stdio.h>
#define MAX 1001

int n, m, v;
int visited[MAX] = {0,};
int queue[MAX] = {0,};
int link[MAX][MAX] = {0,};

void clear(int n)
{
	for(int i = 0; i <= n; i++)
		visited[i] = 0;
}

void dfs(int num)
{
	visited[num]++;
	printf("%d ", num);

	for(int i = 0; i <= n; i++)
	{
		if(link[num][i] && !visited[i])
			dfs(i);
	}
}

void bfs(int num)
{
	int next, front = 0, rear = 0;

	visited[num]++;
	printf("%d ", num);
	queue[rear++] = num;

	while(front < rear)
	{
		next = queue[front++];

		for(int i = 0; i <= n; i++)
		{
			if(link[next][i] && !visited[i])
			{
				printf("%d ", i);
				queue[rear++] = i;
				visited[i]++;
			}
		}
	}
	next = queue[front++];
}


int main()
{
	scanf("%d %d %d", &n, &m, &v);

	int x, y;
	while(m--)
	{
		scanf("%d %d", &x ,&y);
		link[x][y]++;
		link[y][x]++;
	}

	dfs(v);

	printf("\n");
	clear(n);
	
	bfs(v);

	return 0;
}