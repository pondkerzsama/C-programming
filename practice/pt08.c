/*
รับ N                    P
รับจำนวนเต็ม N ตัว          P

หาช่วงติดกันที่มี "ผลรวมเป็นศูนย์"               P
ถ้ามีหลายช่วง → เลือกช่วงที่เริ่ม index น้อยสุด    P
ถ้ายังเท่ากัน → เลือกช่วงที่สั้นที่สุด               X

Output: start end

Input:
5
1 2 -3 4 5

Output:
0 2


pseudo code
    create {time} print scan
    {number time} 
    loop 
        print
        scan
    func
    return

    function check(t,n)
        {sum} {ST} {EN}             {len}

        loop (i t   for st)
            loop(j i t     for +)
                + from each st                  len
                if sum == 0 && i <= ST           
                    update ST EN                
                    break
                reset sum len
        print
*/
#include <stdio.h>

void check(int t,int n[t])
{
    int sum=0, ST=0, EN=0, len=0, lessLen=t+1;

    for(int i=0; i<t; i++)
    {
        for(int j=i; j<t; j++)
        {

            sum += n[j];
            len++;

            if (sum == 0 && i <= ST && len < lessLen)
            {
                ST = i;
                EN = j;
                lessLen = len;
            }
            
        }

        sum = 0;
        len = 0;
    }

    printf("%d %d",ST,EN);
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