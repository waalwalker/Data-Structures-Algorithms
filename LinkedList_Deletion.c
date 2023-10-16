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

// CASE 1:
struct Node * deleteFirst(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);

    return head;
};

// CASE 2:
struct Node * deleteInBetween(struct Node * head, int index)
{
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};

// CASE 3:
struct Node * deleteAtLast(struct Node * head)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

// CASE 4: Deleting an element with a given value
struct Node * deleteAtIndex(struct Node * head, int value)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
};


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
    third->data = 8;
    third->next = fourth;

    // Terminating list at third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // head = deleteFirst(head);
    // head = deleteFirst(head);
    // head = deleteInBetween(head, 2);
    // head = deleteAtLast(head);
    head = deleteAtIndex(head, 3);

    printf("Linked list after deletion\n");
    linkedListTraversal(head);
    
    return 0;
}