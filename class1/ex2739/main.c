#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);
    for(int i = 1; i <= 9; i++)
    {
        printf("%d * %d = %d", N, i, N * i);
        printf("\n");
    }
    return(0);
}
