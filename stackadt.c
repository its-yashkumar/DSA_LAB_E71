#include<stdio.h>
#include<stdlib.h>
struct Mystack{
 int top;
 int size;
 int* sptr;
};
void createstack(struct Mystack *);
int isfull(struct Mystack *);
void push(struct Mystack*,int);
int main(){
   struct Mystack stack;
   int com,data;
   printf("Enter the value of size of stack :\n");
   scanf("%d",&stack.size);
   createstack(&stack);
   while(1){
   printf("Enter the command to perform operations\nEnter 1 to push a element\n");
   scanf("%d",&com);
   switch (com)
   {
   case 1:
     printf("Enter element you want to push :\n");
     scanf("%d",&data);
     push(&stack,data);
     break;
   
   default:
       break;
   }
   printf("Enter -1 to exit else enter another command\n");
   if(com==-1){
       break;
   }
   }
}
void createstack(struct Mystack* stack){
    stack->top=-1;
    stack->sptr=(int *)malloc(stack->size*sizeof(struct Mystack));
}
int isfull(struct Mystack * stack){
    if(stack->top==stack->size-1){
        return 1;
    }
    else return 0;
}
void push(struct Mystack* stack,int data){
   int flag;
   flag=isfull(stack);
   if(flag==1){
       printf("The stack is full cannot push more elements");
   }
   else{
       stack->top++;
       (stack->sptr)[stack->top]=data;
       //printf()
   }
}
