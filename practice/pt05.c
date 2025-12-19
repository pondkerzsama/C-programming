/*
create input  for row column
    input 
create matrix
    use loop for input

function
    sum bestRow bestSum=0
    loop for i
        loop for j
            + inrow
        update bestRow by check sum
        reset sum        
    print
*/
#include <stdio.h>

void check (int r, int c, int n[r][c])
{
    int sum = 0, bestRow, bestSum = 100000;

    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            sum += n[i][j];
        }

        if (sum < bestSum)
        {
            bestRow = i;
            bestSum = sum;
        }

        sum = 0;
    }

    printf("%d %d",bestRow,bestSum);
}


int main ()
{
    int row, column ;
    printf("enter row and column in order : ");
    scanf("%d",&row);
    scanf("%d",&column);

    int number [row][column] ;
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {

            printf("enter number in row %d column %d : ",i+1,j+1);
            scanf("%d",&number[i][j]);
        }
    }

    check(row, column, number);


    return 0;
}