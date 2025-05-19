#include <stdio.h>

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int max = 0;
	int trees[1000000];

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &trees[i]);
		if(trees[i] > max)
			max = trees[i];
	}

	long long find_height;
	long long start = 0;
	long long end = max;
	while(start <= end)
	{
		long long sum = 0;
		long long mid = (start + end) / 2;
		
		for(int i = 0; i < N; i++)
			if(mid < trees[i])
				sum += trees[i] - mid;

		if(sum >= M)
		{
			find_height = mid;
			start = mid + 1;
		}

		else		
			end = mid - 1;
	}
	printf("%lld", find_height);
	return 0;
}