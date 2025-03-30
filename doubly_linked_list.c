#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node* createnode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct node *head)
{
    if (head == NULL){
        printf("List is empty. \n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

void count(struct node *head)
{
    int ct=0;
    if (head == NULL){
        printf("number of items is 0.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL){
        ct++;
        temp=temp->next;
    }
    printf("number of items is %d \n",ct);
}

void ins_end(struct node **head ,int no)
{
    struct node *ptr,*temp= createnode(no);
    if (*head == NULL){
        *head = temp;
        printf("Inserted %d at end (list was empty)\n", no);
        return ;
    }
    ptr = *head;
    while (ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    printf("Inserted %d at end\n", no);  
}

void ins_beg(struct node **head,int no)
{
    struct node* temp = createnode(no);
    if (*head == NULL){
        *head = temp;
        printf("Inserted %d at beginning (list was empty)\n", no); 
        return ;
    }
    temp->next = *head;
    (*head)->prev = temp;
    *head=temp;
    printf("Inserted %d at beginning\n", no);
}

void ins_pos(struct node **head,int no,int pos)
{
    struct node *ptr ,*temp = createnode(no);
    if (pos < 1) {
        printf("Invalid position! Position must be >= 1\n");
        free(temp);
        return;
    }
  
    if (pos == 1) {
        ins_beg(head,no); 
        return;
    }
    ptr = *head;
    for(int i = 1 ;i < pos-1 && ptr!=NULL ;i++){
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Position out of bounds\n");
        free(temp);
        return;
    }
    
    if (ptr->next != NULL) {
    ptr->next->prev = temp;
    }
    
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    printf("Inserted %d at position %d\n", no, pos);
}

void del_end(struct node **head){
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    struct node *prev = NULL, *temp = *head;
    if (temp->next == NULL) {
        printf("Deleted node from end: %d\n", temp->data);
        free(temp);
        *head = NULL;  
        return;
    }
    
    while(temp->next!=NULL){
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    printf("Deleted node from end: %d\n", temp->data);
    free(temp);
}

void del_beg(struct node **head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    printf("Deleted node from beginning: %d\n", temp->data);
    free(temp);
}

void del_pos(struct node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    if (pos == 1) {
        del_beg(head);
        return;
    }
    struct node *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    printf("Deleted node from position %d: %d\n", pos, temp->data);
    free(temp);
}

void reverse(struct node **head) {
    struct node *temp = NULL, *current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;  
    }
    printf("List is reversed.\n");
}

void free_list(struct node **head) {
    struct node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
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
        printf("9 - reverse the list \n");
        printf("10 - quit \n");
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
        }else if (ch == 9){
            reverse(&head);
        }
        else if (ch == 10){
            free_list(&head);
            break;
        }
        else
            printf("wrong key pressed !!!\n");
    }
    return 0;
    
}
