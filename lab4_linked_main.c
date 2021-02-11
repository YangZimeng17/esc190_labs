#include <stdlib.h>
#include <stdio.h>
#include "lab4_linkedlist.h"

int main(void)
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    printf("In Main beginning, new head addr: %ld\n", head);
    /*
    append( head, 2);
    append( head, 3);
    append( head, 4);
    append( head, 5);
    append( head, 10);
    */
    head = insert(head, 1, 10);
    head = insert(head, 2, 20);
    head = insert(head, 1, 100);
    head = insert(head, 0, 500);
    insert_node(&head, 0, 600);
    insert_node(&head, 1, 700);
    print_linked_list(head);
    delete_node_byvalue(&head, 1);
    printf("In main end, new head addr: %ld\n", head);
    print_linked_list(head);
}
