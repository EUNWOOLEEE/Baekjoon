#include <stdio.h>
#define MAX 101

typedef struct
{
	int x;
	int y;
} coor;

int n, m;
int front = 0, rear = 0;
int map[MAX][MAX] = {0,}; //입력받은 값
int ans[MAX][MAX] = {0,}; //거리 기록용
coor queue[MAX * MAX] = {0,};

void bfs()
{
	coor cur, next;

	int dx[4] = {-1, +1, 0, 0}; //상하
	int dy[4] = {0, 0, -1, +1}; //좌우

	cur.x = cur.y = 1;
	ans[cur.x][cur.y] = 1;
	queue[rear++] = cur;

	while(front < rear)
	{
		cur = queue[front++];

		for(int i = 0; i < 4; i++)
		{
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if(next.x < 1 || next.x > n || next.y < 1 || next.y > m)
				continue;

			if(!map[next.x][next.y])
				continue;

			if(!ans[next.x][next.y])
			{
				queue[rear++] = next;
				ans[next.x][next.y] = ans[cur.x][cur.y] + 1;
			}
		}
	}
}

void init()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);
}

int main()
{
	scanf("%d %d", &n, &m);
	init();
	bfs();
	printf("%d\n", ans[n][m]);

	return 0;
}