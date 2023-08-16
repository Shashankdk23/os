#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head,max,min,range,i;
    char direction;
    int sum = 0;

    printf("SCAN\n");
    printf("Enter the number of requests (n):");
    scanf("%d", &n);

    int rs[n];
    printf("Enter request sequence one by one (in ascending)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }

    printf("Enter initial head position (p):");
    scanf("%d", &head);

    printf("Enter the direction(l or r)");
    scanf(" %c", &direction);

    if (direction == 'l')
    {
      max=rs[0];
     for (i=0;i<n;i++)
    {
        if (rs[i] > max)
        {
                max=rs[i];
        }
    }
        sum = head +max;
        printf("Total Seek Time: %d\n", sum);
    }

    else if (direction == 'r')
    {
        printf("enter the range:");
        scanf("%d",&range);
        min=999;
         for (i=0;i<n;i++)
    {
        if (rs[i]<min)
        {
                min=rs[i];
        }
    }
        sum = (range-head)+(range-min);
        printf("Total Seek Time: %d\n", sum);
    }

    else
    {
        printf("invalid input try l or r");
    }
    return 0;
}
