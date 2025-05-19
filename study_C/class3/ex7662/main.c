#include <stdio.h>
#define INT 2147483647

char c;
int t, k, n;
int size, max, min;
int min_idx;
int queue[1000001] = {0,};

void insert(int num)
{
	// printf("num: %d, size: %d\n", num, size);

	if(size < 0)
		return;

	int idx = ++size;

	while((idx != 1) && (num > queue[idx / 2]))
	{
		if(num < queue[idx / 2])
			break;

		queue[idx] = queue[idx / 2];
		idx /= 2;
	}

	if(max < num)
		max = num;

	if(min > num) //첫 입력값 때문에 둘 다 if로
	{
		min = num;
		min_idx = idx;
	}

	queue[idx] = num;

	// printf("idx: %d, max: %d, min: %d\n", idx, max, min);
}

void max_delete()
{
	int parent = 1, child = 2;
	int tmp = queue[size--];

	while(child <= size)
	{
		if(child < size && queue[child] < queue[child + 1])
			child++;

		if(tmp >= queue[child])
			break;

		queue[parent] = queue[child];
		parent = child;
		child *= 2;
	}

	max = queue[1];
	queue[parent] = tmp;

	// printf("max_d size: %d\n", size);
}

int get_min()
{
	int idx;
	min = queue[min_idx / 2];

	for(int i = size; i >= min_idx / 2; i--)
	{
		if(min > queue[i])
		{
			min = queue[i];
			idx = i;
		}
	}

	return idx;
}

void min_delete()
{
	int parent = min_idx / 2, child = min_idx;
	int tmp = queue[size--];

	while(parent >= 1)
	{
		if(tmp < queue[parent])
			break;

		queue[child] = queue[parent];
		child = parent;
		parent /= 2;
	}

	queue[child] = tmp;
	min_idx = get_min();

	// printf("min_d size: %d, min_idx: %d\n", size, min_idx);
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &k);
		getchar(); //개행이 버퍼에 남아서 다음 입력 시 개행이 입력됨

		size = 0, min = INT, max = -INT - 1;

		while(k--)
		{
			scanf("%c %d", &c, &n);
			getchar();

			if(size < 0)
				continue;

			if(c == 'D')
			{
				if(!size)
					size--;

				else if(n == 1)
					max_delete();

				else //n == -1
					min_delete();
			}

			else //c == 'I'
				insert(n);

			// printf("queue\n");
			// for(int i = 1; i <= size; i++)
			// 	printf("%d ", queue[i]);
			// printf("\n");
		}

		if(size < 0)
			printf("EMPTY\n");
		
		else
		printf("%d %d\n", max, min);

		// printf("\n\n");
	}

	return 0;
}