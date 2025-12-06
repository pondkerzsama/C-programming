#include <stdio.h>

void check(char word[])
{
    int i=0;
    int total_char = 0, alpha = 0, digit = 0, space = 0, words = 0 ;
    int letters[26] = {0};

    /* -----------------------------------------------------
       (1) FIX #1 – นับคำแรกอย่างถูกต้อง
           เพราะคำแรกไม่มี space นำหน้า ต้องเช็กเอง
       ----------------------------------------------------- */
    if (word[0] != ' ' && word[0] != '\n' && word[0] != '\0') {
        words++;
    }

    while(word[i] != '\0')
    {
        if ((word[i] != ' ') && (word[i] != '\n'))
        {
            total_char++;

            if((word[i] >= 'A') && (word[i] <= 'Z'))
            {
                alpha++;
                letters[word[i] - 'A']++;
            }
            else if((word[i] >= 'a') && (word[i] <= 'z'))
            {
                alpha++;
                letters[word[i] - 'a']++;
            }
            else if((word[i] >= '0') && (word[i] <= '9'))
            {
                digit++;                                    
            }
        }
        else if(word[i] == ' ')                      
        {
            space++;

            /* -----------------------------------------------------
               (2) FIX #2 – นับคำใหม่เมื่อเจอ space + ตัวถัดไปเป็นตัวอักษร
                   (เหมือน logic เดิมแต่กันกรณี edge ครบ)
               ----------------------------------------------------- */
            if ((word[i+1] != ' ') && (word[i+1] != '\0') && (word[i+1] != '\n'))
            {
                words++;
            }
        }

        i++;
    }

    /* -----------------------------------------------------
       (3) FIX #3 – ลบ logic เดิมที่นับคำสุดท้ายเมื่อเจอ '\0'
           เพราะการนับนี้ทำให้จำนวนคำเกินทุกรอบ และไม่จำเป็น
       ----------------------------------------------------- */
    // ❌ ลบอันนี้ทิ้ง:
    // if (word[i+1] == '\0') words++;

    printf("Total chars: %d \nAlphabet: %d \nDigits: %d \nSpaces: %d \nWords: %d \nletter: ",
           total_char, alpha, digit, space, words);

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
