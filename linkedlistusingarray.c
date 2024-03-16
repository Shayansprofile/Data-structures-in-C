#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a node in the linked list
struct Node {
    int data;
    int next; // Index of the next node in the array
};

// Global variables
struct Node arr[MAX_SIZE];
int head = -1; // Index of the first node in the list
int free_list_head = 0; // Index of the first free node in the array
int size = 0; // Size of the linked list

// Function to initialize the linked list
void initialize() {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        arr[i].next = i + 1;
    }
    arr[MAX_SIZE - 1].next = -1; // -1 indicates end of free list
}

// Function to get a free node from the free list
int getFreeNode() {
    if (free_list_head == -1) {
        printf("Error: Memory full\n");
        exit(1);
    }
    int free_node = free_list_head;
    free_list_head = arr[free_node].next;
    return free_node;
}

// Function to return a node to the free list
void returnFreeNode(int index) {
    arr[index].next = free_list_head;
    free_list_head = index;
}

// Function to insert a node after a given node
void insertAfter(int index, int data) {
    int new_node = getFreeNode();
    arr[new_node].data = data;
    arr[new_node].next = arr[index].next;
    arr[index].next = new_node;
    size++;
}

// Function to insert a node at a specific location
void insertAt(int position, int data) {
    if (position < 0 || position > size) {
        printf("Error: Invalid position\n");
        return;
    }
    if (position == 0) { // Insertion at the beginning
        insertAfter(head, data);
        head = size - 1;
    } else {
        int temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = arr[temp].next;
        }
        insertAfter(temp, data);
    }
}

// Function to delete a node after a given node
void deleteAfter(int index) {
    if (arr[index].next == -1) {
        printf("Error: No node to delete after the given node\n");
        return;
    }
    int temp = arr[index].next;
    arr[index].next = arr[temp].next;
    returnFreeNode(temp);
    size--;
}

// Function to delete a node at a specific location
void deleteAt(int position) {
    if (position < 0 || position >= size) {
        printf("Error: Invalid position\n");
        return;
    }
    if (position == 0) { // Deletion at the beginning
        deleteAfter(head);
        head = 0;
    } else {
        int temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = arr[temp].next;
        }
        deleteAfter(temp);
    }
}

// Function to display the linked list
void display() {
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", arr[temp].data);
        temp = arr[temp].next;
    }
    printf("NULL\n");
}

int main() {
    initialize();
    
    insertAt(0, 10);
    insertAt(1, 20);
    insertAt(2, 30);
    insertAt(3, 40);
    insertAt(4, 50);
    insertAt(5, 60);
    
    printf("Initial linked list: ");
    display();

    deleteAt(3);
    printf("After deleting at position 3: ");
    display();

    insertAfter(2, 35);
    printf("After inserting 35 after node with value 30: ");
    display();

    deleteAfter(0);
    printf("After deleting after the first node: ");
    display();

    return 0;
}
