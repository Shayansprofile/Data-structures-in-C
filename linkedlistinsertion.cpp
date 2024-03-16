#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} list;

void beginsert(list **head, int data){
    list *newnode = (list *)malloc(sizeof(list));

    newnode->data=data;
    newnode->next = *head;
    *head = newnode;
}

void endinsert(list **head, int data){
    list *newnode = (list *)malloc(sizeof(list));
    if(newnode==NULL){
        printf("Memory overflow");
    }
    else{
        list *temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        newnode->data = data;
        temp->next = newnode;
        newnode->next = NULL;
    }
}
void insertatloc(list **head, int data, int loc){
    list *temp = *head;
    int i = 1;
    while(i<loc){
        temp = temp->next;
        i++;
    }
    list *newnode = (list*)malloc(sizeof(list));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertafternode(list **head, int data, int nodevalue){
    list *temp = *head;
    
    while(temp->data!=nodevalue){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Element not found");

    }
    else{
        list *newnode = (list *)malloc(sizeof(list));
        newnode->data=data;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
list *createlist(){
    int choice = 1, count=0;
    list *head= NULL, *temp = NULL;
    while(choice == 1){
        list *newnode = (list *)malloc(sizeof(list));
        if(newnode == NULL){
            printf("Memory overflow");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode -> next = NULL;

        if(head==NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("To continue press 1 and to exit press 0: ");
        scanf("%d",&choice);
        count++;

    }
    if(head==NULL){
        printf("List is empty");
    }
    return head;
}

void printlist(list *head){
    list *temp = head;
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else{
        while(temp!=NULL){
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    list *head = createlist();
    printlist(head);
    int data,nodevalue;
    printf("\nEnter data to insert: ");
    scanf("%d", &data);
    printlist(head);
    printf("Enter the number after which node is to be inserted: ");
    scanf("%d", &nodevalue);
    insertafternode(&head, data, nodevalue);
    printlist(head);
    return 0;
}