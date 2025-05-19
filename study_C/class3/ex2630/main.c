#include <stdio.h>

int paper[128][128] = {0,};
int res[2] = {0,};

void init(int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &paper[i][j]);
}

int check(int row, int col, int size)
{
	int start = paper[row][col];

	for(int i = row; i < row + size; i++)
		for(int j = col; j < col + size; j++)
			if(start != paper[i][j])
				return 0;
	return 1;
}

void divide(int row, int col, int size)
{
	if(check(row, col, size))
		res[paper[row][col]]++;

	else
	{
		size /= 2;

		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				divide(row + size * i, col + size * j, size);
	}

}

int main()
{
	int n;
	scanf("%d", &n);
	
	init(n);
	divide(0, 0, n);
	printf("%d\n%d\n", res[0], res[1]);

	return 0;
}