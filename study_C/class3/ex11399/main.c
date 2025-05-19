#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n;
	scanf("%d", &n);

	int time[1000] = {0,};
	for(int i = 0; i < n; i++)
		scanf("%d", &time[i]);

	qsort(time, n, sizeof(time[0]), cmp);

	int sum = 0, res = 0;
	for(int i = 0; i < n; i++)
	{
		sum += time[i];
		res += sum;
	}

	printf("%d\n", res);
	return 0;
}