#include<stdio.h>
#include<stdlib.h>

void insert_data_in_matrix(int *, int,int);
void print_2d_array(int *, int , int );
void print_2d_prim_digonal(int *, int, int);
void matrix_transpose(int *, int, int);

void main(int argc, char *argv[])
{
	int row_count=3, col_count=3;
	int mat[row_count][col_count];
	insert_data_in_matrix(&mat[0][0],row_count,col_count);
	print_2d_array(&mat[0][0],row_count,col_count);
	print_2d_prim_digonal(&mat[0][0],row_count,col_count);
	matrix_transpose(&mat[0][0],row_count,col_count);
	print_2d_array(&mat[0][0],row_count,col_count);
}

void insert_data_in_matrix(int *mat, int row_count, int col_count)
{
	int row_index,col_index;
	for(row_index=0;row_index<=row_count-1;row_index++)
	{
		for(col_index=0;col_index<=col_count-1;col_index++)
		{
			fprintf(stderr, "[%d][%d]",row_index,col_index);
			scanf("%d", mat+row_index+col_index);
		}
		mat=mat+col_count-1;
		fprintf(stderr, "\n");
	}
}

void print_2d_array(int *mat, int row_count, int col_count)
{
	int row_index,col_index;
	for(row_index=0;row_index<=row_count-1;row_index++)
	{
		for(col_index=0;col_index<=col_count-1;col_index++)
			fprintf(stdout, "%d ", *(mat+row_index+col_index));
		mat=mat+col_count-1;
		fprintf(stdout, "\n");
	}
}

void print_2d_prim_digonal(int *mat, int row_count, int col_count)
{
	int index;	
	for(index=0;index<=col_count-1;index++)
	{
		fprintf(stdout, "%d\n", *(mat+index+index));
		mat=mat+col_count-1;
	}
}

void matrix_transpose(int *mat, int row_count, int col_count)
{
	int row_index,col_index;
	for(row_index=0;row_index<=row_count-1;row_index++)
	{
		for(col_index=row_index;col_index<=col_count-1;col_index++)
		{
			int data1=*(mat+row_index+col_index);
			int data2=*(mat+(col_index-row_index)*(col_count-1)+row_index+col_index);
			data1+=data2;
			data2=data1-data2;
			data1-=data2;
			*(mat+row_index+col_index)=data1;
			*(mat+(col_index-row_index)*(col_count-1)+row_index+col_index)=data2;
		}
		mat=mat+col_count-1;
	}
}
