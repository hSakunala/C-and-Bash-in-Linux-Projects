#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[128];
    printf("Enter a string: ");
    scanf("%[^\n]127s", str);

    int len = strlen(str);
    int total;
    for (int i = len - 1; i >= 0; i--)
    {
        char letter = str[i];

        while (letter > 0)
        {
            if (letter & 1)
            {
                NULL;
            }
            else
            {
                total++;
            }
            letter = letter >> 1;
        }
        total++;
    }

    printf("Total amount of zeros is %d", total);
    printf(" in the string \"%s\"\n", str);
}
