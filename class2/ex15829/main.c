#include <stdio.h>

int change_num(char c)
{
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int count;

    for(count = 0; alpha[count] != '\0'; count++)
    {
        if(alpha[count] == c)
        {
            break;
        }
    }
    return (count + 1);
}

int main()
{
    int L;
    int num = 0, sum = 0;
    char str[51] = {0, };

    scanf("%d\n%s", &L, str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        int j = i;
        int r = 1;
        num = change_num(str[i]);
        
        while(j)
        {
            r *= 31;
            j--;
        }
        sum += num * r;
    }
    printf("%d", sum % 1234567891);
    return 0;
}