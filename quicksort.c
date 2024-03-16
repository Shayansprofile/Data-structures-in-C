#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int start = low, end = high;
while(start<end){
    while(arr[start]<=pivot){
        start++;
        }
    while(arr[end]>pivot){
        end--;
    }
    if(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}
int temp = arr[low];
arr[low] = arr[end];
arr[end] = temp;
return end;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int loc = partition(arr, low, high);
        quicksort(arr, low, loc - 1); // Sort elements before the pivot (excluding the pivot)
        quicksort(arr, loc + 1, high); // Sort elements after the pivot (excluding the pivot)
    }
}


void createarray(int arr[],int n){
    printf("Enter the array elements\n ");
    for (int i = 0; i < n;i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);

    }
}
void printarray(int arr[], int n){
    printf("\nThe entered array is:\n");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
        printf("\n");
    }
}

int main(){
    int arr[100], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    createarray(arr, n);
    printf("\nBefore sorting\n");
    printarray(arr, n);
    printf("\nAfter sorting\n");
   quicksort(arr,0, n);
    printarray(arr, n);

    return 0;
}



int partition(int arr[], int low, int high){
    int start = low, end = high;
    int pivot = arr[low];

    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;
    return end;
}


int partition(int arr[], int low, int high){
    int start = low, end = high;
    int pivot = arr[low];
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        
    }
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;
}

void insertionsort(int arr[], int n){
    for (int i = 1; i <= n;i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0&&arr[j]>key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionsort(int arr[], int n){
    int i, j, min;
    for (i = 0; i < n;i++){
        min = i;
        for (j = i + 1; j < n;j++){
            if(arr[j]<min){
                min = j;
            }
        }
        if(min!=i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int partition(int arr[], int low, int high){
    int start = low, end = high;
    int pivot = arr[low];
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;
    return end;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int loc = partition(arr, low, high);
        quicksort(arr, low, loc - 1);
        quicksort(arr, loc + 1, high);
    }
}