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
void insertatend();
void insertatindex();
void deleteatbegin();
void deleteatend();
void deleteatindex();

int main(){
  int com;
  while(1){
  printf("Enter commands to perform following operations :\n");
  printf("1)To create doubly linked list\n2)To traverse from head\n3)To traverse from tail\n");
  printf("4)To insert at begin of list\n5)To insert at end\n6)To insert at index\n");
  printf("7)To delete at begin\n8)To delete at end\n-1)To exit\n");
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
  else if (com==5)
  {
      insertatend();
  }
  else if (com==6)
  {
      insertatindex();
  }
  else if (com==7)
  {
      deleteatbegin();
  }
   else if (com==8)
  {
      deleteatend();
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
        printf("List is empty\n");
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
        printf("List is empty\n");
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
void insertatend(){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    int data;
    printf("Enter data you want to insert at end\n");
    scanf("%d",&data);
    
    ptr->data=data;
    ptr->prev=tail;
    ptr->next=NULL;
    tail->next=ptr;
    tail=ptr;
}
void insertatindex(){
    int data,position,i=1;
    struct Node* temp,*ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->next = NULL;
    printf("Enter position at which you want to insert data\n");
    scanf("%d",&position);
    if(head==NULL){
       
        printf("Enter data you want to insert at %d index\n",position);
        scanf("%d",&data);
        create(data);
    }
    else if (position==1)
    {
        insertatbegin();
    }
    else{
       {  
       temp=head;   
       for(i=0;i<position;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", position);  
               return;  
           }  
       }  
       printf("Enter value\n");  
       scanf("%d",&data);  
       ptr->data = data;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("Node inserted\n");  
   }  
}  
}
void deleteatbegin(){
    struct Node *ptr;  
    if(head == NULL)  
    {  
        printf("List is Empty\n");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("Node deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("Node deleted\n");  
    }  
}
void deleteatend(){
    struct Node *ptr;  
    if(head == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("Node deleted\n");  
    }  
    else   
    {  
        ptr = tail;   
        ptr -> prev -> next = NULL;   
        tail=ptr->prev;
        free(ptr);  
        printf("Node deleted\n");  
    }  
}

