#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int arr[500000];
int frequency[8001];

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	return 0;
}

int main()
{
	int N;
	scanf("%d",&N);

	double sum = 0;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		frequency[arr[i] + 4000]++;
	}

	qsort(arr, N, sizeof(int), cmp);

	int max = 0;
	int find_value;
	for(int i = 0; i < 8001; i++)
	{
		if(frequency[i] > max)
		{
			max = frequency[i];
			find_value = i;
		}
	}

	for(int i = find_value + 1; i < 8001; i++)
	{
		if(frequency[i] == max)
		{
			find_value = i;
			break;
		}
	}

	printf("%d\n", (int)round(sum / N)); //산술평균
	printf("%d\n", arr[(N - 1) / 2]); //중앙값
	printf("%d\n", find_value - 4000); //최빈값
	printf("%d\n", arr[N - 1] - arr[0]); //범위
	return 0;
}