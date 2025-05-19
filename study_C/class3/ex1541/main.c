#include <stdio.h>
#include <stdlib.h>

int main()
{
	char formula[51] = {0,};
	scanf("%s", formula);

	int res = 0;
	int flag = 1, minus = 0;

	for(int i = 0; formula[i]; i++)
	{
		if(formula[i] == '+' || formula[i] == '-')
		{
			flag = 1;
			if(formula[i] == '-')
				minus = 1;
		}

		else if(flag)
		{
			if(!minus)
				res += atoi(&formula[i]);
			else
				res -= atoi(&formula[i]);
			flag = 0;
		}
	}
	printf("%d\n", res);

	return 0;
}