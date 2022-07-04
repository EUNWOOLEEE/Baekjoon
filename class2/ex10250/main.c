#include <stdio.h>

int main()
{
    int T, w, h, n, floor, room;

    scanf("%d", &T);
    while (T)
    {
        scanf("%d %d %d", &h, &w, &n);
        floor = room = 0;

        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                n--;
                floor++;
                if (n == 0)
                    break;
            }
            room++;
            if (n == 0)
                break;
            floor = 0;
        }
        printf("%d", floor);
        if (room < 10)
            printf("0");
        printf("%d\n", room);
        T--;
    }
    return 0;
}