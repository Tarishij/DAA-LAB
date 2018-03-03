#include<stdio.h>
int n;
int fun(int []);
void main()
{
int i;
printf("enter the no of elements\n");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("%d",fun(a));
}
int fun(int a[])
{
int lis[n],i,j,max;
for(i=0;i<n;i++)
lis[i]=1;
for(i=1;i<n;i++){
  for(j=0;j<i;j++){
    if(a[i]>a[j]&&lis[i]<lis[j]+1)
      lis[i]=lis[j]+1;
      }
    }
    max=lis[0];
for(i=1;i<n;i++){
 if(lis[i]>max)
  max=lis[i];
  }
  return max;
  }
