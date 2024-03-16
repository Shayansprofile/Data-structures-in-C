#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} list;

list *beginsert(list **head, int data){
    list *temp = *head;
    list *newnode = (list *)malloc(sizeof(list));
    if(newnode==NULL){
        printf("\nMemory overflow\n");
    }
    else{
        if(temp!=NULL){
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->next = temp;
        temp->prev = newnode;
        *head = newnode;
        }
    }
    return *head;
}

void endinsert(list **head, int data){
    list *temp = *head;
    if(*head!=NULL){
        list *newnode = (list *)malloc(sizeof(list));
        if(newnode==NULL){
            printf("\nMemory overflow\n");
        }
        else{
            newnode->data = data;
            newnode->prev = NULL;
            newnode->next = NULL;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            newnode->prev = temp;
            temp->next = newnode;
            
        }
    }
    
}

void insertafternode(list **head, int data, int nodevalue){
    list *temp = *head;
    if(head!=NULL){
        list *newnode = (list*)malloc(sizeof(list));
        if(newnode==NULL){
            printf("\nMemory overflow\n");

        }
        else{
            newnode->data=data;
            newnode->prev = NULL;
            newnode->next = NULL;
            while(temp->data!=nodevalue){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }

    }
}

void insertatloc(list **head, int data, int loc){
    list *temp = *head;
    int i = 1;
    list *previous = *head;
    if(*head!=NULL){
        list *newnode = (list*)malloc(sizeof(list));
        if(newnode==NULL){
            printf("\nMemory overflow\n");
        }
        else{
            newnode->data = data;
            newnode->prev = NULL;
            newnode->next = NULL;
            while(i<loc){
                temp = temp->next;
                i++;
            }
            while(previous->next!=temp){
                previous = previous->next;
            }
            newnode->next = temp;
            previous->next = newnode;
            temp->prev = newnode;
            newnode->prev = previous;
        }

    }
}
list *createlist()
{
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
    int data;
    list *head = createlist();
    printlist(head);
    printf("Enter the data you want to insert: ");
    scanf("%d", &data);
    // head = beginsert(&head, data);
    // printlist(head);
    // endinsert(&head, data);
    int nodevalue;
    printf("Enter the location after which you want to insert: ");
    scanf("%d", &nodevalue);
    insertatloc(&head, data, nodevalue);
    printlist(head);
    return 0;
}