# include<stdio.h>
# include<stdlib.h>

struct Node * f = NULL;
struct Node * r = NULL;

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * ptr){
    printf("Printing the elements of the LINKED LIST.\n");
    while (ptr != NULL)
    {
        printf("The data entered is: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

void enqueue(int val){
    struct Node *n = (struct Node*)malloc(sizeof (struct Node));
    if (n==NULL)
    {
        printf("The Queue is FULL.\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else
        {
            r->next = n;
            r=n;
        }
    }
}
int dequeue(){
    int val = -1;
    struct Node *ptr = f;
    if (f==NULL)
    {
        printf("The Queue is EMPTY.\n");
    }
    else
    {
        f=f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}


int main(){


    enqueue(34);
    enqueue(17);
    enqueue(7);
    printf("Dequeuing element %d.\n", dequeue());
    linkedListTraversal(f);

    return 0;
}