#include <stdio.h>
#define MAX 101

int n, m;
int arr[MAX] = {0,};
int ans[MAX] = {0,};
int queue[MAX] = {0,};

//사다리, 뱀 모두 arr에 입력받음
void init()
{
	scanf("%d %d", &n, &m);
	
	int x, y;
	for(int i = 0; i < n + m; i++)
	{
		scanf("%d %d", &x, &y);
		arr[x] = y;
	}
}

void bfs()
{
	int cur, next;
	int front = 0, rear = 0;
	
	queue[rear++] = 1;

	while(front < rear)
	{
		cur = queue[front++];

		for(int i = 1; i <= 6; i++)
		{
			next = cur + i;

			if(next > 100) continue;

			if(arr[next]) //사다리나 뱀이 있으면 한번 더 이동
				next = arr[next];

			if(!ans[next]) //사다리나 뱀으로 이동한 곳 또는 주사위로 이동한 곳 방문 여부
			{
				queue[rear++] = next;
				ans[next] = ans[cur] + 1;
			}

			if(next == 100)
			{
				printf("%d\n", ans[next]);
				return ;
			}
		}
	}
}

int main()
{
	init();
	bfs();
	return 0;
}