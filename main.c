#include "main.h"

/*
主題一：大學課程系統

功能要求：
1.需具備教師開課系統：讓老師填入何時願意開課、開設何種課程、是否指定教室....etc.
2.需具備自動排課系統：依照老師填入的開課意願，自動產生一學期的課程
3.需具備學生加退選系統：讓學生可以加選或退選，請注意：必修課沒得自由加選、選修課才可以自由加退選

以上功能一定要具備，細節之處可依現實自由設計，越真實愈好。
帳密檔案內容(格式:帳號、密碼、名稱、生日、性別(0為男/1為女)、教師/學生標籤(0為教師/1為學生))最多80筆資料每項資料最多20個英文字

嗨～😅🐸🐸🐸🐸🐸🐸🐸       🐸     🐸          🐸
🐸🐸🐸🐸🐸🐸🐸🐸           🐸     🐸         🐸🐸
🐸🐸🐸🐸🐸🐸🐸              🐸     🐸        🐸  🐸
🐸🐸🐸🐸🐸                    🐸🐸🐸🐸       🐸   🐸
🐸🐸🐸🐸                       🐸     🐸      🐸🐸🐸🐸
🐸🐸🐸                          🐸     🐸     🐸       🐸
🐸🐸                             🐸     🐸    🐸         🐸
🐸
呱呱 ~
*/

char cle[10]="cls";
char build[18][35][15];
char week[7][4]={"一","二","三","四","五","六","日"};
struct datastruct data[80];
struct coursestruct course[80],ardcourse[80],coursewithoutm[80];
int datanumber=0,coursenumber=0,loginindex=0;

void classsystem()  //課程系統
{
    char in;
    printf("請選擇您想使用的服務:\n1.課表查詢\n2.課表匯出\n3.回到主畫面\n");
    do
    {
        printf("請輸入數字選擇:");
        scanf(" %c",&in);
        switch(in)
        {
        case '1':
            system(cle);
            printf("您已選擇:1.課表查詢\n");
            schedule(0);
            listcourse();
            break;
        case '2':
            system(cle);
            printf("您已選擇:2.課表匯出\n");
            scheduleout(0);
            break;
        case '3':
            system(cle);
            break;
        default:
            printf("請重新輸入\n");
        }
    }while(in>'3'||in<'1');
}

int main()
{
    ruserfile();
    rcoursefile();
    defaultbuild();
    char in='0';
    char leave;
    system(cle);
    do
    {
        
        printf("歡迎使用北科課程系統:\n1.課程系統\n2.登入系統\n3.離開系統\n");
        printf("請輸入數字選擇:");
        scanf(" %c",&in);
        switch(in)
        {
        case '1':
            system(cle);
            printf("您已選擇:1.課程系統\n");
            classsystem();
            break;
        case '2':
            system(cle);

            printf("您已選擇:2.登入系統\n");
            login();
            break;
        case '3':
            system(cle);
            printf("離開系統?(Y/N)\n");
            scanf(" %c",&leave);
            system(cle);
            if(leave=='y'||leave=='Y')
                return 0;
            break;
        default:
            system(cle);
            printf("查無此項\n");
        }
    }
    while(1);
    return 0;
}