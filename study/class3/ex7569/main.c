#include <stdio.h>
#define MAX 100

typedef struct
{
	int x, y, h;
} pos;

int page, row, col, res = 0;
int front = 0, rear = 0;
int dh[6] = {-1, 1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int box[MAX][MAX][MAX];
pos queue[MAX * MAX * MAX] ;

void init()
{
	scanf("%d %d %d", &col, &row, &page);
	
	for(int i = 0; i < page; i++)
		for(int j = 0; j < row; j++)
			for(int k = 0; k < col; k++)
			{
				scanf("%d", &box[i][j][k]);

				if(box[i][j][k] == 1)
				{
					queue[rear].h = i;
					queue[rear].x = j;
					queue[rear++].y = k;
				}
			}
}

int is_possible(int h, int x, int y)
{
	if(h < 0 || x < 0 || y < 0 || h >= page || x >= row || y >= col)
		return 0;
	return 1;
}

void bfs()
{
	pos cur, next;

	while(front < rear)
	{
		cur = queue[front++];

		for(int i = 0; i < 6; i++)
		{
			next.h = cur.h + dh[i];
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];

			if(!is_possible(next.h, next.x, next.y)) ;

			else if(!box[next.h][next.x][next.y])
			{
				box[next.h][next.x][next.y] = box[cur.h][cur.x][cur.y] + 1;
				queue[rear++] = next;
			}
		}
	}
}

int main()
{
	init();
	bfs();

	for(int i = 0; i < page; i++)
		for(int j = 0; j < row; j++)
			for(int k = 0; k < col; k++)	
			{
				if(!box[i][j][k])
				{
					printf("-1\n");
					return 0;
				}

				if(res < box[i][j][k])
					res = box[i][j][k];
			}
	
	printf("%d\n", res - 1);

	return 0;
}