#include <stdio.h>

int main()
{
    int max, num, idx;
    max = num = idx = 0;

    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &num);
        if(num > max)
        {
            max = num;
            idx = i;
        }
    }
    printf("%d\n%d", max, idx + 1);
    return 0;
}