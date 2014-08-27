#include<stdio.h>
#include<stdlib.h>
#define cE c!=EOF

FILE *fpo,*fpe,*fps;

int main()
{
    char c;
    int i,t=0;
    fpo=fopen("myfile.txt","r");
    fpe=fopen("efile.txt","w");
    if(fpo==NULL || fpe==NULL)
    {
      printf("File opening error !!!\n\n");
      exit(0);
    }
    c=fgetc(fpo);
    while(cE)
    {
        for(i=0;i<t;i++)
            fprintf(fpe,"%c",'\t');
        while(c!='{' && c!='}' && c!='\n' && cE)
        {
            fprintf(fpe,"%c",c);
            c=fgetc(fpo);
        }
        if(!(cE))
            break;
        else if(c=='\n')
        {
            c=fgetc(fpo);
            if(c!='{' && c!='}' && c!='\n')
                fprintf(fpe,"%c",'\n');

        }
        else if(c=='{')
        {
            fprintf(fpe,"%c",'\n');
            for(i=0;i<t;i++)
                fprintf(fpe,"%c",'\t');

            fprintf(fpe,"%c",c);
            fprintf(fpe,"%c",'\n');
            t++;
            c=fgetc(fpo);
            while(cE && c=='\n')
                c=fgetc(fpo);
        }
        else
        {
            t--;
            fprintf(fpe,"%c",'\n');
            for(i=0;i<t;i++)
                fprintf(fpe,"%c",'\t');
            fprintf(fpe,"%c%c",c,'\n');
            c=fgetc(fpo);
            while(cE && c=='\n')
                c=fgetc(fpo);
        }
    }
    printf("Operation Succesfull");
    return 0;
}
