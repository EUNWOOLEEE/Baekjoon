#include <stdio.h>

void divisor(int A, int B)
{
    for(int D = A; D >= 1; D--)
    {
        if(B % D == 0 && A % D == 0)
        {
            printf("%d\n", D);
            break;
        }
    }
}

void multiple(int A, int B)
{
    int M;

    for(int i = 1; i; i++)
    {
        M = A * i;
        if(M % B == 0)
        {
            printf("%d\n", M);
            break;
        }
    }
}

int main()
{
    int A, B;

    scanf("%d %d", &A, &B);
    
    divisor(A, B);
    multiple(A, B);
    return 0;
}