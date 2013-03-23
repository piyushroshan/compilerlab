#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct ThreeA{
    char op;
    char* op1;
    char* op2;
    struct ThreeA* next;
} *TAroot,*TAlast;



void TAinstall(char op, char* op1, char* op2){
    struct ThreeA* temp = (struct ThreeA *)malloc(sizeof(struct ThreeA));
    temp->op=op;
    temp->op1=op1;
    temp->op2=op2;
    temp->next=NULL;
    if(TAroot==NULL)
    {
        TAroot = (struct ThreeA *)malloc(sizeof(struct ThreeA));
        TAlast = (struct ThreeA *)malloc(sizeof(struct ThreeA));
        TAroot=temp;
        TAlast=TAroot;
    }
    else
    {
        //TAlast->next=(struct ThreeA *)malloc(sizeof(struct ThreeA));
        TAlast->next=temp;
        TAlast=TAlast->next;
        //TAlast=temp;
    }
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