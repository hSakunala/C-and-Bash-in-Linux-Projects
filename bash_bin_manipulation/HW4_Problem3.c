#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[128];
    printf("Enter a string: ");
    // scanf("%127s", str);
    scanf("%[^\n]127s", str);

    printf("The old string was \"%s\"", str);
    int len = strlen(str);
    char letter;
    for (int i = len - 1; i >= 0; i--)
    {
        letter = str[i] ^ 0x0f;
        str[i] = letter;
    }

    printf(" and the new string is \"%s\"\n", str);
}
