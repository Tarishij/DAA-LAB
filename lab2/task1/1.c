#include<stdio.h>
#include<sys/time.h>
void main()
{
int n,m,i,j;
long time_start, time_end;
struct timeval tv;
printf("enter number of rows and columns\n");
scanf("%d %d",&n,&m);
int a[n][m];
for(i=0;i<n;i++)
for(j=0;j<m;j++)
a[i][j]=-1;
int k=0;

gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
while(k<=n/2)
{

//for rows:
 for(i=0+k;i<m-k;i++)
   if(a[k][i]==-1)
   a[k][i]=k;
 for(i=0+k;i<m-k;i++)
  if(a[n-k-1][i]==-1)
   a[n-k-1][i]=k;
   
//for columns:
  for(i=0+k;i<n-k;i++)
   if(a[i][k]==-1)
    a[i][k]=k;
  for(i=0+k;i<n-k;i++)
    if(a[i][m-k-1]==-1)
    a[i][m-k-1]=k;
  
  k++;
  }

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
for(i=0;i<n;i++){
for(j=0;j<m;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
 printf("Time taken(microsec):%ld\n",time_end-time_start);
}
