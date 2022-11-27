#include <stdio.h>
#define MAX 100

char stack[MAX];
char str[101] = {0,};
int top;

void push(char c)
{
	stack[++top] = c;
}

void pop()
{
	stack[top--] = '\0';
}

int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}

int main()
{
	while(1)
	{
		top = -1;
		gets(str);
		if(str[0] == '.')
			break;
		
		for(int i = 0; str[i] != '.'; i++)
		{
			if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
			{
				if(stack[top] == '(' && str[i] == ')')
					pop();
				else if(stack[top] == '[' && str[i] == ']')
					pop();
				else
					push(str[i]);
			}
		}
		if(isEmpty())
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}