#include <stdio.h>
#define MAX 100001

int n, k;
int sec[MAX] = {0,};
int queue[MAX] = {0,};
int visited[MAX] = {0,};

void bfs()
{
	int x = n;
	int front = 0, rear = 0;
	
	queue[rear++] = x;

	while(front < rear)
	{
		x = queue[front++];

		if(x == k) break;

		if(!visited[x - 1])
		{
			queue[rear++] = x - 1;
			sec[x - 1] = sec[x] + 1;
			visited[x - 1]++;
		}

		if(!visited[x + 1] && x + 1 <= 100000)
		{
			queue[rear++] = x + 1;
			sec[x + 1] = sec[x] + 1;
			visited[x + 1]++;
		}

		if(!visited[x * 2] && x * 2 <= 100000)
		{
			queue[rear++] = x * 2;
			sec[x * 2] = sec[x] + 1;
			visited[x * 2]++;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);

	bfs();

	printf("%d\n", sec[k]);

	return 0;
}