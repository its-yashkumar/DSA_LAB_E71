#include<stdio.h>
#include<stdlib.h>
struct Arrayadt{
  int capacity;
  int size;
  int * aptr;
};
void createarray(struct Arrayadt *);
int main(){
  struct Arrayadt arr;
  printf("Enter the capacity of the array \n");
  scanf("%d",&arr.capacity);
  printf("Enter the size of the array \n");
  scanf("%d",&arr.size);
  createarray(&arr);

}
void createarray (struct Arrayadt * arr){
   arr->aptr=(int *)calloc(arr->capacity,sizeof(int));
}
