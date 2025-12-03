/*
สร้างตัวรับ word

function
เงื่อนไขนับ
    word++ in space
        A-Z && a-z = alpha++
        0-9 = digit++

แสดงตัวอักษรแบบเรียง Letters: dehllloorw ( Hello 123 world! )

[out put]
Total chars: 15
Alphabet: 10
Digits: 3
Spaces: 2
Words: 3
Letters: dehllloorw         ใช้ sort, frequency of letter

*/

// !! เจอปัญหาคือ ทำเงื่อนไขนับ words ผิด เด๋วมาแก้

#include <stdio.h>

void check(char word[])
{
    int i=0;
    int total_char = 0, alpha = 0, digit = 0, space = 0, words = 0 ;
    int letters[26] = {0};


    while(word[i] != '\0')
    {

        if ((word[i] != ' ') && (word[i] != '\0') && (word[i] != '\n') )
        {
            total_char++;

            if((word[i] >= 'A') && (word[i] <= 'Z'))
            {
                alpha++;
                letters[word[i] - 'A']++ ;                                                  // use frequency of letter fix the problem that don't use to lower or upper 

            }
            else if((word[i] >= 'a') && (word[i] <= 'z'))                                   // !! in c they don't have elif
            {
                alpha++;
                letters[word[i] - 'a']++ ;                                                  // use frequency of letter fix the problem that don't use to lower or upper
            }
            else if((word[i] >= '0') && (word[i] <= '9'))                                   // !! in c they don't have elif
            {
                digit++;                                    
            }   

        }
        else if(word[i] == ' ')                      
            {
                space++;

                if ((word[i+1] != ' ') && (word[i+1] != '\0') && (word[i+1] != '\n') )
                {
                    words++;
                }
                
            }
        
        i++;
    }

    printf("Total chars: %d \nAlphabet: %d \nDigits: %d \nSpaces: %d \nWords: %d \nletter: ",total_char, alpha, digit, space, words);

    for(i=0;i<26;i++)
    {

        for(int j=0;j<letters[i];j++)
        {
            printf("%c",i + 'a');
        }

    }
    
}


int main()
{
    char word[200];
    printf("enter something : ");
    fgets(word,200,stdin);
    check(word);
    return 0;

}