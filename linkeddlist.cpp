#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} list;

list *createnode() {
    list *head = NULL, *temp = NULL; 
    int choice = 1;
    while (choice == 1) {
        list *newnode = (list *)malloc(sizeof(list));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return head; 
        }
        printf("Enter the data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to continue? Press 0 for No and 1 for Yes:");
        scanf("%d", &choice);
    }
    if (head == NULL) {
        printf("List is empty\n");
    }
    return head; 
}

void printlist(list *head){
    list *temp = head;
    while(temp!=NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int main(){

    list *head = createnode();
    printlist(head);

    return 0;
}