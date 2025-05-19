#include <stdio.h>
#define MAX 100

typedef struct
{
	int x, y;
} pos;

int n, res1, res2; //1: no blindness, 2: blindness
int front = 0, rear = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char map[MAX][MAX] = {0,};
pos queue[MAX * MAX] = {0,};

void init()
{
	scanf("%d", &n);

	char color[101];
	for(int i = 0; i < n; i++)
	{
		scanf("%s", color);
		for(int j = 0; j < n; j++)
		{
			if(color[j] == 'R')
				map[i][j] = 1;

			else if(color[j] == 'G')
				map[i][j] = 2;
			
			else // 'B'
				map[i][j] = 3;
		}
	}
}

void bfs(int row, int col, int start)
{
	pos cur, next;
	int modi;

	cur.x = row;
	cur.y = col;
	queue[rear++] = cur;

	if(start == 1)
		modi = start + 3;
	else
		modi = start + 2;
	map[row][col] = modi;

	while(front < rear)
	{
		cur = queue[front++];

		for(int i = 0; i < 4; i++)
		{
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if(next.x < 0 || next.y < 0 || next.x >= n || next.y >= n) ;

			else if(map[next.x][next.y] == start)
			{
				map[next.x][next.y] = modi;
				queue[rear++] = next;
			}
		}
	}
}

int main()
{
	init();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3)
			{
				res1++;
				bfs(i, j, map[i][j]);
			}

	front = rear = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(map[i][j] == 4 || map[i][j] == 5)
			{
				res2++;
				bfs(i, j, map[i][j]);
			}

	printf("%d %d\n", res1, res2);

	return 0;
}