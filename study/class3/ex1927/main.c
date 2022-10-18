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

void insert_heap(heaptype *h, element num)
{
	int idx;
	
	idx = ++(h->heap_size);

	while((idx != 1) && (num.key < h->heap[idx / 2].key))
	{
		h->heap[idx] = h->heap[idx / 2];
		idx /= 2;
	}
	h->heap[idx] = num;
}

element delete_heap(heaptype *h)
{
	int parent, child;
	element root, tmp;

	root = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	
	parent = 1;
	child = 2;

	while((child <= h->heap_size))
	{
		if((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;

		if(tmp.key <= h->heap[child].key)
			break;

		else
		{
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}

	h->heap[parent] = tmp;

	return root;
}

int main()
{
	int n;
	scanf("%d", &n);

	element x;
	heaptype heap1;
	while(n--)
	{
		scanf("%d", &x.key);

		if(x.key)
			insert_heap(&heap1, x);
		
		else if(!x.key && heap1.heap_size)
			printf("%d\n", delete_heap(&heap1).key);
		
		else
			printf("0\n");
	}

	return 0;
}