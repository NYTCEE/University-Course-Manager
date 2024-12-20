#include "filerw.h"

void ruserfile()
{
    FILE *fp;
    if((fp=fopen("userdata.b","rb"))==NULL)
    {
        fclose(fp);
        fp=fopen("userdata.b","wb");
        fwrite(&datanumber,sizeof(int),1,fp);
        fwrite(data,sizeof(struct datastruct),80,fp);
        fclose(fp);
    }
    else
    {
        fread(&datanumber,sizeof(int),1,fp);
        fread(data,sizeof(struct datastruct),80,fp);
        fclose(fp);
    }
}

void wuserfile()
{
    FILE *fp=fopen("userdata.b","wb");
    fwrite(&datanumber,sizeof(int),1,fp);
    fwrite(data,sizeof(struct datastruct),80,fp);
    fclose(fp);
}

void rcoursefile()
{
    FILE *fp;
    if((fp=fopen("course.b","rb"))==NULL)
    {
        fclose(fp);
        fp=fopen("course.b","wb");
        fwrite(&coursenumber,sizeof(int),1,fp);
        fwrite(course,sizeof(struct coursestruct),80,fp);
        fclose(fp);
    }
    else
    {
        fread(&coursenumber,sizeof(int),1,fp);
        fread(course,sizeof(struct coursestruct),80,fp);
        fclose(fp);
    }
}

void wcoursefile()
{
    FILE *fp=fopen("course.b","wb");
    fwrite(&coursenumber,sizeof(int),1,fp);
    fwrite(course,sizeof(struct coursestruct),80,fp);
    fclose(fp);
}

void defaultbuild()
{
    FILE *fp;
    fp=fopen("class.b","rb");
    fread(build,sizeof(build),1,fp);
    fclose(fp);
}