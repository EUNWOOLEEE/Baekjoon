#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	int a_len = strlen(a);
	int b_len = strlen(b);

	if(a_len == b_len)
		return strcmp(a, b);
	return (a_len - b_len);
}

int main()
{
	int N;
	char str[20000][51] = {0,};

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%s", str[i]);

	qsort(str, N, sizeof(str[0]), compare);

	for(int i = 0; i < N; i++)
	{
		if(strcmp(str[i + 1], str[i]))
			printf("%s\n", str[i]);
	}
	return 0;
}