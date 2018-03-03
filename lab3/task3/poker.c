#include<stdio.h>
#include <stdbool.h>
int p1,p2,d;
void sort(int a[5]){
    //insertion sort:
    int j,i,key;
    for(j=1;j<5;j++){
        i=j-1;
        key=a[j];
        while(i>=0&&key<a[i]){
            a[i+1]=a[i];
            i--;
            }
            a[i+1]=key;
    }
}
int full_house(int n1[5]){
    int c[15]={0};
    int i,j,n=-1,n2=-1;
    for(i=0;i<5;i++)
    c[n1[i]]++;
    for(i=2;i<15;i++){
        if(c[i]==3){
            n=i;
            break;
        }
     }
    for(i=2;i<15;i++){
        if(c[i]==2){
            n2=i;
            break;
        }
    }
    if(n!=-1&&n2!=-1)
    return n;
    else
    return 0;
}
bool flush(char s[5]){
    int i;
    for(i=1;i<5;i++){
        if(s[0]!=s[i])
            return false;
    }
    return true;
}
bool straight(int n[5]){
    sort(n);
    int i;
    for(i=1;i<5;i++)
        if(n[i]!=n[i-1]+1)
            return false;
    return true;
}
int three_of_a_kind(int n[5]){
    int c[15]={0};
    int i,j;
    for(i=0;i<5;i++)
    c[n[i]]++;
    for(i=2;i<15;i++){
        if(c[i]==3){
        return i;
        }
    }
    return 0;
}
bool two_pairs(int n1[5]){
    int c[15]={0};
    int i,j;
    p1=0,p2=0,d=0;
    for(i=0;i<5;i++)
    c[n1[i]]++;
    for(i=14;i>=2;i--){
        if(c[i]==2){
            p1=i;
            break;}
        }
    for(j=i-1;j>=2;j--){
        if(c[i]==2){
            p2=j;
            break;
        }
    }
    if(p1!=0&&p2!=0){
        for(i=2;i<15;i++){
        if(c[i]==1){
        d=i;
        break;
        }
        }
        return true;
    }
    else
    return false;
}
bool pair(int n[5],int a1[4]){
int c[15]={0};
    int i,j=0,p=-1;
    for(i=0;i<5;i++)
    c[n[i]]++;
    for(i=14;i>=2;i--){
        if(c[i]==2){
        p=i;
        break;}
    }
    if(p==-1)
    return false;
    else{
        a1[j]=p;
        j++;
        for(i=14;i>=2;i--){
            if(c[i]==1){
                a1[j]=i;
                j++;
            }
        }
    }
    return true;
}
int heighest_card(int n1[5],int n2[5]){
    sort(n1);
    sort(n2);
    int i;
    for(i=4;i>=0;i--){
        if(n1[i]>n2[i])
            return 1;
        else if(n1[i]<n2[i])
            return 2 ;
        else if(i==0){
            return 0;
        }
    }
}
int create(char c){
    switch(c){
        case '2':    return 2;
        case '3':    return 3;
        case '4':    return 4;
        case '5':    return 5;
        case '6':    return 6;
        case '7':    return 7;
        case '8':    return 8;
        case '9':    return 9;
        case 'T':    return 10;
        case 'J':    return 11;
        case 'Q':    return 12;
        case 'K':    return 13;
        case 'A':    return 14;
    }
}
bool straight_flush(int n[5],char s[5]){
    int i;
    for(i=1;i<5;i++){
        if(s[0]!=s[i])
            return false;
    }
    sort(n);
    for(i=1;i<5;i++)
        if(n[i]!=n[i-1]+1)
            return false;
    return true;
}
int four_of_a_kind(int n[5]){
    sort(n);
    int i;
    int index=-1;
    int count=1;
    for(i=0;i<4;i++){
        if(n[i]==n[i+1]){
        count++;
        }
        else if(n[i]!=n[i+1]){
        if(count==4)
        index=i;
        else
        count=1;}
        if(i==3)
        {
            if(count==4)
            return n[index];
            else
            return 0;
        }
    }
}
void main(int argc,char *argv[])
{
    FILE *fp;
    fp=fopen(argv[1],"r");
    int n1[5],n2[5],i;
    char s1[5],s2[5];
    char ch;
    do{
            for(i=0;i<5;i++){
                ch=fgetc(fp);
                n1[i]=create(ch);
                s1[i]=fgetc(fp);
                ch=fgetc(fp);
            }
            for(i=0;i<5;i++){
                ch=fgetc(fp);
                n2[i]=create(ch);
                s2[i]=fgetc(fp);
                ch=fgetc(fp);
            }

            //straight flush:

        if(straight_flush(n1,s1)&&straight_flush(n2,s2)){
            sort(n1);
            sort(n2);
            if(n1[4]>n2[4])
               printf("Black wins\n");
            else if(n1[4]<n2[4])
               printf("White wins\n");
            else
                printf("Tie\n");
        }
        else if(straight_flush(n1,s1))
            printf("Black wins\n");
        else if(straight_flush(n2,s2))
            printf("White wins\n");
        else{

            //four of a kind

            if(four_of_a_kind(n1)&&four_of_a_kind(n2)){
                if(four_of_a_kind(n1)>four_of_a_kind(n2))
                    printf("Black wins\n");
                else if(four_of_a_kind(n2)>four_of_a_kind(n1))
                    printf("White wins\n");
            }
            else if(four_of_a_kind(n1)){
                printf("Black wins\n");
            }
            else if(four_of_a_kind(n2))
                printf("White wins\n");
            else{

                //full house

                if(full_house(n1)&&full_house(n2)){
                    if(full_house(n1)>full_house(n2))
                    printf("Black wins\n");
                    else if(full_house(n2)>full_house(n1))
                    printf("White wins\n");
                     }
                else if(full_house(n1))
                printf("Black wins\n");
                else if(full_house(n2))
                printf("White wins\n");
                else{

                    //flush:

                    if(flush(s1)&&flush(s2)){
                        switch(heighest_card(n1,n2)){
                          case 1:    printf("Black wins\n");break;
                          case 2:    printf("White wins\n");break;
                          case 0:    printf("Tie\n");    break;
                    }
                 }
                    else if(flush(s1)){
                        printf("Black wins\n");
                    }
                    else if(flush(s2))
                        printf("White wins\n");
                    else{

                        //straight:

                        if(straight(n1)&&straight(n2)){
                            sort(n1);
                            sort(n2);
                            if(n1[4]>n2[4])
                                printf("Black wins\n");
                            else if(n1[4]<n2[4])
                                printf("White wins\n");
                            else
                                printf("Tie\n");
                              }
                        else if(straight(n1)){
                        printf("Black wins\n");
                               }
                        else if(straight(n2))
                        printf("White wins\n");
                        else{

                            //three of a kind:

                             if(three_of_a_kind(n1)&&three_of_a_kind(n2))
                             {
                                 if(three_of_a_kind(n1)>three_of_a_kind(n2))
                                 printf("Black wins\n");
                                 else if(three_of_a_kind(n1)<three_of_a_kind(n2))
                                 printf("White wins\n");
                                 else
                                 printf("Tie\n");
                             }
                             else if(three_of_a_kind(n1))
                             printf("Black wins\n");
                             else if(three_of_a_kind(n2))
                             printf("White wins\n");
                             else{

                                 //two pairs:
                                int a,b,c,a1,c1,b1;
                                if(two_pairs(n1)){
                                    a=p1;
                                    b=p2;
                                    c=d;}
                                if(two_pairs(n2)){
                                    a1=p1;
                                    b1=p2;
                                    c1=d;
                                }
                                if(two_pairs(n1)&&two_pairs(n2)){
                                    if(a>a1)
                                    printf("Black wins\n");
                                    else if(a<a1)
                                    printf("White wins\n");
                                    else{
                                        if(b>b1)
                                        printf("Black wins\n");
                                        else if(b<b1)
                                        printf("White wins\n");
                                        else{
                                            if(c>c1)
                                            printf("Black wins\n");
                                            else if(c<c1)
                                            printf("White wins\n");
                                            else{
                                            printf("Tie\n");
                                            }
                                        }
                                    }
                                }
                                else if(two_pairs(n1)){
                                    printf("Black wins\n");
                                }
                                else if(two_pairs(n2))
                                printf("White wins\n");
                                else{

                                   //pair:
                                   int first[4],sec[4],i;
                                   if(pair(n1,first)&&pair(n2,sec)){
                                       for(i=0;i<4;i++){
                                           if(first[i]>sec[i]){
                                               printf("Black wins\n");
                                               break;}
                                            else if(first[i]<sec[i]){
                                                printf("White wins\n");
                                                break;}
                                            else if(i==3)
                                                printf("Tie\n");
                                       }
                                   }
                                   else if(pair(n1,first))
                                       printf("Black wins\n");
                                    else if(pair(n2,sec))
                                        printf("White wins\n");
                                    else{

                                        //high card:
                                        switch(heighest_card(n1,n2)){
                                            case 1:    printf("Black wins\n");break;
                                            case 2:    printf("White wins\n");break;
                                            case 0:    printf("Tie\n");    break;
                                              }
                                    }
                                }
                                }
                             }
                        }
                    }
                }
            }
        }while(ch!=EOF);
}
