#include <stdio.h>
#include <stdlib.h>

int str[1000001] = {0,};

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int N;

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &str[i]);
	
	qsort(str, N, sizeof(int), compare);

	for(int i = 0; i < N; i++)
		printf("%d\n", str[i]);

	return 0;
}