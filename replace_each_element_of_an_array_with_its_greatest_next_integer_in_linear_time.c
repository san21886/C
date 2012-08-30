#include<stdio.h>
#include<stdlib.h>


void replace_each_element_of_an_array_with_its_greatest_next_integer_in_linear_time(int *, int);

void main(int argc, char *argv[])
{
	int arr[argc-1];	
	int count;
	for(count=0;count<=argc-2;count++)
		arr[count]=atoi(argv[count+1]);
	replace_each_element_of_an_array_with_its_greatest_next_integer_in_linear_time(arr, argc-1);
	for(count=0;count<=argc-2;count++)
		printf("%d\n", arr[count]);
}

void replace_each_element_of_an_array_with_its_greatest_next_integer_in_linear_time(int *arr, int size)
{
	int current_max=arr[size-1];
	int count;
	int ret_arr[size];
	for(count=size-2;count>=0;count--)
	{
		int temp_val=*(arr+count);
		*(arr+count)=current_max;
		current_max=(temp_val>current_max) ? temp_val : current_max;
	}
}
