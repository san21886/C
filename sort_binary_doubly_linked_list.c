#include<stdio.h>
#include<stdlib.h>

struct BDLinkedList{
	int data;
	struct BDLinkedList *prev, *next;
};

typedef struct BDLinkedList bdll;

bdll *append_list(bdll *, int);
bdll *dlist_sort(bdll *);
void print_list(bdll *);

void main(int argc, char *argv[])
{
	int arr_size=argc-1;
	int count;
	bdll *head=NULL;
	for(count=1;count<=arr_size;count++)
		head=append_list(head, atoi(argv[count]));
	head=dlist_sort(head);
	print_list(head);
}

bdll *append_list(bdll *head, int data)
{
	bdll *node=(bdll *) malloc(sizeof(bdll));
	node->data=data;
	node->next=NULL;
	if(head==NULL)
	{
		node->prev=NULL;
		return node;
	}
	else
	{
		bdll *current_node=head;
		while(current_node->next!=NULL)
			current_node=current_node->next;
		current_node->next=node;
		node->prev=current_node;
	}
	return head;
}


bdll *dlist_sort(bdll *head)
{
	if(head==NULL)
		return NULL;
	else
	{
		bdll *current_node=head;
		while(current_node!=NULL)
		{
			int ousted_data=current_node->data;
			bdll *hole_node=current_node;
			bdll *prev_to_hole=hole_node->prev;
			while(prev_to_hole!=NULL && prev_to_hole->data>ousted_data)
			{
				hole_node->data=prev_to_hole->data;
				hole_node=prev_to_hole;
				prev_to_hole=hole_node->prev;
			}
			hole_node->data=ousted_data;
			current_node=current_node->next;
		}
	}
	return head;
}

void print_list(bdll *head)
{
	while(head!=NULL)
	{
		printf("%d\n", head->data);
		head=head->next;
	}
}
