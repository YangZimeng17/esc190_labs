#include <stdio.h>
#include <malloc.h>

struct node{
    void *p_data;
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

struct node *append_int(struct node *start, int new_value)
{
    struct node *new_node;
    struct node *ptr;
    ptr = start;

    //create new node
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->type = 0;
    new_node->p_data = &new_value; //how to pass value? i'm not sure if this is right
    new_node->next = NULL;

    // move pointer to last
    while (ptr->next != NULL){
        ptr = ptr->next;
    }

    //link new node to linked list
    ptr->next = new_node;

    return start;

}



int main(){

    return 0;
}