#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next,*prev;
};
struct Node * head,*tail;
void create(int data){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    head=ptr;
    tail=ptr;
}

int main(){
  
}