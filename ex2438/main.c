#include <stdio.h>

int main()
{
    int i;
    int j;
    int count;

    j = 1;
    scanf("%d", &i);
    while(i > 0)
    {
        count = j;
        while(count)
        {
            printf("*");
            count--;
        }
        printf("\n");
        i--;
        j++;
    }
    
}