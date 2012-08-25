#include<stdio.h>
#include<stdlib.h>

void quick_sort(int *, int, int);
int partition(int *, int,int,int);
void swap(int *, int *);

void quick_sort(int *arr, int left_index, int right_index)
{
	if(left_index<right_index)
	{
		int size=right_index-left_index+1;
		int pivot_index=(size%2==0) ? (size/2 - 1) : ((size+1)/2 - 1);
		pivot_index+=left_index;
		pivot_index=partition(arr, left_index, right_index, pivot_index);
		quick_sort(arr, left_index, pivot_index-1);
		quick_sort(arr, pivot_index+1, right_index);
	}
}


int partition(int *arr, int li, int ri, int pi)
{
	/*swap pivot element to right most element*/
	swap(arr+pi, arr+ri);
	int count;
	int hole_index=li;
	for(count=li;count<=ri-1;count++)
	{
		if(arr[count]<arr[ri])	
		{
			swap(arr+hole_index, arr+count);
			hole_index++;
		}

	}
	swap(arr+hole_index, arr+ri);
	return hole_index;
}

void swap(int *loc1, int *loc2)
{
	if(loc1!=loc2)
	{
		*loc1=*loc1+*loc2;
		*loc2=*loc1-*loc2;
		*loc1=*loc1-*loc2;
	}
}
