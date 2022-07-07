#include <stdio.h>

void divisor(int large, int small)
{
    for(int D = small; D >= 1; D--)
    {
        if(large % D == 0 && small % D == 0)
        {
            printf("%d\n", D);
            break;
        }
    }
}

void multiple(int large, int small)
{
    int M;

    for(int i = 1; i; i++)
    {
        M = large * i;
        if(M % small == 0)
        {
            printf("%d\n", M);
            break;
        }
    }
}

int main()
{
    int A, B;
    int small, large;

    scanf("%d %d", &A, &B);
    if(A > B)
    {
        large = A;
        small = B;
    }
    else
    {
        large = B;
        small = A;
    }

    divisor(large, small);
    multiple(large, small);
    return 0;
}