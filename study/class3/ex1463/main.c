#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int min;
	int arr[1000001] = {0,};
	
	for(int i = 2; i <= n; i++)
	{
		min = arr[i - 1] + 1;

		if(!(i % 2))
			if(arr[i / 2] + 1 < min)
				min = arr[i / 2] + 1;

		if(!(i % 3))
			if(arr[i / 3] + 1 < min)
				min = arr[i / 3] + 1;

		arr[i] = min;
	}

	printf("%d\n", arr[n]);
}