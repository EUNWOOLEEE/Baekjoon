#include <stdio.h>

int arr[1000000] = {0,};

int main()
{
	int N;

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		arr[i] = i + 1;

	if(N == 1)
	{
		printf("%d", N);
		return 0;
	}

	int start = 0;
	for(int i = 0; i <= N - 2; i++)
	{
		int end = N + i;

		arr[start] = 0;
		start++;
			
		arr[end] = arr[start];
		start++;
	}
	printf("%d", arr[start - 1]);
	return 0;
}