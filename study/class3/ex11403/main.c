#include <stdio.h>
#define MAX 100

int n;
int map[MAX][MAX] = {0,};

void init()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
}

void find_route()
{
	for(int k = 0; k < n; k++) //k를 거쳐
		for(int i = 0; i < n; i++) //i에서
			for(int j = 0; j < n; j++) //j로 갈 때
				//k를 거쳐가는 두 경로가 모두 가능할 때 업데이트
				if((map[i][k] && map[k][j]))
					map[i][j] = 1;
}

int main()
{
	scanf("%d", &n);
	init();
	find_route();

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}

	return 0;
}