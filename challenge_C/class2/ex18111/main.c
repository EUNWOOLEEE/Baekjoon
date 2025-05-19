#include <stdio.h>

int main()
{
	int N, M, B;
	scanf("%d %d %d", &N, &M, &B);

	int land[250000] = {0,};
	int max = 0, min = 256;
	for(int i = 0; i < N * M; i++)
	{
		scanf("%d", &land[i]);
		if(land[i] > max)
			max = land[i];
		else if(land[i] < min)
			min = land[i];
	}

	int cur_time, min_time, inventory, height;
	for(int criteria = min; criteria <= max; criteria++)
	{
		inventory = B;
		cur_time = 0;
		for(int i = 0; i < N * M; i++)
		{
			if(land[i] > criteria)
			{
				cur_time += 2 * (land[i] - criteria);
				inventory += land[i] - criteria;
			}

			else
			{
				cur_time += criteria - land[i];
				inventory -= criteria - land[i];
			}
		}
		if(criteria == min)
			min_time = cur_time;
		if(inventory >= 0 && cur_time <= min_time)
		{
			min_time = cur_time;
			height = criteria;
		}
	}
	printf("%d %d", min_time, height);
	return 0;
}