#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} coordinate;

int compare(const void *a, const void *b)
{
	coordinate* A = (coordinate*)a;
	coordinate* B = (coordinate*)b;

	if(A->x == B->x)
		return A->y - B->y;
	return A->x - B->x;
}

int main()
{
	int N;
	coordinate dot[100000];

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &dot[i].x, &dot[i].y);
	}

	qsort(dot, N, sizeof(dot[0]), compare);

	for(int i = 0; i < N; i++)
	{
		printf("%d %d\n", dot[i].x, dot[i].y);
	}
	return 0;
}