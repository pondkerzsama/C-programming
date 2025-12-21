/*
รับ N                P
รับจำนวนเต็ม N ตัว      P

หาค่าที่ "ปรากฏน้อยที่สุด"         P
ถ้ามีหลายค่า → เลือกค่าที่มากที่สุด   X
แสดง: ค่า + จำนวนครั้ง          P

Input:
8
1 2 2 3 3 4 4 4

Output:
1 1

pseudo code 
    create {time} print scan {nubmer} 
    loop
        print scan
    func
    return

function check (t,n)
    {count} {lessC} {lessN}
    loop(pict st)
        loop(collect freq)
            if (check min freq)
                + freq
        if less than lessC(update lessC[count] lessN[i] )
        reset count
    print d d

problem use == to assign, use t++ instead of i++
*/
#include <stdio.h>

void check(int t, int n[t])
{
    int count=0, lessC=999999999, lessN=0;

    for(int i=0; i<t; i++)
    {
        for(int j=0; j<t; j++)
        {

            if (n[i] == n[j] )
            {
                count++;
            }

        }

        if ((count < lessC) || (count == lessC) && (n[i] > lessN))
        {
            lessN = n[i];
            lessC = count;
        }

        count = 0;
    }
    printf("%d %d",lessN,lessC);
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

    check(time, number);

    return 0;
}
