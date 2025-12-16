#include <stdio.h>

void compress(char w[])
{
    int i = 0;
    int count = 1;

    while (w[i] != '\0' && w[i] != '\n')
    {
        if (w[i] == w[i + 1])   // ตัวซ้ำติดกัน
        {
            count++;
        }
        else
        {
            if (w[i] == ' ')
                printf("_%d", count);
            else
                printf("%c%d", w[i], count);

            count = 1;  // reset
        }

        i++;
    }
}

int main()
{
    char word[200];

    printf("enter word: ");
    fgets(word, 200, stdin);

    compress(word);
    return 0;
}
