#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;  
    struct node *next;
};

int has_cycle(struct node *head){
    if (head == NULL)
        return 0;
        
    struct node *h = head;   // h for hare
    struct node *t = head;   // t for tortoise
        
    while(h->next != NULL && h->next->next != NULL) //h in a linked list will never reach NULL since it always comes back to the nodes that are already taversed
    {
        t = t->next;
        h = h->next->next;

        if (t == h){
            return 1;
        }
    }    
    return 0;
}


int main(void)
{
    //empty linked list
    //struct node *node0 = NULL;

  /*
    //looped linked list
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->value = 0;
    
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->value = 1;
    node0->next = node1;

    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->value = 2;
    node1->next = node2;

    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->value = 3;
    node2->next = node3;

    struct node *node4 = (struct node *)malloc(sizeof(struct node));
    node4->value = 4;
    node3->next = node4;

    struct node *node5 = (struct node *)malloc(sizeof(struct node));
    node5->value = 5;
    node4->next = node5;
    node5->next = node2;
*/

/*
    //unlooped list w 2 nodes
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->value = 0;

    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->value = 1;
    node0->next = node1;

    node0->next = NULL;

    //unlooped list w 1 node
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->value = 0;
    node0->next = NULL;

    //looped list pointing to itself
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->value = 0;
    node0->next = node0;
*/

    if (has_cycle(node0))
        printf("Yes, it has cycle!\n");
    else
    {
        printf("No, it has no cycles!\n");
    }
    
    return 0;
}