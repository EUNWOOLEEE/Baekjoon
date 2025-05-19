#include <stdio.h>
#include <stdlib.h>

int arr[100000] = {0,};

int compare(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else
		return -1;
	return 0;
}

int binary_search(int num, int n)
{
	int low = 0;
	int high = n - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(arr[mid] == num || arr[low] == num || arr[high] == num)
			return 1;
		else if(arr[mid] > num)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main()
{
	int N, M;
	int num;

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	qsort(arr, N, sizeof(arr[0]), compare);

	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &num);
		printf("%d\n", binary_search(num, N));
	}
    return 0;
}