#include <stdio.h>

int main()
{
	long n;
	scanf("%ld", &n);

	long arr[1001] = {0,};
	arr[1] = 1;
	arr[2] = 2;

	for(long i = 3; i <= n; i++)
		arr[i] += (arr[i - 1] + arr[i - 2]) % 10007;

	printf("%ld\n", arr[n]);
	return 0;
}