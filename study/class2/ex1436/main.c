#include <stdio.h>

int is_end(int num)
{
	int cnt = 0;

	while (num)
	{
		if ((num % 10) == 6)
			cnt++;
		else
			cnt = 0;
		num /= 10;
		if (cnt == 3)
			return 1;
	}
	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);

	int i = 0, cnt = 0;
	while (1)
	{
		i++;
		if (is_end(i))
			cnt++;
		if (cnt == N)
			break;
	}
	printf("%d", i);
}