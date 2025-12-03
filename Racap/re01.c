#include <stdio.h>

void check(char word[]){
    int i=0, word_count=0 ;
    while(1)
    {
        int count = 0;
        while(1)
        {
            if ((word[i] != '\n') && (word[i] != ' '))
            {
                printf("%c",word[i]);
                i++;
                count++;
            }
            else
            {
                i++;
                for(i;word[i] == ' ';i++)
                {
                    if((word[i] != ' ') && (word[i] != '\n') && (word[i] != '\0')) 
                    {
                        break;
                    }
                    word_count++;
                }
                printf(" (%d)\n",count);
                break;
            }   
        }
        if (word[i] == '\0')
        {
            if (count > 0) 
            {
                word_count++;
            }
            printf("total word = %d",word_count);
            break;
        }
    }
}

int main()
{
    char word[200] ;
    printf("enter something\n");
    fgets(word,200,stdin);
    check(word);
    return 0;
}