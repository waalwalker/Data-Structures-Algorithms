# include<stdio.h>
# include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    printf("Element is %d. \n", ptr->data);
    ptr = ptr->next;
    
    do{
        printf("Element is %d. \n", ptr->data);
        ptr = ptr->next;
    }while (ptr!=head);   
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;

    while (p->next != head)
    {
        p = p->next;

    }
    // At this point p points to the last node of the circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
 
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocating memory for nodes of linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // Linking head(first) and second node
    head->data = 4;
    head->next = second;

    // Linking second and third node
    second->data = 3;
    second->next = third;

    // Linking third and fourth node
    third->data = 6;
    third->next = fourth;

    // Terminating list at third node
    fourth->data = 1;
    fourth->next = head;

    printf("Circular Linked list before insertion: \n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 7);
    printf("Circular Linked list After insertion: \n");
    linkedListTraversal(head);
    return 0;
}