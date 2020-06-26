/*linux 下的加密小工具*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME_SIZE 100

int main(int argc,char *argv[])
{
    int i;
    int flag = 0;
    int num;
    char *pCh,*qCh;
    char *buf;
    char key;
    FILE *fp_in,*fp_out;
    char filename[FILE_NAME_SIZE];
    /*printf("argc=%d\n",argc);
    
    for(i=0;i<argc;i++)
        printf("argv[%d]:%s\n",i,argv[i]);
    */
    
    if(argc != 4)
    {
        printf("input wrongful!\n");
        return 0;
    }
    
    pCh = argv[2];
    //printf("%c\n",*pCh);
    if(*pCh != '@')
    {
      printf("input wrongful\n");
      return 0;
    }
    pCh++;
    key = *pCh;
    pCh = NULL;
    //printf("%c\n",key);
    
    if(!strcmp(argv[1],"-e"))
    {
        //printf("jiami!\n");
        pCh = argv[3];
        while(*pCh != '\0')
        {
            if(*pCh == '.')
            {
                flag = 1;
                break;
            }
            pCh++;
        }
        
        pCh = argv[3];
        qCh = filename;
        if(flag == 1)
        {
            while(*pCh != '.')
            {
                *qCh = *pCh;
                pCh++;
                qCh++;
            }
            /*
            *qCh = 'x';
            qCh++;
            *qCh = key;
            qCh++;
            */
            *qCh = *pCh;
            pCh++;
            qCh++;
            *qCh = 'x';
            qCh++;
            
            while(*pCh != '\0')
            {
                *qCh = *pCh;
                pCh++;
                qCh++;
            }
            *qCh = '\0';
        }
        else
        {
            while(*pCh != '\0')
            {
                *qCh = *pCh;
                pCh++;
                qCh++;
            }
            *qCh = '_';
            qCh++;
            *qCh = 'x';
            qCh++;
            /*
            *qCh = key;
            qCh++;
            */
            *qCh = '\0';
            qCh = NULL;
            pCh = NULL;
        }
        
        //printf("%d\n",flag);
    }
    else if(!strcmp(argv[1],"-d"))
    {
        //printf("jiemi!\n");
        pCh = argv[3];
        while(*pCh != '\0')
        {
            if(*pCh == '.')
            {
                flag = 1;
                break;
            }
            pCh++;
        }
        
        pCh = argv[3];
        qCh = filename;
        if(flag == 1)
        {
            while(*pCh != '.')
            {
                *qCh = *pCh;
                pCh++;
                qCh++;
            }
            *qCh = *pCh;
            pCh++;
            qCh++;
            pCh++;
            while(*pCh != '\0')
            {
                *qCh = *pCh;
                pCh++;
                qCh++;
            }
            *qCh = '\0';
            pCh = NULL;
            qCh = NULL;
        }
        else
        {
            while(*pCh != '_')
            {
                *qCh = *pCh;
                qCh++;
                pCh++;
            }
            *qCh = '\0';
            pCh = NULL;
            qCh = NULL;
        }
    }
    else
    {
        printf("input wrong!\n");
    }
    
    buf = (char*)malloc(sizeof(char));
    if(!buf)
    {
        printf("failed!\n");
        exit(-1);
    }
    
    fp_in = fopen(argv[3],"rb");
    if(!fp_in)
    {
        printf("failed!\n");
        exit(-1);
    }
    fp_out = fopen(filename,"wb");
    if(!fp_out)
    {
        printf("failed!\n");
        exit(-1);
    }
    
    printf("please wait ...\n");
    
    while(!feof(fp_in))
    {
        num = fread(buf,sizeof(char),1,fp_in);
        *buf = *buf ^ key;
        fwrite(buf,sizeof(char),num,fp_out);
    }
    
    fclose(fp_in);
    fclose(fp_out);
    
    //printf("%s\n",filename);
    printf("finished!\n");
    
    return 0;
}
