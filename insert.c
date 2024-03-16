void insertionsort(int arr[], int n){
    for (int i = 1; i < n;i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0&&arr[j]>key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionsort(int arr[], int n){
    int min, i, j;
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