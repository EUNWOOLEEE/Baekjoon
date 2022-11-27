#include <stdio.h>
#include <string.h>
#define MAX 10000

int queue[MAX];
int f_index = 0;
int b_index = 0;

int empty()
{
	if(f_index == b_index)
		return 1;
	return 0;
}

void push(int num)
{
	queue[b_index++] = num;
}

int pop()
{
	if(empty())
		return -1;
	return queue[f_index++];
}

int front()
{
	if(empty())
		return -1;
	return queue[f_index];
}

int back()
{
	if(empty())
		return -1;
	return queue[b_index - 1];
}

int size()
{
	return b_index - f_index;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	while(N--)
	{
		char order[6] = {0,};
		scanf("%s", order);

		if(!strcmp(order, "push"))
		{
			int num;
			scanf("%d", &num);
			push(num);
		}

		else if(!strcmp(order, "pop"))
			printf("%d\n", pop());

		else if(!strcmp(order, "size"))
			printf("%d\n", size());

		else if(!strcmp(order, "empty"))
			printf("%d\n", empty());

		else if(!strcmp(order, "front"))
			printf("%d\n", front());

		else if(!strcmp(order, "back"))
			printf("%d\n", back());
	}
	return 0;
}