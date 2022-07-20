#include <stdio.h>
#include <stdlib.h>

#define MAX 500000

int arr1[MAX] = {0,};
int arr2[MAX] = {0,};

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else
		return -1;
	return 0;
}

int upper_bound(int num, int n)
{
	int start = 0;
	int end = n - 1;

	while(start < end)
	{
		int mid = (start + end) / 2;

		if(arr1[mid] <= num)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

int lower_bound(int num, int n)
{
	int start = 0;
	int end = n - 1;

	while(start < end)
	{
		int mid = (start + end) / 2;

		if(arr1[mid] < num)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr1[i]);

	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
		scanf("%d", &arr2[i]);

	qsort(arr1, N, sizeof(int), cmp);

	for(int i = 0; i < M; i++)
	{
		if(arr2[i] == arr1[N - 1])
		{
			printf("%d ", upper_bound(arr2[i], N) - lower_bound(arr2[i], N) + 1);
			continue;
		}
		printf("%d ", upper_bound(arr2[i], N) - lower_bound(arr2[i], N));
	}
}