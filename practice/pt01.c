/*
ให้เขียนโปรแกรมที่รับประโยคเข้ามา แล้วแปลงรูปแบบดังนี้:
รูปแบบการแปลง

1 รวมตัวอักษรติดกันที่เหมือนกัน เช่น "aaabbc" → "a3b2c1"
2 ไม่สนใจช่องว่าง ให้ข้ามไป
3 ตัวอักษรตัวเล็ก/ตัวใหญ่ถือว่า "ต่างกัน" เช่น A ไม่เท่ากับ a

Heeellooo Wooorld
H1e3l2o3W1o3r1l1d1

word
    -> check (frequency)
        w != end(\0)
            w == A-z
                ++ frequency
print
            if w i == w i+1
                don't print
            else
                if i>0
                    if (wi == wi-1)
                        conti
                    else
                        print

use loop to print data
    print char & print A-word[i]
        

use frequency to collect number of each character

problem :
1 index n=1 of frequency was worng (because i use 'A'- word[i] it was - nubmer ) 19.35-19.55
2 forget to check print cause: H1e3e3e3l3l3o6o6o6 32758W1o6o6o6r1l3d1 20.00 - 20.12
3 forget to check that frequency colloct all of number that happen so the output is (H1e3l3o6 32759W1o6r1l3d1\n032767) 20.14 - 20.27
4 forget to print the first index because 
    if (w[i] != w[i+1] && i<0)
        {
            if (w[i] != w[i-1])
            {
                printf("%c%d",w[i],frequency[w[i]-'A']);
            }
        }

        i++;
5 it show only char that have one connect becaues 
    if (w[i] != w[i+1] )
            {

                if (i == 0)
                {
                    printf("%c%d",w[i],frequency[w[i]-'A']);
                }
                else
                    if (w[i] != w[i-1])
                    {
                        printf("%c%d",w[i],frequency[w[i]-'A']);
                    }

            }

*/

#include <stdio.h>

void check(char w[])
{
    int i=0, count = 0 ;

    while (w[i] != '\0')
    {

        if ((w[i] >= 'A' && w[i] <= 'Z') || (w[i] >= 'a' && w[i] <= 'z'))       //before confix : if ((w[i] >= 'A') && (w[i] <= 'z'))
        {
                count++;

                if (w[i] != w[i+1] )
                {
                    printf("%c%d",w[i],count);
                    count = 0;
                }
        }
        
        i++;
    }

}

int main()
{
    char word[200];

    printf("enter word : ");
    fgets(word,200,stdin);
    check(word);
    return 0;

}