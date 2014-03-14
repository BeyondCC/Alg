#include<stdio.h>
#include<stdlib.h>

typedef int Element;

struct Node{
    Element element;
    struct Node  * next;
};

typedef struct Node *pNode;
typedef pNode Stack;

/*
 * The list is a pointer,when want to change it ,should pass the address
 * of it
 * The pointer pass as argument, it will not change
 *
 * When implement push and pop ,this program does not check the stack is null
 * 
 */
void CreateStack(Stack  *stack)
{
    *stack = (Stack) malloc(sizeof(struct Node));
    (*stack)->next = NULL;
}

void Push(Element x, Stack stack)
{
    pNode tmp = (pNode)malloc(sizeof(struct Node));
    
    tmp->element = x;
    tmp->next = stack->next;
    stack->next = tmp;
}

Element Pop(Stack stack)
{
    pNode tmp = stack->next;
    stack->next = tmp->next;

    Element element = tmp->element;
    free(tmp);
    tmp = NULL;

    return element;
}

void PrintStack(Stack stack)
{
   pNode top = stack->next;

   while(top != NULL)
   {
        printf("%4d", top->element);
        top = top->next;
   }

   printf("\n");
    
}
int main(int argc, char **argv)
{
    Stack stack;
    CreateStack(&stack);
    Push(1, stack);
    Push(2, stack);
    Push(3, stack);
    PrintStack(stack);
    
    printf("pop : %d\n", Pop(stack));
    PrintStack(stack);

}
