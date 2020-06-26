#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    //int i;
    char *pCh;
    char key;
    FILE *fp;
    
    if(argc == 3)
    {
        /*
        printf("argc = %d\n",argc);
        for(i=0;i<argc;i++)
            printf("argv[%d]:%s\n",i,argv[i]);
        */
        if(!strcmp(argv[1],"-o"))
        {
            fp = fopen(argv[2],"rb");
            if(!fp)
            {
                printf("failed!\n");
                return 0;
            }
            
            fseek(fp,-1,SEEK_END);
            
            key = fgetc(fp);
            key = key ^ 'a';
            
            fclose(fp);
            printf("key is %c\n",key);
        }
        else
        {
            printf("input wrongful!\n");
            return 0;
        }
    }
    else if(argc == 4)
    {
        /*
        printf("argc = %d\n",argc);
        for(i=0;i<argc;i++)
            printf("argv[%d]:%s\n",i,argv[i]);
        */
        if(!strcmp(argv[1],"-i"))
        {
            pCh = argv[2];
            if(*pCh != '@')
            {
                printf("input wrongful!\n");
                return 0;
            }
            else
            {
                fp = fopen(argv[3],"ab");
                if(!fp)
                {
                    printf("failed!\n");
                    return 0;
                }
                
                pCh = argv[2];
                pCh++;
                key = *pCh;
                key = key ^ 'a';
                //printf("key is %c.\n",key);
                
                fputc(key,fp);
                
                fclose(fp);
                printf("ok!\n");
                
                }
        }
        else
        {
            printf("input wrongful!\n");
            return 0;
        }
    }
    else
    {
        printf("input wrongful!\n");
        return 0;
    }
    
    return 0;
}
