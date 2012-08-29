#include<stdio.h>
#include<stdlib.h>

struct BTNode {
	int data;
	struct BTNode *lnp, *rnp;
};
typedef struct BTNode btn;

btn *create_bst(int *, int);
btn *insert_node(btn *, int);
int check_if_y_lies_in_path_between_x_and_z(btn *,btn *,btn *, btn *);

void main(int argc, char *argv[])
{
	int nodes_count=argc-1;
	int arr[nodes_count];
	int count;
	for(count=0;count<=nodes_count-1;count++)
		arr[count]=atoi(argv[count+1]);
	btn *root=create_bst(arr, nodes_count);
	btn *x=(btn *) malloc(sizeof(btn));
	x->data=11;
	btn *y=(btn *) malloc(sizeof(btn));
	y->data=10;
	btn *z=(btn *) malloc(sizeof(btn));
	z->data=0;
	printf("%d\n", check_if_y_lies_in_path_between_x_and_z(root, x, y, z));
}

btn *create_bst(int *arr, int node_count)
{
	btn *root=NULL;
	int count;
	for(count=0;count<=node_count-1;count++)
		root=insert_node(root, arr[count]);
	return root;
}

btn *insert_node(btn *root, int data)
{
	if(root==NULL)	
	{
		btn *node=(btn *) malloc(sizeof(btn));
		node->data=data;
		node->lnp=NULL;
		node->rnp=NULL;
		return node;
	}
	else
	{
		if(data<=root->data)
			root->lnp=insert_node(root->lnp, data);
		else
			root->rnp=insert_node(root->rnp, data);
	}
	return root;
}

int check_if_y_lies_in_path_between_x_and_z(btn *root, btn *x,btn *y, btn *z)
{
	int static smaller_of_xandz_found=0;
	int static xandz_found=0;
	int static y_found=0;
	int return_flag=0;
	btn *small;
	btn *large;
	if (x->data<=z->data)
	{
		small=x;
		large=z;
	}
	else
	{
		small=z;
		large=x;
	}

	if(root!=NULL)	
	{
		if(root->lnp!=NULL)
			return_flag=check_if_y_lies_in_path_between_x_and_z(root->lnp, x, y, z);
		
		int root_data=root->data;
		if(root_data==small->data)
		{
			if(!smaller_of_xandz_found)	
				smaller_of_xandz_found=1;
		}
		if(smaller_of_xandz_found && !y_found && !xandz_found && y->data==root_data)	
		{
			y_found=1;
		}
		if(smaller_of_xandz_found && y_found && !xandz_found && large->data==root_data)	
		{
			xandz_found=1;
		}
		

		if(root->rnp!=NULL)
			return_flag=check_if_y_lies_in_path_between_x_and_z(root->rnp, x, y, z);
		
	}

	if(xandz_found && y_found)
		return 1;
	else
		return 0;
}
