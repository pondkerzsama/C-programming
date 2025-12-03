#include <stdio.h>
#include <ctype.h>

void check(char word[]) {
    int i = 0;
    int word_len = 0;
    int word_count = 0;

    while (word[i] != '\0') {

        // ข้ามช่องว่างก่อนเริ่มคำใหม่
        while (word[i] == ' ' || word[i] == '\n')
            i++;

        // ถ้าถึงจุดสิ้นสุดเลยก็หยุด
        if (word[i] == '\0')
            break;

        // เริ่มคำใหม่
        word_len = 0;
        while (word[i] != ' ' && word[i] != '\n' && word[i] != '\0') {
            printf("%c", word[i]);
            i++;
            word_len++;
        }

        printf(" (%d)\n", word_len);
        word_count++;
    }

    printf("total word = %d\n", word_count);
}

int main() 
{
    char word[200];
    printf("enter something : ");
    fgets(word,200,stdin);
    check(word);
    return 0;
}