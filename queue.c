#include <stdio.h>
#include <stdlib.h>
#define MAXQ 100

typedef struct queue{
    int f;
    int r;
    int arr[MAXQ];
}queue;

queue *createqueue(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->f = -1;
    q->r = -1;
    return q;
}

int enqueue(queue *q, int data){
    if(q->r == MAXQ-1){
        printf("\nQueue is Full\n");
        return -1;
    }
    else{
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(queue *q){
    int deleted;
    if(q->f > q->r){ 
        printf("\nQueue is Empty \n");
        return -1;
    }
    else{
        deleted = q->arr[q->f];
        q->f++;
        return deleted;
    }
}

int printqueue(queue *q){
  
    
        for (int i = q->f; i <= q->r; i++){
            printf(" %d ", q->arr[i]);
        
    }
}
int main(){
    queue *q = createqueue();
    enqueue(q, 5);
    dequeue(q);
    enqueue(q, 7);
    printqueue(q);
    return 0;
}