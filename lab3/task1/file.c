#include<stdio.h>
#include<string.h>
#include<sys/time.h>
void main()
{
printf("enter the text\n");
char a[100];int index_x[100],index_y[100];
int j=0,k=0,i,l,count=0;
scanf("%[^\n]s",a);
long time_start, time_end;
struct timeval tv;
 

  //FIRST ALGORITHM:

gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

for(int i=0;i<strlen(a);i++){
    if(a[i]=='X'){
        index_x[j]=i;
        j++;
      }
    else if(a[i]=='Y'){
        index_y[k]=i;
         k++;
      }
  }
for(l=0;l<k;l++){
    for(i=0;i<j;i++){
         if(index_y[l]>index_x[i])
             count++;
          else
             break;
      }
     }
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("%d\n",count);
printf("time taken(microsec):%ld\n",time_end-time_start);


  //SECOND ALGORITHM:
count=0;
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

for(int i=0;i<strlen(a);i++){
    if(a[i]=='X'){
        for(int j=i+1;j<strlen(a);j++){
            if(a[j]=='Y')
                count++;
            }
      }
}


gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("%d\n",count);
printf("time taken(microsec):%ld\n",time_end-time_start);

       //THIRD ALGORITHM

count=0;
int x=0,sum=0,y=0;
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

for(i=0;i<strlen(a);i++){
    if(a[i]=='X')
      x++;
    else if(a[i]=='Y')
      y++;
   }
int total=x*y,index=0;
for(i=0;i<strlen(a);i++){
    if(a[i]=='Y'){
    
        for(j=index;j<i;j++){
            if(a[j]=='X'){
                 sum++;
              }
          }
        count+=x-sum;
        index=i;
      }
 }
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("%d\n",total-count);
printf("time taken(microsec):%ld\n",time_end-time_start);

}
