#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int main()
{
	int t, n;
	scanf("%d", &t);

	while(t--)
	{
		char c[21];
		char type[31][21] = {0,};

		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%s %s\n", c, type[i]);

		qsort(type, n, sizeof(type[0]), cmp);

		int sum = 1, cnt = 1;
		for(int i = 0; i < n; i++)
		{
			if(!strcmp(type[i], type[i + 1]))
				cnt++;
			else
			{
				sum *= (cnt + 1);
				cnt = 1;
			}
		}

		printf("%d\n", sum - 1);
	}
	return 0;
}