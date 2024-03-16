#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} list;

list *begdelete(list **head){
    int deleted;
    list *temp = *head;
    if(head == NULL){
        printf("\n No node is present\n");
    }
    else{
        deleted = temp->data;
        *head = temp->next;
        free(temp);
        printf("\nDeleted element: %d\n", deleted);
    }
    return *head;
}

void endelete(list **head){
    int deleted;
    list *temp = *head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    deleted = temp->next->data;
    free(temp->next);
    temp->next=NULL;
    printf("\n Deleted element at the end : %d \n",deleted);
}
void deleteafternode(list **head, int nodevalue){
    int deleted;
    list *temp = *head;
    list *temp2 = NULL;
    while(temp->data!=nodevalue){
        temp = temp->next;
    }
    deleted = temp->next->data;
    temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    printf("The deleted number is %d \n", deleted);
}
list *createlist(){
    int choice = 1,count = 0;
    list *temp = NULL,  *head = NULL;
    while(choice==1){
        list *newnode = (list *)malloc(sizeof(list));
        if(newnode==NULL){
            printf("\nMemory overflow\n");
        }
        else{
            printf("Enter data: ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
        }
        if(head==NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("Press 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
        count++;
        }

        printf("\nThere are %d nodes in the linked list\n", count);
        if(head==NULL){
            printf("\nList is empty\n");
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
    int nodevalue;
    list *head = createlist();
    printlist(head);
    head = begdelete(&head);
    printlist(head);
    endelete(&head);
    printlist(head);
    printf("\nEnter the value after which node is to be deleted: ");
    scanf("%d", &nodevalue);
    deleteafternode(&head, nodevalue);
    printlist(head);

    return 0;
}