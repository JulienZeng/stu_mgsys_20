/*
��Դ�ļ��Ĺ���Ϊ��
    1.ʹ������ʵ����Ϣ��ɾ��(�������˻�����)
*/
#include "list.h"

//����Info����ͷ
Node *CreateInfoList ()
{
    Node *listHeadNode = (Node *)malloc(sizeof(Node));
    listHeadNode->next = NULL;
    return listHeadNode;
}
//����Col����ͷ
ColNode *CreateColList ()
{
    ColNode *listHeadNode = (ColNode *)malloc(sizeof(ColNode));
    listHeadNode->next = NULL;
    return listHeadNode;
}
//����Sex����ͷ
SexNode *CreateSexList ()
{
    SexNode *listHeadNode = (SexNode *)malloc(sizeof(SexNode));
    listHeadNode->next = NULL;
    return listHeadNode;
}
//�����ڵ�
Node *createNode(Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data ;
    newNode -> next = NULL ;
    return newNode;
}
//��
//ͷ�巨�������ݵ�����
void *insetNodeByHead (Node *listheadNode,Data data)
{
    Node *nweNode = createNode(data);
    nweNode -> next = listheadNode -> next;
    listheadNode->next = nweNode;
}
//��
//ʹ��name(char)���ҽڵ�
Node *searchNodeByName(Node *listHeadNode,char searchname[64])
{
    Node *pMove = listHeadNode->next;
    if (pMove == NULL)
    return pMove;
    else
    {
        while (strcmp(pMove->data.name,searchname)!=0)
        {
            pMove = pMove->next;
            if (pMove == NULL)
            break;
        }
        return pMove;
    }
}
//ɾ
//ʹ��name(char)ɾ���ڵ�
void deleNode(Node *listHeadNode ,Node *dele)
{
    Node *p = listHeadNode->next;
    Node *q = p->next;
    while ( strcmp(q->data.name,dele->data.name)!=0 )
    {   
        p = p->next;
        q = q->next;
        if(q == NULL)
        return;
    }
    p->next = q->next;
    return;
}
//�����ڵ�
ColNode *createColNode(Col data)
{
    ColNode *newNode = (ColNode *)malloc(sizeof(ColNode));
    newNode -> col = data ;
    newNode -> next = NULL ;
    return newNode;
}
//ͷ�巨�������ݵ�����
void *insetColNodeByHead (ColNode *listheadNode,Col data)
{
    ColNode *nweNode = createColNode(data);
    nweNode -> next = listheadNode -> next;
    listheadNode->next = nweNode;
}
SexNode *createSexNode(Sex data)
{
    SexNode *newNode = (SexNode *)malloc(sizeof(SexNode));
    newNode -> sex = data ;
    newNode -> next = NULL ;
    return newNode;
}
//ͷ�巨�������ݵ�����
void *insetSexNodeByHead (SexNode *listheadNode,Sex data)
{
    SexNode *nweNode = createSexNode(data);
    nweNode -> next = listheadNode -> next;
    listheadNode->next = nweNode;
}