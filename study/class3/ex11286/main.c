#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[100001];
	int heap_size;
} heaptype;

void insert_heap(heaptype *h, element item)
{
	int idx = ++(h->heap_size);

	while((idx != 1) && (abs(item.key) <= abs(h->heap[idx / 2].key)))
	{
		if(abs(item.key) == abs(h->heap[idx / 2].key))
			if(item.key > h->heap[idx / 2].key)
				break;

		h->heap[idx] = h->heap[idx / 2];
		idx /= 2;
	}

	h->heap[idx] = item;
}

element delete_heap(heaptype *h)
{
	int parent = 1, child = 2;
	element root, tmp;

	root = h->heap[1];
	tmp = h->heap[(h->heap_size)--];

	while(child <= h->heap_size)
	{
		if((child < h->heap_size) && (abs(h->heap[child].key) > abs(h->heap[child +1].key)))
			child++;

		else if((child < h->heap_size) && 
			(abs(h->heap[child].key) == abs(h->heap[child +1].key)) &&
			h->heap[child].key > h->heap[child +1].key)
			child++;
		
		if(abs(tmp.key) < abs(h->heap[child].key))
			break;

		else if(abs(tmp.key) == abs(h->heap[child].key) &&
				tmp.key < h->heap[child].key)
				break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
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

		else if(heap1.heap_size)
			printf("%d\n", delete_heap(&heap1).key);
		
		else
			printf("0\n");
	}
	return 0;
}