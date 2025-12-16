/*
รายละเอียด
เขียนฟังก์ชันที่รับ string 1 บรรทัด แล้วทำงานดังนี้ (fgets)

เงื่อนไข
1 แยกคำ (word)
    คำ = กลุ่มของตัวอักษร A–Z a–z เท่านั้น
    ตัวอื่น (space, digit, symbol) เป็นตัวคั่น

2 แปลงคำทุกคำ
    แปลงให้เป็น ตัวพิมพ์เล็กทั้งหมด
    เรียงตัวอักษรในคำจาก a → z

3 แสดงผล
    แสดงคำที่ผ่านการแปลงแล้ว ทีละคำ
    พร้อมความยาวของคำนั้น

HeLLo!!  WoRLd123  CBA

ehllo (5)
dlorw (5)
abc (3)


translate condition
    create word, 
    word = if A-z, 
    space digit symbol = else,
    use ascii (a-upper)+upper || tolower (can't use)
    use frequency for sort a-z,
    printf

pseudo code 
    if meet char count++
        if meet space digit symbol print with frequency and count then reset

flow
create word
create function
    check while \0
        if meet char \ word = if A-z has gap bet 91-96 \ count++      if char is upper use\ use ascii (a-upper)+upper \
        else print with frequency and count then reset
        i++

problem
cause inf loop from try to use skip print count 0 (problem is when i use continue i forgot to add i++)
*/
#include <stdio.h>

void compress(char w[])
{
    int i=0, count=0 ;
    char frequency[26] = {0};

    while (w[i] != '\0')
    {

        if ((w[i] >= 'A') && (w[i] <= 'Z') || (w[i] >= 'a') && (w[i] <= 'z'))
        {
            count++;

            if ((w[i] >= 'A') && (w[i] <= 'Z'))
            {
                frequency[w[i]-'A']++;
            }
            else
            {
                frequency[w[i]-'a']++;
            }

        }
        else
        {
            if (count == 0)
            {
                i++;
                continue;
            }

            for(int n=0; n<26; n++)
            {

                for(int j=0; j<frequency[n]; j++)
                {
                    printf("%c",n+'a');
                }
                
            }
            
            printf(" (%d)\n",count);

            count = 0;
            for(int n=0; n<26; n++)
            {
                frequency[n] = 0;
            }
        }

        i++;
    }

    if (count > 0)
    {
        for (int n = 0; n < 26; n++)
        {
            for (int j = 0; j < frequency[n]; j++)
            {
                printf("%c", n + 'a');
            }
        }
        printf(" (%d)\n", count);
    }

}

int main ()
{
    char word[200];

    printf("enter some word : ");
    fgets(word,200,stdin);
    compress(word);

    return 0;
}