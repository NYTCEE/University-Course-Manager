#include "student.h"

void adddrop()
{
	char s;
    if(!(data[loginindex].selnumber>0))
    {
        printf("※系統會將必修課自動添加至課表中\n");
        for(int i=0;i<coursenumber;i++)
        {
            if(course[i].sele==1)
            {
                data[loginindex].selindex[data[loginindex].selnumber]=course[i].index;
                data[loginindex].selnumber++;
                wcoursefile();
                wuserfile();
            }
        }
    }
    
	printf("請選擇:\n1.加選 2.退選\n");
	scanf(" %c",&s);
    system(cle);
	switch(s)
	{
		case '1':
            if(data[loginindex].selnumber==0)
                printf("您尚未選擇課程\n");
            else
            {
                printf("您已選擇了:\n");
                int c=0;
                for(int i=0;i<data[loginindex].selnumber;i++)
                {
                    printf("%d.",i+1);
                    printf("課程名稱:%s\t",course[data[loginindex].selindex[i]].name);
                    printf("授課老師:%s\t",course[data[loginindex].selindex[i]].teachername);
                    printf("時間:星期%s\t",week[course[data[loginindex].selindex[i]].time[0]-1]);
                    printf("第%d節\t",course[data[loginindex].selindex[i]].time[1]);
                    printf("上課教室:%s",build[course[data[loginindex].selindex[i]].room[0]-1][0]);
                    printf("%s\t",build[course[data[loginindex].selindex[i]].room[0]-1][course[data[loginindex].selindex[i]].room[1]]);
                    printf("人數限制:%d\t",course[data[loginindex].selindex[i]].max);
                    printf(course[data[loginindex].selindex[i]].sele==1?"必修課\n":"選修課\n");
                    
                }
            }
            printf("\n-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
			printf("可選課程:\n");
            arrangecourse();
            int m=listcoursewithoutm();
            do
            {
                printf("請輸入課程數字或輸入0取消:");
                scanf("%d",&s);
            }while(s<0||s>m);
            system(cle);
            if(s==0)
            {
                printf("您已取消選課\n");
            }
            else
            {
                for(int i=0;i<data[loginindex].selnumber;i++)
                {
                    if(data[loginindex].selindex[i]==coursewithoutm[s-1].index)
                    {
                        printf("您已選擇過該課程\n");
                        return;
                    }
                }
                printf("您已選擇課程:%s\n",coursewithoutm[s-1].name);
                data[loginindex].selindex[data[loginindex].selnumber]=coursewithoutm[s-1].index;
                data[loginindex].selnumber++;
                wcoursefile();
                wuserfile();
            }
			break;


		case '2':
			if(data[loginindex].selnumber==0)
                printf("您尚未選擇課程\n");
            else
            {
                printf("您已選擇了:\n");
                int c=0;
                for(int i=0;i<data[loginindex].selnumber;i++)
                {
                    printf("%d.",i+1);
                    printf("課程名稱:%s\t",course[data[loginindex].selindex[i]].name);
                    printf("授課老師:%s\t",course[data[loginindex].selindex[i]].teachername);
                    printf("時間:星期%s\t",week[course[data[loginindex].selindex[i]].time[0]-1]);
                    printf("第%d節\t",course[data[loginindex].selindex[i]].time[1]);
                    printf("上課教室:%s",build[course[data[loginindex].selindex[i]].room[0]-1][0]);
                    printf("%s\t",build[course[data[loginindex].selindex[i]].room[0]-1][course[data[loginindex].selindex[i]].room[1]]);
                    printf("人數限制:%d\t",course[data[loginindex].selindex[i]].max);
                    printf(course[data[loginindex].selindex[i]].sele==1?"必修課\n":"選修課\n");
                    
                }
            }
            printf("\n-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
			printf("可退選課程:\n");
            int n=0,dr;
            int drop[data[loginindex].selnumber];
            for(int i=0;i<data[loginindex].selnumber;i++)
            {
                if(course[data[loginindex].selindex[i]].sele==2)
                {
                    printf("%d.",n+1);
                    printf("課程名稱:%s\t",course[data[loginindex].selindex[i]].name);
                    printf("授課老師:%s\t",course[data[loginindex].selindex[i]].teachername);
                    printf("時間:星期%s\t",week[course[data[loginindex].selindex[i]].time[0]-1]);
                    printf("第%d節\t",course[data[loginindex].selindex[i]].time[1]);
                    printf("上課教室:%s",build[course[data[loginindex].selindex[i]].room[0]-1][0]);
                    printf("%s\t",build[course[data[loginindex].selindex[i]].room[0]-1][course[data[loginindex].selindex[i]].room[1]]);
                    printf("人數限制:%d\t選修課\n",course[data[loginindex].selindex[i]].max);
                    drop[n]=i;
                    n++;
                }
            }
            do
            {
                printf("請輸入課程數字或輸入0取消:");
                scanf("%d",&dr);
            }while(dr<0||dr>n);
            system(cle);
            if(dr==0)
            {
                printf("您已取消退選\n");
            }
            else
            {
                printf("您已退選課程:%s\n",course[data[loginindex].selindex[drop[dr-1]]].name);
                for(int i=drop[dr-1];i<data[loginindex].selnumber;i++)
                {
                    if(i!=data[loginindex].selnumber)
                        data[loginindex].selindex[i]=data[loginindex].selindex[i+1];
                }
                data[loginindex].selnumber--;
                wcoursefile();
                wuserfile();
            }
			break;
	}
}

void student()
{
	char leave,in;
	do
    {
        printf("請選擇您想使用的服務:\n1.課表查詢\n2.加退選系統\n3.課表匯出\n4.帳號刪除\n5.登出\n");
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
            printf("您已選擇:2.加退選系統\n");
            adddrop();
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
