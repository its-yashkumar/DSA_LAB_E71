#include<stdio.h>
#include<stdlib.h>
struct Mystack{
 int top;
 int size;
 int* sptr;
};
void createstack(struct Mystack *);
int main(){
   struct Mystack stack;
   printf("Enter the value of size of stack :\n");
   scanf("%d",&stack.size);
   createstack(&stack);
}
void createstack(struct Mystack* stack){
    stack->sptr=(int *)calloc(stack->size,sizeof(struct Mystack));
}