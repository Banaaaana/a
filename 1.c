#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define DATA_LENGTH_MAXNUM 30
#define MAXNUM 40

int exit0, i_number = 0 ;

typedef struct BIG_STICK_HOSPITAL
{
    char name[DATA_LENGTH_MAXNUM];
    char room[DATA_LENGTH_MAXNUM];
    char grade[DATA_LENGTH_MAXNUM];
    char time[DATA_LENGTH_MAXNUM];
}doctor;

doctor doctor0[20]={
    {'张','a','a','a'},
    {'a','a','a','a'},
    {'a','a','a','a'},
    };

struct list
{
    doctor data[MAXNUM];
    int length;
};

int main()
{
    struct list list;
    int temp, temp1;
    start_list(&list);
    while (1)
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
        case 3:
            look_name(&list, list.length);
            printf("按任意键返回主菜单\n");
            getch();
            break;
        case 4:
            look_room(&list, list.length);
            printf("按任意键返回主菜单\n");
            getch();
            break;
        case 5:
            //if (Insert(&list, temp1)) {
            //printf("----插入成功----\n");
            //list->length += 1;
            //}
            break;
        case 6:
            delete (&list, list.length);
            break;
            /*case 7:
            Statistics(&list, temp1);
            break;*/
        case 8:
            return 0;
            break;

        default:
            break;
        }
        //addmember();
        //delete();
    };
}

void start_list(struct list *list)
{    
    list->length = 20;
    for (int i = 0; i < 20; i++)
    {
        strcpy(list->data[i].name,doctor0[i].name);
    }

};

void menu()
{
    printf("-------------------大铁棍子医院医生信息簿------------------\n");
    printf("--------------------------帮助--------------------------\n");
    printf("1.添加医生信息\t2.显示医生信息\t3.查找医生\t4.查找房间号\n");
    printf("5.插入医生信息\t6.删除医生信息\t7.统计医生人数\t\t8.退出\n");
    printf("------------------------------------------------------------\n");
};

void create_list(struct list *list, int list_length)
{
    int i;
    printf("请分别输入每位医生的信息:\n");
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
        printf("----------------\n");
    }
    printf("添加成功\n");
    printf("按任意键返回主菜单\n");
    getch();
};

void showlist(struct list *list, int list_length)
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
    printf("按任意键返回主菜单\n");
    getch();
};

int look_name(struct list *list, int list_length)
{
    int i, flag = 0;
    char temp_name[20];
    printf("请输入想要查找的医生的姓名：");
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
        i_number = i;
        return i_number;
    }
    else
        printf("暂未收录该医生信息\n");
    return 0;
};

int look_room(struct list *list, int list_length)
{
    int i, flag = 0;
    char temp_room[20];
    printf("请输入想要查找的房间号：");
    scanf("%s", temp_room);
    for (i = 0; i < list_length; i++)
    {
        if (strcmp(temp_room, list->data[i].room) == 0)
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
        i_number = i;
        return i_number;
    }
    else
        printf("暂未收录该医生信息\n");
    return 0;
};

void addmember();
void delete (struct list *list, int list_length)
{
    int i_number_conclusion, a;
    i_number_conclusion = look_name(list, list_length);
    if (i_number_conclusion != 0)
    {
        printf("输入-1来确认删除该医生的信息，输入0取消");
        scanf("%d", &a);
        if (a == -1)
        {
            int i = i_number_conclusion;
            strcpy(list->data[i].name, list->data[i + 1].name);
            strcpy(list->data[i].room, list->data[i + 1].room);
            strcpy(list->data[i].grade, list->data[i + 1].grade);
            strcpy(list->data[i].time, list->data[i + 1].time);
            list->length--;
            printf("删除成功");
            showlist(list, list->length);
            printf("按任意键返回主菜单\n");
            getch();
        }
        else
        {
            printf("按任意键返回主菜单\n");
            getch();
            return;
        }
    }
    else
    {
        printf("删除失败");
        printf("按任意键返回主菜单\n");
        getch();
    }
}