// passing Array as POINTER in Bubble Sort function
#include<stdio.h>

void bubbleSort(int *ptr, int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(ptr[i]>ptr[j]){
                temp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
            }
        }
    }
}

void main(){

    int arr[]={5,4,3,2,1};
    int size=sizeof(arr)/sizeof(int);

    bubbleSort(arr,size);

    for(int i=0;i<size;i++)
        printf("%d ", arr[i]);

}

/*
COMPLEXITY
Outer loop: n times
Inner looper: n-1 times
f(n)= n(n-1) = (n^2 - n) => O(n^2)
*/