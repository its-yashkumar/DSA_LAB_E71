#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node * next;
};


struct Node * createlinkedlist(struct Node *);
void display(struct Node *);
struct Node * insertatbegin(struct Node *);
struct Node * insertatend(struct Node *);
struct Node * insertatindex(struct Node *,int index);
struct Node * insertatdata(struct Node *head,int data);
struct Node * deleteatend(struct Node *);
struct Node * deleteatbegin(struct Node * head);
struct Node * reverse(struct Node * head);
int main(){
    struct Node * head;
    int index,com;
   while(com!=-1){
    printf("Enter Commands :\n1)To create head\n2)To insert at being\n3)To insert at end\n4)To insert at index\n");
    printf("5)To delete at end\n6) To delete at start\n-1 to exit\n");
    scanf("%d",&com);
     
    if(com==1){
    head=createlinkedlist(head);
    printf("Displaying head data :\n");
    display(head);
    }
    else if(com==2){
    head=insertatbegin(head);
    printf("After insert at begin\n");
    display(head);
    }
   else if(com==3){
    head=insertatend(head);
    printf("After insert at end\n");
    display(head);
   }
   else if(com==4){
    printf("Enter the index you want to insert : \n");
    scanf("%d",&index);
    head=insertatindex(head,index);
    printf("After inserting at %d index\n",index);
    display(head);
   }
   else if(com==5){
    head=deleteatend(head);
    printf("After deleting at end\n");
    display(head);
   }
   else if(com==6){
    head=deleteatbegin(head);
    printf("After deleting at begin\n");
    display(head);
   }
   else if(com==-1) break;
   else{
       printf("Enter valid command\n");
   }
  
    
}

}
struct Node * createlinkedlist(struct Node * head){
    int data;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data you want to insert\n");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    return head;
}
void display(struct Node * head){
    struct Node* ptr;
    ptr=head;
    while(ptr != NULL){
       printf("%d\n",ptr->data);
       ptr=ptr->next;
    }
}
struct Node * insertatbegin(struct Node *head){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    int data;
    printf("Enter data you want to insert at begin\n");
    scanf("%d",&data);

    ptr->data = data;

    ptr->next = head;
    return ptr;
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
struct Node * insertatindex(struct Node *head,int index){
    struct Node * ptr,*p;
    int i=0;
    p=head;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    int data;
    printf("Enter data you want to insert at end\n");
    scanf("%d",&data);
    ptr->data = data;
    while(i != index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node * deleteatend(struct Node *head){
     struct Node * p,*q;
     p=head;
     q=head->next;
     while(q->next != NULL){
         p=p->next;
         q=q->next;
     }
     p->next=NULL;
     free(q);
     return head;
}
struct Node * deleteatbegin(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node * deleteatindex(struct Node * head){
    int index;
    struct Node * p,*q;
    p=head;
    q=head->next;
    printf("Enter the index of node you want to delete :\n");
    scanf("%d",&index);
    int i=0;
    while(i != index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;

}
struct Node * deleteatvalue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}
struct Node * reverse(struct Node * head){

}