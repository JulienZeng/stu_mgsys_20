#include "stumgsys20.h"
//��ӡ�ڵ�
//����������ʽ��Ҫ���ģ�������
void printNode(Node *curNode)
{
    cout<<"\tѧ��\t����\tѧԺ\t�Ա�\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4"<<endl;
    printf("%d %s %s %s ",curNode->data.id,
    curNode->data.name,
    curNode->data.col,
    curNode->data.sex);
    for(int i=0;i<4;i++)
    {
        printf("%lf ",curNode->data.score[i]);
    }
}
//��ѧԺ����ת��Ϊ����
int Col_changeToInt(char col[64])
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
int Sex_changeToInt(char sex[4])
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
Data Col_changeToChar(Data tempData)
{
    ColNode *pMove = colist->next;
    for(int i=0;i<collen;i++)
    {
        if(tempData.colid = pMove->col.colnum)
        {
            strcpy(tempData.col,pMove->col.col);
            break;
        }
        pMove = pMove->next;
    }
}
//���Ա����ת��Ϊ����
Data Sex_changeToChar(Data tempData)
{
    SexNode *pMove = sexlist->next;
    for(int i=0;i<sexlen;i++)
    {
        if(tempData.sexid = pMove->sex.sexnum)
        {
            strcpy(tempData.sex,pMove->sex.sex);
            break;
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