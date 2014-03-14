#include<stdio.h>
#include<stdlib.h>

typedef int Element;

struct Node{
    Element element;
    struct Node  * next;
};

typedef struct Node *pNode;
typedef pNode List;

/*
 * The list is a pointer,when want to change it ,should pass the address
 * of it
 * The pointer pass as argument, it will not change
 * 
 */
void CreateList(List  *list)
{
    *list =(List)malloc(sizeof(struct Node));
    (*list)->next = NULL;
}

void Insert(List list, Element x)
{
    pNode tmp = (pNode)malloc(sizeof(struct Node));
    tmp->element = x;

    pNode fstNode = list->next;

    list->next = tmp;
    tmp->next = fstNode;
}

void Delete(List list, Element x)
{
    pNode currNode = list->next;
    pNode preNode = list;
    
    while(currNode != NULL && currNode->element != x){
        preNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == NULL)
      return;
    else{
        preNode->next = currNode->next;
        free(currNode);
    }
}

void PrintList(List list)
{
    printf("the list is \n");

    pNode current = list->next;

    while(current != NULL){
        printf("%4d", current->element);
        current = current->next;
    }

    printf("\n");
}

int main(int argc, char **argv){
    List l;
    CreateList(&l);
    Insert(l, 1);
    Insert(l, 2);
    Insert(l, 3);
    PrintList(l);

    Delete(l, 2);
    PrintList(l);
    return 0;
}
