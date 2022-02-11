#include<stdio.h>
#include<stdlib.h>
struct Mystack{
 int top;
 int size;
 int* sptr;
};
void createstack(struct Mystack *);
int isfull(struct Mystack *);
int isempty(struct Mystack *);
void push(struct Mystack*,int);
int peek(struct Mystack* ,int);
int pop(struct Mystack*);

int main(){
   struct Mystack stack;
   int com,data,peekdata,index;
   printf("Enter the value of size of stack :\n");
   scanf("%d",&stack.size);
   createstack(&stack);
   while(1){
   printf("Enter the command to perform operations\nEnter 1 to push a element\nEnter 2 to peek\n3 to pop element\n");
   scanf("%d",&com);
   switch (com)
   {
   case 1:
     printf("Enter element you want to push :\n");
     scanf("%d",&data);
     push(&stack,data);
     break;
   case 2:
     printf("Enter index whose value you want to peek from top\n");
     scanf("%d",&index);
     peekdata=peek(&stack,index);
     if(peekdata!=-1)
     printf("The element at the %d down of stack is : %d\n",index,peekdata);
     break;
   case 3:
      data=pop(&stack);
      if(data!=-1)
      printf("The popped data is : %d\n",data);
      break;
   
   default:
       break;
   }
   printf("\nEnter -1 to exit else enter another command\n");
   if(com==-1){
       break;
   }
   }
}
void createstack(struct Mystack* stack){
    stack->top=-1;
    stack->sptr=(int *)malloc(stack->size*sizeof(int));
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
       printf("The element %d is pushed to top of stack\n",data);
   }
}
int peek(struct Mystack* stack,int index){
    if(index<=stack->top)
    return (stack->sptr)[((stack->top)-index)];
    else{
     printf("Invalid index");
     return -1;
    }

}
int pop(struct Mystack* stack){
    int empty=isempty(stack);;
    if(empty==1){
        printf("The stack is underflowed and hence cannot pop");
        return -1;
    }
    else{
       int val=(stack->sptr)[stack->top];
       stack->top--;
       return val;
    }
}
int isempty(struct Mystack * stack){
    if(stack->top==-1){
        return 1;
    }
    else return 0;
}