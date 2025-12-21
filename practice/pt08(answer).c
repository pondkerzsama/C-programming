void check(int t,int n[t])
{
    int sum = 0;
    int ST = -1, EN = -1;
    int len = 0, bestLen = t + 1;

    for(int i = 0; i < t; i++)
    {
        sum = 0;
        for(int j = i; j < t; j++)
        {
            sum += n[j];
            len = j - i + 1;

            if (sum == 0)
            {
                if (ST == -1 ||                   // เจอครั้งแรก
                    i < ST ||                     // start น้อยกว่า
                    (i == ST && len < bestLen))   // start เท่ากัน แต่สั้นกว่า
                {
                    ST = i;
                    EN = j;
                    bestLen = len;
                }
            }
        }
    }

    if (ST == -1)
        printf("-1 -1");
    else
        printf("%d %d", ST, EN);
}
