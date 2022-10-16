#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int arr[1001] = {0,};
	arr[1] = 1;
	arr[2] = 3;

	for(int i = 3; i <= n; i++)
		arr[i] += ((arr[i - 2] * 2) + arr[i - 1]) % 10007;

	printf("%d", arr[n]);
	return 0;
}