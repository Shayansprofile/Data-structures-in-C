#include <stdio.h>
#include <stdlib.h>

#define MAXSTK 100

typedef struct stack{
    int top;
    int arr[MAXSTK];
}stack;

stack *createstack(){
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->top = -1;
    return sp;
}

void push(stack *sp, int data){
    if(sp->top==MAXSTK-1){
        printf("\nStack overflow\n");
        return;
    }
    else{
        sp->top++;
        sp->arr[sp->top] = data;
    }
}

int pop(stack *sp){
    int deleted;
    if(sp->top==-1){
        printf("\nStack underflow\n");
        return;
    }
    else{
        deleted = sp->arr[sp->top];
        sp->top = sp->top - 1;
        return deleted;
    }
}

void printstack(stack *sp){
    if(sp->top==-1){
        printf("\nStack is empty.\n");
        return;
    }
    else{
        for (int i = 0; i <= sp->top;i++){
            printf(" %d ", sp->arr[i]);
        }
    }
}

int main(){
    stack *sp = createstack();
    push(sp, 50);
    push(sp, 100);
    push(sp, 500);
    printstack(sp);
    pop(sp);
    printstack(sp);
    return 0;
}