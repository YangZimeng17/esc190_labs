#include <stdlib.h>
#include <stdio.h>
#include "lab4_linkedlist.h"

int main(void)
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    printf("At the beginning of Main, new head addr: %ld\n", head);

    head = insert(head, 1, 10);
    head = insert(head, 2, 20);
    head = insert(head, 1, 100);
    head = insert(head, 0, 500);
    //insert_node(&head, 0, 600);
    //insert_node(&head, 1, 700);
    print_linked_list(head);
    delete_node_byvalue(&head, 1);
    printf("At the ends of main, new head addr: %ld\n", head);
    print_linked_list(head);
    free_linked_list(head);
    //print_linked_list(head);
}
