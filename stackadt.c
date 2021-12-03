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
   printf("Enter the value of size of stack :\n");
   scanf("%d",&stack.size);
   createstack(&stack);

}
void createstack(struct Mystack* stack){
    stack->top=-1;
    stack->sptr=(int *)calloc(stack->size,sizeof(struct Mystack));
}
int isfull(struct Mystack * stack){
    if(stack->top==stack->size-1){
        return 1;
    }
    else return 0;
}