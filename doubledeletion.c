#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} list;

list *begdelete(list **head){
    if(*head == NULL){
        printf("\nNo nodes present\n");
    } else {
        list *temp = *head;
        int deleted = temp->data;
        *head = temp->next;

        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("\nDeleted element: %d\n", deleted);
    }
     return *head;
    
}
void endelete(list **head){
    int deleted;
    list *deltemp = *head;
    list *temp = *head;
    if(*head == NULL){
        printf("The list is empty.\n");
    }
    else{
        while (deltemp->next != NULL)
        {
            deltemp = deltemp->next;
        }
        deleted = deltemp->data;
        while(temp->next!=deltemp){
            temp=temp->next;
        }
        temp->next = NULL;
        free(deltemp);
        printf("\nDeleted element: %d\n", deleted);
}
}

int deleteafternode(list **head, int nodevalue){
    int deleted;
    list *temp = *head;
    list *current = *head;
    if(*head==NULL){
        printf("\nList is empty\n");
    }
    else{
        while(temp->data!=nodevalue){
            temp = temp->next;
            if(temp==NULL){
                printf("Element not found");
                return -1;
            }      
        }
         while(current!=temp->next){
           current = current->next;
        }
        deleted = current->data;
        temp->next = current->next;
           if (current->next != NULL) { 
    }
        free(current);
        printf("\nDeleted element: %d\n", deleted);
            }
}

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
    head = begdelete(&head);
    printlist(head);
    endelete(&head);
    printlist(head);
    int nodevalue;
    printf("\nEnter the node after which is to be deleted: ");
    scanf("%d", &nodevalue);
    deleteafternode(&head, nodevalue);
    printlist(head);
    return 0;
}