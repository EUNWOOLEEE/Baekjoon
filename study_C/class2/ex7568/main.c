#include <stdio.h>

typedef struct
{
	int w;
	int h;
	int ranking;
} build;

int main()
{
	int n;
	scanf("%d", &n);

	build person[50];
	for(int i = 0; i < n; i++)
		scanf("%d %d", &person[i].w, &person[i].h);

	int cnt;
	for(int i = 0; i < n; i++)
	{
		cnt = 1;
		for(int j = 0; j < n; j++)
		{
			if(person[i].w < person[j].w && person[i].h < person[j].h)
				cnt++;
		}
		person[i].ranking = cnt;
	}

	for(int i = 0; i < n; i++)
		printf("%d ", person[i].ranking);
}