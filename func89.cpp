#include "func89.h"

void UpdataPW()
{
    char a[20];
    printf("���������룺");
    scanf("%s", a);
    FILE *fp = fopen("pw.txt", "w");
    fprintf(fp, "%s\n", a);
    fclose(fp);
    return;
}

void FindBadBoy(Node *p)
{
    Node *pMove = p->next;
    while(pMove!=NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (pMove->data.score[i] < 60)
                printf("%s�ĳɼ�%d�����񣬳ɼ�Ϊ%d\n", pMove->data.name, i + 1, pMove->data.score[i]);
        }
        pMove = pMove->next;
    }
    return;
}
