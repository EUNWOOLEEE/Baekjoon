#include <stdio.h>

int main()
{
    int N, M;
    int A, B, C;
    int sum, result;
    int card[101] = {0,};

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) 
        scanf("%d", &card[i]);

    sum = result = 0;
    A = 0;
    while(A < N - 2)
    {
        B = A + 1;
        while(B < N - 1)
        {
            C = B + 1;
            while(C < N)
            {
                sum = card[A] + card[B] + card[C];
                if(sum <= M && sum > result)
                {
                    result = sum;
                }
                C++;
            }
            B++;
        }
        A++;
    }
    printf("%d", result);
    return 0;
}