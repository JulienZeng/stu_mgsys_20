#include "fun12.h"
/*
�������������
��ƽ���ɼ��������
*/ 
//sumΪѧ������ 
void sortOnName1(Node *p,int sum)//��С���� ������ ���� 
{
	Data *mid;
	Node *px=p->next;
	
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
				if(strcmp(p->data.name,p->next.data.name)>0)
			{
				*mid=p->data;
				p->data=p->next.data;
				p->next.data=*mid;
			}
			px=px->next;	
		}
		p=p->next;
		px=p->next;
	}

} 
void sortOnName2(Node *p,int num)//�Ӵ�С ������ ���� 
{
	Data *mid;
	Node *px=p->next;
	
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
				if(strcmp(p->data.name,p->next.data.name)<0)
			{
				*mid=p->data;
				p->data=p->next.data;
				p->next.data=*mid;
			}
			px=px->next;	
		}
		p=p->next;
		px=p->next;
	}

}

void sortaverage(Node *p,int num)  //��ƽ���ɼ��Ӵ�С���� 
{
	Data *mid;
	Node *px=p->next;
	
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
				if(p->data.average<p->next.data.average)
			{
				*mid=p->data;
				p->data=p->next.data;
				p->next.data=*mid;
			}
			px=px->next;	
		}
		p=p->next;
		px=p->next;
	}
}


