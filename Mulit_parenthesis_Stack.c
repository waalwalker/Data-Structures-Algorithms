#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char val){
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d in the stack. \n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack. \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        return val;
    }
}

char stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int parenthesisMatch(char* exp){
    //Create and initialize stack, but not for validation of expression
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if (exp[i]==')')
        {
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int match(char a, char b){
    if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
    
}

int MultiParenthesisMatch(char* exp){
    //Create and initialize stack, but not for validation of expression
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i] == '{' || exp[i] == '['){
            push(sp, exp[i]);
        }
        else if (exp[i]==')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
            
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char * exp = "(8*(9))(()){1 + 2}-[45-4]";

    if (MultiParenthesisMatch(exp))
    {
        printf("The parenthesises are balanced.\n");
    }
    else
    {
        printf("The parenthesises are not balanced.\n");
    }
    
    
    return 0;
}