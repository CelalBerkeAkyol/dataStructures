#include <stdlib.h>
#include <stdio.h>
struct node{
    int data; 
    struct node* rigt;
    struct node* left; 
};
struct node * createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data =data;
    newNode->rigt = NULL;
    newNode->left = NULL;
    return newNode; 
}
void inorderTraversal(struct node *root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d->",root->data);
    inorderTraversal(root->rigt);
       
}
void preorderTraversal(struct node *root){
    if(root == NULL) return; 
    printf("%d->",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->rigt);
}
void postorderTraversal(struct node *root){
    if(root == NULL) return; 
    postorderTraversal(root->left);
    postorderTraversal(root->rigt);
    printf("%d->",root->data);
}
struct node *insertLeft(struct node *root, int data){
    root->left = createNode(data);
    return root->left; 
}
struct node *insertRight(struct node *root,int data){
    root->rigt = createNode(data);
    return root->rigt; 
}
int main(){
    struct node *root = createNode(8);
    insertLeft(root,3);
    insertLeft(root->left,1);
    insertRight(root->left,2);
    insertRight(root,20);
    postorderTraversal(root);

}
