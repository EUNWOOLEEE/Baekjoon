#include <stdio.h>

int coin[10] = {0,};

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int coin_num;
	for(coin_num = 0; coin_num < n; coin_num++)
		scanf("%d", &coin[coin_num]);

	int sum = 0, count = 0;
	coin_num--;
	while(sum < k)
	{
		sum += coin[coin_num];
		count++;
		if(sum > k)
		{
			sum -= coin[coin_num];
			coin_num--;
			count--;
		}
	}
	printf("%d\n", count);
	return 0;
}