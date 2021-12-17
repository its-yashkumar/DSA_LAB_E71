#include<iostream>
using namespace std;
struct Dequeue
{ 
   //max size is 30
   int capacity;
   int front;
   int rear;
   int* dptr;
};
void createdequeue(struct Dequeue *);
int getfront(struct Dequeue *);
int getrear(struct Dequeue *);
int isoverflow(struct Dequeue *);
int isunderflow(struct Dequeue *);
void enqueue_rear(struct Dequeue *);

int main(){
   struct Dequeue deq;
   int com;
   createdequeue(&deq);
   cout<<"Enter Commands to perform following operations"<<endl;
   cout<<"1. To enqueue from front "<<endl;
   cin>>com;
   while(1){
   if(com==1){
       enqueue_rear(&deq);
       getrear(&deq);
   }
   cin>>com;
   if(com==-1){
       break;
   }
   }

}
void createdequeue(struct Dequeue * deq){
     deq->capacity=30;
     deq->front=-1;
     deq->rear=-1;
     deq->dptr=(int *)calloc(deq->capacity,sizeof(int));
}
int getfront(struct Dequeue * deq){
     cout<<"The value of rear is : "<<deq->rear<<endl;
     cout<<"The value at rear is :"<<(deq->dptr)[deq->front];
     return (deq->dptr)[deq->front];
}
int getrear(struct Dequeue * deq){
     cout<<"The value of front is : "<<deq->front<<endl;
     cout<<"The value at front is"<<(deq->dptr)[deq->rear]<<endl;
     return (deq->dptr)[deq->rear];
}
int isoverflow(struct Dequeue * deq){
    if((deq->front==0 && deq->rear==deq->capacity-1) || deq->front==deq->rear+1){
    return 1;
    }
    else return 0;
}
int isunderflow(struct Dequeue * deq){
    if((deq->front==-1) && (deq->rear==-1)){
        return 1;
    }
    else return 0;
}
void enqueue_rear(struct Dequeue * deq){
    if(isoverflow(deq)){
        cout<<"The queue is full cannot add further elements"<<endl;
    }
    else if(isunderflow(deq)){
        deq->front=deq->rear=0;
        (deq->dptr)[deq->rear]=1;
    }
    else if(deq->rear==deq->capacity-1){
        deq->rear=0;
        (deq->dptr)[deq->rear]=1;
    }
    else{
        deq->rear++;
        (deq->dptr)[deq->rear]=1;
    }
}