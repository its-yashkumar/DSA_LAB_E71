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

int main(){
   struct Dequeue deq;
   createdequeue(&deq);

}
void createdequeue(struct Dequeue * deq){
     deq->capacity=30;
     deq->front=-1;
     deq->rear=-1;
     deq->dptr=(int *)calloc(deq->capacity,sizeof(int));
}
int getfront(struct Dequeue * deq){
     return (deq->dptr)[deq->front];
}
int getrear(struct Dequeue * deq){
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