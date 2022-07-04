#include <stdio.h>

int main()
{
    int N, result, i;
    char str[8] = {0,};

    scanf("%d", &N);
    for(int M = 1; M <= 1000000; M++)

    {
        sprintf(str, "%d", M);
        result = M;

        for(i = 0; str[i] != '\0'; i++)
        {
            result += str[i] - '0';
        }
        if(result == N)
        {
            printf("%d\n", M);
            return 0;
        }
    }
    printf("0");
    return 0;
}