#include<stdio.h>
#include "main.h"
void bubble(int a[],int n){
int i,j,flag;
for(i=0;i<n-1;i++){
flag=0;
 for(j=0;j<n-i-1;j++){
   if(a[j]>a[j+1]){
     a[j]=a[j]+a[j+1];
     a[j+1]=a[j]-a[j+1];
     a[j]=a[j]-a[j+1];
     flag=1;
   }
  }
  if(flag==0)
  break;
 }

}
