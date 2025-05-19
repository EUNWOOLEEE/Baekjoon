#include <stdio.h>

int main()
{
    int N;
    int sum = 0;
    char str[101];
    
    scanf("%d", &N);
    scanf("%s", str);
    for(int i = 0; i<N; i++)
    {
        sum = sum + str[i] - '0';
    }
    printf("%d\n", sum);
    return 0;
}