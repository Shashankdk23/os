#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head,max,min,range,i,fmax,fmin;
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
    printf("enter the range:");
    scanf("%d",&range);

    printf("Enter the direction(l or r)");
    scanf(" %c", &direction);

       fmax=rs[0];
     for (i=0;i<n;i++)
    {
        if (rs[i] > max)
        {
                fmax=rs[i];
        }
    }

    fmin=range;
         for (i=0;i<n;i++)
    {
        if (rs[i]<fmin)
        {
                fmin=rs[i];
        }
    }
    if (direction == 'r')
    {

    max=0;
     for (i=0;i<n;i++)
    {

        if (rs[i] > max && rs[i]<head )
        {
                max=rs[i];
        }
    }
        sum = (fmax-head)+(max-fmin);
        printf("Total Seek Time: %d \n", sum);
    }

    else if (direction == 'l')
    {

    min=range;
         for (i=0;i<n;i++)
    {
        if (rs[i]<min && rs[i]> head)
        {
                min=rs[i];
        }
    }
        sum = (head-fmin)+(fmax-min);
        printf("Total Seek Time: %d \n", sum);
    }

    else
    {
        printf("invalid input try l or r");
    }
    return 0;
}


