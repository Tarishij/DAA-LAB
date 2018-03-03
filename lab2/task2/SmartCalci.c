#include<stdio.h>
#include "Number.h"
#include "Base.h"
#include "BaseOps.h"
#include "NumberOps.h"
#include<string.h>
void main(int argc,char *argv[])
{
    FILE *fp,*fptr;
    fp=fopen(argv[1],"r");
    fptr=fopen(argv[2],"r");
    if(fp==NULL||fptr==NULL){
        FILE *f=fopen("file","w");
        fprintf(f,"can't open the file");
    }
    else{
       int maxD=initializeBase(fp);
       do
       {
       char s[10],d;
       fscanf(fptr,"%[^\n]",s);   //s contains operator
       d=fgetc(fptr);            //to take \n
       char c[100];
       char bs[5];
       fscanf(fptr,"%[^ ]",bs);   //to take base
       d=fgetc(fptr);
       fscanf(fptr,"%[^\n]",c);   //to take number
       struct Number a=createNumber(atoi(bs),c);

       d=fgetc(fptr);
       fscanf(fptr,"%[^ ]",bs);   //to take base
       d=fgetc(fptr);
       fscanf(fptr,"%[^\n]",c);

       struct Number b=createNumber(atoi(bs),c);
       struct Number result;

       if(strcmp(s,"add")==0){
           result=add(a,b);
          // printf("%d\n",result.length);
           printNumber(a);
           printf(" + ");
           printNumber(b);
           printf(" = ");
           printNumber(result);
       }
       else{
           result=subtract(a,b);
           printNumber(a);
           printf(" - ");
           printNumber(b);
           printf(" = ");
           printNumber(result);
    }
    printf("\n");
    }while(fgetc(fptr)!=EOF);
    }
}
