#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct
{
	int start;
	int end;
} meeting;

int cmp(const void *a, const void *b)
{
	meeting *A = (meeting *)a;
	meeting *B = (meeting *)b;

	if(A->end == B->end)
		return (A->start - B->start);
	return (A->end - B->end);
}

int main()
{
	int n;
	scanf("%d", &n);

	meeting time[MAX] = {0,};
	for(int i = 0; i < n; i++)
		scanf("%d %d", &time[i].start, &time[i].end);

	qsort(time, n, sizeof(meeting), cmp);

	int cnt = 0, cur_end = 0;
	for(int i = 0; i < n; i++)
		if(cur_end <= time[i].start)
		{
			cur_end = time[i].end;
			cnt++;
		}

	printf("%d\n", cnt);
	
	return 0;
}