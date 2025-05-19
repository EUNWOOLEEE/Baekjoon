#include <stdio.h>

int width, length;
int map[50][50] = {0,};

void rec(int x, int y)
{
	if(!map[x][y])
		return ;
	if(map[x][y])
	{
		map[x][y] = 0;

		if(map[x - 1][y] && x) //상
			rec(x - 1, y);
		if(map[x + 1][y] && x != length -1) //하
			rec(x + 1, y);
		if(map[x][y - 1] && y) //좌
			rec(x, y - 1);
		if(map[x][y + 1] && y != width -1) //우
			rec(x, y + 1);
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int k;
		scanf("%d %d %d", &width, &length, &k);

		int x, y;
		while(k--)
		{
			scanf("%d %d", &x, &y);
			map[y][x]++;
		}

		int cnt = 0;
		for(int i = 0; i < length; i++)
		{
			for(int j = 0; j < width; j++)
			{
				if(map[i][j])
				{
					cnt++;
					rec(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}