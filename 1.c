#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define DATA_LENGTH_MAXNUM 40
#define MAXNUM 40

typedef struct
{
    char name[DATA_LENGTH_MAXNUM];
    //char room[DATA_LENGTH_MAXNUM];
    //char grade[DATA_LENGTH_MAXNUM];
    //char time[DATA_LENGTH_MAXNUM];
    int length;
}list_type; 

void create_list(list_type *list)
{
    int i;
    list->length = 0;
    for (i = 0; i < MAXNUM; i++)
    {
        switch (i)
        {
        case 0:
            list->name[0] = "acv";
            /*list->room[i] = "A301";
            list->grade[i] = "主任";
            list->time[i] = "2019.6.5" ;*/
            list->length++;
            printf("89");
            break;
        default:
            break;
        }
        
    }
};

int main()
{
    list_type list;
    //menu();
    create_list(&list);
    look_through(&list);
    //addmember();
    //delete();
    printf("阿哲");
    printf("1kopkpkp");
};

void look_through(list_type *list){
printf("80");
printf("%s",list->name[0]/*,list->room[0],list->grade[0],list->time[0]*/);};
void addmember();
void delete();
