# include<stdio.h>
# include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
};

void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    printf("Element is %d. \n", ptr->data);
    ptr = ptr->next;
    ptr->prev = NULL;
    
    do{
        printf("Element is %d. \n", ptr->data);
        ptr = ptr->next;
    }while (ptr!=head);   
}


int main(){
    //Creating Nodes:
    struct Node * N1;
    struct Node * N2;
    struct Node * N3;
    struct Node * N4;

    N1 = (struct Node *) malloc(sizeof(struct Node));
    N2 = (struct Node *) malloc(sizeof(struct Node));
    N3 = (struct Node *) malloc(sizeof(struct Node));
    N4 = (struct Node *) malloc(sizeof(struct Node));

    //Linking Nodes:
    N1->next = N2;
    N1->prev = NULL;

    N2->next = N3;
    N2->prev = N1;

    N3->next = N4;
    N3->prev = N2;

    N4->next = N3;
    N4->prev = NULL;

    printf("The Doubly linked list is as follows: \n");
    linkedListTraversal(N1);

    return 0;
}