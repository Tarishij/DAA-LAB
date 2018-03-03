#include<stdio.h>
#include "main.h"
#include<stdlib.h>
#include<sys/time.h>
#define n 100000
int main()
{
    int a[n],i;

    for(i=0;i<n;i++)
   		 a[i]=rand()%n;
//printf("Input data\n");
//for(i=0;i<n;i++)
//printf("%d ",a[i]);
long time_start, time_end;
struct timeval tv;
gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
insertion(a,n);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;

//printf("\nSorted array: \n");
  //  for (i=0; i < n; i++)
    //    printf("%d ", a[i]);
    printf("\n");
    printf("Time taken(microsec) by Insertion Sort:%ld",time_end-time_start);

    srand(1);
    for(i=0;i<n;i++)
   		 a[i]=rand()%n;


gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
quick(a,0,n-1);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;


    printf("\n");
    printf("Time taken(microsec) by Quick Sort:%ld",time_end-time_start);




    printf("\n");
     srand(1);
    for(i=0;i<n;i++)
   		 a[i]=rand()%n;

gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
merge_sort(a,0,n-1);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
    printf("\n");
    printf("Time taken(microsec) by Merge Sort:%ld",time_end-time_start);



    printf("\n");
     srand(1);
    for(i=0;i<n;i++)
   		 a[i]=rand()%n;

gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
selection(a,n);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;


    printf("\n");
    printf("Time taken(microsec) by Selection Sort:%ld",time_end-time_start);



    printf("\n");
     srand(1);
    for(i=0;i<n;i++)
   		 a[i]=rand()%n;


gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
bubble(a,n);

gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;


    printf("Time taken(microsec) by Bubble Sort:%ld",time_end-time_start);

    printf("\n");
    return 0;
}
