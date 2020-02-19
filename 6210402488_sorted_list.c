// 6210402488 Panupat Chulaotrakul

#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
    int data; 
    struct Node *next; 
}Node; 

struct Node *newNode(int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = NULL; 
    return new_node; 
}

void sortedInsert(struct Node **head_ref, struct Node *new_node) 
{ 
    struct Node *current; 
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        current = *head_ref; 
        while (current->next != NULL && current->next->data < new_node->data) 
            current = current->next; 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

int main() 
{ 
    struct Node *head = NULL; 
    struct Node *new_node;
    int num;
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = newNode(num); 
        sortedInsert(&head, new_node);
        scanf("%d", &num); 
    }
    while(head != NULL) 
    { 
        printf("%d\n", head->data); 
        head = head->next; 
    }
} 