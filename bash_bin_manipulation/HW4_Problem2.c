#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned int unsignInt;
    int count = 0;
    int rCount = 0;
    int ans = 0;
    int rResult = 0;
    printf("Enter an unsigned integer: ");
    scanf("%d", &unsignInt);

    while (unsignInt != 0)
    {
        rCount++;
        if (unsignInt & 1 == 1)
        {
            count++;
            if (count > ans)
            {
                rResult = rCount;
                ans = count;
            }
        }
        else
        {
            count = 0;
        }
        unsignInt = unsignInt >> 1;
    }

    int rLow = rResult - ans;
    printf("Longest sequence of 1s: %d\n", ans);
    printf("bit %d", rLow);
    printf("~bit %d\n", rResult - 1);
}
