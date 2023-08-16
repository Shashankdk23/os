#include <stdio.h>
#include <stdlib.h>
    int n, head,max,min,range,i,fmax,fmin;
    char direction;
    int sum = 0;

void fcfs(int rs[])
{
    sum=abs(head-rs[0]);

for(int j=1;j<n;j++){
    sum=sum+abs(rs[j]-rs[j-1]);
}

printf("Total seek operation:%d",sum);
}

void sstf(int rs[]){
int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int sum = 0;
    int current = head;

    for (int i = 0; i < n; i++) {
        int minDiff = 1e9;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int diff = abs(current - rs[j]);
                if (diff < minDiff) {
                    minDiff = diff;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        sum += minDiff;
        current = rs[index];
    }

    printf("Total Seek Time: %d\n", sum);
}


void scan(int rs[])
{
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

}

void look(int rs[]){
printf("Enter the direction(l or r)");
    scanf(" %c", &direction);

            max=rs[0];
     for (i=0;i<n;i++)
    {
        if (rs[i] > max)
        {
                max=rs[i];
        }
    }
     min=999;
         for (i=0;i<n;i++)
    {
        if (rs[i]<min)
        {
                min=rs[i];
        }
    }

    if (direction == 'l')
    {

        sum = (head-min)+(max-min);
        printf("Total Seek Time: %d\n", sum);
    }

    else if (direction == 'r')
    {
       sum = (max-head)+(max-min);
        printf("Total Seek Time: %d\n", sum);
    }

    else
    {
        printf("invalid input try l or r");
    }
}

void cscan(int rs[]){
printf("Enter the direction(l or r)");
    scanf(" %c", &direction);

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
        sum = (range-head)+max;
        printf("Total Seek Time: %d\n", sum);
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
        sum = head+(range-min);
        printf("Total Seek Time: %d\n", sum);
    }

    else
    {
        printf("invalid input try l or r");
    }
}
void clook(int rs[])
{
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
}
void main()
{
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
    printf("\n fcfs");
    fcfs(rs);
    printf("\n sstf");
    sstf(rs);
    printf("\n scan ");
    scan(rs);
    printf("\n look");
    look(rs);
    printf("\n cscan");
    cscan(rs);
    printf("\n clook");
    clook(rs);

}

