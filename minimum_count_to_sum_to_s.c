#include<stdio.h>
#include<stdlib.h>
#include "merge_sort.h"

/*
 * Given a list of 'N' coins, their values being in an array A[], return the minimum number of coins required to sum to 'S'
*/

void usage(char *);
int min_count_to_sum_to_s(int *, int, int);

void main(int argc, char *argv[])
{
	if(strcmp("-h", argv[1])==0 || argc==1)
	{
		usage(argv[0]);
		exit(1);
	}
	int arr_size=argc-1;
	int *arr=(int *) malloc(sizeof(int)*arr_size);
	int count;
	for(count=0;count<=arr_size-1;count++)
		arr[count]=atoi(argv[count+1]);
	arr=merge_sort(arr, arr_size);
	int sum;
	fprintf(stderr, "enter the sum:\n");
	scanf("%d", &sum);
	printf("min_count:%d\n", min_count_to_sum_to_s(arr, arr_size, sum));
}

void usage(char *scriptname)
{
	fprintf(stderr, "usage:\n%s %s\n", scriptname, "<list of integers>");
}

int min_count_to_sum_to_s(int *arr, int size, int sum)
{
	int count;
	int min_count=0;
	for(count=size-1;count>=0;count--)
	{
		if(arr[count]==sum)
		{
			min_count=1;
			break;
		}
		else if(arr[count]>sum)
			continue;
		else
			break;
	}

	if(min_count==1)
		return min_count;
	else
	{
		int new_arr_size=count+1;
		for(count=0;count<=new_arr_size-1;count++)
		{
			int count_incr=1;
			while(count+count_incr<=new_arr_size-1)
			{
				int internal_count;
				int sum_found=0;
				int temp_sum=arr[count];
				int temp_min_count=1;
				for(internal_count=count+count_incr;internal_count<=new_arr_size-1;internal_count++)
				{
					temp_sum+=arr[internal_count];
					if(temp_sum==sum)
					{
						sum_found=1;		
						temp_min_count++;
						break;
					}
					else if(temp_sum>sum)
						break;
					temp_min_count++;
				}
				if(sum_found && min_count==0)	
					min_count=temp_min_count;
				else if(sum_found && min_count>temp_min_count)
					min_count=temp_min_count;
				count_incr++;
			}
		}
	}
	return min_count;
}
