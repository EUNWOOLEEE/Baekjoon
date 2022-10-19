#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int first_idx;
	int coor;
	int num;
} numtype;

int n;
numtype arr[1000000] = {0,};

void init()
{
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].coor);
		arr[i].first_idx = i;
	}
}

int cmp1(const void *a, const void *b)
{
	numtype *A = (numtype *)a;
	numtype *B = (numtype *)b;

	return (A->coor - B->coor);
}

int cmp2(const void *a, const void *b)
{
	numtype *A = (numtype *)a;
	numtype *B = (numtype *)b;

	return (A->first_idx - B->first_idx);
}

void count()
{
	for(int i = 1; i < n; i++)
	{
		if(arr[i].coor != arr[i - 1].coor)
			arr[i].num = (arr[i - 1].num + 1);

		else
			arr[i].num = arr[i - 1].num;
	}
}

int main()
{
	scanf("%d", &n);
	init();

	qsort(arr, n, sizeof(arr[0]), cmp1);

	count();

	qsort(arr, n, sizeof(arr[0]), cmp2);

	for(int i = 0; i < n; i++)
		printf("%d ", arr[i].num);
		
	return 0;
}