#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* createnode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct node *head){
    if (head == NULL){
        printf("List is empty. \n");
        return;
    }
    struct node *temp = head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!= head);
    printf("(head)\n");
}

void count(struct node *head){
    int ct=0;
    if (head == NULL){
        printf("number of items is 0.\n");
        return;
    }
    struct node *temp = head;
    do{
        ct++;
        temp=temp->next;
    }while(temp!= head);
    printf("number of items is %d \n",ct);
}

void ins_end(struct node **head, int no) {
    struct node *temp = createnode(no);
    if (*head == NULL) {
        *head = temp;
        temp->next = temp;
        temp->prev = temp;
        printf("Inserted %d at end (list was empty)\n", no);
        return;
    }
    
    struct node *last = (*head)->prev;
    
    temp->next = *head;
    (*head)->prev = temp;
    temp->prev = last;
    last->next = temp;
    
    printf("Inserted %d at end\n", no);
}

void ins_beg(struct node **head,int no){
    struct node* temp = createnode(no);
    if (*head == NULL){
        *head = temp;
        temp->next = temp;
        temp->prev = temp;
        printf("Inserted %d at beginning (list was empty)\n", no); 
        return ;
    }
    struct node *last = (*head)->prev;
    
    temp->next = *head;
    temp->prev = last;
    last->next = temp;
    (*head)->prev = temp;
    *head = temp;
    printf("Inserted %d at beginning\n", no);
}

void ins_pos(struct node **head,int no,int pos){
    
    if (pos < 1) {
        printf("Invalid position! Position must be >= 1\n");
        return;
    }

    if (pos == 1) {
        ins_beg(head,no); 
        return;
    }
    struct node *temp = createnode(no);
    struct node *ptr = *head;
    int i;
    for(i = 1 ;i < pos-1 && ptr->next != *head ;i++){
        ptr = ptr->next;
    }
    
    if (i < pos - 1 || ptr->next == *head && pos > i + 1) {
        printf("Position out of bounds\n");
        free(temp);
        return;
    }
    
    temp->next = ptr->next;
    ptr->next->prev = temp;
    temp->prev = ptr;
    ptr->next = temp;
    printf("Inserted %d at position %d\n", no, pos);
}

void del_end(struct node **head){
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    
    struct node *last = (*head)->prev;
    if (last->next == *head) {
        printf("Deleted node from end: %d\n", last->data);
        free(last);
        *head = NULL;  
        return;
    }
    
    struct node *prev = last->prev;
    prev->next = *head;
    (*head)->prev = prev;
    printf("Deleted node from end: %d\n", last->data);
    free(last);
}

void del_beg(struct node **head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    
    struct node *temp = *head;
    if (temp->next == *head) {
        *head = NULL;
    } else {
        struct node *last = (*head)->prev;
        
        last->next = temp->next;
        temp->next->prev = last; 
        *head = temp->next;
    }
    printf("Deleted node from beginning: %d\n", temp->data);
    free(temp);
}

void del_pos(struct node **head, int pos)
{
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (pos < 1) {
        printf("Invalid position! Position must be >= 1\n");
        return;
    }
    
    if (pos == 1) {
        del_beg(head);
        return;
    }
    struct node *temp = *head;
    int i;
    for (i = 1; i < pos && temp->next != *head; i++){
        temp = temp->next;
    }
    
    if (i < pos || temp == *head) {
        printf("Position out of bounds\n");
        return;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev ;
    printf("Deleted node from position %d: %d\n", pos, temp->data);
    free(temp);
}

void free_list(struct node **head)
{
if (*head == NULL) return;
struct node *current = *head, *temp;
do {
    temp = current;
    current = current->next;
    free(temp);
} while (current != *head);
*head = NULL;
}

int main() {
    struct node *head = NULL;
    int ch;
    int no,pos;
    while (true)
    {
        printf("1 - insert at end \n");
        printf("2 - insert at beginning \n");
        printf("3 - insert at pos \n");
        printf("4 - delete at end \n");
        printf("5 - delete at beginning \n");
        printf("6 - delete at pos \n");
        printf("7 - list display \n");
        printf("8 - number of items in list \n");
        printf("9- quit \n");
        scanf(" %d",&ch);
        if (ch == 1)
        {
            printf("enter number : ");
            scanf("%d",&no);
            ins_end(&head,no);
            printf("\n");
        }
        else if (ch == 2)
        {
            printf("enter number : ");
            scanf("%d",&no);
            ins_beg(&head,no);
            printf("\n");
        }
        else if (ch == 3)
        {
            printf("enter number : ");
            scanf("%d",&no);
            printf("enter position : ");
            scanf("%d",&pos);
            ins_pos(&head,no,pos);
            printf("\n");
        }
        else if(ch == 4)
        {
            del_end(&head);
            printf("\n");
        }
        else if(ch == 5)
        {
            del_beg(&head);
            printf("\n");
        }
        else if(ch == 6)
        {
            printf("enter position : ");
            scanf("%d",&pos);
            del_pos(&head,pos);
            printf("\n");
        }
        else if (ch == 7)
        {
            display(head);
            printf("\n");
        }
        else if (ch == 8)
        {
            count(head);
            printf("\n");
        }
        else if (ch == 9){
            free_list(&head);
            break;
        }
        else
            printf("wrong key pressed !!!\n");
    }
    return 0;
}
