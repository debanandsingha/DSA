#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

void main(){

    int arr[]={55,6,1,2,77,100};
    int size=sizeof(arr)/sizeof(int);
    int element=6;
    int search=linearSearch(arr,size,element);

    if(search==-1){
        printf("Element not found!");
    }else{
        printf("Element %d found at position %d",element,search);
    }
}