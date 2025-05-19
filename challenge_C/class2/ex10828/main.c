#include <stdio.h>
#include <string.h>
#define MAX 10000

int stack[MAX];
int stack_top = -1;

int empty()
{
	if(stack_top == -1)
		return 1;
	return 0;
}

void push(int num)
{
	stack[++stack_top] = num;
}

int pop()
{
	if(empty())
		return -1;
	return stack[stack_top--];
}

int size()
{
	return (stack_top + 1);
}

int top()
{
	if(empty())
		return -1;
	return stack[stack_top];
}

int main()
{
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
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

		else if(!strcmp(order, "top"))
			printf("%d\n", top());
	}
	return 0;
}