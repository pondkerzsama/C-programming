/*
รับ
    จำนวนเต็ม N
    จำนวนเต็ม N ตัว

ให้หา
ช่วงติดกัน (subarray) ที่มี ผลรวมมากที่สุด
เงื่อนไข tie-break
    ถ้ามีหลายช่วงที่ผลรวมเท่ากัน → เลือกช่วงที่ เริ่ม index น้อยที่สุด
    ถ้ายังเท่ากัน → เลือกช่วงที่ สั้นที่สุด

แสดงผล
start end sum

Input:
5
1 -2 3 4 -1

Output:
2 3 7

Pseudo Code :
    {time} print scanf
    {number}[time] 
    (loop for) print scanf
    
    func
    return 0;

    func check(t,n)
    {Bsum} {sum} {ST} {EN} {len} {Llen}
    loop (ST)
        loop (EN)
        sum len

        if (if sum more than Bsum)
            update {ST} {EN} {Llen} {Bsum}
        if (if sum == Bsum && i < ST)
            updata {ST {EN} {Llen} {Bsum}
            if (len < Llen)
                updata {ST} {EN} {Llen}
        
        reset sum len
    
    print




ค่าเริ่มต้น Bsum = 0 ❌
    กรณี ตัวเลขติดลบทั้งหมด จะพังทันที

    int Bsum = n[0];
    int ST = 0, EN = 0;
    int Llen = 1;


เงื่อนไข tie-break เขียนรวมผิด logic ⚠️
    if((sum > Bsum) || (sum == Bsum) && (i < ST))
    {
        if(len < Llen)
        {
            update
        }
        else
        {
            update
        }
    }
    ปัญหา:
    len < Llen ไม่มีผลจริง เพราะ update ทั้งคู่
    เงื่อนไข “ความยาว” ต้องใช้ เฉพาะตอน



    ลำดับ tie-break ที่ถูกต้อง (สำคัญสุด)
    ต้องคิดแบบนี้เท่านั้น 👇
    ถ้า sum > Bsum
        update

    ถ้า sum == Bsum
        ถ้า i < ST
            update
        ถ้า i == ST และ len < Llen
            update

*/

#include <stdio.h>

void check(int t, int n[t])
{
    int Bsum=0, ST=0, EN=0, Llen=t-1;

    for(int i=0; i<t; i++)
    {
        int sum=0, len=0;

        for(int j=i; j<t; j++)
        {
            sum += n[j];
            len++;

            if(sum > Bsum)
            {
                Bsum = sum;
                ST = i;
                EN = j;
                Llen = len;
            }
            
            if (sum == Bsum)
            {
                if (i < ST)
                {
                    ST = i;
                    EN = j;
                    Llen = len;
                }
                else if (len < Llen)
                {
                    EN = j;
                    Llen = len;
                }

            }
        }
    }

    printf("%d %d %d",ST,EN,Bsum);
}

int main()
{
    int time;
    printf("enter time : ");
    scanf("%d",&time);

    int number[time];

    for (int i=0; i<time; i++)
    {
        printf("enter number %d : ",i+1);
        scanf("%d",&number[i]);
    }

    check(time,number);

    return 0;
}