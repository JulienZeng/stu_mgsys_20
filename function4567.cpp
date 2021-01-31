/*
��Դ�ļ��Ĺ���Ϊ��
    1.��ѧ����Ϣ����ɾ�Ĳ�(�����˻�����)
    2.���ļ����в���
*/
#include "function4567.h"
//��ӡ�ڵ�
//����������ʽ��Ҫ���ģ�������
void printNode(Node *curNode)
{
    //cout<<"\tѧ��\t����\tѧԺ\t�Ա�\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\tƽ����"<<endl;
    printf("\t%d\t%s\t%s\t\t%s\t",curNode->data.id,
    curNode->data.name,
    curNode->data.col,
    curNode->data.sex);
    for(int i=0;i<4;i++)
    {
        printf("%d",curNode->data.score[i]);
        if(i!=3) printf("\t");
    }
    printf("\t%lf",curNode->data.average);
    printf("\n");
}
//��ѧԺ����ת��Ϊ����
//������治��Ҫ��
int Col_changeToInt(ColNode *colist,char col[64],int collen)
{
    ColNode *pMove = colist->next;
    for(int i=0;i<collen;i++)
    {
        if( strcmp(pMove->col.col,col)==0 )
        {
            return pMove->col.colnum;
        }
        pMove = pMove->next;
    }
}
//���Ա�ת��Ϊ����
//������治��Ҫ��
int Sex_changeToInt(SexNode *sexlist,char sex[4],int sexlen)
{
    SexNode *pMove = sexlist->next;
    for(int i=0;i<sexlen;i++)
    {
        if( strcmp(pMove->sex.sex,sex)==0 )
        {
            return pMove->sex.sexnum;
        }
        pMove = pMove->next;
    }
}
//��ѧԺ����ת��Ϊ����
//������治��Ҫ��
Data Col_changeToChar(ColNode *colist,Data tempData,int collen)
{
    ColNode *pMove = colist->next;
    for(int i=0;i<collen;i++)
    {
        if(tempData.colid == pMove->col.colnum)
        {
            strcpy(tempData.col,pMove->col.col);
            return tempData;
        }
        pMove = pMove->next;
    }
}
//���Ա����ת��Ϊ����
//������治��Ҫ��
Data Sex_changeToChar(SexNode *sexlist,Data tempData,int sexlen)
{
    SexNode *pMove = sexlist->next;
    for(int i=0;i<sexlen;i++)
    {
        if(tempData.sexid == pMove->sex.sexnum)
        {
            strcpy(tempData.sex,pMove->sex.sex);
            return tempData;
        }
        pMove = pMove->next;
    }
}
//�˵���ʽ������
void Menu_DeleNodeByName()
{
    cout<<"��ȷ������Ҫ���еĲ�����"<<endl;
    cout<<"1.ɾ����ѧ��������Ϣ"<<endl;
    cout<<"2.����ѧ���ĳɼ�1����"<<endl;
    cout<<"3.����ѧ���ĳɼ�2����"<<endl;
    cout<<"4.����ѧ���ĳɼ�3����"<<endl;
    cout<<"5.����ѧ���ĳɼ�4����"<<endl;
    cout<<"0.ȡ��������������һ��"<<endl;
}
double coutAve(Data tempData)
{
    double sum = 0;
    for(int i=0;i<4;i++)
    {
        sum += tempData.score[i];
    }
    return sum/4;
}
//��
void insetNode(Node *listHeadNode,ColNode *colHeadNode,SexNode *sexHeadNode,int collen,int sexlen)
{
    char colinput[64];
    char sexinput[4];
    Data newdata;
    cout<<"�����ѧ������ɼ���"<<endl;
    cout<<"������ѧ����Ϣ��(ÿһ����Ϣ���ÿո�ָ�)"<<endl;
    cout<<"ѧ�� ���� ѧԺ �Ա� �ɼ�1 �ɼ�2 �ɼ�3 �ɼ�4"<<endl;
    scanf("%d%s%s%s",&newdata.id,
    newdata.name,colinput,sexinput);
    for(int i=0;i<4;i++)
    {
        scanf("%d",newdata.score[i]);
    }
    newdata.colid = Col_changeToInt(colHeadNode,colinput,collen);
    newdata.sexid = Sex_changeToInt(sexHeadNode,sexinput,sexlen);
    insetNodeByHead(listHeadNode,newdata);
    cout<<"����ѧ����Ϣ�ɹ���"<<endl;
    //�����ļ�
    saveInfoToFile(listHeadNode);
}
//ɾ
//ͨ������(char)ɾ����Ϣ
void deleNodeByName(Node *listHeadNode)
{
    char delename[64];
    Node *deleStu;
    cout<<"��ɾ��ѧ���ɼ���"<<endl;
    cout<<"��������Ҫɾ����ѧ����������";
    scanf("%s",delename);
    deleStu = searchNodeByName(listHeadNode,delename);
    if( deleNode == NULL )
    {
        cout<<"Error:δ�ҵ����ѧ������Ϣ"<<endl;
    }
    else
    {
        printNode(deleStu);
        Menu_DeleNodeByName();
        int chose;
        cin>>chose;
        switch (chose)
        {
        case 1:
            deleNode(listHeadNode,deleStu);
            saveInfoToFile(listHeadNode);
            break;
        
        case 2:
        case 3:
        case 4:
        case 5:
            cout<<"�������ѧ���ɼ�"<<chose-1<<"���³ɼ�"<<endl;
            scanf("%d",deleStu->data.score[chose-2]);
            saveInfoToFile(listHeadNode);
            break;

        case 0:
            break;
        default:
            cout<<"ѡ�������ȡ�����β�����"<<endl;
            break;
        }
    }
}
//��
void changeNodeByName(Node *listHeadNode)
{
    cout<<"���޸�ѧ���ɼ���"<<endl;
    char searchname[64];
    cout<<"������ѧ����������";
    scanf("%s",searchname);
    Node *searchNode;
    searchNode = searchNodeByName(listHeadNode,searchname);
    if( searchNode == NULL )
    {
        cout<<"Error:δ�ҵ����ѧ������Ϣ"<<endl;
    }
    else
    {
        char chose;
        printNode(searchNode);
        cout<<"ȷ���޸ĸ�ѧ���ɼ���(Y/N)"<<endl;
        scanf("%c",&chose);
        switch (chose)
        {
        case 'Y':
        case 'y':
            cout<<"�������ѧ�����Ĵγɼ�"<<endl;
            for(int i=0;i<4;i++)
            {
                scanf("%d",searchNode->data.score[i]);
            }
            cout<<"�ɼ��޸ĳɹ�!"<<endl;
            saveInfoToFile(listHeadNode);
            break;
        
        case 'N':
        case 'n':
            cout<<"����ȡ��"<<endl;
            break;

        default:
            cout<<"���������ȡ���ôβ���"<<endl;
            break;
        }
    }
}
//��
void searchByName(Node *listHeadNode)
{
    cout<<"����ѯѧ���ɼ���"<<endl;
    char searchname[64];
    cout<<"��������Ҫ��ѯ��ѧ��������"<<endl;
    scanf("%s",searchname);
    cout<<"����ѧ����Ϣ���£�"<<endl;
    printNode(searchNodeByName(listHeadNode,searchname));
}
//���ָ��ѧԺѧ��
void *searchColNodeByColid(Node *listHeadNode,int chose)
{
    Node *pMove = listHeadNode->next;
    cout<<"\tѧ��\t����\t\tѧԺ\t�Ա�\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4"<<endl;
    while(1)
    {
        if(pMove == NULL)
            break;
        else if( pMove->data.colid == chose )
        {
            printNode(pMove);
        }
        pMove = pMove->next;
    }
}
void printColStu(Node *listHeadNode,ColNode *colHeadNode,int collen)
{
    ColNode *pMove = colHeadNode->next;
    int chose,flg;
    cout<<"���������ѧԺ��ѧ����"<<endl;
    cout<<"��ѡ����Ҫ����Ѱ�ҵ�ѧԺ��"<<endl;
    for(int i=collen;i>0;i--)
    {
        printf("%d��%s\n",i,pMove->col.col);
        pMove = pMove->next;
    }
    cin>>chose;
    if(chose<=collen&&chose>0) flg = 1;
    switch (flg)
    {
    case 1:
        cout<<"��ѧԺ��ѧ�����ɼ����£�"<<endl;
        searchColNodeByColid(listHeadNode,chose);
        break;
    
    default:
        cout<<"Error:�������"<<endl;
        break;
    }
}

/*���ļ����в���*/

//����ע����
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
int readColFromFile(ColNode *colHeadNode)
{
    //�˴���������ڵ���ǰ����
    //cout<<"���ڶ�ȡ�ļ�(1/3)"<<endl;
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
    int collen = readFromFile(fp);
    for(int i=0;i<collen;i++)
    {
        fscanf(fp,"%d%s",&tempData.colnum,tempData.col);
        insetColNodeByHead(colHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
    return collen;
}
//��ȡ�Ա����
int readSexFromFile(SexNode *sexHeadNode)
{
    //�˴���������ڵ���ǰ����
    //cout<<"���ڶ�ȡ�ļ�(2/3)"<<endl;
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
    int sexlen = readFromFile(fp);
    for(int i=0;i<sexlen;i++)
    {
        fscanf(fp,"%d%s",&tempData.sexnum,tempData.sex);
        insetSexNodeByHead(sexHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
    }
    fclose(fp);
    return sexlen;
}
//���ļ��ж�ȡѧ����Ϣ
int readStuInfoFromFile(Node *listHeadNode,ColNode *colHeadNode,SexNode *sexHeadNode,int collen,int sexlen)
{
    int num=0;
    //�˴���������ڵ���ǰ����
    //cout<<"���ڶ�ȡ�ļ�(3/3)"<<endl;
    FILE *fp;
    fp = fopen("Stu_Info(tab).txt","r");
    if (fp == NULL)
    {
        fprintf(stdout,"w");
        cout<<"��ȡ�ļ�ʧ�ܡ�(1103)"<<endl;
        exit(1);
    }
    Data tempData;
    while(!feof(fp))
    {
        fscanf(fp,"%d%s%d%d",
        &tempData.id,
        tempData.name,
        &tempData.colid,
        &tempData.sexid);
        for(int i=0;i<4;i++)
        {
            fscanf(fp,"%d",&tempData.score[i]);
        }
        tempData = Col_changeToChar(colHeadNode,tempData,collen);
        tempData = Sex_changeToChar(sexHeadNode,tempData,sexlen);
        tempData.average = coutAve(tempData);
        insetNodeByHead(listHeadNode,tempData);
        memset(&tempData,0,sizeof(tempData));
        num++;
    }
    fclose(fp);
    return num;
}
//����Ϣд���ļ�
void saveInfoToFile(Node *listHeadNode)
{
    FILE *fp = fopen("Stu_Info.txt","w");
    if (fp == NULL)
    {
        fprintf(stdout,"w");
        cout<<"��������ʧ�ܡ�(1201)"<<endl;
        exit(1);
    }
    Node *pMove = listHeadNode->next;
    while (pMove)
    {
        fprintf(fp,"%d %s %d %d ",
        pMove->data.id,
        pMove->data.name,
        pMove->data.colid,
        pMove->data.sexid);
        for(int i=0;i<4;i++)
        {
            fprintf(fp,"%d",pMove->data.score[i]);
            if(i!=3)
            {
                fprintf(fp," ");
            }
        }
        fprintf(fp,"\n");
        pMove = pMove->next;
    }
    fclose(fp);
}