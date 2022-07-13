#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};


int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}


int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;    
    } 
    return 0;
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d into the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return -1;
    }else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    struct stack *s = (struct stack*) malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int*) malloc(s->size * sizeof(int));    
    printf("stack has been created successfully\n");
    printf("Before push | Empty :%d \n",isEmpty(s));
    printf("Before push | Full :%d \n",isFull(s));
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);
    printf("After push | Empty :%d \n",isEmpty(s));
    printf("After push | Full :%d \n",isFull(s));
    printf("%d",s->arr[0]);
    printf("poping a value from the stack\n poped value : %d\n",pop(s));
    return 0;
}