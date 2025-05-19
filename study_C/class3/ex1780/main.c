#include <stdio.h>

int paper[2187][2187] = {0,};
int res[3] = {0,};

void init(int n)
{
	int num;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &num);
			paper[i][j] = ++num;
		}
}

int check(int row, int col, int size)
{
	int start = paper[row][col];

	for(int i = row; i < row + size; i++)
		for(int j = col; j < col + size; j++)
			if(paper[i][j] != start)
				return 0;
	return 1;
}

void divide(int row, int col, int size)
{
	if(check(row, col, size))
		res[paper[row][col]]++;

	else
	{
		size /= 3;

		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				divide(row + size * i, col + size * j, size);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	init(n);
	divide(0, 0, n);

	printf("%d\n%d\n%d\n", res[0], res[1], res[2]);

	return 0;
}