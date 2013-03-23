#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct ThreeA{
    int op;
    char* op1;
    char* op2;
    struct ThreeA* next;
} *TAroot,*TAlast;



void TAinstall(int op, char* op1, char* op2){
    struct ThreeA *current = TAroot;
    struct ThreeA* newNode = (struct ThreeA *)malloc(sizeof(struct ThreeA));
    if (newNode == NULL) {
        printf("malloc failed\n");
        exit(-1);
    }

    newNode->op=op;
    newNode->op1=op1;
    newNode->op2=op2;
    newNode->next=NULL;
    if(current==NULL)
    {
        TAroot=newNode;
        return;
    }
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}


void print_TAlist(){
    struct ThreeA* temp = (struct ThreeA *)malloc(sizeof(struct ThreeA));
    temp=TAroot;
    while(temp)
    {
        printf("%c\t%s\t%s\n",temp->op,temp->op1,temp->op2);
        temp = temp->next;
    }
}