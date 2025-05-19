#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

int t, n;
int front, rear;
int queue[MAX] = {0,};
char cmd[MAX] = {0,};
char nums[MAX] = {0,};

int count_digit(int num)
{
	int cnt = 0;

	while(num)
	{
		cnt++;
		num /= 10;
	}

	return cnt;
}

void divide_nums()
{
	int digit;

	for(int i = 0; nums[i]; i++)
		if(nums[i] >= '0' && nums[i] <= '9')
		{
			queue[rear] = atoi(&nums[i]);
			digit = count_digit(queue[rear]);
			i += digit;
			rear++;

			if(i > MAX) break;
		}
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s %d %s", cmd, &n, nums);
		
		front = rear = 0;
		divide_nums();

		int r_flag = 0;
		for(int i = 0; cmd[i]; i++)
		{
			if(cmd[i] == 'R')
				r_flag++;

			else // D
			{
				if(r_flag % 2) //반전 된 상태
					rear--;

				else
					front++;

				if(front > rear)
					break;				
			}
		}
		if(front > rear)
			printf("error\n");

		else
		{
			printf("[");

			if(front == rear) ;

			else if(r_flag % 2) //반전 된 상태
			{
				for(int i = rear - 1; i >= front; i--)
				{
					printf("%d", queue[i]);
					if(i != front)
						printf(",");
				}
			}
		
			else //!(r_flag % 2)
			{
				for(int i = front; i < rear; i++)
				{
					printf("%d", queue[i]);
					if(i + 1 != rear)
						printf(",");
				}
			}
			
			printf("]\n");
		}

	}
	
	return 0;
}