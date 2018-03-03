#include<stdio.h>
#include "main.h"
void selection(int a[],int n)
{
int i,min,j,index;
for(i=0;i<n-1;i++)
{
 min=a[i];
 for(j=i+1;j<n;j++){
   if(a[j]<min){
     min=a[j];
     index=j;
    }
  }
  if(min!=a[i]){
 a[i]=a[i]+a[index];
 a[index]=a[i]-a[index];
 a[i]=a[i]-a[index];
 }
}


    }
