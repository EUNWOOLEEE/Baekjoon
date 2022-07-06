#include <stdio.h>

int main()
{
    int N, len, i, j;

    while(1)
    {
        char str[6] = {'\0', };

        scanf("%d", &N);
        if(N == 0) break;
        len = sprintf(str, "%d", N);

        j = len - 1;
        for(i = 0; i <= len / 2; i++)
        {
            if(str[i] != str[j])
            {
                printf("no\n");
                break;
            }
            j--;
        }
        if(i > j)
             printf("yes\n");
    }
    return 0;
}