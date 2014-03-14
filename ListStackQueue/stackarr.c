#include<stdio.h>
#include<stdlib.h>

#define false 0
#define true  1

typedef int bool;
typedef int Element;

struct StackRecord{
    int capacity;
    int top;
    Element * array;
};

typedef struct StackRecord * Stack;
/*
 * The list is a pointer,when want to change it ,should pass the address
 * of it
 * The pointer pass as argument, it will not change
 *
 * When implement push and pop ,this program does not check the stack is null
 * 
 */
void CreateStack(Stack  *stack, Element max)
{
    *stack = (Stack) malloc(sizeof(struct StackRecord));
    (*stack)->capacity = max;
    (*stack)->top = -1;
    (*stack)->array = (Element *)malloc(sizeof(Element) * max);
}

bool IsEmpty(Stack stack)
{
    if(stack->top < 0)
      return true;

    return false;
}

void Push(Element x, Stack stack)
{
//  the argument size_t of realloc should use sizeof(int)*size
    if(stack->top + 1 == stack->capacity){
        stack->array = (int *)realloc(stack->array, sizeof(int) * (stack->capacity + 10));
        stack->capacity += 10;
    }
    
    stack->array[++stack->top] = x;
    printf("top: %d value: %d\n", stack->top, stack->array[stack->top]);

}

//0 as the end
Element Pop(Stack stack)
{
    if(!IsEmpty(stack))
        return stack->array[stack->top--];

    return 0;
}

void PrintStack(Stack stack)
{
    int index;

    for(index = stack->top; index >= 0; index--)
    {
        printf("%4d", stack->array[index]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Stack stack;
    CreateStack(&stack, 10);
    Push(1, stack);
    Push(2, stack);
    Push(3, stack);
    Push(4, stack);
    Push(5, stack);
    Push(6, stack);
    Push(7, stack);
    Push(8, stack);
    Push(9, stack);
    Push(10, stack);
    Push(11, stack);
    Push(12, stack);
    Push(13, stack);
    Push(14, stack);
    Push(15, stack);
    PrintStack(stack);

    printf("pop : %d\n", Pop(stack));
    PrintStack(stack);

}
