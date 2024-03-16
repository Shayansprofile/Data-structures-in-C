#include <stdio.h>
#include <stdlib.h>


void bubblesort(int arr[], int n){
    for (int i = 0; i < n - 1;i++){
        for (int j = 0; j < n - i - 1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int n){

}
int partition(int arr[], int low, int high){
    int pivot = arr[0];
    int start = low;
    int end = high;
    while(start<end){
        if(arr[start]<=pivot){
            start++;
        }
        if(arr[end]>pivot){
            end--;
        }
        if(start<end){
            int temp=arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int loc = partition(arr, low, high);
        quicksort(arr, low, loc-1);
        quicksort(arr, loc + 1, high);
    }
}



int main(){
    int arr[100], n;
    return 0;
}