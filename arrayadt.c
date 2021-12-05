#include<stdio.h>
#include<stdlib.h>
struct Arrayadt{
  int capacity;
  int size;
  int * aptr;
};
void createarray(struct Arrayadt *);
void getarray(struct Arrayadt *);
void printarray(struct Arrayadt *);
void insertindex(struct Arrayadt *,int,int);

int main(){
  struct Arrayadt arr;
  int com,index,ele;
  printf("Enter the capacity of the array \n");
  scanf("%d",&arr.capacity);
  printf("Enter the size of the array \n");
  scanf("%d",&arr.size);
  createarray(&arr);
  getarray(&arr);
  printarray(&arr);
  printf("\nEnter the commands to perform operation on array \n1. to insert an element at given index\n");
  scanf("%d",&com);
  switch (com)
  {
  case 1:
    printf("Enter element you want to insert :\n");
    scanf("%d",&ele);
    printf("Enter index at which you want to insert element :\n");
    scanf("%d",&index);


    break;
  
  default:
    break;
  }
}
void createarray (struct Arrayadt * arr){
   arr->aptr=(int *)calloc(arr->capacity,sizeof(int));
}
void getarray(struct Arrayadt * arr){
   for(int i=0;i<arr->size;i++){
     printf("Enter %d element of array : \n",i);
     scanf("%d",&(arr->aptr)[i]);
   }
}
void printarray(struct Arrayadt * arr){
   for(int i=0;i<arr->size;i++){
     printf("Enter %d element of array is : %d\n",i,(arr->aptr)[i]);
   }
}

