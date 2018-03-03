#include<stdio.h>
#include "main.h"
void quick(int a[],int low,int high)
{
    if(low < high)
    {
        int p=partition(a,low,high);
        quick(a, low, p - 1);
        quick(a, p + 1, high);

    }


}
int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int j=high,i=low+1;
    while(i<=j)
    {
    while(a[i]<pivot&&i<high)
    i++;
    while(a[j]>pivot)
    j--;
        if(i<j)
        {

            a[i]=a[i]+a[j];
			a[j]=a[i]-a[j];
			a[i]=a[i]-a[j];
			i++;j--;
        }
        else
        i++;
    }
    a[low]=a[j];
    a[j]=pivot;
    return j;
}
