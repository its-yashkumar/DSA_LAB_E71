#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node * left;
   struct Node * right;
};
struct Node* create(int data);
struct Node* insert(int data);
int main(){
    
}
struct Node* create(int data){
   struct Node * tree;
   tree=(struct Node *)malloc(sizeof(struct Node));
   tree->data=data;
   tree->left=NULL;
   tree->right=NULL;
   return tree;
}
struct Node* insert(struct Node *root,int data){
   if(root==NULL){
       return create(data);
   }
   else if(data>root->data){
       root->right=insert(root->right,data);
   }
   else{
       root->left=insert(root->left,data);
   }
   return root;
}
