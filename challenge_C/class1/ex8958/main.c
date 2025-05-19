#include <stdio.h>

int main()
{
    int N, i, j, sum, score;
    char str[80];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%s", str);
        j = score = 0;
        while(str[j] != '\0')
        {
            if(str[j] == 'O')
            {
                score++;
                sum += score;
            }
            else if(str[j] == 'X')
            {
                score = 0;
            }
            j++;
        }
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}