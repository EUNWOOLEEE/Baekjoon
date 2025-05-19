#include <stdio.h>

int main()
{
    char *str = "12345678";
    int i, j, num;

    i = 0;
    j = 7;
    for(int count = 0; count < 8; count++)
    {
       scanf("%d", &num);
       if(num == str[i] - 48)
        i++;
       else if(num == str[j] - 48)
        j--;
    }
    if(i == 8)
        printf("ascending");
    else if(j == 0)
        printf("descending");
    else
        printf("mixed");
    return 0;
}