#include<stdio.h>
int burst[2][40];
char pn[40];
int w[40];
void main()
{
 int i,j,n,tat=0,wt=0;
 printf("enter the no of programs");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("enter the name: ");
  scanf("%s",&pn[i]);
  printf("enter the arrival time of %c:",pn[i]);
  scanf("%d",&burst[0][i]);
  printf("enter the burst time of %c:",pn[i]);
  scanf("%d",&burst[1][i]);
 }

 for(i=0;i<n;i++)
 {   if(i!=0)
     {
       w[i]=w[i-1]+burst[1][i-1];
     }else
     {
         w[i]=0;
     }
 }
 for(i=0;i<n;i++)
 {
    tat+=w[i+1]-burst[0][i];
 }
 tat=tat/n;

for(i=0;i<n;i++)
 {
     w[i]=w[i]-burst[0][i];
      wt+=w[i];
 }
wt=wt/n;
printf(" processor \t waiting time \n");
for(i=0;i<n;i++)
 {
 printf(" %c \t %d \t \n ",pn[i],w[i]);

 }

  for(i=0;i<n;i++)
 {
 printf(" %d \t %c \t ",w[i],pn[i]);

 }
 printf(" atat is :%d \n",tat);
  printf(" awt is :%d",wt);
}
