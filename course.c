#include "course.h"

void exchange(struct coursestruct list[],int a,int b)//資料對調函式
{
    struct coursestruct temp;
    temp=list[b];
    list[b]=list[a];
    list[a]=temp;
}

void arrangecourse()        //排課演算法
{
    for(int i=0;i<80;i++)
    {
        ardcourse[i]=course[i];
    }

    for(int i=0;i<coursenumber;i++)
    {
        for(int j=i+1;j<coursenumber;j++)
        {
            if(ardcourse[j].time[1]<ardcourse[i].time[1])
                exchange(ardcourse,i,j);
            if(ardcourse[j].time[1]==ardcourse[i].time[1]&&ardcourse[j].time[0]<ardcourse[i].time[0])
                exchange(ardcourse,i,j);
        }
    }
    for(int i=0;i+1<coursenumber;i++)
    {
        int k=0;
        while(ardcourse[i].time[1]==ardcourse[i+1].time[1]&&ardcourse[i].time[0]==ardcourse[i+1].time[0]&&k<coursenumber)
        {
            k++;
            int j=i+1;
            while(ardcourse[j].time[1]==ardcourse[j+1].time[1]&&j+1<coursenumber)
            {
                exchange(ardcourse,j,j+1);
                j++;
            }
        }
    }
}

void schedule(int t)    //顯示課表 t=0 匿名 1教師/學生
{
    arrangecourse();
    int c=0;

    for(int i=1;i<8;i++)
    {
        printf("\t\t星期%s",week[i-1]);
    }
    printf("\n");
    for(int i=1;i<10;i++)   //節1~9
    {
        printf("第%d節\t\t",i);
        if(ardcourse[c].time[1]==i)
        {
            while(ardcourse[c].time[1]==i)
            {
                for(int j=1;j<8;j++)    //星期1~7
                {
                    if(ardcourse[c].time[0]==j)
                    {
                        if(t==1)
                        {
                            int flag=0;
                            for(int k=0;k<data[loginindex].selnumber;k++)
                            {
                                if(data[loginindex].selindex[k]==ardcourse[c].index)
                                {
                                    flag=1;
                                    break;
                                }
                            }
                            printf(flag?"*%s*\t\t":"%s\t\t",ardcourse[c].name);
                        }
                        else
                            printf("%s\t\t",ardcourse[c].name);
                        c++;
                    }
                    else
                        printf(" \t\t");
                }
                printf("\n\t\t");
            }
        }
        printf("\n");
    }
    if(t==1)
        printf("**代表您所選/開的課程\n");
}

void scheduleout(int t)  //課表匯出
{
    char path[50];
    printf("請輸入您想儲存的檔案位置與檔名:");
    scanf("%s",path);
    strcat(path,".csv");
    FILE *fp;
    system(cle);
    if((fp=fopen(path,"w"))==0)
        printf("檔案建立失敗\n");
    else
    {
        printf("檔案建立成功\n");
        arrangecourse();
        int c=0;
        for(int i=1;i<8;i++)
        {
            fprintf(fp,",星期%s",week[i-1]);
        }
        fprintf(fp,"\n");
        for(int i=1;i<10;i++)   //節1~9
        {
            fprintf(fp,"第%d節,",i);
            if(ardcourse[c].time[1]==i)
            {
                while(ardcourse[c].time[1]==i)
                {
                    for(int j=1;j<8;j++)    //星期1~7
                    {
                        if(ardcourse[c].time[0]==j)
                        {
                            if(t==1)
                            {
                                int flag=0;
                                for(int k=0;k<data[loginindex].selnumber;k++)
                                {
                                    if(data[loginindex].selindex[k]==ardcourse[c].index)
                                    {
                                        flag=1;
                                        break;
                                    }
                                }
                                fprintf(fp,flag?"*%s*,":"%s,",ardcourse[c].name);
                            }
                            else
                                fprintf(fp,"%s,",ardcourse[c].name);
                            c++;
                        }
                        else
                            fprintf(fp,",");
                    }
                    fprintf(fp,"\n,");
                }
            }
            fprintf(fp,"\n");
        }
    }
    if(t==1)
    {
        fprintf(fp,"**代表您所選/開的課程\n");
        fprintf(fp,data[loginindex].ts==0?"教師%s":"學生%s",data[loginindex].name);
    }
    
    fclose(fp);
}

void listcourse()     //列出課程
{
    for(int i=0;i<coursenumber;i++)
    {
        printf("%d.",i+1);
        printf("課程名稱:%s\t",ardcourse[i].name);
        printf("授課老師:%s\t",ardcourse[i].teachername);
        printf("時間:星期%s\t",week[ardcourse[i].time[0]-1]);
        printf("第%d節\t",ardcourse[i].time[1]);
        printf("上課教室:%s",build[ardcourse[i].room[0]-1][0]);
        printf("%s\t",build[ardcourse[i].room[0]-1][ardcourse[i].room[1]]);
        printf("人數限制:%d\t",ardcourse[i].max);
        printf(ardcourse[i].sele==1?"必修課\n":"選修課\n");
    }
    for(int i=0;i<115;i++)
    {
        printf("-");
    }
    printf("-\n");
}

int listcoursewithoutm()     //列出課程
{
    int withoutm;
    arrangecourse();
    for(int i=0;i<coursenumber;i++)
    {
        coursewithoutm[i]=ardcourse[i];
    }
    withoutm=coursenumber;
    
    for(int i=0;i<coursenumber;i++)
    {
        while(coursewithoutm[i].sele==1)
        {
            for(int j=i;j<withoutm;j++)
            {
                if(j!=coursenumber)
                    coursewithoutm[j]=coursewithoutm[j+1];
            }
            withoutm--;
        }
    }

    for(int i=0;i<withoutm;i++)
    {
        printf("%d.",i+1);
        printf("課程名稱:%s\t",coursewithoutm[i].name);
        printf("授課老師:%s\t",coursewithoutm[i].teachername);
        printf("時間:星期%s\t",week[coursewithoutm[i].time[0]-1]);
        printf("第%d節\t",coursewithoutm[i].time[1]);
        printf("上課教室:%s",build[coursewithoutm[i].room[0]-1][0]);
        printf("%s\t",build[coursewithoutm[i].room[0]-1][coursewithoutm[i].room[1]]);
        printf("人數限制:%d\t選修課\n",coursewithoutm[i].max);
    }
    return withoutm;
}