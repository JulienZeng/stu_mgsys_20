#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "list.h"
#include "function4567.h"
#include "func89.h"

#define COURSE_NUM 4	 // ���Ŀ��Կ�Ŀ��
#define LEN sizeof(Node) // ���ݽṹ�ĳ���

int Menu(void);

int main()
{
	int i;
	// ��¼
	FILE *fp;
	char strLine[20]; //��ȡ������
	char ps[20];
	if ((fp = fopen("pw.txt", "r")) == NULL) //�ж��ļ��Ƿ���ڼ��ɶ�
	{
		printf("Open Falied!");
		return -1;
	}
	while (!feof(fp)) //ѭ����ȡÿһ�У�ֱ���ļ�β
	{
		fgets(strLine, 20, fp); //��fp��ָ����ļ�һ�����ݶ���strLine������
								// printf(strLine);
	}
	fclose(fp);
	printf("���������룺");
	while (1)
	{
		scanf("%s", ps);
		if (*ps == *strLine)
			break;
		else
		{
			printf("���������룺");
			continue;
		}
	}

	Node head;
	// = (Node *)malloc(LEN);
	printf("\t\t\t*****************************************************************\n");
	printf("\t\t\t\t\t��ʼ���С���\n");
	printf("\t\t\t*****************************************************************\n");
	Node *info_list;
	ColNode *col_list;
	SexNode *Sex_list;
	info_list = CreateInfoList();
	col_list = CreateColList();
	Sex_list = CreateSexList();
	// extern int ColLen = readColFromFile(col_list);
	// extern int SexLen = readSexFromFile(Sex_list);

	while (1)
	{
		system("cls"); //����
		i = Menu();
		switch (i)
		{
		case 1:
			system("cls"); //����
			break;
		case 2:
			system("cls"); //����
			break;
		case 3:
			system("cls"); //����
			break;
		case 4:
			system("cls"); //����
			printf("\n\n\n");
			// insetNode(info_list,col_list,Sex_list);
			break;
		case 5:
			system("cls"); //����
			printf("\n\n\n");
			break;
		case 6:
			system("cls"); //����
			printf("\n\n\n");
			break;
		case 7:
			system("cls"); //����
			printf("\n\n\n");
			break;
		case 8:
			system("cls"); //����
			printf("\n\n\n");
			printf("\t\t\t��������:\n");
			UpdataPW();
			printf("\n\n\n");
			break;
		case 9:
			system("cls"); //����
			printf("\n\n\n");
			break;
		case 0:
			system("cls"); //����
			// TODO: ������һ���˵�
			return 0;
		default:
			system("cls"); //����
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput error!\n");
			printf("\t\t\t******************************************************************************\n");
		}
	}

	return 0;
}
// �����˵�
int Menu(void)
{
	int i;
	printf("\n\n");
	printf("\t\t\t                         ѧ���ɼ�����ϵͳ\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t*                Management for Students' scores\n");
	printf("\t\t\t*                1.  �������������\n");
	printf("\t\t\t*                2.  ��ƽ���ɼ��������\n");
	printf("\t\t\t*                3.  �������ѧԺѧ��\n");
	printf("\t\t\t*                4.  ���ѧ������ɼ�\n");
	printf("\t\t\t*                5.  �޸ĸ���ѧ���ɼ���Ϣ\n");
	printf("\t\t\t*                6.  ��������ѯѧ�������\n");
	printf("\t\t\t*                7.  ɾ��ѧ���ɼ�\n");
	printf("\t\t\t*                8.  �޸�ϵͳ����\n");
	printf("\t\t\t*                9.  ����ҿ�ѧ����Ϣ��ǿ����ҵ��Ŀ�Ŀ\n");
	printf("\t\t\t*                0.  ������һ���˵�\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************����ѡ��:");
	scanf("%d", &i);
	return i;
}