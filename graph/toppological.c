//using adjacecncy matrix representation of graph

#include <stdio.h>
void main()
{
    int n,i,j;
    printf("enter no.of vertices\n");
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {printf("enter %d row",i+1);
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        indeg[i+1]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        indeg[i+1]=indeg[i+1]+a[j][i];
    }
    count=0;
    while(count<n){
    for(i=0;i<n;i++)
    {
        if(indeg[i+1]==0){
        printf("%d",i+1);
        indeg[i+1]=-1;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            indeg[j+1]--;
        }
        }
    }
    count++;
    }
    
}


