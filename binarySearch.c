#include<stdio.h>

//Function for binary search
int binarySearch(int arr[], int size, int element){
    int low,mid,high;
    low=0;
    high=size-1;

    while(low<=high){

        mid=(low+high)/2;
        
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    return -1;
}

//Function to sort an array
void sort(int *arr, int size){
    int temp;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void main(){

    int arr[]={22,5,1,55,88};   //initializing the array
    int size=sizeof(arr)/sizeof(int);   //determining the size of the array
    int element=55; //element to search

    //Calling sort function to sort the array
    sort(arr, size);

    //call binary search function
    int search=binarySearch(arr,size,element);

    if(search==-1){
        printf("Element not found!");
    }else{
        printf("Element %d found a position %d",element, search);
    }

}