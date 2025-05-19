#include <stdio.h>
#define MAX 100001

typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[MAX];
	int heap_size;
} heaptype;

heaptype heap1;

void insert_heap(element item)
{
	int idx;

	idx = ++(heap1.heap_size);

	while(idx != 1 && (item.key > heap1.heap[idx / 2].key))
	{
		heap1.heap[idx] = heap1.heap[idx / 2];
		idx /= 2;
	}

	heap1.heap[idx] = item;
}

element delete_heap()
{
	element root, tmp;
	int parent = 1, child = 2;

	root = heap1.heap[1];
	tmp = heap1.heap[(heap1.heap_size)--];

	while(child <= heap1.heap_size)
	{
		if((child < heap1.heap_size) && (heap1.heap[child].key < heap1.heap[child + 1].key))
			child++;
		
		if(tmp.key > heap1.heap[child].key)
			break;

		else
		{
			heap1.heap[parent] = heap1.heap[child];
			parent = child;
			child *= 2;
		}
	}
	heap1.heap[parent] = tmp;

	return root;
}

int main()
{
	int n;
	scanf("%d", &n);

	element x;

	while(n--)
	{
		scanf("%d", &x.key);

		if(x.key)
			insert_heap(x);

		else if(heap1.heap_size)
			printf("%d\n", delete_heap().key);

		else
			printf("0\n");
	}
	return 0;
}