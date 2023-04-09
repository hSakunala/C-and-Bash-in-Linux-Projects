#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unsignInt, rMin, rMax;
    printf("Enter an unsigned integer: ");
    scanf("%d", &unsignInt);
    printf("Enter the starting bit in range ");
    scanf("%d", &rMin);
    printf("Enter the ending bit in range ");
    scanf("%d", &rMax);
    int mask = ~(1 << (rMax - rMin + 1));
    int trim = unsignInt >> rMin;
    int final = trim & mask;
    printf("%d\n", final);
    return 0;
}
