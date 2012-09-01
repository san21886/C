#include<stdio.h>
#include<stdlib.h>

struct BTNode{
	int data;
	struct BTNode *lnp, *rnp;
};
typedef struct BTNode btn;

btn *create_bst(int *, int);
btn *insert_node(btn *, int );
void inorder(btn *);
int bt_find_the_level_at_which_the_tree_is_complete(btn *);

void main(int argc, char *argv[])
{
	int arr[argc-1];
	int count;
	for(count=0;count<=argc-2;count++)
		arr[count]=atoi(argv[count+1]);
	btn *root = create_bst(arr, argc-1);
	//inorder(root);
	int l = bt_find_the_level_at_which_the_tree_is_complete(root);
	printf("level=%d\n", l);
}

btn *create_bst(int *arr, int size)
{
	int count;
	btn *root=NULL;
	for(count=0;count<=size-1;count++)
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

void inorder(btn *root)
{
	if(root!=NULL)
	{
		if(root->lnp!=NULL)
			inorder(root->lnp);
		printf("%d\n", root->data);
		if(root->rnp!=NULL)
			inorder(root->rnp);
	}
}

//recursive
int bt_find_the_level_at_which_the_tree_is_complete(btn *root)
{
	int static cbtd = -1;
	int static level = 0;
	if(root->lnp!=NULL && root->rnp!=NULL)
	{
		level++;
		bt_find_the_level_at_which_the_tree_is_complete(root->lnp);
		bt_find_the_level_at_which_the_tree_is_complete(root->rnp);
		level--;
	}
	else
	{
		if(cbtd==-1 || level<cbtd)
			cbtd=level;
	}
	return cbtd;
}
