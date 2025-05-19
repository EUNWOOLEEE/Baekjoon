#include <stdio.h>
#include <stdlib.h>

int num = 0;
int N, R, C;

void rec(int row, int col, int size)
{
	if(!row && !col) return ;

	int half = size / 2;
	int r = row / half;
	int c = col / half;

	if(!r && !c) //왼쪽 위 구역	
		num += half * half * 0;

	else if(!r && c) //오른쪽 위
		num += half * half * 1;

	else if(r && !c) //왼쪽 아래
		num += (half * half) * 2;
			
	else //r && c, 오른쪽 아래
		num += (half * half) * 3;

	rec(row % half, col % half, size / 2);
}

int main()
{
	scanf("%d %d %d", &N, &R, &C);

	int size = 1;
	while(N--)
		size *= 2;
	
	rec(R, C, size);

	printf("%d\n", num);
	return 0;
}