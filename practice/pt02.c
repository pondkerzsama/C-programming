/*
เขียนฟังก์ชันที่รับ string แล้วแปลงรูปแบบตามนี้:
1 ตัวอักษรทุกชนิดนับหมด (A–Z, a–z, 0–9, symbol)
2 ถ้าตัวเดียวกันติดกัน → รวมเป็น <ตัว><จำนวน>
3 ถ้าเป็นช่องว่าง ' ' → ให้พิมพ์เป็น _ แทน เช่น " " → _3
4 ข้าม \n / \0
5 ไม่ต้องสนใจว่าเป็นตัวเล็ก/ใหญ่เหมือนกันหรือไม่ (A ≠ a)

input : Heeellooo   123!!!
output : H1e3l2o3_3 1231!3

note
word(input)  count(frequency)
function
while w != '\n'
    if 2 case (1 = aphabet+space 2 = number) count
        if (for check that next index is same or not) if not printf(str+count) break and reset count
        for number case check that next index is number or not if it not (str+count) number so reset count

problem
1 miss about printing number that when meet number must print all of them don't count them
2 go wrong on condition in line 39 "if ((w[i+1] < 0) && (w[i+1] > 9))"
3 case number 999
*/
#include <stdio.h>

void compress(char w[])
{
    int i = 0, count = 0;

    while(w[i] != '\0' )
    {

        if(w[i] == '\n') {
            i++;
            continue;
        }

        if(w[i] >= '0' && w[i] <= '9')//number case
        {
            count = 1;

            if ((w[i+1] < '0') || (w[i+1] > '9'))// if w out of range 0-9 reset count
            {
                printf("%c%d",w[i],count);
                count = 0;
            }
            else if(w[i] == w[i+1])
            {
                count++;
                printf("%c",w[i]);
            }
            else
            {
                printf("%c",w[i]);
            }
        
        }
        else
        {
            count++;

            if (w[i+1] != w[i])
            {
                if (w[i] == ' ')
                {
                    printf("_%d",count);
                    count = 0;
                }
                else
                {
                    printf("%c%d",w[i],count);
                    count = 0;
                }

            }
        }

        i++;
    }
}

int main ()
{
    char word[200];
    
    printf("enter word: ");
    fgets(word,200,stdin);
    compress(word);

    return 0;
}