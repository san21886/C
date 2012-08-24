#include<stdio.h>
#include<stdlib.h>

int *merge_sort(int *, int);
int *merge(int *,int ,int *,int);

int *merge_sort(int *arr, int size)
{
	if(size==1)
	{
		return arr;	
	}
	else
	{
		int mid=(size%2==0) ? size/2 : (size+1)/2;
		int *larr=merge_sort(arr, mid);
		int *rarr=merge_sort(arr+mid, size-mid);
		arr=merge(larr,mid,rarr,size-mid);
	}
	return arr;
}

int *merge(int *larr,int lsize,int *rarr,int rsize)
{
	int merged_size=lsize+rsize;
	int *arr=(int *) malloc(sizeof(int)*merged_size);
	int count;
	int lindex=0;
	int rindex=0;
	for(count=0;count<=merged_size-1;count++)
	{
		if(lindex<=lsize-1 && rindex<=rsize-1)
		{
			if(larr[lindex]<=rarr[rindex])	
			{
				arr[count]=larr[lindex];
				lindex++;
			}
			else
			{
				arr[count]=rarr[rindex];
				rindex++;
			}
		}
		else if(lindex<=lsize-1)
		{
			arr[count]=larr[lindex];
			lindex++;
		}
		else
		{
			arr[count]=rarr[rindex];
			rindex++;
		}
	}
	return arr;
}
