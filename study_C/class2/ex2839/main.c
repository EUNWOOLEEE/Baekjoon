#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i = 0, three = 0, five = 0;
	while(i < n)
	{
		i += 5;
		five++;
		if(i > n)
		{
			i -= 5;
			five--;
			while(i < n)
			{
				i += 3;
				three++;
				if(!five && i > n)
					break;
				if(i > n)
				{
					i -= 5;
					five--;
					i -= (three * 3);
					three = 0;
				}
			}
		}
	}
	if(i == n)
		printf("%d", five + three);
	else
		printf("-1");
}