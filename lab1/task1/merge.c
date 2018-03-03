#include<stdio.h>
#include "main.h"
void merge_sort(int a[],int p,int r){
if(p>=r)
return;
int q;
q=(p+r)/2;
merge_sort(a,p,q);
merge_sort(a,q+1,r);
merge(a,p,q,r);
}
void merge(int a[],int p,int q,int r){

int n1=q-p+1,k,i,j;
int n2=r-q;
int l[n1],m[n2];
for(i=0;i<n1;i++)
l[i]=a[p+i];
for(j=0;j<n2;j++)
m[j]=a[q+1-j];
i=0,j=0,k=p;
while(i<n1&&j<n2){
if(l[i]<=m[j]){
a[k]=l[i];
i++;
}
else{
a[k]=m[j];
j++;
}
k++;
}
while(i<n1){
a[k]=l[i];
k++;i++;}
while(j<n2){
a[k]=m[j];
k++;j++;}
}
