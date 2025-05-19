#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	int n;
	for(int i = 0; i < t; i++)
	{
		int b_zero, zero, b_one, one;
		scanf("%d", &n);

		if(!n)
		{
			printf("1 0\n");
			continue;
		}
		else if(n == 1)
		{
			printf("0 1\n");
			continue;
		}
		else
		{
			b_zero = 0, b_one = 1;
			zero = 1, one = 1;
			int sum;

			for(int i = 2; i < n; i++)
			{
				sum = b_zero + zero;
				b_zero = zero;
				zero = sum;

				sum = b_one + one;
				b_one = one;
				one = sum;
			}
		}
		printf("%d %d\n", zero, one);
	}

	return 0;
}