#include <stdio.h>

int main()
{
	int N, num, count, res;

	res = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		count = 0;
		for(int j = 1; j <= num; j++)
		{
			if(num % j == 0)
				count++;
		}
		if(count == 2)
			res++;
	}
	printf("%d", res);
	return 0;
}