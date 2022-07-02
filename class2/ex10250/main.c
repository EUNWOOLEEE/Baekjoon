#include <stdio.h>

int main()
{
    int T, w, h, n, floor, room;

    scanf("%d", &T);
    while (T)
    {
        scanf("%d %d %d", &h, &w, &n);
        floor = room = 1;
        if (n == 1)
        {
            printf("%d0%d\n", floor, room);
            return 0;
        }

        for (int x = 0; x < w; x++)
        {
            for (int y = 1; y < h; y++)
            {
                n--;
                if (n <= 0)
                    break;
                floor++;
            }
            n--;
            if (n <= 0)
                break;
            floor = 1;
            room++;
        }
        printf("%d", floor);
        if (room < 10)
            printf("0");
        printf("%d\n", room);
        T--;
    }
    return 0;
}