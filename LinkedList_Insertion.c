# include<stdio.h>
# include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node * ptr){
    printf("Linked list Traversal: \n");
    while (ptr != NULL)
    {
        printf("The data entered is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}
// CASE 1:
struct Node * insertAtFirst(struct Node *head, int data){
    printf("Here it is the new Node head as follows: \n");
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

// CASE 2:
struct Node * insertInBetween(struct Node *head, int data, int index)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
};

// CASE 3:
struct Node * insertAtEnd(struct Node *head, int data)
{
    printf("Here it is the new Node at the end: \n");
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
    
};

// CASE 4:
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    printf("Here it is the new Node after a node in the List: \n");
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr->data =data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
    
};



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

    printf("Here it is the new Node in between as follows: \n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertInBetween(head, 56, 2);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, second, 45);
    linkedListTraversal(head);
    
    return 0;
}