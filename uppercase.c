#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("\033[0;31m");
    printf("Utility: Corrects lowercase punctuation \n");
    printf("\033[0m");

    string text = get_string("Type your text:\n");
    char x = '.';    // full stop
    char y = '!';    // exclamation mark
    char z = '?';    // question mark
    int length = strlen(text);
    char s = ' ';

    bool capitalize_next = false;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == x || text[i] == y || text[i] == z)
        {
            printf("%c", text[i]);
            int j = i + 1;
            while (j < length && text[j] == s)
            {
                printf("%c", text[j]);
                j++;
            }
            if (j < length)
            {
                if (!capitalize_next)
                {
                    text[j] = toupper(text[j]);
                    capitalize_next = true;
                }
                printf("%c", text[j]);
            }
            i = j;  // Skip to the next character after punctuation and spaces
        }
        else if (text[i] == s)
        {
            printf("%c", text[i]);
            capitalize_next = false;
        }
        else
        {
            printf("%c", text[i]);
            capitalize_next = false;
        }
    }

    printf("\n");

    return 0;
}