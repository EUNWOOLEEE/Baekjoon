#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char site[21];
	char pswd[21];
} memo;

memo list[100001];

int cmp(const void *a, const void *b)
{
	memo *A = (memo *)a;
	memo *B = (memo *)b;

	return (strcmp(A->site, B->site));
}

int b_search(char *str, int n)
{
	int low = 0;
	int high = n - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(!strcmp(list[mid].site, str))
			return mid;
		else if(strcmp(list[mid].site, str) > 0)
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
		scanf("%s %s", list[i].site, list[i].pswd);

	qsort(list, n, sizeof(list[0]), cmp);

	char to_find[21];
	for(int i = 0; i < m; i++)
	{
		scanf("%s", to_find);
		int pos = b_search(to_find, n);
		printf("%s\n", list[pos].pswd);
	}
	
	return 0;
}