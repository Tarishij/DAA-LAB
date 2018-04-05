
#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node*next;
};
 struct node*adj[20];
int visited[20]={0};      //white color=0 ( vertex in unvisited)
int d[20],f[20];
void create(int);
void DFS(int);
int t;
void main()
{
   
    int i,n,j,s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    adj[i]=NULL;
    create(n);
    t=0;
   
     for(i=0;i<n;i++)
     if(visited[i]==0)
     DFS(i);
     int a[n];
     for(i=0;i<n;i++)
     a[i]=i;
     //arrange vertices in decreasing order of their finishing time
     for(i=0;i<n-1;i++){
         for(j=0;j<n-i-1;j++){
             if(f[j]>f[j+1]){
                 f[j]=f[j]+f[j+1];
                 f[j+1]=f[j]-f[j+1];
                 f[j]=f[j]-f[j+1];
                 
                 a[j]=a[j]+a[j+1];
                 a[j+1]=a[j]-a[j+1];
                 a[j]=a[j]-a[j+1];
             }
         }
     }
     for(i=n-1;i>=0;i--)
     printf("%d",a[i]);
}
//create adjacency list
void create(int n)
{
    int n1,j,i,val;
    struct node*last,*tmp;
    for(i=0;i<n;i++){
    last=NULL;
    printf("enter no.of elements in %d list\n",i+1);
    scanf("%d",&n1);
    for(j=1;j<=n1;j++)
    {
        printf("enter value\n");
        scanf("%d",&val);
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->v=val;
        tmp->next=NULL;
        if(adj[i]==NULL)
        adj[i]=tmp;
        else
        last->next=tmp;
        last=tmp;
    }}
}
void DFS(int i){
    visited[i]=1;         //gray color=1 (vertex has just been discovered)
    t++;
    d[i]=t;
    struct node*p;
    p=adj[i];
    while(p->next){
        p=p->next;
        if(visited[p->v]==0){
            DFS(p->v);
        }
    }
    visited[i]=2;          //black color=2 (completely visited)
    t++;
    f[i]=t;
}
