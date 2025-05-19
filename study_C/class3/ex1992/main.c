#include <stdio.h>

int n;
int map[64][64] = {0,};

int check(int row, int col, int half)
{
	int criteria = map[row][col];

	for(int i = row; i < half + row; i++)
		for(int j = col; j < half + col; j++)
			if(criteria != map[i][j])
				return 0;
	return 1;
}

void rec(int row, int col, int size)
{
	int half = size / 2;

	if(check(row, col, size))
		printf("%d", map[row][col]);

	else
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
			{
				if(!i && !j) printf("(");

				rec(half * i + row, half * j + col, half);
				
				if(i && j) printf(")");
			}
	}

void init()
{
	char str[65] = {0,};

	for(int i = 0; i < n; i++)
	{
		scanf("%s", str);
		for(int j = 0; j < n; j++)
			map[i][j] = str[j] - '0';
	}
}

int main()
{
	scanf("%d", &n);
	
	init();
	
	rec(0, 0, n);

	return 0;
}