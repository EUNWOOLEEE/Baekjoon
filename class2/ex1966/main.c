#include <stdio.h>

typedef struct
{
	int begin_idx;
	int priority;
} document;

int main()
{
	document input[10000];
	document print[100];

	int tc;
	scanf("%d", &tc);

	while(tc--)
	{
		int N, M;
		scanf("%d %d", &N, &M);

		for(int i = 0; i < N; i++)
		{
			scanf("%d", &input[i].priority);
			input[i].begin_idx = i;
		}

		int i_idx = N;
		int p_idx = 0;
		for(int i = 0; i < i_idx; i++)
		{
			for(int j = i + 1; j < i_idx; j++)
			{
				if(input[i].priority < input[j].priority)
				{
					input[i_idx].begin_idx = input[i].begin_idx;
					input[i_idx].priority = input[i].priority;
					i_idx++;
					break;
				}
				if(j == i_idx - 1)
				{
					print[p_idx].begin_idx = input[i].begin_idx;
					print[p_idx].priority = input[i].priority;
					p_idx++;
				}
			}
			if(i == i_idx - 1)
			{
				print[p_idx].begin_idx = input[i].begin_idx;
				print[p_idx].priority = input[i].priority;
				p_idx++;
			}
		}

		for(int i = 0; i < N; i++)
		{
			if(print[i].begin_idx == M)
				printf("%d\n", i + 1);
		}
	}
	return 0;
}