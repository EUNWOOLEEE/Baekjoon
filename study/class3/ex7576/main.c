#include <stdio.h>
#define MAX 1000

typedef struct
{
	int x, y;
} coor;

int row, col, res = 0;
int front = 0, rear = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int box[MAX][MAX];
coor queue[MAX * MAX];

void bfs()
{
	coor cur, next;
	
	while(front < rear)
	{
		cur = queue[front++];

		for(int i = 0; i < 4; i++)
		{
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if(next.x < 0 || next.y < 0 || next.x >= row || next.y >= col)
				continue;

			if((!box[next.x][next.y]))
			{
				queue[rear++] = next;
				box[next.x][next.y] = box[cur.x][cur.y] + 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &col, &row);

	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		{
			scanf("%d", &box[i][j]);

			if(box[i][j] == 1)
			{
				queue[rear].x = i;
				queue[rear++].y = j;
			}
		}

	bfs();

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(!box[i][j])
			{
				printf("-1\n");
				return 0;
			}
			
			if(res < box[i][j])
				res = box[i][j];
		}
	}
	printf("%d\n", res - 1);

	return 0;
}