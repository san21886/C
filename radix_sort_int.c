#include<stdio.h>
#include<stdlib.h>

void radix_sort(int *, int);

void radix_sort(int *arr, int size)
{
	int max=arr[0];
	int count;
	for(count=1;count<=size-1;count++)
		if(arr[count]>max)
			max=arr[count];
	int divisor=1;
	while(max/divisor>0)
	{
		int temp_arr[10]={0};
		for(count=0;count<=size-1;count++)
		{
			int sb=(arr[count]/divisor) %10;
			temp_arr[sb]++;
		}
		for(count=1;count<=9;count++)
			temp_arr[count]+=temp_arr[count-1];
		int temp_arr2[size];
		for(count=size-1;count>=0;count--)
		{
			int sb=(arr[count]/divisor) %10;
			int new_index=--temp_arr[sb];
			temp_arr2[new_index]=arr[count];
		}
		for(count=0;count<=size-1;count++)
			arr[count]=temp_arr2[count];
		divisor*=10;
	}
}
