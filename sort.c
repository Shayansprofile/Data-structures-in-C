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
            if(arr[j]<arr[min]){
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

void bubblesort(int arr[], int n){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n - i - 1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

void quicksort(int arr[], int low, int high )
{
    if(low<high){
        int loc = partition(arr, low, high);
        quicksort(arr, low, loc-1);
        quicksort(arr, loc +1, high);
    }
}

void merge(int arr[], int low, int mid, int high){
    int newarr[100];
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            newarr[k] = arr[i];
            i++;
        }
        else{
            newarr[k] = arr[j];
            j++;
        }
        k++;

    }
    if(i>mid){
        while(j<=high){
            newarr[k] = arr[j];
            j++;
            k++;
        }

    }
    else{
        while(i<=mid){
            newarr[k] = arr[i];
            i++;
            k++;
        }
    }
    for (int i = low; i <= high;i++){
        newarr[i] = arr[i];
    }
}
void mergesort(int arr[], int low, int high){
    if(low<high){
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


void merge(int arr[], int low, int mid, int high){
    int newarr[100];
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while(i<=mid && j<=high){
        if(arr[i]<= arr[j]){
            newarr[k] = arr[i];
            i++;
        }
        else{
            newarr[k] = arr[j];
        }
        k++;

    }
    if(i>mid){
        while(j<=high){
            newarr[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            newarr[k] = arr[i];
            i++;
            k++;
        }

    }
    for (int i = low; i <= high;i++){
        newarr[i] = arr[i];
    }
}
#define MAXQ 1000
typedef struct circularqueue{
    int front, rear;
    int arr[MAXQ];

} queue;

queue *create(queue *q){
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q){
    if(q->front == -1){
        return 1;
    }
}
int isfull(queue *q){
    if(q->front = (q->rear+1)%MAXQ){
        return 1;
    }
}

int enqueue(queue *q){
    int data;
    if(isfull(q)){
        return -1;
    }
    if(q->front == -1){
        q->front = 0;
        q->rear = 0;
    }
    else{
        q->rear = (q->rear + 1) % MAXQ;
        q->arr[q->rear] =  data;
    }
    
}

int dequeue(queue *q){
    int deleted;
    if(isempty(q)){
        return -1;
    }
    deleted = q->arr[q->front];
    if(q->front==q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = q->front + 1 % MAXQ;
    }
    return deleted;
}


