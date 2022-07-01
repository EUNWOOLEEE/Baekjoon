#include <stdio.h>

int main()
{
    char S[21], P[161];
    int T, R, idxP;

    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d %s", &R, S);
        idxP = 0;
        for(int idxS = 0; S[idxS] != '\0'; idxS++)
        {
            for(int j = 0; j < R; j++)
            {
                P[idxP] = S[idxS];
                idxP++;
            }
        }
        P[idxP] = '\0';
        printf("%s\n", P);
    }
    return 0;
}