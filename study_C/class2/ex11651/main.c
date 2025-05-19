#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} coordinates;

int cmp(const void *a, const void *b)
{
	coordinates *A = (coordinates *)a;
	coordinates *B = (coordinates *)b;

	if(A->y == B->y)
		return (A->x - B->x);
	return (A->y - B->y);
}

int main()
{
	int n;
	scanf("%d", &n);

	coordinates dot[100000];
	for(int i = 0; i < n; i++)
		scanf("%d %d", &dot[i].x, &dot[i].y);

	qsort(dot, n, sizeof(dot[0]), cmp);

	for(int i = 0; i < n; i++)
		printf("%d %d\n", dot[i].x, dot[i].y);
}