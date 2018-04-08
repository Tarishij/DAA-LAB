//main graph represented via adj list
//its reverse graph represented via adj matrix
//done using stack, where vertex with least finishing time is stored at the bottom of the staack

#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    struct node*next;
};
int ad[20][20];    //reverse graph's adjacency matrix
 struct node*adj[20];
int visited[20]={0};
void create(int);
int empty();
void push(int );
int pop();
void dfs(int,int);
void create_reverse_graph(int );
void DFS(int);

int s[20],top=-1;
void main()
{
   
    int i,n,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    adj[i]=NULL;
    
    create(n);
    for(i=0;i<n;i++)
    if(visited[i]!=1)
    DFS(i);
    for(i=0;i<n;i++)
    visited[i]=0;
    
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            ad[i][j]=0;
    }
    }
    create_reverse_graph(n);
    printf("SCC:\n");
        while(!empty()){
            j=pop();
            
            if(visited[j]==0){
            dfs(j,n);
            printf("\n");
            }
            
        }
    }
//first garph through adj list:
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
//dfs of first graph
void DFS(int i)
{
    struct node *p;
    int j;
    
    
    p=adj[i];
    visited[i]=1;
    p=p->next;
    while(p!=NULL)
    {
       j=p->v;
       
       if(!visited[j])
            DFS(j);
       
        p=p->next;
    }
    push(i);
}
//first graph's reverse represented with adj matrix:
void create_reverse_graph(int n){
    struct node *p;
    int i,j;
    for(i=0;i<n;i++){
        p=adj[i];
        p=p->next;
        while(p){
            ad[p->v][i]=1;    //adj matrix
            p=p->next;
        }
        
    }

}
//dfs on reversed graph:
void dfs(int i,int n){
    int j;
    printf("%d",i);
    visited[i]=1;
    for(j=0;j<n;j++){
        if(ad[i][j]==1){
            if(visited[j]==0)
            dfs(j,n);
        }
    }
}
//stack operations
void push(int i){
    
    top++;
    s[top]=i;
    
}
int pop(){
    int j=s[top];
    top--;
    return j;
}
int empty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
