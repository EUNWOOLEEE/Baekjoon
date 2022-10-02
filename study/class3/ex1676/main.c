#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int cnt = 0, tmp = 0;
	for(int i = 5; i <= n; i++)
	{
		tmp = i;
		while(!(tmp % 5))
		{
			tmp /= 5;
			cnt++;
		}
	}

	printf("%d", cnt);
}