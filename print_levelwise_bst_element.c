#include<stdio.h>
#include<stdlib.h>

struct BSTNode{
	int data;
	struct BSTNode *lnp, *rnp;
};
typedef struct BSTNode bstn;

struct LLnode{
	int data;
	struct LLnode *next;
};
typedef struct LLnode lln;

lln *hashindex[10]={NULL};

bstn *create_bst(int *, int);
bstn *insert_bst_node(bstn *, int);
void preorder_traverse(bstn *, int);
void index_in_hashtable(int , int);
void print_nodes_levelwise();

void main(int argc, char *argv[])
{
	int arr_size=argc-1;
	int count;
	int arr[arr_size];
	for(count=0;count<=arr_size-1;count++)
		arr[count]=atoi(argv[count+1]);
	bstn *root=create_bst(arr, arr_size);
	preorder_traverse(root, -1);
	print_nodes_levelwise();
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

void preorder_traverse(bstn *root, int level)
{
	if(root!=NULL)
	{
		level++;
		//printf("%d\n", root->data);
		index_in_hashtable(level, root->data);
		if(root->lnp!=NULL)
			preorder_traverse(root->lnp, level);
		if(root->rnp!=NULL)
			preorder_traverse(root->rnp, level);
	}
}

void index_in_hashtable(int index, int data)
{
	lln *node=(lln *) malloc(sizeof(lln));
	node->data=data;
	node->next=NULL;
	if(hashindex[index]==NULL)
		hashindex[index]=node;
	else
	{
		lln *last_node=hashindex[index];
		while(last_node->next!=NULL)
			last_node=last_node->next;
		last_node->next=node;
	}
}

void print_nodes_levelwise()
{
	int count;
	for(count=0;count<=9;count++)
	{
		if(hashindex[count]!=NULL)
		{
			printf("[%d]", count);
			lln *current_node=hashindex[count];
			while(current_node!=NULL)
			{
				if(current_node->next!=NULL)
					printf("%d->", current_node->data);
				else
					printf("%d\n", current_node->data);
				current_node=current_node->next;
			}
		}
	}
}
