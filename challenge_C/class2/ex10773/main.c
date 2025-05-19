#include <stdio.h>

int arr[100000] = {0,};

int main()
{
	int K;
	int sum = 0, idx = 0;

	scanf("%d", &K);
	while(K--)
	{
		scanf("%d", &arr[idx]);
		if(arr[idx] == 0)
			sum -= arr[--idx];
		else
			sum += arr[idx++];
	}
	printf("%d", sum);
	return 0;
}