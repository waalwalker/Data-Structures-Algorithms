# include<stdio.h>
# include<malloc.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node *n; // creating a node pointer
    n = (struct node*) malloc(sizeof(struct node)); // Allocating memory heap
    n->data = data; // setting the data
    n->left = NULL; // Setting the left children to NULL
    n->right = NULL; // Setting the left children to NULL
    return n; // Finally returning the created node
};

int main(){
    
    /*
    // Constructing the root node
    struct node* p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;
    struct node* p1;

    // Cosntructing the second node
    p1 = (struct node *) malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;
    struct node* p2;

    // Cosntructing the thrid node
    p2 = (struct node *) malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    */

    // Constructing the root node
    struct node* p = createNode(2);
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}