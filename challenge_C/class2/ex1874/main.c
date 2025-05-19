#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int input, num = 0;
	int stack_idx = 0, sign_idx = 0;
	int stack[100000] = {0,};
	char sign[1000000] = {0,};
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if(input > num) //push
		{
			int count = input - num;
			while(count--)
			{
				stack[stack_idx++] = ++num;
				sign[sign_idx++] = '+';
			}
		}
		if(input <= num) //pop
		{
			stack_idx--;
			sign[sign_idx++] = '-';
		}
		if(stack[stack_idx] != input)
			break;
	}
	if(stack[stack_idx] == input)
	{
		for(int i = 0; sign[i]; i++)
			printf("%c\n", sign[i]);
	}
	else
		printf("NO\n");
	return 0;
}