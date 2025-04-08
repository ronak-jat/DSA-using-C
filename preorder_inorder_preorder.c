#include<stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node *left;
    struct node *right;
};

struct node *init(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(struct node *root){
    if (root != NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(struct node *root){
    if (root != NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }
}

void postorder(struct node *root){
    if (root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    }
}

int main(){
    struct node *h = init(10);
    struct node *l = init(20);
    struct node *r = init(30);
    struct node *ll = init(40);
    struct node *rr = init(50);
    h->left = l;
    h->right = r;
    l->left = ll;
    r->right = rr;
    
    printf("Preorder: ");
    preorder(h);
    printf("\n");

    printf("Inorder: ");
    inorder(h);
    printf("\n");

    printf("Postorder: ");
    postorder(h);
    printf("\n");
}
