#include<stdio.h>
#include<stdlib.h>

struct BSTNode{
	int data;
	struct BSTNode *lnp, *rnp;
};
typedef struct BSTNode bstn;

bstn *create_bst(int *, int);
bstn *insert_bst_node(bstn *, int);
void print_node_ancestor(bstn *, int, int);
void print_ancestors(bstn *ancestors[]);


void main(int argc, char *argv[])
{
	int arr_size=argc-1;
	int count;
	int arr[arr_size];
	for(count=0;count<=arr_size-1;count++)
		arr[count]=atoi(argv[count+1]);
	bstn *root=create_bst(arr, arr_size);
	//bstn *ancestors[100]={NULL};
	printf("Enter element to find its ancestors\n");
	int element;
	scanf("%d", &element);
	int element2;
	printf("Enter element to find common ancestor\n");
	scanf("%d", &element2);
	print_node_ancestor(root, element, element2);
}

bstn *create_bst(int *arr, int size)
{
	bstn *root=NULL;
	int count;
	for(count=0;count<=size-1;count++)
		root=insert_bst_node(root, arr[count]);
	return root;
}

bstn *insert_bst_node(bstn *root, int data)
{
	if(root==NULL)
	{
		bstn *node=(bstn *) malloc(sizeof(bstn));
		node->data=data;
		node->lnp=NULL;
		node->rnp=NULL;
		return node;
	}
	else
	{
		if(data<=root->data)
			root->lnp=insert_bst_node(root->lnp, data);
		else
			root->rnp=insert_bst_node(root->rnp, data);
	}
	return root;
}

int data1_ancestors[10];
int data2_ancestors[10];

void print_node_ancestor(bstn *root, int data, int data2)
{
	bstn static *ancestors[100]={NULL};
	int static data1_found=0;
	int static data2_found=0;
	if(root!=NULL)
	{
		if(root->data==data)
		{
			int count=0;
			while(ancestors[count]!=NULL)
			{
				data1_ancestors[count]=ancestors[count]->data;;
				count++;
			}
			data1_found=1;
			print_ancestors(ancestors);
		}

		if(root->data==data2)
		{
			int count=0;
			while(ancestors[count]!=NULL)
			{
				data2_ancestors[count]=ancestors[count]->data;
				count++;
			}
			data2_found=1;
			print_ancestors(ancestors);
		}

		int count=0;
		while(ancestors[count]!=NULL)
			count++;
		ancestors[count]=root;

		if(root->lnp!=NULL)
			 print_node_ancestor(root->lnp, data, data2);
		
		if(root->rnp!=NULL)
			 print_node_ancestor(root->rnp, data, data2);

		count=0;
		while(ancestors[count]!=NULL)
			count++;
		ancestors[count-1]=NULL;
	}

	if(data1_found && data2_found)
	{
		int count=0;
		int min=data1_ancestors[count];
		while(data1_ancestors[count]==data2_ancestors[count])
		{
			if(data1_ancestors[count]<min)
				min=data1_ancestors[count];
			count++;
		}
		printf("min ancestor found:%d\n", min);
	}
}

void print_ancestors(bstn *ancestors[])
{
	int count=0;
	while(ancestors[count]!=NULL)
	{
		if(ancestors[count+1]!=NULL)
			printf("%d->", ancestors[count]->data);
		else
			printf("%d\n", ancestors[count]->data);
		count++;
	}
}
