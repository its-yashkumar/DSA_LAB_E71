#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node * next;
};
struct Node * createlinkedlist(struct Node * head){
    int data;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data you want to insert\n");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    return head;
}
struct Node * insertatend(struct Node *head){
    struct Node * ptr,*p;
    p=head;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    int data;
    printf("Enter data you want to insert at end\n");
    scanf("%d",&data);
    ptr->data = data;
    while(p->next != NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
int isSorted(struct Node *head) 
{  
    if (head == NULL) 
        return 1; 
    
    for (struct Node * t=head; t->next != NULL; t=t->next) 
       if (t->data > t->next->data) 
            return 0; 
            
    return 1; 
} 
int main(){
    struct Node * head;
    head=createlinkedlist(head);
    head=insertatend(head);
    head=insertatend(head);
    head=insertatend(head);
    if(isSorted(head)){
        printf("The LL is sorted");
    }
    else printf("LL is not sorted");

    
    
}