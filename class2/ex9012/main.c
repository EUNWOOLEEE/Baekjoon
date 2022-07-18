#include <stdio.h>

char str[51] = {0,};

int main()
{
    int T, count;

    scanf("%d", &T);
    while(T)
    {
        scanf("%s", str);
        count = 0;
        for(int i=0; str[i]; i++)
        {
            if (str[i] == '(')
                count++;
            else if (str[i] == ')')
                count--;
            if (count < 0)
                break;
        }
        if (count == 0)
            printf("YES\n");
        else
            printf("NO\n");
        T--;
    }
    return 0;
}