#include<stdio.h>
#include <stdbool.h>

#define max 20

typedef struct{ 
    int arr[max];
    int front ;
    int rear;
}queue;

void initqueue(queue * q){
    q->front = q->rear = -1;
}

void enqueue(queue *q , int val){
    if ((q->rear+1) % max == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    
    if (q->front == -1) 
        q->front = 0;
        
    q->rear = (q->rear+1)%max;
    q->arr[q->rear] = val;
}

int dequeue(queue *q) {
    if (q->front == -1) {  
        printf("Queue is empty\n");
        return -1; 
    }
    int val = q->arr[q->front];

    if (q->front == q->rear) {  
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % max;
    }
    return val;
}

void display(queue *q){
    if (q->front == -1){
        printf("Queue is empty\n");
        return ;
    }
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % max;  
    }
    printf("\n");
}

int main(){
    queue myQueue;
    initqueue(&myQueue);
    int ch;
    int no;

    while (true)
    {
        printf("1 - enqueue\n");
        printf("2 - dequeue\n");
        printf("3 - display\n");
        printf("4 - quit\n");
        printf("Enter choice: ");
        
        scanf(" %d", &ch);
        
        switch (ch){
        case 1:
            printf("Enter number: ");
            scanf("%d", &no);
            enqueue(&myQueue, no);
            break;
            
        case 2 :
            printf("Dequeued item: %d\n", dequeue(&myQueue));
            break;
            
        case 3:
            display(&myQueue);
            break;
            
        case 4:
            return 0;
            
        default:
            printf("Wrong key pressed.\n");
        }
    }
}
