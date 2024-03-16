#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} list;

list *insertbeg(list **head, int data);
void insertend(list **head, int data);
void insertafternode(list **head, int data, int nodevalue);
list *insertatloc(list **head, int data, int loc);
list *deletebeg(list **head);
void deleteend(list **head);
void deleteafternode(list **head, int nodevalue);
void deleteatloc(list **head, int loc);
list *createlist();
void printlist(list *head);

int main() {
    list* head = createlist();
    int choice, data, position;
    
    
    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert after a Node\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete after a Node\n");
        printf("8. Delete at Specific Position\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertbeg(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertend(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data after which to insert: ");
                scanf("%d", &position);
                insertafternode(&head, data, position);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter location to insert: ");
                scanf("%d", &position);
                insertatloc(&head, data, position);
                break;
            case 5:
                head = deletebeg(&head);
                break;
            case 6:
                deleteend(&head);
                break;
            case 7:
                printf("Enter data after which to delete: ");
                scanf("%d", &position);
                deleteafternode(&head, position);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteatloc(&head, position);
                break;
            case 9:
                printf("List: ");
                printlist(head);
                break;
            case 10:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 10);


    
    return 0;
}
list *insertbeg(list **head, int data){
    list *newnode = (list *)malloc(sizeof(list));
    if(newnode!=NULL){
         newnode->data = data;
    newnode->next = *head;
    *head = newnode;
    return *head;

    }
   
}
void insertend(list **head, int data){
    list *newnode = (list *)malloc(sizeof(list));
    if(newnode!=NULL && *head!=NULL){
        list *temp = *head;
    newnode->data = data;
    newnode->next = NULL;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;

    }
    
}
void insertafternode(list **head, int data, int nodevalue){
    list *newnode = (list *)malloc(sizeof(list));
    list *temp = *head;
    list *prev = *head;
    if(newnode!=NULL && *head!=NULL){
        newnode->data = data;
    newnode->next = NULL;
    while(temp->data!=nodevalue){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    }
   
}
list *insertatloc(list **head, int data, int loc){
    list *newnode = (list *)malloc(sizeof(list));
    list *temp = *head;
    int i = 1;
    if(newnode!=NULL && *head!=NULL){
        newnode->data = data;
        newnode->next = NULL;
        if(loc==1){
            *head = insertbeg(&(*head), data);
            return *head;
        }
        else if(i!=0){
            while(i<loc-1 && temp!=NULL){
                temp = temp->next;
                }
                 
                newnode->next = temp->next;
                temp->next = newnode;
            

        }
         if(temp==NULL){
                    printf("The location is more than the number of nodes in the linked list\n");
                  }
        
    }
}
list *deletebeg(list **head){
    if(*head==NULL){
        printf("\nList is empty\n");
    }
    else{
        list *temp = *head;
        int deleted = temp->data;
        *head = (*head)->next;
        free(temp);
        printf("\nDeleted element: %d\n", deleted);
    }

}
void deleteend(list **head){
     if(*head==NULL){
        printf("\nList is empty\n");
    }
    else{
        list *temp = *head;
        list *prev = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        while(prev->next!=temp){
            prev = prev->next;
        }
        int deleted = temp->data;
        prev->next = NULL;
        free(temp);
        printf("\nDeleted element: %d\n", deleted);
       
    }


}
void deleteafternode(list **head, int nodevalue){
      if(*head==NULL){
        printf("\nList is empty\n");
    }
    else{
        list *temp = *head;
        list *prev = *head;
        list *curr = *head;
        int deleted;
        while(curr->data!=nodevalue){
            curr = curr->next;
        }
        
        temp = curr->next;
        deleted = temp->data;
        prev = temp->next;
        curr->next = prev;
        free(temp);
        printf("\nDeleted element: %d\n",deleted);
        }


}
void deleteatloc(list **head, int loc){
    if(*head == NULL) {
        printf("\nList is empty\n");
    }
    int i = 1;
    if(loc==1){
        deletebeg(&(*head));
    }
    else if(loc!=0){
        list *temp = *head;
        list *prev = *head;
        while(i<loc&&temp!=NULL){
            temp = temp->next;
            i++;
        }
        while(prev->next!=temp&&prev->next!=NULL){
            prev = prev->next;
        }
        if(temp==NULL){
            printf("\nLocation out of range\n");
        }
         int deleted = temp->data;
         prev->next=temp->next;
         free(temp);
         printf("\nDeleted element: %d\n", deleted);
    }
}
void printlist(list *head){
    if(head==NULL){
        printf("\nList is empty\n");
    }
    list *temp = head;
    while(temp!=NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}
list *createlist(){
     int choice = 1, count=0;
    list *head= NULL, *temp = NULL;
    while(choice==1){
        list *newnode = (list *)malloc(sizeof(list));
        if(newnode==NULL){
            printf("\nMemory overflow\n");
        }
        else{
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

        count++;
        printf("\nDo you want to add more? Enter 1 for yes and 0 for no: ");
        scanf("%d",&choice);
    }
    
        
        }
        if(head==NULL){
            printf("\nList is empty\n");
        }
        

        return head;

}