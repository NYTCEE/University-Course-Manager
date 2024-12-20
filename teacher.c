#include "teacher.h"

void creatclass()
{
    char doublecheck=1;
    do
    {
        int week,time,class,cer,sele,max;
        int *room;
        char name[20];

        printf("請輸入課程名稱:\n");
        scanf("%s",name);
        system(cle);
        printf("請輸入此門課為星期幾的課程?(1~7):\n");
        scanf("%d",&week);
        while(week<1||week>7)
        {
            printf("輸入錯誤,請重新輸入:");
            scanf("%d",&week);
        }
        system(cle);
        printf("請輸入開課時間？(1~9):\n");
        scanf("%d",&time);
        while(time<1||time>9){
            printf("輸入錯誤,請重新輸入:");
            scanf("%d",&time);
        }
        system(cle);
        printf("請輸入最大授課人數？(max:100):\n");
        scanf("%d",&max);
        while(max<1||max>100){
            printf("輸入錯誤,請重新輸入:");
            scanf("%d",&max);
        }
        system(cle);
        printf("請問此課程是否指定教室?\n1.是 2.否\n");
        scanf("%d",&cer);
        while(cer!=1&&cer!=2)
        {
            printf("輸入錯誤,請重新輸入:\n1.是 2.否\n");
            scanf("%d",&cer);
        }
        system(cle);
        selectroom(cer,room);

        printf("請問此堂課為必修或選修課程?\n1.必修課程 2.選修課程\n");
        scanf("%d",&sele);
        while(sele!=1&&sele!=2) //1.必 2.選
        {
            printf("輸入錯誤,請重新輸入:\n1.必修課程2.選修課程\n");
            scanf("%d",&sele);
        }
        system(cle);
        printf("請再次確認以下您所輸入的課程名稱是否正確:\n");
        printf("課程名稱:%s\n",name);
        printf("授課老師:%s\n",data[loginindex].name);
        printf("開課時間:星期%d",week);
        printf("第%d節課\n",time);
        printf("最大授課人數:%d\n",max);
        printf("教室:%s%s",build[*room-1][0],build[*room-1][*(room+1)]);
        printf(sele==2?"選修課程\n":"必修課程\n");

        printf("資料是否正確Y/N\n");
        scanf(" %c",&doublecheck);
        if(doublecheck=='y'||doublecheck=='Y')
        {
            strcpy(course[coursenumber].name,name); //課程名稱
            strcpy(course[coursenumber].teachername,data[loginindex].name); //教師名字
            course[coursenumber].room[0]=class;
            course[coursenumber].room[1]=class;
            course[coursenumber].sele=sele;
            if(sele==1)
            {
                for(int i=0;i<datanumber;i++)
                {
                    if(data[i].ts==1&&data[i].selnumber!=0)
                    {
                        data[i].selindex[data[i].selnumber]=coursenumber;
                        data[i].selnumber++;
                    }
                }
            }
            course[coursenumber].max=max;
            course[coursenumber].time[0]=week;
            course[coursenumber].time[1]=time;
            course[coursenumber].index=coursenumber;
            course[coursenumber].room[0]=*room;
            course[coursenumber].room[1]=*(room+1);
            data[loginindex].selindex[data[loginindex].selnumber]=coursenumber;     //開課紀錄
            coursenumber++;
            data[loginindex].selnumber++;
            wuserfile();
            wcoursefile();
            system(cle);
            printf("儲存成功\n");
        }
        else
        {
            doublecheck=1;
            printf("是否要重新輸入Y/N");
            scanf(" %c",&doublecheck);
            if(doublecheck=='y'||doublecheck=='Y')
            {
                doublecheck=1;
            }
            system(cle);
        }

    }while(doublecheck==1);
}

int selectroom(int cer,int room[2])
{
    int i,j;
    srand(time(NULL));
    if(cer==1)
    {
        do
        {
            for(i=0;i<18;i++)
                printf("%d.%s\n",i+1,build[i][0]);
            printf("請選擇欲使用教室的大樓:");
            scanf("%d",&room[0]);
            system(cle);
        }while(1>room[0]||room[0]>18);
		i=1;
		while(strlen(build[room[0]-1][i])>1)
		{
			printf("%d.%s\n",i,build[room[0]-1][i]);
			++i;
		}
        do
        {
            printf("請選擇欲使用的教室:");
            scanf("%d",&room[1]);
            system(cle);
        }while(0>=room[1]||room[1]>=i);
		printf("你已選擇:%s%s教室\n",build[room[0]-1][0],build[room[0]-1][room[1]]);
    }
    else
    {
        system(cle);
        room[0]=rand()%18;
		i=1;
		while(strlen(build[room[0]-1][i])>1)
			++i;
        room[1]=rand()%(i-1);
        printf("電腦排定為:*%s%s*教室\n",build[room[0]-1][0],build[room[0]-1][room[1]]);
    }
}

void teacher()
{
    char in;
    char leave;
    do
    {
        printf("請選擇您想使用的服務:\n1.課表查詢\n2.開課系統\n3.課表匯出\n4.帳號刪除\n5.登出\n");
        printf("請輸入數字選擇:");
        scanf(" %c",&in);
        switch(in)
        {
        case '1':
            system(cle);
            printf("您已選擇:1.課表查詢\n");
            schedule(1);
            listcourse();
            break;
        case '2':
            system(cle);
            printf("您已選擇:2.開課系統\n");
            creatclass();
            break;
        case '3':
            system(cle);
            printf("您已選擇:3.課表匯出\n");
            scheduleout(1);
            break;
        case '4':
            system(cle);
            printf("您已選擇:4.帳號刪除\n");
            printf("確定要刪除?(Y/N)\n");
            scanf(" %c",&leave);
            system(cle);
            if(leave=='y'||leave=='Y')
            {
                char account[20],password[20],name[20];
                printf("請輸入帳號:");
                scanf("%s",account);
                printf("請輸入密碼:");
                scanf("%s",password);
                printf("請輸入姓名:");
                scanf("%s",name);
                if(strcmp(account,data[loginindex].account)==0&&strcmp(password,data[loginindex].password)==0&&strcmp(name,data[loginindex].name)==0)
                {
                    for(int i=loginindex;i<datanumber;i++)
                    {
                        if(i!=datanumber)
                            data[i]=data[i+1];
                    }
                    datanumber--;
                    system(cle);
                    printf("帳號已刪除\n");
                    wuserfile();
                    return;
                }
                else
                {
                    printf("問題輸入錯誤，帳號刪除失敗\n");
                }
            }
                
            break;
        case '5':
            system(cle);
            printf("登出?(Y/N)\n");
            scanf(" %c",&leave);
            system(cle);
            if(leave=='y'||leave=='Y')
                return;
            break;
        default:
            system(cle);
            printf("查無此項\n");
        }
    }while(1);
}
