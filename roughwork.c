#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j;
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			if(i+j==8)
				printf("%d",i+j);
			else if(i==j)
				printf("%d",i);
			else
				printf("%s"," ");
		}
		printf("\n");
	}
}
