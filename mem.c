#include<stdio.h>
int n,m;
 struct mem{
 int d;
 int f;
};
struct mem p[100];

void best(int r[]);
void worst(int r[]);
void first(int r[]);
void main()
{

    int c,i,temp;
    printf("enter the no of pits:");
    scanf("%d",&n);
    printf("enter the size of pits:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].d);
        p[i].f=0;
    }
    printf("enter the no of files to run:");
    scanf("%d",&m);
    int r[m];
    for(i=0;i<m;i++)
    {
     scanf("%d",&r[i]);
    }
    first(r);
    best(r);
    worst(r);

}
 void first(int r[])
{
    int i,j,a[m],b[m],count;
     for(i=0;i<m;i++)
    {
        count=0;
      for(j=0;j<n;j++)
    {
        count++;
       if(p[j].d>=r[i] && p[j].f==0)
       {
          a[i]=p[j].d;
           p[j].f=1;
           j=n;
       }
    }
    if(count==n-1){
      printf("Memory allocation failed for size %d \n ",r[i]);
       a[i]=0;
    }
     printf("the pits assigned are:\n");
     for(i=0;i<m;i++)
     {
         printf("%d: %d \n",r[i],a[i]);
     }
}
 void best(int r[])
{
    int i,j,k,a[m],min,count;
     for(i=0;i<m;i++)
    {
        count=0;
        min=9999;
      for(j=0;j<n;j++)
    {
         count++;
       if(p[j].d>=r[i] && p[j].f==0)
       {
        if(p[j].d<=min)
            min=p[j].d;
       }
    }
     if(count==n-1){
      printf("Memory allocation failed for size %d \n ",r[i]);
    }
    a[i]=min;
     for(k=0;k<n;k++)
     {
        if(p[k].d==min && p[j].f==0 )
        {
          p[j].f=1;
           j=n;
        }
     }
    }
     printf("the pits assigned are:\n");
     for(i=0;i<m;i++)
     {
         printf("%d: %d \n",r[i],a[i]);
     }
}
 void worst(int r[])
{
    int i,j,k,a[m],max,count;
     for(i=0;i<m;i++)
    {
        max=-1;
         count=0;
      for(j=0;j<n;j++)
    {
        count++;
       if(p[j].d>=r[i] && p[j].f==0)
       {
        if(p[j].d>=max)
            max=p[j].d;
       }
    }
      if(count==n-1){
      printf("Memory allocation failed for size %d \n ",r[i]);
    }
     for(k=0;k<n;k++)
     {
        if(p[k].d==max && p[j].f==0 )
        {
          p[k].f=1;
           k=n;
        }
     }
         a[i]=max;

    }
     printf("the pits assigned are:\n");
     for(i=0;i<m;i++)
     {
         printf("%d: %d \n",r[i],a[i]);
     }
}















