// 1 1 2 3 1 1 4 4
#include <stdio.h>

void check (int w[], int t)
{
    int count=0, num, countMax=0, numMax ;

    for (int i=0; i<t; i++)
    {
        num = w[i];

        for (int j=0; j<t; j++)
        {
            if (w[j] == num)
            {
                count++;
            }
            
        }

        if ((count > countMax) || (count == countMax) && (num < numMax))
        {
                countMax = count;
                numMax = num;
        }
        count = 0;

    }

    printf("%d %d",numMax,countMax);
}


int main ()
{
    int time;
    printf("enter number of time : ");
    scanf("%d",&time);

    int word[time];
    for (int i = 0; i<time ; i++)
    {
        printf("enter the number %d : ",i+1);
        scanf("%d",&word[i]);
    }

    check (word,time);

    return 0;
}