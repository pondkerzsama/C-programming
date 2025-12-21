/* 17.18
รับจำนวนเต็ม N
รับข้อมูล N บรรทัด
แต่ละบรรทัดมี: start end   (start < end)

ช่วงเวลา [start, end)                    ####(รวม start ไม่รวม end)   

ให้หาจำนวน "ช่วงที่ทับซ้อนกันมากที่สุด" ในเวลาเดียวกัน                       
และแสดงช่วงเวลาที่เกิดการทับซ้อนสูงสุดนั้น                                 
                                                               
ถ้ามีหลายช่วงเวลา → เลือกช่วงที่ start น้อยที่สุด

input :
5
1 4     123
2 6     2345
3 5     34
7 9     78
8 10    89

อธิบาย
    ช่วง [3,4) มีช่วงซ้อนกัน 3 ช่วง
    (1–4, 2–6, 3–5)

output :
3 4 3


4
1 3
3 5
5 7
7 9


1 3 1
เพราะไม่มีช่วงไหนทับซ้อนกันเกิน 1

pseudo code :
    {line} printf scanf

    {ST} {EN}
    for (line)
        for (assign)
            printf
            scanf ST EN
    
    func
    return

    check ()
    for i with line (set time from t[line] 0-4 ) 
        for t(st - en) (time of each line)



*/
#include <stdio.h>

void check(int l, int S[l], int E[l])
{
    int time, Mcount=0 , Mstart=0, Mend=0;

    for(int i=0; i<l; i++)
    {
        time = S[i];
        int count = 0, minend=1000000000;

        for(int j=0; j<l; j++)
        {
            if((time >= S[j]) && (time < E[j]))
            {
                count++;

                if (E[j] < minend)
                {
                    minend = E[j];
                }
            }
        }

        if((count > Mcount) || (count == Mcount) && (time < Mstart))
        {
            Mcount = count;
            Mstart = time;
            Mend = minend;
        }
    }

    printf("%d %d %d",Mstart,Mend,Mcount);
}

int main()
{
    int line;
    printf("enter line : ");
    scanf("%d",&line);

    int ST[line], EN[line];
    for(int i=0; i<line; i++)
    {
        printf("enter start/end of time of line %d : ",i+1);
        scanf("%d %d",&ST[i],&EN[i]);
    }

    check(line, ST, EN);
    return 0;
}
