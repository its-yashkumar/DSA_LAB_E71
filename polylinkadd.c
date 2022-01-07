//Add two polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
struct Polynomial
{
    float coeff;
    float expo;
    struct Polynomial* next;
};

struct Polynomial * createpolyequation(struct Polynomial* p);
struct Polynomial * addterms(struct Polynomial* p);

int main(){
    struct Polynomial* p1,*p2;
    p1=createpolyequation(p1);
    p2=createpolyequation(p2);
    printf("Enter terms of polynomials p1");
    p1=addterms(p1);

}
struct Polynomial * createpolyequation(struct Polynomial* p){
    p=(struct Polynomial *)malloc(sizeof(struct Polynomial));
    p->coeff=0
    p->expo=0;
    p->next=NULL;

    return p;
}
struct Polynomial * addterms(struct Polynomial* p){

}
