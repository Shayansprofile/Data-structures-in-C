void insertionsort(int arr[], int n){
    for (int i = 1; i <= n;i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

























void insertionsort(int arr[],int n){
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
#define MAXQ 100
typedef struct queue{
    int front, rear;
    int arr[MAXQ];
} queue;

queue *initialize(queue *q){
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q){
    if(q->f==-1){
        return 1;
    }
}
int isfull(queue *q){
    if(q->front = (q->rear+1)%MAXQ){
        return 1;
    }
}

void enqueue(queue *q){
    if(isfull){
        exit(0);
    }
    if(q->front == -1){
        q->front = 0;
        q->rear = 0;
    }
    else{
        q->rear = (q->rear + 1) % MAXQ;
        q->arr[q->rear] = data;
    }
}
int dequeue(queue *q){
    if(isempty){
        exit(0);
    }
    int deleted = q->arr[q->front];
    if(q->front==q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = q->front + 1 % MAXQ;

    }
}

void bubblesort(int arr[], int n){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n - i - 1;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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


void selectionsort(int arr[], int n){
    int i, j, min;
    for (i = 0; i < n;i++){
        min = i;
        for (j = i + 1; i < n;j++){
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