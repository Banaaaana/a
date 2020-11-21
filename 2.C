#include <stdio.h>
#include <string.h>

#define MAXSIZE 20 // 最多能存储的学生人数
#define ERROR 0
#define OK 1

//定义一个学生类型
typedef struct student {
    char no[10];   //学号
    char name[20]; //姓名
    int score;     //分数
} STU;

//定义一个学生信息的顺序线性表
typedef struct {
    STU data[MAXSIZE]; //存储学生信息
    int length;        //表示学生当前人数即线性表的长度
} SqList;

void SqInit(SqList *s) { s->length = 0; } //初始化顺序表

//输入函数
void prin(SqList *s, int n);
//输出函数
void output(SqList *s, int n);
//按内容查找函数
void Locate(SqList *s, int n);
//按序号查找函数
void search(SqList *s, int n);
//插入函数
int Insert(SqList *s, int n);
//删除函数
int Delete(SqList *s, int n);
//统计函数
void Statistics(SqList *s, int n);
//清空缓存区
void empty();

//主函数
int main() {
    SqList std;
    int a;
    int exit = 0;
    while (exit != 1) {
        printf("--------------------------功能界面--------------------------\n");
        printf("1.添加学生\t2.显示学生表\t3.按姓名查找学生\t4.按序号查找学生\n");
        printf("5.插入学生\t6.删除学生信息\t7.统计学生人数\t\t8.退出\n");
        printf("------------------------------------------------------------\n");
        scanf("%d", &a);

        switch (a) {
        case 1:
            printf("请输入学生人数:");
            scanf("%d", &std.length);
            prin(&std, std.length);
            break;
        case 2:
            output(&std, std.length);
            break;
        case 3:
            Locate(&std, std.length);
            break;
        case 4:
            search(&std, std.length);
            break;
        case 5:
            if (Insert(&std, std.length)) {
                printf("----插入成功----\n");
                std.length += 1;
            }
            break;
        case 6:
            if (Delete(&std, std.length)) {
                printf("----删除成功----\n");
                std.length -= 1;
            }
            break;
        case 7:
            Statistics(&std, std.length);
            break;
        case 8:
            exit = 1;
            break;
        default:
            printf("----输入错误----\n");
            break;
        }
        empty();
    }
    printf("----------------------\n");
    printf("^_^ 感谢使用学生表 ^_^\n");
    printf("----------------------\n");
    return 0;
}

//输入函数
void prin(SqList *s, int n) {
    int i;
    printf("请分别输入每个学生的信息:\n");
    for (i = 0; i < n; i++) {
        printf("学号:");
        scanf("%s", s->data[i].no);
        printf("姓名:");
        scanf("%s", s->data[i].name);
        printf("成绩:");
        scanf("%d", &s->data[i].score);
        printf("----------------------------------\n");
    }
}

//输出函数
void output(SqList *s, int n) {
    int i;

    printf("------学生表------\n");
    printf("学号\t姓名\t成绩\n");
    for (i = 0; i < n; i++)
        printf("%s\t%s\t%d\n", s->data[i].no, s->data[i].name, s->data[i].score);
}

//按内容查找函数
void Locate(SqList *s, int n) {
    int i;
    char student_name[20];

    printf("请输入想要查找学生的姓名：");
    scanf("%s", student_name);

    for (i = 0; i < n; i++)
        if (strcmp(student_name, s->data[i].name) == 0) //比较
            break;
    if (i < n) {
        printf("----学生信息如下----\n");
        printf("学号\t姓名\t成绩\n");
        printf("%s\t%s\t%d\n", s->data[i].no, s->data[i].name, s->data[i].score);
    } else
        printf("----未找到此学生信息----\n");
}

//按序号查找函数
void search(SqList *s, int n) {
    int i;

    printf("请输入想要查找学生表序号：");
    scanf("%d", &i);

    if (i <= n) {
        printf("----学生信息如下----\n");
        printf("学号\t姓名\t成绩\n");
        printf("%s\t%s\t%d\n", s->data[i - 1].no, s->data[i - 1].name, s->data[i - 1].score); //数组从 0 开始
    } else
        printf("----未找到该序号----\n");
}

//插入函数
int Insert(SqList *s, int n) {
    int i, k;

    printf("输入你想要插入的位置：");
    scanf("%d", &k);

    if (k < 1 || k > s->length + 1) {
        printf("---插入位置不合法---\n");
        return (ERROR);
    }
    if (s->length >= MAXSIZE - 1) {
        printf("----学生表已满----\n");
    }
    for (i = s->length; i >= k - 1; i--) {
        strcpy(s->data[i + 1].no, s->data[i].no);
        strcpy(s->data[i + 1].name, s->data[i].name);
        s->data[i + 1].score = s->data[i].score;
    }
    printf("输入新学生信息：\n");
    printf("学号：");
    scanf("%s", s->data[k - 1].no);
    printf("姓名：");
    scanf("%s", s->data[k - 1].name);
    printf("成绩：");
    scanf("%d", &s->data[k - 1].score);

    return (OK);
}

int Delete(SqList *s, int n) {
    int i, k;

    printf("输入你想要删除的位置：");
    scanf("%d", &k);

    if (k < 1 || k >= s->length + 1) {
        printf("---删除位置不合法---\n");
        return (ERROR);
    }
    for (i = k; i <= s->length; i++) {
        strcpy(s->data[i - 1].no, s->data[i].no);
        strcpy(s->data[i - 1].name, s->data[i].name);
        s->data[i - 1].score = s->data[i].score;
    }
    return (OK);
}

//统计函数
void Statistics(SqList *s, int n) { printf("---当前共有%d名学生---\n", s->length); }

//清空缓存区
void empty() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}
