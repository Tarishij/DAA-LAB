#include "NumberOps.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "BaseOps.h"
#include<string.h>
#include "Base.h"
#include "Number.h"
struct Number createNumber(int bs,char *number_format){
    struct Number a;
    a.base=bs;
    struct list *head=NULL,*tmp;
    //struct list *last=NULL;
    int count=0;
    while(*number_format!='\0'){

       char c=*number_format;       //taking single charachter at a time

       //creating a new node named temp

       tmp=(struct list*)malloc(sizeof(struct list));
       tmp->d=c;
       tmp->next=NULL;
       tmp->prev=NULL;
       if(head==NULL){
           head=tmp;
       //    last=tmp;
       }
       else{
           struct list *ptr=head;
           while(ptr->next!=NULL)
           ptr=ptr->next;
           ptr->next=tmp;
           tmp->prev=ptr;
        //   last=tmp;
       }

       count++;     //counting the total no. of digits
       number_format++;
    }
    a.digit=head;
    a.length=count;

    return a;
}
struct Number add(struct Number a,struct Number b){
    int common_base;
    int sum;
    if(a.base!=b.base){
        if(a.base>b.base)
          common_base=a.base;
        else
          common_base=b.base;
    }
    else
      common_base=a.base;
    int new_a=convert_in_decimal(a);
    int new_b=convert_in_decimal(b);
    sum=new_a+new_b;

    return convert(sum,common_base);

}
struct Number subtract(struct Number a,struct Number b){
    int common_base;
    int sum;
    if(a.base!=b.base){
        if(a.base>b.base)
          common_base=a.base;
        else
          common_base=b.base;
    }
    else
    common_base=a.base;
    int new_a=convert_in_decimal(a);
    int new_b=convert_in_decimal(b);
    sum=new_a-new_b;
   // printf("sum:%d",sum);
    return convert(sum,common_base);
}
struct Number convert(int n, int to_base)
{
   char arr[100];
   int i=0;
   while(n!=0){
       arr[i]=Base[n%to_base];
       i++;
       n=n/to_base;
    }

    char ar[i];

    int j;
    char t;
   for(j=0;j<i/2;j++){
       t=arr[j];
       arr[j]=arr[i-j-1];
       arr[i-j-1]=t;
   }
   for(j=0;j<i;j++)
   ar[j]=arr[j];

   return createNumber(to_base,ar);

}
void printNumber(struct Number n){
    struct list *ptr=n.digit;

            while(ptr){
                 printf("%c",ptr->d);
                 ptr=ptr->next;
                 }
            printf("(%d)",n.base);
}
int convert_in_decimal(struct Number n){

    int count=n.length-1,sum=0;
    struct list *ptr=n.digit;

    while(count>=0){
        sum+=(pow(n.base,count)*(lookup(ptr->d)));
        count--;
        ptr=ptr->next;
        }
    return sum;
}
