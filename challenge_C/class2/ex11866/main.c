#include <stdio.h>

int main()
{
	int N, K;
	int str1[1000] = {0,};
	int str2[1000] = {0,};

	scanf("%d %d", &N, &K);

	int idx1 = 0, idx2 = 0;
	while(idx2 < N)
	{
		int count = 0;

		while(count < K)
		{
			if(idx1 == N)
				idx1 = 0;
			if(str1[idx1] == 0)
			{
				count++;
				idx1++;
			}
			else
				idx1++;
		}
		str1[idx1 - 1] = 1;
		str2[idx2] = idx1;
		idx2++;
	}


	int i;

	printf("<");
	for(i = 0; i < N - 1; i++)
	{
		printf("%d, ", str2[i]);
	}
	printf("%d>", str2[i]);
	return 0;
}