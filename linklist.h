#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct ThreeA{
    char op;
    char* op1;
    char* op2;
    char* op3;
    struct ThreeA* next;
} *TAroot,*TAlast;



void TAinstall(char op, char* op1, char* op2,char* op3){
    struct ThreeA *current = TAroot;
    struct ThreeA* newNode = (struct ThreeA *)malloc(sizeof(struct ThreeA));
    if (newNode == NULL) {
        printf("malloc failed\n");
        exit(-1);
    }

    newNode->op=op;
    newNode->op1=op1;
    newNode->op2=op2;
    newNode->op3=op3;
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
        printf("%c\t%s\t%s\t%s\n",temp->op,temp->op1,temp->op2,temp->op3);
        temp = temp->next;
    }
}