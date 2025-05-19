#include <stdio.h>

int main()
{
    int a, b, c;

    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);

        if(a == 0 || b == 0 || c == 0)
            return 0;

        if((a * a + b * b) == c * c)
            printf("right\n");
        else if((a * a + c * c) == b * b)
            printf("right\n");
        else if((b * b + c * c) == a * a)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}