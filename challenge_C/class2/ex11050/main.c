#include <stdio.h>

int factorial(int N)
{
    if(N == 0)
        return 1;
    return N * factorial(N - 1);
}

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);
    printf("%d", (factorial(N) / (factorial(K) * factorial(N - K))));
}