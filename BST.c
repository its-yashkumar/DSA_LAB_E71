#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node * left;
   struct Node * right;
};
struct Node* create(int data);
struct Node* insert(struct Node *root,int data);
struct Node* delete(struct Node *root,int data);
struct Node* find_minright(struct Node *root);
struct Node* search(struct Node *root, int data);
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
struct Node* delete(struct Node *root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data>root->data){
        root->right=delete(root->right,data);
    }
    else if(data<root->data){
        root->left=delete(root->left,data);
    }
    else{
      if(root->left==NULL && root->right==NULL){
          return NULL;
      }
      else if(root->left==NULL || root->right==NULL){
          struct Node * temp;
          if(root->left){
              temp=root->right;
          }
          else{
              temp=root->left;
          }
          free(root);
          return temp;
      }
      else{
          struct Node * temp=find_minright(root->right);
          root->data=temp->data;
          root->right=delete(root->right,temp->data);
      }

      }
      return root;
}
struct Node* find_minright(struct Node* root){
    if(root==NULL){
        return NULL;
    }
    else if(root->left != NULL){
        return find_minright(root->left);
    }
    return root;
}
struct Node* search(struct Node *root, int data){
    if(root==NULL || root->data==data){
        return root;
    }
    else if(data>root->data){
        return search(root->right,data);
    }
    else{
        return search(root->left,data);

    }
}


