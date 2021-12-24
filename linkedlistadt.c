#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node * next;
};
struct Node * head;

void createlinkedlist();

int main(){
    struct Node * ptr;
    createlinkedlist();
    ptr=head;
    printf("%d",head->data);
}
void createlinkedlist(){
  int data;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data you want to insert\n");
    scanf("%d",&data);
    head->data=data;
}