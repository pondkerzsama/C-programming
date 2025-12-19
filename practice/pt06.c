/*
เขียนโปรแกรมภาษา C รับข้อมูลดังนี้
    - รับจำนวนเต็ม N
    - รับจำนวนเต็ม N ตัว (บวก / ลบ / ศูนย์)

เงื่อนไข
    - หาผลรวมของ ช่วงติดกัน (subarray) ที่มีค่ามากที่สุด
    - out put : {start_index} {end_index} {sum}
    - ถ้ามีหลายช่วงที่ได้ผลรวมมากที่สุด
        ให้เลือกช่วงที่ เริ่มต้น index น้อยที่สุด
        ถ้ายังเท่ากันอีก → เลือกช่วงที่ สั้นที่สุด
    - ห้ามใช้ library เพิ่ม

input :
    8
    -2 1 -3 4 -1 2 1 -5

    5
    1 -1 1 -1 1


output :
    3 6 6

    0 0 1

explain :  [4, -1, 2, 1] → sum = 6



pseudo code 
    create input {number} {time}
    print
    scan time
    loop
        print
        scan number
    
    function (n,t)
        {sum} {bestsum} {bestST} {bestEN}
        {loop} i use t
            {loop} i for start to find bestsum by {sum}
            {if} to update {bestsum} {bestST} {bestEN}

        print
*/
#include <stdio.h>

void check(int t, int n[t])
{
    int sum=0, bestSum=-2147483648, bestST=0, bestEN=0;
    
    for (int i=0; i<t; i++)
    {
        for (int j=i; j<t; j++)
        {

            sum += n[j];
            if ((sum > bestSum) || (sum == bestSum) && (i<bestST))
            {
                bestSum = sum;
                bestST = i;
                bestEN = j;
            }
        }

        sum = 0;
    }
    
    printf("%d %d %d",bestST,bestEN,bestSum);
}

int main()
{
    int time;
    printf("enter time of number : ");
    scanf("%d",&time);

    int number[time];
    for (int i=0; i<time; i++)
    {
        printf("enter number of index %d : ",i);
        scanf("%d",&number[i]);
    }

    check(time,number);
    return 0;
}