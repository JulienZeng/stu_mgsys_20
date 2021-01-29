#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int collen;
int sexlen;

//�洢ѧ����Ϣ�Ľṹ��
typedef struct Data
{
    int id;
    char name[64];
    int colid;
    int sexid;
    char col[64];
    char sex[4];
    double score[4];
    double average;
}Data;
Data *pstu;
//����ڵ�ṹ��
typedef struct Node 
{
    Data data;
    Node *next;
}Node;
//ѧԺ����ṹ��
typedef struct Col
{
    int colnum;
    char col[64];
}Col;
//ѧԺ��������ڵ�
typedef struct ColNode
{
    Col col;
    ColNode *next;
}ColNode;
//�ļ���ȡ�Ա����ṹ��
typedef struct Sex
{
    int sexnum;
    char sex[64];
}Sex;
//�Ա����ṹ��
typedef struct SexNode
{
    Sex sex;
    SexNode *next;
}SexNode;
//��������
Node *list = NULL;
ColNode *colist = NULL;
SexNode *sexlist = NULL;

#ifndef __STUMGSYS20_H__
#define __STUMGSYS20_H__
//����
Node *CreateInfoList ();
ColNode *CreateColList ();
SexNode *CreateSexList ();
Node *createNode(Data);
void *insetNodeByHead (Node*,Data);
Node *searchNodeByName(Node*,char []);
void deleNode(Node*,Node*);
ColNode *createColNode(Col);
void *insetColNodeByHead (ColNode*,Col);
SexNode *createSexNode(Sex);
void *insetSexNodeByHead (SexNode*,Sex);
//�ļ�����
int readFromFile(FILE*);
void readColFromFile(ColNode*);
void readSexFromFile(SexNode*);
void readStuInfoFromFile(Node*);
void saveInfoToFile(Node*);
void printNode(Node*);
//ǰ�ù���
int Col_changeToInt(char []);
int Sex_changeToInt(char []);
Data Col_changeToChar(Data);
Data Sex_changeToChar(Data);
void Menu_DeleNodeByName();
double coutAve(Data);
//��ɾ�Ĳ�
void insetNode(Node*);
void deleNodeByName(Node*);
void changeNodeByName(Node*);
void searchByName(Node*);

#endif