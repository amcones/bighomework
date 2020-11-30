#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct student{
    char num[9];
    char name[20];
    char sex;
    double shuxue;
    double wuli;
    double c;
    double pjcj;
    double zcj;
}STUDENT;

STUDENT* open(STUDENT* head)
{
    FILE *fp;
    char ch;
    //文件以追加的方式打开，并判断是否成功
    if( (fp=fopen("student.txt","a+")) == NULL ){
        printf("无法打开文件，按任意键退出！\n");
        getchar();
        exit(1);
    }
    //printf("Input a string:\n");
    //每次从键盘读取一个字符并写入文件
    getchar();
    while ( (ch=getchar()) != '\n' ){
        fputc(ch,fp);
    }
    fclose(fp);
}

STUDENT* creat(STUDENT* head)//调用open函数，打开文件，读入已有学生信息，继续输入学生信息；若文件不存在，输入学生信息。
{
    open(head);
}
STUDENT* del(STUDENT* head)//删除函数（模块）：通过学号(或姓名)删除学生的信息及成绩。
{

}

void paint()
{
    int i;
    printf("                           长沙理工大学学生\n");
    printf("                             成绩管理系统   \n");
    for (i = 0; i < 80; i++)
        putchar('+');
    putchar('\n');
    printf("             1 输入学生信息                     2 排序 \n");
    printf("             3 浏览学生信息                     4 查找学生信息\n");
    printf("             5 按学号顺序插入                   6 删除学生信息\n");
    printf("             7 按平均分输出统计信息              8 保存到文件\n");
    printf("             0 退出\n");
    for (i = 0; i<= 79; i++)
        putchar('+');
    putchar('\n');
    printf(" 请输入各操作对应的序号:\n");
}

int main()
{
    STUDENT *head;
    int len=0;
    char ctrl_ch;
    paint();
    scanf("%c",&ctrl_ch);
    while(ctrl_ch!='0'){
        switch(ctrl_ch){
            case'1':
                creat(head);
                break;
            case'6':
                del(head);
                break;
            default:
                if(ctrl_ch!='\n')printf("%s\n","输入错误！");
                break;
        }
        if(ctrl_ch!='\n')paint();
        scanf("%c",&ctrl_ch);
    }
    return 0;
}