#include <stdio.h>
#include <stdlib.h>
#include "lab4_linkedlist.h"

void print_linked_list(struct node *head)
{
    while(head){
        printf("%d\n", head->data);
        head = head->next;
    }
}

int append(struct node * head, int value){
    struct node * cur = head;
    while (cur->next!=NULL)
        cur=cur->next;
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->next=NULL;
    node->data=value;
    cur->next=node;
    return 1;
}

struct node *insert(struct node *head, int index, int value){
    struct node * cur = head;
    if (index==0){   //insert before the head node
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->next=head;
        node->data=value;
        return node;
    }

    while (--index!=0){
        if (cur==NULL){
            printf("Index is out of bound!\n");
            return NULL;
        }
        else
            cur=cur->next;
    }
    // cur points to the node before where the new node would be inserted.
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->next=cur->next;
    node->data=value;
    cur->next=node;
    return head;    
}


int delete_node_byvalue(struct node ** head, int value){
    if (*head==NULL)
        return 0;
    struct node * cur=*head;
    struct node * tmp;
    if(cur->data==value){
        //printf("In delete note, head addr: %ld\n", *head);
        *head=cur->next;
        free(cur);
        //printf("In delete note, new head addr: %ld\n", *head);
        return 1;
    }
    
    while(cur->next!=NULL){
        if(cur->next->data==value){
            tmp=cur->next;
            cur->next=cur->next->next;
            free(tmp);
            return 1;
        }
        cur=cur->next;
    }
    return 0;    
}


void free_linked_list(struct node * head)
{
    struct node * tmp;
    struct node * cur=head;
    while (cur!=NULL){
        tmp=cur;
        cur=cur->next;
        free(tmp);
    }
}

/*
int insert_node(struct node **head, int index, int value){
    struct node * cur = *head;
    if (index==0){   //insert before the head node
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->next=*head;
        node->data=value;
        *head = node;
        return 1;
    }

    while (--index!=0){
        if (cur==NULL){
            printf("Index is out of bound!\n");
            return 0;
        }
        else
            cur=cur->next;
    }
    // cur is pointing to the node after it the new node will be inserted.
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->next=cur->next;
    node->data=value;
    cur->next=node;
    return 1;        
}
*/

/*
Below function does not work if you want to delete the head node
int delete_node(struct node * head, struct node * anode){
    if (head==NULL)
        return 0;     
    struct node * cur=head;
    //struct node * tmp;
    if(head==anode){
        head=head->next;
        free(cur);
        return 1;
    }
    
    while(cur->next!=NULL){
        if(cur->next==anode){
            cur->next=cur->next->next;
            free(anode);
            return 1;
        }
        cur=cur->next;
    }
    return 0;
}
*/
/*
Below function does not work if you want to delete the head node
int delete_node_byvalue(struct node * head, int value){
    if (head==NULL)
        return 0;
    struct node * cur=head;
    struct node * tmp;
    if(head->data==value){
        printf("In delete note, head addr: %ld\n", head);
        head=head->next;
        free(cur);
        printf("In delete note, new head addr: %ld\n", head);
        return 1;
    }
    
    while(cur->next!=NULL){
        if(cur->next->data==value){
            tmp=cur->next;
            cur->next=cur->next->next;
            free(tmp);
            return 1;
        }
        cur=cur->next;
    }
    return 0;    
}
*/

/*
int delete_node(struct node ** head, struct node * anode){
    if (*head==NULL)
        return 0;     
    struct node * cur=*head;
    //struct node * tmp;
    if(cur==anode){
        *head=cur->next;
        free(cur);
        return 1;
    }
    
    while(cur->next!=NULL){
        if(cur->next==anode){
            cur->next=cur->next->next;
            free(anode);
            return 1;
        }
        cur=cur->next;
    }
    return 0;
}*/
