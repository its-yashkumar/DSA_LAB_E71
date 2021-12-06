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
void delete(struct Arrayadt *,int);
int insertend(struct Arrayadt *,int);
int sumelements(struct Arrayadt *);
float avgelements(struct Arrayadt *);
int linearsearch(struct Arrayadt *,int);
int binarysearch(struct Arrayadt *,int);
int main(){
  struct Arrayadt arr;
  int com,index,ele,sumele,key,searchindex;
  float avg;
  printf("Enter the capacity of the array \n");
  scanf("%d",&arr.capacity);
  printf("Enter the size of the array \n");
  scanf("%d",&arr.size);
  createarray(&arr);
  getarray(&arr);
  printarray(&arr);
  printf("\nEnter the commands to perform operation on array \n1. to insert an element at given index\n");
  printf("2. To insert at end of array :\n3. To sum all elements of array\n4. To find average of all elements in an array\n");
  printf("5. For linear search \n6. For Binary Search\n7 Delete an element from array\n");
  scanf("%d",&com);
  switch (com)
  {
  case 1:
    printf("Enter element you want to insert :\n");
    scanf("%d",&ele);
    printf("Enter index at which you want to insert element :\n");
    scanf("%d",&index);
    insertindex(&arr,index,ele);
    printarray(&arr);
    break;
  case 2:
    printf("Enter element you want to insert :\n");
    scanf("%d",&ele);
    insertend(&arr,ele);
    printarray(&arr);
    break;
  case 3:
    sumele=sumelements(&arr);
    printf("The sum of all elements of array is : %d\n",sumele);
    break;
  case 4:
     avg=avgelements(&arr);
     printf("The average of all elements of array is : %.2f\n",avg);
     break;
  case 5:
     printf("Enter element you want to search\n");
     scanf("%d",&key);
     searchindex=linearsearch(&arr,key);
     if(searchindex==-1){
       printf("Element not present in array");
     }
     else if(searchindex>=0){
       printf("Element %d present at %d index of array",key,searchindex);
     }
     break;
  case 6:
     printf("Enter element you want to search\n");
     scanf("%d",&key);
     searchindex=binarysearch(&arr,key);
     if(searchindex==-1){
       printf("Element not present in array");
     }
     else if(searchindex>=0){
       printf("Element %d present at %d index of array",key,searchindex);
     }
     break;
  case 7:
      printf("Enter index at which you want to delete element :\n");
      scanf("%d",&index);
      delete(&arr,index);
      printarray(&arr);


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
     printf("The %d element of array is : %d\n",i,(arr->aptr)[i]);
   }
}
void insertindex(struct Arrayadt * arr,int index,int ele){
  if(arr->size==arr->capacity){
    printf("Array is full cannot enter more elemnts\n");
  }
  else{
    for(int i=arr->size;i>=index;i--){
      (arr->aptr)[i+1]= (arr->aptr)[i];
    }
    (arr->aptr)[index]=ele;
    arr->size++;
  }
}
int insertend(struct Arrayadt * arr,int ele){
    (arr->aptr)[arr->size]=ele;
    arr->size++;
}
int sumelements(struct Arrayadt * arr){

   int sumele=0;
   for(int i=0;i<arr->size;i++){
    sumele+= (arr->aptr)[i];
   }
   return sumele;
}
float avgelements(struct Arrayadt * arr){
   float sumele=0;
   for(int i=0;i<arr->size;i++){
    sumele+= (arr->aptr)[i];
   }
   return ((sumele)/(arr->size));
}
int linearsearch(struct Arrayadt * arr,int key){
  int flag;
    for(int i=0;i<arr->size;i++){
           if(arr->aptr[i]==key){
               return i;
           }
           else continue;
       }
  return -1;
}
int binarysearch(struct Arrayadt * arr,int key){

  int l=0;
  int r=arr->size;
  while (l <= r) {
     int m = l + (r - l) / 2;
     if (arr->aptr[m] == key)
       return m;
     if (arr->aptr[m] < key)
        l = m + 1;
     else
    r = m - 1;
  }
return -1;
}
void delete(struct Arrayadt * arr,int index){
    for(int i=index;i<(arr->size)-1;i++){
      (arr->aptr)[i]=(arr->aptr)[i+1];
    }
    arr->size--;
}