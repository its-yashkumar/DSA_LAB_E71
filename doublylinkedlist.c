#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next,*prev;
};
struct Node * head,*tail;
void create(int data);
void displayhead();
void displaytail();
void insertatbegin();

int main(){
  int com;
  while(1){
  printf("Enter commands to perform following operations :\n");
  printf("1)To create doubly linked list\n2)To traverse from head\n3)To traverse from tail\n");
  printf("4)To insert at begin of list\n-1)To exit\n");
  scanf("%d",&com);
  if(com==1){
      int data;
      printf("Enter the data\n");
      scanf("%d",&data);
      create(data);
  }
  else if (com==2)
  {
      printf("Traversing from head\n");
      displayhead();
  }
  else if (com==3)
  {
      printf("Traversing from tail\n");
      displaytail();
  }
  else if (com==4)
  {
      insertatbegin();
  }
  else if (com==-1)
  {
      return 0;
  }
  else
  {
      printf("Enter valid command\n");
  }
  }
}
void create(int data){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    head=ptr;
    tail=ptr;
}
void displayhead(){
    struct Node* ptr;
    ptr=head;
    if(head==NULL){
        printf("List is empty");
    }
    else{
    while(ptr != NULL){
       printf("%d\n",ptr->data);
       ptr=ptr->next;
       }
    }
}
void displaytail(){
    struct Node* ptr;
    ptr=tail;
    if(tail==NULL){
        printf("List is empty");
    }
    else{
    while(ptr != NULL){
       printf("%d\n",ptr->data);
       ptr=ptr->prev;
       }
    }
}
void insertatbegin(){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    int data;
    printf("Enter data you want to insert at begin\n");
    scanf("%d",&data);

    ptr->data = data;
    ptr->next = head;
    ptr->prev=NULL;
    head->prev=ptr;
    head=ptr;
}