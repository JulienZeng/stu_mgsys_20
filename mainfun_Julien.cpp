/*
��Դ�ļ��Ĺ���Ϊ��
��ѧ����Ϣ����ɾ�Ĳ�
(�����˻�����)
*/
#include "stumgsys20.h"
//��
void insetNode(Node *listHeadNode)
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
    newdata.colid = Col_changeToInt(colinput);
    newdata.sexid = Sex_changeToInt(sexinput);
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