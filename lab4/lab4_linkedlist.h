#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H
struct node{
    int data;
    struct node *next;
};

void print_linked_list(struct node *head);

int append(struct node * head, int value);

struct node *insert(struct node *head, int index, int value);

//int insert_node(struct node **head, int index, int value);

//int delete_node(struct node ** head, struct node * anode);

int delete_node_byvalue(struct node ** head, int value);

void free_linked_list(struct node * head);

#endif


/*
#include <stdio.h>

struct node{
    int data;
    struct node next;
};

//header file
struct node *create(struct node *start){
	int number;
	struct node *ptr;
	struct node *new_node;
	
	printf("\nInput an integer: ");
	scanf("%d", &number);
	

	while (number != -1) 
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = number;
		new_node->next = NULL;

		if (start == NULL)
		{
			start = new_node;
			ptr = NULL;
		}
		if (ptr != NULL)
		{
			ptr->next = new_node;
		}
		ptr = new_node;
	
		printf("\nInput an integer: ");
		scanf("%d", &number);
	}
	
	return start;
}
struct node *insert(struct node *start, int index);
struct node *delete_node(struct node *start);
struct node *free_entire(struct node *start);
*/
