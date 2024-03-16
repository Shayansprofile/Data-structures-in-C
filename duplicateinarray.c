#include <stdio.h>

void findDuplicates(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[abs(arr[i])] >= 0) {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        } else {
            printf("Duplicate found: %d\n", abs(arr[i]));
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 3, 4, 5, 6, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}
