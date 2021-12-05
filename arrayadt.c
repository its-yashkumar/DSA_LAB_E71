#include<stdio.h>
#include<stdlib.h>
struct Arrayadt{
  int capacity;
  int size;
  int * aptr;
};
void createarray(struct Myarray*);
int main(){
  struct Arrayadt arr;
  printf("Enter the capacity of the array");
  scanf("%d",arr.capacity);
  printf("Enter the size of the array");
  scanf("%d",arr.size);
  

}
