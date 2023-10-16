# include<stdio.h>
# include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct queue *q){
    if (q->r == q->size -1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueueF(struct queue*q, int val){
    if (isFull(q))
    {
        printf("The queue is Full.");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d.\n", val);
    }
}

void enqueueB(struct queue*q, int val){
    if (isFull(q))
    {
        printf("The queue is Full.");
    }
    else
    {
        q->f++;
        q->arr[q->f] = val;
        printf("Enqued element: %d.\n", val);
    }
}

int dequeueF(struct queue*q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is Empty.");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int dequeueB(struct queue*q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is Empty.");
    }
    else
    {
        q->r--;
        a = q->arr[q->r];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));

    

    //Enqueue few elements:
    enqueueF(&q, 12);
    enqueueB(&q, 15);
    enqueueF(&q, 7);
    enqueueF(&q, 8);
    printf("Dequeuing element %d. \n", dequeueF(&q));
    printf("Dequeuing element %d. \n", dequeueB(&q));
    // printf("Dequeuing element %d. \n", dequeue(&q));
    if (isEmpty(&q))
    {
        printf("Queue is Empty.");
    }
    if (isFull(&q))
    {
        printf("Queue is Full.");
    }
    return 0;
}