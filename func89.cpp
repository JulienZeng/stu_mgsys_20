#include "func89.h"

// �޸�����
void UpdataPW()
{
    char a[20];
    scanf("%s",a);
    FILE *fp = fopen("ps.txt", "w");
    fprintf(fp,"%s\n",a);	
    fclose(fp);
    return;
}
