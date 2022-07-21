#include <stdio.h>
#include <string.h>
#define MAX 10000

int deque[MAX];
int f_idx = 0, b_idx = 0;
int in = 0, out = 0;

int empty()
{
	if(in == out)
		return 1;
	return 0;
}

void push_front(int num)
{
	in++;
	if(!f_idx)
	{
		f_idx = MAX;
		deque[f_idx] = num;
		return ;
	}
	deque[--f_idx] = num;
}

void push_back(int num)
{
	in++;
	if(b_idx == MAX)
	{
		deque[b_idx] = num;
		b_idx = 0;
		return ;
	}
	deque[b_idx++] = num;
}

int pop_front()
{
	if(empty())
		return -1;
	
	out++;
	if(f_idx == MAX)
	{
		f_idx = 0;
		return deque[MAX];
	}
	else if(f_idx < b_idx)
		return deque[f_idx++];
	return deque[f_idx++];
}

int pop_back()
{
	if(empty())
		return -1;

	out++;
	if(!b_idx)
	{
		b_idx = MAX;
		return deque[b_idx];
	}
	else if(b_idx > f_idx)
		return deque[--b_idx];
	return deque[--b_idx];
}

int size()
{
	return (in - out);
}

int front()
{
	if(empty())
		return -1;
	return deque[f_idx];
}

int back()
{
	if(empty())
		return -1;
	else if(!b_idx)
		return deque[MAX];
	return deque[b_idx - 1];
}

int main()
{
	int N;
	scanf("%d", &N);
	while(N--)
	{
		int num;
		char order[11] = {0,};
		scanf("%s", order);

		if(!strcmp(order, "push_front"))
		{
			scanf("%d", &num);
			push_front(num);
		}

		else if(!strcmp(order, "push_back"))
		{
			scanf("%d", &num);
			push_back(num);
		}

		else if(!strcmp(order, "pop_front"))
			printf("%d\n", pop_front());
		
		else if(!strcmp(order, "pop_back"))
			printf("%d\n", pop_back());
		
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