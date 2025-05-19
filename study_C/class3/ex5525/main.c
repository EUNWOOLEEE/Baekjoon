#include <stdio.h>
#define MAX 1000001

int main()
{
	int n, m;
	char str[MAX] = {0,};
	scanf("%d %d %s", &n, &m, str);

	int cnt = 0, ans = 0;

	for(int i = 1; i < m - 1; i++)
	{
		if(str[i] == 'O' && str[i + 1] == 'I')
		{
			cnt++;

			if(cnt == n)
			{
				if(str[i - (cnt * 2 - 1)] == 'I')
					ans++;
				cnt--;
			}

			i++;
		}
		else
			cnt = 0;
	}

	printf("%d\n", ans);

	return 0;
}