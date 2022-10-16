#include <stdio.h>

int main()
{
	long t, n;
	scanf("%ld", &t);

	while(t--)
	{
		scanf("%ld", &n);

		long arr[101] = {0,};
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 1;
		arr[3] = 1;
		arr[4] = 2;

		for(int i = 5; i <= n; i++)
			arr[i] += arr[i - 5] + arr[i - 1];

		printf("%ld\n", arr[n]);
	}
	return 0;
}