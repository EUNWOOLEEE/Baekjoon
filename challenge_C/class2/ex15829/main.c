#include <stdio.h>

int main()
{
    int L;
    int num = 0;
    long long sum = 0;
    char str[51] = {0, };

    scanf("%d\n%s", &L, str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        int j = i;
        long long r = 1;
        num = str[i] - 'a' + 1;
        
        while(j)
        {
            r = (r * 31) % 1234567891;
            j--;
        }
        sum += num * r;
    }
    printf("%lld", sum % 1234567891);
    return 0;
}