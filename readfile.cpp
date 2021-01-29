/*
������ʵ�ֵĹ��ܣ�
��ȡ�ļ�������

*/
//����ע�Ͳ���ȡ���ݳ���
#include "stumgsys20.h"
int readFromFile(FILE *fp)
{
    char readinfo[128],*ps=readinfo;
    while(1)
    {
        fscanf(fp,"%s",readinfo);
        if( *ps != '#')
            break;
    }
    int num=0;
    while(*ps)
    {
        num = num*10 + *ps++ -'0';
    }
    return num;
}
//��ȡѧԺ����
void readColFromFile(ColNode *colHeadNode)
{
    cout<<"���ڶ�ȡ�ļ�(1/3)"<<endl;
    FILE *fp;
    Col tempData;
    //C_Code.txtΪѧԺ�����ļ�
    fp=fopen("C_Code.txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"file(r)");
        cout<<"��ȡ�ļ�ʧ�ܡ�(1101)"<<endl;
        exit(1);
    }
    collen = readFromFile(fp);
    for(int i=0;i<collen;i++)
    {
        fscanf(fp,"%d%s",&tempData.colnum,tempData.col);
        insetColNodeByHead(colHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
}
//��ȡ�Ա����
void readSexFromFile(SexNode *sexHeadNode)
{
    cout<<"���ڶ�ȡ�ļ�(2/3)"<<endl;
    FILE *fp;
    Sex tempData;
    //S_Code.txtΪ�Ա�����ļ�
    fp=fopen("S_Code.txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"file(r)");
        cout<<"��ȡ�ļ�ʧ�ܡ�(1102)"<<endl;
        exit(1);
    }
    sexlen = readFromFile(fp);
    for(int i=0;i<sexlen;i++)
    {
        fscanf(fp,"%d%s",&tempData.sexnum,tempData.sex);
        insetSexNodeByHead(sexHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
}
//���ļ��ж�ȡѧ����Ϣ
void readStuInfoFromFile(Node *listHeadNode)
{
    FILE *fp;
    fp = fopen("Stu_Info.txt(tab)","r");
    if (fp == NULL)
    {
        fprintf(stdout,"w");
        cout<<"��ȡ�ļ�ʧ�ܡ�(1103)"<<endl;
        exit(1);
    }
    Data tempData;
    while(fp)
    {
        fscanf(fp,"%d\t%s\t%d\t%d",
        &tempData.id,
        tempData.name,
        &tempData.colid,
        &tempData.sexid);
        for(int i=0;i<4;i++)
        {
            fscanf(fp,"\t%d",&tempData.score[i]);
        }
        tempData = Col_changeToChar(tempData);
        tempData = Sex_changeToChar(tempData);
        tempData.average = coutAve(tempData);
        insetNodeByHead(listHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
}
//����Ϣд���ļ�
void saveInfoToFile(struct Node* listHeadNode)
{
    FILE *fp = fopen("Stu_Info.txt","w");
    if (fp == NULL)
    {
        fprintf(stdout,"w");
        cout<<"��������ʧ�ܡ�(1201)"<<endl;
        exit(1);
    }
    struct Node* pMove = listHeadNode->next;
    while (pMove)
    {
        fprintf(fp,"%d\t%s\t%d\t%d\t",
        pMove->data.id,
        pMove->data.name,
        pMove->data.colid,
        pMove->data.sexid);
        for(int i=0;i<4;i++)
        {
            fprintf(fp,"%d",pMove->data.score[i]);
            if(i!=4)
            {
                fprintf(fp,"\t");
            }
            else
            {
                fprintf(fp,"\n");
            }
        }
        pMove = pMove->next;
    }
    fclose(fp);
}