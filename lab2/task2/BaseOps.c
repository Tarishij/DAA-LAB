#include<stdio.h>
#include "BaseOps.h"
#include "Number.h"
#include "NumberOps.h"
#include "Base.h"
int count=0;

int initializeBase(FILE *fp){

    int i=0;
    char ch=fgetc(fp);
    while(ch!=EOF){
        Base[i]=ch;
        count++;
        ch=fgetc(fp);
        ch=fgetc(fp);
        i++;
    }

    return count;
}
int lookup(char c){
    int i;
    for(i=0;i<count;i++){
        if(c==Base[i]){
            return i;
        }
    }

}
