#include <stdio.h>

int main()
{
    int T;

    scanf("%d", &T);
    while(T)
    {
        int str[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
        int k, n;

        scanf("%d\n%d", &k, &n);
        while(k)
        {
            for(int i = 1; i <= 13; i++)
            {
                str[i] = str[i - 1] + str[i];
            }
            k--;
        }
        printf("%d\n", str[n-1]);
        T--;
    }
    return 0;
}