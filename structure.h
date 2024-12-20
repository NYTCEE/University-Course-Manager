#ifndef _STRUCTURE_H
#define _STRUCTURE_H

struct datastruct
{
    char account[20];
    char password[20];
    char name[20];
    int bir[3];
    int classnumber;
    int sex;
    int ts;
    int selnumber;
    int selindex[40];   //選擇/開課的課程index
};

struct coursestruct
{
    char name[20];
    char teachername[20];
    int time[2];    //0:星期 1:節
    int room[2];    //0:建築 1:教室
    int sele,max,index; //選修必修 人數上限(最多100人) 索引(for課表)
};

extern struct coursestruct course[80],ardcourse[80],coursewithoutm[80];
extern struct datastruct data[80];
extern int datanumber,coursenumber,loginindex;
extern char filename[2][16];
extern char cle[10];
extern char week[7][4];
extern char build[18][35][15];
extern char type[5][15];

#endif
