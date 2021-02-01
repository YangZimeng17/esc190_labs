#include <stdio.h>
#include <stdlib.h>


struct node{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

void append_int(struct node *head, int type, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (type==0)  { // for int   
        node->p_data=(int *) malloc(sizeof(int));  
        *((int*)node->p_data)=value;
    }
    node->next = NULL;
    node->type = type;
    cur->next = node;
    //printf("add a node with type: %d, vaule %d\n", node->type, *((int*)node->p_data));
}

void append_float(struct node *head, int type, float value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (type==1)  { // for float  
        node->p_data=(float *) malloc(sizeof(float)) ;  
        *((float*)node->p_data)=value;
    }
    node->next = NULL;
    node->type = type;
    cur->next = node;     
}

void append_double(struct node *head, int type, double value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (type==2)  { // for double  
        node->p_data=(double *) malloc(sizeof(double)) ;  
        *((double*)node->p_data)=value;
    }
    node->next = NULL;
    node->type = type;
    cur->next = node;    
}

void print(struct node *head){
    struct node *cur = head;
    while(cur != NULL){
        if(cur->type==0)
            printf("This node contains an integer: %d\n",*((int *)cur->p_data));
        
        if(cur->type==1)
            printf("This node contains a float: %f\n",*((float*)cur->p_data));
        
        if(cur->type==2)
            printf("This node contains a double: %Lf\n",*((double*)cur->p_data));
        
        cur = cur->next;
    }
}

int main(void)
{
    struct node *node0=  (struct node *)malloc(sizeof(struct node));
    node0->next = NULL;
    node0->type = 0;
    node0->p_data=(int *)malloc(sizeof(int));
    *((int*)node0->p_data)=10;
 
    //printf("node0->p_data value: %d\n", *((int*)node0->p_data));   
    append_int(node0, 0, 20);
    append_int(node0, 0, 30);

    append_float(node0, 1, 40.0);
    append_double(node0, 2, 50.0);

    append_float(node0, 1, 3.1415);
   /*
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 5;
    node1->next = NULL;
    */

    print(node0);
    //printf("hi, all\n");
    return 0;
}