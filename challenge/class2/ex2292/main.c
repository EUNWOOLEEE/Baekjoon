#include <stdio.h>

int main()
{
    int N;
    int step = 1, range = 1;
    int grow = 6;
    
    scanf("%d", &N);
    while(N > range)
    {
        range += grow;
        grow += 6;
        step += 1;
    }
    printf("%d", step);
    return 0;
}