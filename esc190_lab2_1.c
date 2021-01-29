#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node *start);
void print_linked(struct node *start);
void print_linked_recur(struct node *curr);


int main(){
    start = create(start);
    print_linked(start);
    print_linked_recur(start);
    
    return 0;
}

void print_linked(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while (ptr != NULL)
    {
        printf("current = %d, value = %d, next = %d\n", ptr, ptr->data, ptr->next);
        ptr = ptr->next;
    }
}

void print_linked_recur(struct node *curr)
{
    if (curr != NULL){
        printf("current = %d, value = %d, next = %d\n", curr, curr->data, curr->next);
        print_linked_recur(curr->next);
    }
}

//create a linked list (for testing)
struct node *create(struct node *start)
{
	int number;
	struct node *ptr;
	struct node *new_node;
	
	printf("\nInput a non zero positive integer: ");
	scanf("%d", &number);
	

	while (number > 0) 
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
	
		printf("\nInput a non zero positive integer: ");
		scanf("%d", &number);
	}
	
	return start;
}
