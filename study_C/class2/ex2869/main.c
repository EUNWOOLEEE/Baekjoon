#include <stdio.h>
#include <math.h>

int main()
{
	double A, B, V;
	scanf("%lf %lf %lf", &A, &B, &V);

	double day;
	day = ceil((V - B) / (A - B));

	printf("%d", (int)day);
}