#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int a;
	int b;
} computers;

int is_overlap(int *arr, int a)
{
	while(*arr)
	{
		if(*arr == a)
			return 1;
		arr++;
	}
	return 0;
}

void init(computers *A)
{
	A->a = 0;
	A->b = 0;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	computers *list;
	list = (computers *)malloc(sizeof(computers) * m);

	for(int i = 0; i < m; i++)
		scanf("%d %d", &list[i].a, &list[i].b);

	int res[100] = {0,};
	res[0] = 1;
	int idx = 1;

	for(int i = 0; i < m; i++)
	{
		if(!res[i])
			break;
		for(int j = 0; j < m; j++)
		{
			if(res[i] == list[j].a)
			{
				if(!is_overlap(res, list[j].b))
					res[idx++] = list[j].b;
				init(&list[j]);
			}
			else if(res[i] == list[j].b)
			{
				if(!is_overlap(res, list[j].a))
					res[idx++] = list[j].a;
				init(&list[j]);
			}
		}
	}

	printf("%d\n", idx - 1);
	return 0;
}