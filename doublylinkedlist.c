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
   create(34);
   insertatbegin();
   printf("Traversing from head\n");
   displayhead();
   printf("Traversing from tail\n");
   displaytail();
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