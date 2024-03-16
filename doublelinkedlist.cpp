#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} list;

list *createlist(){
    list *temp = NULL, *head = NULL;
    int choice = 1, count = 0;
    while(choice==1){
        list *newnode = (list *)malloc(sizeof(list));
        if(newnode==NULL){
            printf("\nMemory overflow\n");
        }
        else{
            printf("\nEnter data: ");
            scanf("%d", &newnode->data);
            newnode->prev = NULL;
            newnode->next = NULL;
        }
        if(head==NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("\nWant to add more? Enter 1 for yes and 0 for no : ");
        scanf("%d",&choice);
    }
    if(head==NULL){
        printf("\nList is empty\n");
    }
    return head;
}

void printlist(list *head){
    list *temp=head;
    while(temp!=NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    list *head = createlist();
    printlist(head);
    return 0;
}