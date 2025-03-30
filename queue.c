#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef struct {
    int items[MAX];
    int front;
    int rear;
} queue;

void init(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isfull(queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(queue *q, int val)
{
    if (isfull(q)) {
        printf("Queue is full!\n");
        return;
    } else if (isempty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = val;
}

int dequeue(queue *q)
{
    int item;
    if (isempty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else if (q->front == q->rear) {
        item = q->items[q->front];
        q->front = q->rear = -1;
    } else {
        item = q->items[q->front];
        q->front++;
    }
    return item;
}

void display(queue *q)
{
    if (isempty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() 
{
    queue myQueue;
    init(&myQueue);
    char ch;
    int no;

    while (true)
    {
        printf("e - enqueue\n");
        printf("d - dequeue\n");
        printf("s - display\n");
        printf("q - quit\n");
        printf("Enter choice: ");
        
        scanf(" %c", &ch);

        if (ch == 'e') {
            printf("Enter number: ");
            scanf("%d", &no);
            enqueue(&myQueue, no);
        } else if (ch == 'd') {
            printf("Dequeued item: %d\n", dequeue(&myQueue));
        } else if (ch == 's') {
            display(&myQueue);
        } else if (ch == 'q') {
            break;
        } else {
            printf("Wrong key pressed.\n");
        }
    }

    return 0;
}

