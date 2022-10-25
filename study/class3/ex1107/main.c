#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

int n, m;
int broken[10] = {0,};

//고장난 숫자가 포함되어 있는지
int check(int num)
{
	int digit = 0;

	//num이 0일땐 고장났는지 아닌지 확인하고 리턴
	if(!num)
		return broken[0] ? 0 : 1;

	while(num)
	{
		if(broken[num % 10])
			return 0;
		num /= 10;
		digit++;
	}
	return digit;
}

//100에서 -+로 움직이는 횟수
int from_hundred()
{
	return abs(100 - n);
}

//가장 가까운 수로 이동하는 횟수 + 그 숫자에서 -+로 움직이는 횟수
int near_num()
{
	int res, min = MAX;

	for(int num = 0; num < MAX; num++)
		if(check(num))
			if(min > abs(n - num))
			{
				min = abs(n - num);
				res = num;
			}

	return min + check(res);
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++)
	{
		int tmp;

		scanf("%d", &tmp);
		broken[tmp] = 1;
	}

	int num1 = from_hundred();
	int num2 = near_num();

	printf("%d\n", num1 < num2 ? num1 : num2);

	return 0;
}