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
   printf("Enter the command to perform operations\nEnter 1 to push a element\n");
   scanf("%d",&com);
   switch (com)
   {
   case 1:
     printf("Enter element you want to push :\n");
     scanf("%d",&data);
     break;
   
   default:
       break;
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
  
}
