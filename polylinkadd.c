//Add two polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
struct Polynomial
{
    int coeff;
    int expo;
    struct Polynomial* next;
};

struct Polynomial * createpolyequation(struct Polynomial* p,int);
struct Polynomial * addterms(struct Polynomial* p,int,int);

int main(){
    struct Polynomial* p1,*p2;
    int count1=0,count2=0,expo;
    int coeff,com;
    while(1){
        printf("Enter 1.For polynomial one\n2.For polynomial two\n");
        printf("Enter terms of polynomial p1 \n");
        scanf("%d",&com);
        if(com==1){
        if(count1==0){
          printf("Enter constant term\n");
          scanf("%d",&coeff);
             p1=createpolyequation(p1,coeff);
             count1++;
            }
       else if(count1>0){
        printf("Enter %d degree coefficient \n",count1);
        scanf("%d",&coeff);
        p1=addterms(p1,coeff,count1);
        count1++;
      }
    }
    else if(com==2){
        if(count2==0){
          printf("Enter constant term\n");
          scanf("%d",&coeff);
             p2=createpolyequation(p2,coeff);
             count2++;
        }
        else if(count1>0){
        printf("Enter %d degree coefficient \n",count2);
        scanf("%d",&coeff);
        p2=addterms(p1,coeff,count2);
        count2++;
    }
      printf("Enter -1 to exit or press any key to continue");
      scanf("%d",&com);
      if(com==-1)break;
   
    }
}
struct Polynomial * createpolyequation(struct Polynomial* p,int coeff){
    p=(struct Polynomial *)malloc(sizeof(struct Polynomial));
    p->coeff=coeff;
    p->expo=0;
    p->next=NULL;
    return p;
}
struct Polynomial * addterms(struct Polynomial* p,int coeff,int count1){
    struct Polynomial* pterm;
    pterm=(struct Polynomial *)malloc(sizeof(struct Polynomial));
    pterm->coeff=coeff;
    pterm->expo=count1;
    pterm->next=p;
    return pterm;


}
