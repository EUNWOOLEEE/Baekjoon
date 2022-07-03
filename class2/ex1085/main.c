#include <stdio.h>

int main()
{
    int X, Y, W, H;
    int outX, outY;

    scanf("%d %d %d %d", &X, &Y, &W, &H);

    if(X < W / 2)
        outX = X;
    else if(X > W /2)
        outX = W - X;

    if(Y < H / 2)
        outY = Y;
    else if(Y > H / 2)
        outY = H - Y;

    if(outX >= outY)
        printf("%d", outY);
    else if(outX < outY)
        printf("%d", outX);
    return 0;
}