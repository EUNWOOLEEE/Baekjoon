#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char never_heard[500001][21] = {0,};
char never_seen[500001][21] = {0,};
char list[500001][21] = {0,};

int cmp(const void *a, const void *b)
{
	return(strcmp((char *)a, (char *)b));
}

int b_seach(char *str, int n)
{
	int low = 0;
	int high = n - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(!strcmp(never_seen[mid], str))
			return 1;
		else if(strcmp(never_seen[mid], str) > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%s", never_heard[i]);

	for(int i = 0; i < m; i++)
		scanf("%s", never_seen[i]);

	qsort(never_heard, n, sizeof(never_heard[0]), cmp);
	qsort(never_seen, m, sizeof(never_seen[0]), cmp);

	int idx = 0;
	for(int i = 0; i < n; i++)
		if(b_seach(never_heard[i], m))
			strcpy(list[idx++], never_heard[i]);
	list[idx][0] = 0;

	printf("%d\n", idx);
	for(int i = 0; list[i][0]; i++)
		printf("%s\n", list[i]);
}