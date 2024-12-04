#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int data;
    char name[50];
    char course[50];
};

int main()
{
    FILE *fp;
    fp = fopen("abc.txt", "r+");
    int value;
    fscanf(fp, "%d", &value);

    printf("value is : %d \n", value);

    struct student *st = (struct student *)malloc(value * sizeof(struct student));

    for (int i = 0; i < value; i++)
    {
        fscanf(fp, "%d %s %s", &((*(st + i)).data), (*(st + i)).name, (*(st + i)).course);
        printf("%d %s %s\n", (st[i].data), st[i].name, st[i].course);
    }

    char buffer[30];
    fscanf(fp, "%s", buffer);
    printf("%s ", buffer);

    fgets(buffer, 30, fp);
    printf("%s ", buffer);

    fscanf(fp, "%s", buffer);
    printf("%s ", buffer);

    fgets(buffer, 30, fp);
    printf("%s ", buffer);

    // SEEK_SET = 0,SEEK_CUR = 1,SEEK_END = 2

    fseek(fp, 0, SEEK_SET);

    fgets(buffer, 30, fp);
    printf("%s ", buffer);

    fclose(fp);
    return 0;
}