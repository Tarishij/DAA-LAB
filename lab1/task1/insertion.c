#include<stdio.h>
#include "main.h"
void insertion(int a[], int n)
{
  int i,j,key;
  for(i=1;i<n;i++)
  {
  key=a[i];
  j=i-1;
  while(j>=0&&a[j]>key)
  {
   a[j+1]=a[j];
   j=j-1;
  }
  a[j+1]=key;
 }

}