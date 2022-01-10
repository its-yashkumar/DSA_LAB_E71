#include<iostream>
using namespace std;
struct Dequeue
{ 
   //max size is 30
   int capacity;
   int front;
   int rear;
   char * dptr;
};
void createdequeue(struct Dequeue *);
int main(){
    struct Dequeue deq;
    int com;
    createdequeue(&deq);
}
void createdequeue(struct Dequeue * deq){
     deq->capacity=30;
     deq->front=15;
     deq->rear=15;
     deq->dptr=(char *)calloc(deq->capacity,sizeof(char));
}
