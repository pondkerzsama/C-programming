/*
เขียนโปรแกรมภาษา C รับข้อมูลดังนี้
    รับจำนวนเต็ม N (จำนวนข้อมูล)
    รับจำนวนเต็ม N ตัว (อยู่บรรทัดเดียวหรือหลายบรรทัดก็ได้)

เงื่อนไข
    หาค่าที่ ปรากฏซ้ำมากที่สุด
    แสดงค่า + จำนวนครั้งที่ซ้ำ
    ถ้ามีหลายค่าที่ซ้ำมากที่สุด → ให้แสดง ค่าที่น้อยที่สุด
    ตัวเลขอาจเป็น บวก, ศูนย์, หรือลบ
    ห้ามใช้ library sort

ใช้ได้เฉพาะ:
    array
    loop
    if
    function พื้นฐาน


Input:
10
1 2 3 2 5 3 2 3 3 1

Output:
3 4

อธิบาย:
3 เจอ 4 ครั้ง
2 เจอ 3 ครั้ง
เลือก 3 เพราะซ้ำมากสุด


Input:
6
5 1 2 1 5 2

Output :
1 2

อธิบาย:
1, 2, 5 ซ้ำเท่ากัน = 2
เลือกค่าน้อยสุด → 1

pseudocode 

*/
#include <stdio.h>

void check(int n[], int t)
{
    int bestN, bestC = 0, N, C=0;

    for(int i=0; i<t; i++)
    {
        N = n[i];

        for(int j=0; j<t; j++)
        {
            
            if (n[i] == n[j])
            {
                C++;
            }

        }

        if (C > bestC)
        {

            bestN = N;
            bestC = C;

        }
        else if(C == bestC)
        {

            if (N < bestN)
            {
                bestN = N;
                bestC = C;
            }
        
        }

        C=0;
    }

    printf("%d %d",bestN,bestC);
}

int main()
{
    int time;
    printf("enter time of number: ");
    scanf("%d",&time);

    int num[time];
    for(int i=0; i<time; i++)
    {
        printf("enter value of number %d: ",i+1);
        scanf("%d",&num[i]);
    }

    check(num,time);
    return 0;
}