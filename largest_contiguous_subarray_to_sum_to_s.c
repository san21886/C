#include<stdio.h>
#include<stdlib.h>

void largest_contiguous_subarray_to_sum_to_s(int *, int , int);

void main(int argc, char *argv[])
{
	int arr_size=argc-1;
	int arr[arr_size];
	int count;
	for(count=0;count<=arr_size-1;count++)
		arr[count]=atoi(argv[count+1]);

	int S;
	printf("Enter Sum:\n");
	scanf("%d", &S);
	largest_contiguous_subarray_to_sum_to_s(arr, arr_size, S);
}

void largest_contiguous_subarray_to_sum_to_s(int *arr, int size, int S)
{
	int largest_subarray_start_index=-1;
	int largest_subarray_last_index=-1;
	int count;
	for(count=0;count<=size-1;count++)
	{
		int start_index=count;
		int last_index=count;
		int sum=arr[count];
		int internal_counter;
		for(internal_counter=count+1;internal_counter<=size-1;internal_counter++)
		{
			sum+=arr[internal_counter];
			last_index=internal_counter;
			if(sum>S)
			{
				if(sum-arr[internal_counter]==S)
					last_index=internal_counter-1;
				else
					last_index=-1;
				break;
			}
		}
		if(last_index!=-1 && (last_index-start_index)>(largest_subarray_last_index-largest_subarray_start_index))
		{
			largest_subarray_start_index=start_index;
			largest_subarray_last_index=last_index;
		}
	}
	if(largest_subarray_start_index!=-1)
		printf("largest contiguous sub array to sum S: start_index:%d and end_index:%d\n", largest_subarray_start_index, largest_subarray_last_index);
	else
		printf("No sub array exist to sum to:%d\n", S);
}
