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
int main(){
    struct Polynomial* p1,*p2;
    p1=createpolyequation(p1);
}
struct Polynomial * createpolyequation(struct Polynomial* p){
    p=(struct Polynomial *)malloc(sizeof(struct Polynomial));
    return p;
}