/*
 * =====================================================================================
 *
 *       Filename:  ref.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/22/2009 09:40:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    char name[30];
    struct node *lchild,*rchild;
}TreeNode , *BiTree;

void PreOrderTraverse(TreeNode *T,int counter)
{
    int i;
    if(T){
        for(i=0;i<counter;i++) printf("+");
        printf("%s\n",T->name);
        PreOrderTraverse(T->lchild,counter+1);
        PreOrderTraverse(T->rchild,counter);
    }
    return;
}

TreeNode *r,*temT;
void findPersonNew(TreeNode *T,char name[])
{
    int i;
    if(T){
        if(T->lchild && strcmp(T->lchild->name,name)==0){
            r=T;
            temT=T->lchild;
            return;
        }
        else if(T->rchild && strcmp(T->rchild->name,name)==0){
            r=T;
            temT=T->rchild;
            return;
        }
        findPersonNew(T->lchild,name);
        findPersonNew(T->rchild,name);
    }
    return;
}

void hirePerson(BiTree &T,char name1[],char name2[]){
    TreeNode *newNode,*p;//,*temT;
    p=T;
    temT=T;
    r=T;
    findPersonNew(T,name1);
   
    /*Here [existing member] is the name of any individual who is already a member of the organization,
    [new member] is the name of an individual who is not a member of the organization as yet.*/
    if(temT->lchild!=NULL){/*have chindren*/
        temT=temT->lchild;
        while(temT->rchild!=NULL){
            temT=temT->rchild;
        }
        newNode=(TreeNode*)malloc(sizeof(TreeNode));
        if(newNode!=NULL){
            strcpy(newNode->name,name2);
            temT->rchild=newNode;
            newNode->lchild=newNode->rchild=NULL;
        }
    }else{
        newNode=(TreeNode*)malloc(sizeof(TreeNode));
        strcpy(newNode->name,name2);
        temT->lchild=newNode;
        newNode->lchild=newNode->rchild=NULL;
    }
}

void firePerson(BiTree &T,char name[]){
    TreeNode *newNode,*p;//,*temT,*r;
    p=T;
    temT=T;
    r=T;
    findPersonNew(T,name);
   
    if(r==T){ /*remove the root*/
        while(temT->lchild!=NULL){
                strcpy(temT->name,temT->lchild->name);
                r=temT;
                temT=temT->lchild;
            }
            if(temT->lchild==NULL && temT->rchild==NULL){
                if(r->lchild==temT) r->lchild=NULL;
                else if(r->rchild==temT) r->rchild=NULL;
                free(temT);
            }else if(temT->lchild==NULL && temT->rchild!=NULL){
                r->lchild=temT->rchild;
                free(temT);
            }
    }else{
        if(temT->lchild==NULL && temT->rchild==NULL){
            if(r->lchild==temT) r->lchild=NULL;
            else if(r->rchild==temT) r->rchild=NULL;
            free(temT);
        }else if(temT->lchild==NULL && temT->rchild!=NULL){
            if(r->lchild==temT) r->lchild=temT->rchild;
            else if(r->rchild==temT) r->rchild=temT->rchild;
            free(temT);
        }else{
            while(temT->lchild!=NULL){
                strcpy(temT->name,temT->lchild->name);
                r=temT;
                temT=temT->lchild;
            }
            if(temT->lchild==NULL && temT->rchild==NULL){
                if(r->lchild==temT) r->lchild=NULL;
                else if(r->rchild==temT) r->rchild=NULL;
                free(temT);
            }else if(temT->lchild==NULL && temT->rchild!=NULL){
                if(r->lchild==temT) r->lchild=temT->rchild;
                else if(r->rchild==temT) r->rchild=temT->rchild;
                free(temT);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i;
    char tem[30];
    char name1[30],name2[30];
   
    /*create tree*/
    TreeNode *root;
   
    /*CEO*/
    scanf("%s",tem);
    root=(TreeNode*)malloc(sizeof(TreeNode));
    root->lchild=root->rchild=NULL;
    strcpy(root->name,tem);

    while(scanf("%s",tem)!=EOF){
        if(strcmp(tem,"print")==0){
            PreOrderTraverse(root,0);
            printf("------------------------------------------------------------\n");
        }else if(strcmp(tem,"fire")==0){
            scanf("%s",name1);
            firePerson(root,name1);
        }else{/*hire*/
            strcpy(name1,tem);
            scanf("%s",tem);
            scanf("%s",name2);
            hirePerson(root,name1,name2);
        }
    }
    return 0;
}
