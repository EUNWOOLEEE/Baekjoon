#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[21];
	char idx[7];
} pokemon;

pokemon list[100001];
pokemon tmp[100001];

int cmp(const void *a, const void *b)
{
	pokemon *A = (pokemon *)a;
	pokemon *B = (pokemon *)b;

	return(strcmp(A->name, B->name));
}

int b_search_name(char *name, int n)
{
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if(!strcmp(list[mid].name, name))
			return mid;
		else if(strcmp(list[mid].name, name) > 0)
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
	{
		scanf("%s", list[i].name);
		strcpy(tmp[i].name, list[i].name);
		sprintf(list[i].idx, "%d", i + 1);
	}
	
	qsort(list, n, sizeof(list[0]), cmp);

	char cmd[21] = {0,};
	int pos;

	for(int i = 0; i < m; i++)
	{
		scanf("%s", cmd);

		if(cmd[0] >= '1' && cmd[0] <= '9')
		{
			pos = atoi(cmd);
			printf("%s\n", tmp[pos - 1].name);
		}
		else
		{
			pos = b_search_name(cmd, n);
			printf("%s\n", list[pos].idx);
		}
	}
	return 0;
}