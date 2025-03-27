#include <stdio.h>
#include <stdbool.h>
#define MAX 20 

typedef struct {
    int arr[MAX]; 
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("%d pushed to stack\n", value);
}


void pop(Stack *s)
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow! Nothing to pop.\n");
        return ;
    }
    printf("Deleted Element : %d",s->arr[s->top--]) ;
    printf("\n");
}

void peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return ;
    }
    printf("Top Element is : %d",s->arr[s->top]); 
    printf("\n");
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s); 
    char ch;
    int no;
    while (true)
    {
        printf("press p for push \n");
        printf("press v for pop \n");
        printf("press a for peek \n");
        printf("press d for stack display \n");
        printf("press q for quit \n");
        scanf(" %c",&ch);
        if (ch == 'p')
        {
            printf("enter number : ");
            scanf("%d",&no);
            push(&s,no);
            printf("\n");
        }
        else if(ch == 'v'){
            pop(&s);
            printf("\n");
        }
        else if (ch == 'a'){
            peek(&s);
            printf("\n");
        }else if (ch == 'd'){
            display(&s);
            printf("\n");
        }else if (ch == 'q'){
            break;
        }else{
            printf("wrong key pressed !!!");
        }
    }
    
    return 0;
}

