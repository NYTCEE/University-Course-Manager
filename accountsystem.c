#include "accountsystem.h"

int cheak(char ac[], char ps[])
{
    int sizea,sizeb;
    sizea=strlen(ac);
    sizeb=strlen(ps);
    for(int i=0;i<datanumber;i++)
    {
        if(sizea==strlen(data[i].account)&&strncmp(ac,data[i].account,sizea)==0)
        {
            if(sizeb==strlen(data[i].password)&&strncmp(ps,data[i].password,sizeb)==0)
            {
                loginindex=i;
                return 1;
            }
        }
    }
    return 0;
}

int cheaknumber(int nummber)
{
    for(int i=0;i<datanumber;i++)
    {
        if(data[i].classnumber==nummber)
        {
            system(cle);
            printf("學號已存在\n");
            return 1;
        }
    }
    return 0;
}

void CreatHelpAccount() //帳號系統
{
    int classnumber,sex,ts;
    int bir[3];
    char account[20],password[20],name[20];
    char in,c;
    do
    {
        printf("1.帳號創建\n2.帳號救援\n3.回到主畫面\n");
        printf("請輸入數字選擇:");
        scanf(" %c",&in);
        switch(in)
        {
        case '1':
            system(cle);
            printf("您已選擇:1.帳號創建\n");
            printf("請輸入帳號:\n");
            scanf("%s",account);
            system(cle);
            printf("請輸入密碼:\n");
            scanf("%s",password);
            system(cle);
            printf("請輸入姓名:\n");
            scanf("%s",name);
            system(cle);
            do
            {
                printf("請輸入學號:\n");
                scanf("%d",&classnumber);
            }while(cheaknumber(classnumber));

            system(cle);
            do
            {
                printf("請輸入生日年(YYYY):\n");
                scanf("%d",&bir[0]);
                system(cle);
            }while(bir[0]<0||bir[0]>2023);

            do
            {
                printf("請輸入生日月(MM):\n");
                scanf("%d",&bir[1]);
                system(cle);
            }while(bir[1]<0||bir[1]>12);

            do
            {
                printf("請輸入生日日(DD):\n");
                scanf("%d",&bir[2]);
                system(cle);
            }while(bir[2]<0||bir[2]>31);
            
            do
            {
                printf("請輸入性別(1為男 2為女):\n");
                scanf("%d",&sex);
                system(cle);
            }while(sex!=1&&sex!=2);

            sex=sex==1?0:1;
            do
            {
                printf("請問您的身份是(1為教師 2為學生):\n");
                scanf("%d",&ts);
                system(cle);
            }while(ts!=1&&ts!=2);
            ts=ts==1?0:1;
            printf("帳號:%s\n",account);
            printf("密碼:%s\n",password);
            printf("姓名:%s\n",name);
            printf("學號:%d\n",classnumber);
            printf("生日:%d年%d月%d日\n性別:",bir[0],bir[1],bir[2]);
            printf(sex==0?"男\n":"女\n");
            printf(ts==0?"身分:教師\n":"身分:學生\n");
            printf("以上資料是否正確(回答y確認)?");
            scanf(" %c",&c);
            if(c!='y'&&c!='Y')
                break;
            system(cle);
            strcpy(data[datanumber].account,account);
            strcpy(data[datanumber].password,password);
            strcpy(data[datanumber].name,name);
            data[datanumber].classnumber=classnumber;
            for(int i=0;i<3;i++)
                data[datanumber].bir[i]=bir[i];
            data[datanumber].sex=sex;
            data[datanumber].ts=ts;
            data[datanumber].selnumber=0;
            datanumber++;
            printf("儲存成功\n");
            wuserfile();
            ruserfile();
            break;
        case '2':
            system(cle);
            printf("您已選擇:2.帳號救援\n");
            helpaccount();
            break;
        case '3':
            system(cle);
            break;
        default:
            printf("請重新輸入\n");
        }
    }while(in>'3'||in<'1');
}

void helpaccount()  //帳號問題
{
    char in;
    char na[20];
    int bir[3];
    do
    {
        printf("請問您是\n1.忘記帳號\n2.忘記密碼\n3.回到主畫面\n");
        printf("請輸入數字選擇:");
        scanf(" %c",&in);
        switch(in)
        {
            case '1':
                system(cle);
                printf("您已選擇:1.忘記帳號\n");
                printf("請輸入姓名:");
                scanf("%s",na);
                printf("請輸入生日年(YYYY):\n");
                scanf("%d",&bir[0]);
                printf("請輸入生日月(MM):\n");
                scanf("%d",&bir[1]);
                printf("請輸入生日日(DD):\n");
                scanf("%d",&bir[2]);
                for(int i=0;i<datanumber;i++)
                {
                    if(strcmp(data[i].name,na)==0&&data[i].bir[0]==bir[0]&&data[i].bir[1]==bir[1]&&data[i].bir[2]==bir[2])
                    {
                        system(cle);
                        printf("您的帳號為:%s\n",data[i].account);
                        return;
                    }
                }
                system(cle);
                printf("查無資料\n");
                break;
            case '2':
                system(cle);
                printf("您已選擇:2.忘記密碼\n");
                printf("請輸入帳號:");
                scanf("%s",na);
                printf("請輸入生日年(YYYY):\n");
                scanf("%d",&bir[0]);
                printf("請輸入生日月(MM):\n");
                scanf("%d",&bir[1]);
                printf("請輸入生日日(DD):\n");
                scanf("%d",&bir[2]);
                for(int i=0;i<datanumber;i++)
                {
                    if(strcmp(data[i].account,na)==0&&data[i].bir[0]==bir[0]&&data[i].bir[1]==bir[1]&&data[i].bir[2]==bir[2])
                    {
                        system(cle);
                        printf("您的密碼為:%s\n",data[i].password);
                        return;
                    }
                }
                system(cle);
                printf("查無資料\n");
                break;
            case '3':
                system(cle);
                break;
            default:
                printf("請重新輸入\n");
        }
    }while(in<'1'||in>'3');
}

void login()
{
    char in;
    char account[20],password[20],name[20];
    do
    {
        printf("請選擇您想使用的服務:\n1.帳號登入\n2.帳號創建/帳號救援\n3.回到主畫面\n");
        printf("請輸入數字選擇:");
        scanf(" %c",&in);
        switch(in)
        {
            case '1':
                system(cle);
                printf("您已選擇:1.帳號登入\n");
                printf("請輸入帳號(創建帳號請至帳號系統):");
                scanf("%s",account);
                printf("請輸入密碼:");
                scanf("%s",password);
                system(cle);
                int result=cheak(account,password);
                printf(result==1?"登入成功\n":"登入失敗\n");
                if(result==0)
                    break;
                if(data[loginindex].ts)      //0教師 1學生
                {
                    printf("您的身份為:學生\n");
                    student();
                }
                else
                {
                    printf("您的身份為:教師\n");
                    teacher();
                }
                break;
            case '2':
                system(cle);
                printf("您已選擇:2.帳號創建/帳號救援\n");
                CreatHelpAccount();
                break;
            case '3':
                system(cle);
                break;
            default:
                printf("請重新輸入\n");
        }
    }while(in<'1'||in>'3');
}
