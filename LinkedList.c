# include<stdio.h>
# include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("The data entered is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Allocating memory for nodes of linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // Linking head(first) and second node
    head->data = 7;
    head->next = second;

    // Linking second and third node
    second->data = 11;
    second->next = third;

    // Terminating list at third node
    third->data = 66;
    third->next = NULL;

    linkedListTraversal(head);
    
    return 0;
}