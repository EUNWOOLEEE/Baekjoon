#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

int t, a, b;
int cur, next;
int front, rear;
char cmd[MAX + 1] = {0,};
int queue[MAX + 1] = {0,};
int visited[MAX + 1] = {0,};
void (*fp[4])(void);
char cmd_type[5] = "DSLR";

void D()
{
	next = cur * 2;
	
	if(next > MAX - 1)
		next = next % MAX;
}

void S()
{
	next = cur - 1;

	if(!next || !cur)
		next = 9999;
}

void L()
{
	next = ((cur % 1000) * 10) + (cur / 1000);
}

void R()
{
	next = ((cur % 10) * 1000) + (cur / 10);
}

void print_rec(int num)
{
	if(num == a)
		return ;

	if(visited[num] >= 0)
	{
		print_rec(visited[num]);

		printf("%c", cmd[num]);
	}
	return ;
}

void bfs(void(*fp[])(void))
{
	cur = a;
	queue[rear++] = cur;
	visited[cur] = -1;

	while(front < rear)
	{
		cur = queue[front++];

		if(!cur)
		{
			fp[1]();

			if(!visited[next])
			{
				visited[next] = cur;
				queue[rear++] = next;
				cmd[next] = cmd_type[1];
			}

			if(next == b)
				return (print_rec(next));
		}

		else
			for(int i = 0; i < 4; i++)
			{
				fp[i]();

				if(cur == next)
					continue ;

				if(!visited[next])
				{
					visited[next] = cur;
					queue[rear++] = next;
					cmd[next] = cmd_type[i];
				}

			if(next == b)
				return (print_rec(next));
			}
	}
}

void clear()
{
	front = rear = 0;

	for(int i = 0; i <= MAX; i++)
	{
		cmd[i] = 0;
		visited[i] = 0;
		queue[i] = 0;
	}
}

int main()
{
	scanf("%d", &t);

	fp[0] = D;
	fp[1] = S;
	fp[2] = L;
	fp[3] = R;

	while(t--)
	{
		scanf("%d %d", &a, &b);

		clear();
		bfs(fp);
		printf("\n");
	}

	return 0;
}