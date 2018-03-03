#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int[],int );
void main()
{
	int i,v;
	printf("Enter value of v:\n");
	scanf("%d",&v);

	int a[v];
	for(i=0;i<v;i++)
		a[i]=i+1;

	shuffle(a,v);
	for(i=0;i<v-1;i++){
		printf("(%d,%d) ",a[i],a[i+1]);
	}
}
void shuffle(int a[],int n){
	int i,j;
	srand(time(NULL));
	for(i=n-1;i>0;i--){
		j=rand()%(i+1);

		a[i]=a[i]+a[j];
		a[j]=a[i]-a[j];
		a[i]=a[i]-a[j];
	}
}
