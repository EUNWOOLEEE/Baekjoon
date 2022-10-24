#include <stdio.h>

int gcd(int a, int b)
{
	int tmp;

	while(b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	int t, m, n, x, y;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);

		int i, tmp, limit = lcm(m, n);
		for(i = x; i <= limit; i += m)
		{
			tmp = i % n;
			if(!tmp)
				tmp = n;

			if(tmp == y)
			{
				printf("%d\n", i);
				break;
			}
		}
		if(i > limit)
			printf("-1\n");
	}

	return 0;
}