/*
�������������
��ƽ���ɼ��������
�������ѧԺѧ��*/ 
void sortOnName1(Node *p)//��С���� ������ ���� 
{
	Data *mid;
	
	while(*p->next)
	{
		if(strcmp(p->data->name,p->next->data->name)>0)
		{
			*mid=p->data;
			p->data=p->next->data;
			p->next->data=*mid;
		}
		p=p->next;
	}
} 
void sortOnName2(Node *p)//�Ӵ�С ������ ���� 
{
	Data *mid;
	
	while(*p->next)
	{
		if(strcmp(p->data->name,p->next->data->name)<0)
		{
			*mid=p->data;
			p->data=p->next->data;
			p->next->data=*mid;
		}
		p=p->next;
	}
} 

void sortaverage(Node *p)  //��ƽ���ɼ��Ӵ�С���� 
{
	Data *mid;
	
	while(*p->next)
	{
		if(p->data->average<p->next->data->average)
		{
			*mid=p->data;
			p->data=p->next->data;
			p->next->data=*mid;
		}
		p=p->next;
	}
}


