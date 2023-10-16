# include<stdio.h>
# include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct circularQueue *q){
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue*q, int val){
    if (isFull(q))
    {
        printf("The queue is Full.\n");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqued element: %d.\n", val);
    }
}
int dequeue(struct circularQueue*q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is Empty.\n");
    }
    else
    {
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));

    

    //Enqueue few elements:
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 7);
    enqueue(&q, 3);
    printf("Dequeuing element %d. \n", dequeue(&q));
    printf("Dequeuing element %d. \n", dequeue(&q));
    printf("Dequeuing element %d. \n", dequeue(&q));
    if (isEmpty(&q))
    {
        printf("Queue is Empty.\n");
    }
    if (isFull(&q))
    {
        printf("Queue is Full.\n");
    }
    return 0;
}