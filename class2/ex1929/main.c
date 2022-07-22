#include <stdio.h>

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	
	int prime[1000001] = {0,};
	prime[0] = prime[1] = 1;

	for(int i = 2; i * i <= N; i++)
	{
		for(int j = 2; i * j <= N; j++)
			prime[i * j] = 1;
	}

	for(int i = M; i <= N; i++)
	{
		if(!prime[i])
			printf("%d\n", i);
	}
	return 0;
}