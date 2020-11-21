#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define DATA_LENGTH_MAXNUM 20
#define MAXNUM 40

int exit0;

typedef struct BIG_STICK_HOSPITAL
{
    char name[DATA_LENGTH_MAXNUM];
    char room[DATA_LENGTH_MAXNUM];
    char grade[DATA_LENGTH_MAXNUM];
    char time[DATA_LENGTH_MAXNUM];
} doctor;

typedef struct list
{
    doctor data[MAXNUM];
    int length;
} list_type;

int main()
{
    list_type list;
    int temp, temp1;
    start_list(&list);
    while (exit != 1)
    {
        menu(&list);
        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            printf("添加多少名医生:");
            scanf("%d", &list.length);
            create_list(&list, list.length);
            break;
        case 2:
            showlist(&list, list.length);
            break;
            /*case 3:
            Locate(&list, temp1);
            break;
        case 4:
            search(&list, temp1);
            break;
        case 5:
            if (Insert(&list, temp1)) {
                printf("----插入成功----\n");
                list->length += 1;
            }
            break;
        case 6:
            if (Delete(&list, temp1)) {
                printf("----删除成功----\n");
                list->length -= 1;
            }
            break;
        case 7:
            Statistics(&list, temp1);
            break;
        case 8:
            exit = 1;
            break;
        default:
            printf("----输入错误----\n");
            break;
        }
        empty();*/
            //addmember();
            //delete();
        }
    };
};

void start_list(list_type *list)
{
    list->length = 0;
};

void menu()
{
    printf("-------------------大铁棍子医院医生信息簿------------------\n");
    printf("--------------------------帮助--------------------------\n");
    printf("1.添加医生信息\t2.显示医生信息\t3.查找医生\t4.查找房间号\n");
    printf("5.插入医生信息\t6.删除医生信息\t7.统计医生人数\t\t8.退出\n");
    printf("------------------------------------------------------------\n");
};

void create_list(list_type *list, int list_length)
{
    int i;
    printf("请分别输入每位医生的信息（不要输入中文）:\n");
    for (i = 0; i < list_length; i++)
    {
        printf("姓名:");
        scanf("%s", list->data[i].name);
        printf("房间号:");
        scanf("%s", list->data[i].room);
        printf("评级:");
        scanf("%s", list->data[i].grade);
        printf("就职时间:");
        scanf("%s", list->data[i].time);
        printf("----------------------------------\n");
    }
};

void showlist(list_type *list, int list_length)
{
    int i;
    if (list->length <= 0)
    {
        printf("顺序表长度错误!\n");
        return;
    }
    printf("--------大铁棍子医院医生信息簿--------\n");
    printf("姓名\t房间号\t评级\t就职时间\n");
    for (i = 0; i < list_length; i++)
        printf("%s\t%s\t%s\t%s\n", list->data[i].name, list->data[i].room, list->data[i].grade, list->data[i].time);
};

void delete(list_type *list, int list_length)
{
    int i, flag = 0;
    char temp_name[20];
    printf("请输入想要删除的医生的姓名：");
    scanf("%s", temp_name);
    for (i = 0; i < list_length; i++)
    {
        if (strcmp(temp_name, list->data[i].name) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("----医生信息如下----\n");
        printf("姓名\t房间号\t评级\t就职时间\n");
        printf("%s\t%s\t%s\t%s\n", list->data[i].name, list->data[i].room, list->data[i].grade, list->data[i].time);
    }
    else
        printf("暂未收录该医生信息\n");
};
void addmember();
void delete (list_type *list, int list_length)
{

};

