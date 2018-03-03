#include<stdio.h>
#include <sys/time.h>
#define n 2
void main()
{
	int i,j,k,min,count;
	int a[n][n];
    long time_start, time_end;
    struct timeval tv;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
    gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
    time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	for(j=0;j<n;j++)
	{
		min=a[0][j];
		for(i=1;i<n;i++)
		{
			if(min>a[i][j])
				min=a[i][j];
		}

		while(1)
		{
			count=0;
			for(i=0;i<n;i++)
				a[i][j]-=(min-1);

			for(i=0;i<n;i++)
			{
				if(a[i][j]==1)
				{
					count++;
					for(k=0;k<n;k++)
						a[i][k]*=2;
				}
			}
			if(count==n)
				min=3;
			else if(count==0)
				break;
			else
				min=2;

		}
	}
    gettimeofday (&tv, NULL);
    time_end = (tv.tv_sec *1e+6) + tv.tv_usec;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}
	printf("Time taken:%ld\n",time_end-time_start);
}
