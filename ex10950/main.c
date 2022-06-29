#include <stdio.h>

int main()
{
    int T, A, B;

    scanf("%d", &T);
    for(int i = T; i > 0; i--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }
    return 0;
}