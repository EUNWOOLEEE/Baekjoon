#include <stdio.h>
#define MAX 101

int n, m;
int queue[MAX] = {0,};
int visited[MAX] = {0,};
int path_len[MAX] = {0,};
int link[MAX][MAX] = {0,};

void init()
{
	while(m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		link[x][y]++;
		link[y][x]++;
	}
}

void bfs(int user)
{
	int front = 0, rear = 0;

	queue[rear++] = user;
	visited[user]++;

	int num;
	while(front < rear)
	{
		num = queue[front++];

		for(int i = 1; i <= n; i++)
			if(link[num][i] && !visited[i])
			{
				queue[rear++] = i;
				visited[i]++;
				path_len[i] = path_len[num] + 1;
			}
	}
}

void reset()
{
	for(int i = 1; i <= n; i++)
	{
		visited[i] = 0;
		path_len[i] = 0;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	init();

	int sum, res, min = 100000;

	for(int i = 1; i <= n; i++)
	{
		reset();
		bfs(i);

		sum = 0;
		for(int j = 1; j <= n; j++)
			sum += path_len[j];	

		if(min > sum)
		{
			min = sum;
			res = i;
		}
	}

	printf("%d", res);

	return 0;
}