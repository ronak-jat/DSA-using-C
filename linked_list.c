#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node * next;
};

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty. \n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

void count(struct node *head)
{
    int ct=0;
    if (head == NULL)
    {
        printf("number of items is 0.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        ct++;
        temp=temp->next;
    }
    printf("number of items is %d \n",ct);
}

void ins_end(struct node **head ,int no)
{
    struct node *ptr,*temp= (struct node*)malloc(sizeof(struct node));
    temp->data=no;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        printf("Inserted %d at end (list was empty)\n", no);
        return ;
    }
    ptr = *head;
    while (ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    printf("Inserted %d at end\n", no);  
}

void ins_beg(struct node **head,int no)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=no;
    temp->next = NULL;
    if (*head == NULL){
        *head = temp;
        printf("Inserted %d at beginning (list was empty)\n", no); 
        return ;
    }
    temp->next = *head;
    *head=temp;
    printf("Inserted %d at beginning\n", no);
}

void ins_pos(struct node **head,int no,int pos)
{
    struct node *ptr ,*temp = (struct node*)malloc(sizeof(struct node));
    temp->data = no;
    
    if (pos < 1) {
        printf("Invalid position! Position must be >= 1\n");
        free(temp);
        return;
    }

    if (pos == 1) {
        temp->next = *head;
        *head = temp;
        printf("Inserted %d at position 1\n", no); 
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
    
    temp->next = ptr->next;
    ptr->next = temp;
    printf("Inserted %d at position %d\n", no, pos);
}

void del_end(struct node **head)
{
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
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted node from end: %d\n", temp->data);
    prev->next=NULL;
    free(temp);
}

void del_beg(struct node **head)
{
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    printf("Deleted node from beginning: %d\n", temp->data);
    free(temp);
}

void del_pos(struct node **head, int pos)
{
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
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted node from position %d: %d\n", pos, temp->data);
    free(temp);
}

void free_list(struct node **head)
{
    struct node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() 
{
    struct node *head = NULL;
    char ch;
    int no,pos;
    while (true)
    {
        printf("p - insert at end \n");
        printf("w - insert at beginning \n");
        printf("e - insert at pos \n");
        printf("r - delete at end \n");
        printf("t - delete at beginning \n");
        printf("y - delete at pos \n");
        printf("d - list display \n");
        printf("c - number of items in list \n");
        printf("q - quit \n");
        scanf(" %c",&ch);
        if (ch == 'p')
        {
            printf("enter number : ");
            scanf("%d",&no);
            ins_end(&head,no);
            printf("\n");
        }
        else if (ch == 'w')
        {
            printf("enter number : ");
            scanf("%d",&no);
            ins_beg(&head,no);
            printf("\n");
        }
        else if (ch == 'e')
        {
            printf("enter number : ");
            scanf("%d",&no);
            printf("enter position : ");
            scanf("%d",&pos);
            ins_pos(&head,no,pos);
            printf("\n");
        }
        else if(ch == 'r')
        {
            del_end(&head);
            printf("\n");
        }
        else if(ch == 't')
        {
            del_beg(&head);
            printf("\n");
        }
        else if(ch == 'y')
        {
            printf("enter position : ");
            scanf("%d",&pos);
            del_pos(&head,pos);
            printf("\n");
        }
        else if (ch == 'd')
        {
            display(head);
            printf("\n");
        }
        else if (ch == 'c')
        {
            count(head);
            printf("\n");
        }
        else if (ch == 'q'){
            free_list(&head);
            break;
        }
        else
            printf("wrong key pressed !!!\n");
    }
    return 0;   
}
