#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	int idx;
	char name[101];
} member;

int compare(const void *a, const void *b)
{
	member* A = (member*)a;
	member* B = (member*)b;

	if(A->age == B->age)
		return (A->idx - B->idx);
	return A->age - B->age;
}

int main()
{
	int N;
	member list[100000];

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		scanf(" %d %s", &list[i].age, list[i].name);
		list[i].idx = i;
	}

	qsort(list, N, sizeof(list[0]), compare);

	for(int i = 0; i < N; i++)
		printf("%d %s\n", list[i].age, list[i].name);
	return 0;
}