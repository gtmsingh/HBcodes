#include<stdio.h>
#include<stdlib.h>
#define small c<='z' && c>='a'
#define capital c<='Z' && c>='A'

struct arr
{
    int x;
    struct arr *next;
};
typedef struct arr nd;

nd *start,*temp,*temp2;

int main()
{
    int i,b;
    FILE *fp;
    char c,query[100];
    printf("Enter the name of the file : ");
    scanf("%s",query);
    fp=fopen(query,"r");
    if(fp<=0)
    {
        printf("File Opening error...pls check that the file is present\n");
        return -1;
    }

    start=(nd*)malloc(sizeof(nd)*26);
    for(i=0;i<26;i++)
    {
        start[i].x=0;
        start[i].next=NULL;
    }
    c=fgetc(fp);
    while(c!=EOF)
    {
        temp=start;
        while((capital || small) && c!=EOF)
        {
            if(small)
            {
                if(temp[c-'a'].x!=3)
                    temp[c-'a'].x=1;
                b=c-'a';
            }
            else
            {
                if(temp[c-'A'].x!=3)
                    temp[c-'A'].x=1;
                b=c-'A';
            }
            c=fgetc(fp);
            if(temp[b].next==NULL && (capital || small))
            {
                temp2=(nd*)malloc(sizeof(nd)*26);
                for(i=0;i<26;i++)
                {
                    temp2[i].next=NULL;
                    temp2[i].x=0;
                }
                temp[b].next=temp2;
            }
            else if(!(capital || small))
                temp[b].x=3;

            temp=temp[b].next;
        }
        while( !(small || capital) && c!=EOF)
            c=fgetc(fp);
    }
    printf("Enter the word to search(-1 to exit) : ");
    scanf("%s",query);
    while(query[0]!='-' || query[1]!='1' || query[2]!='\0')
    {
        c=query[0];
        i=1;
        temp=start;
        while(c!='\0' && temp!=NULL)
        {
            temp2=temp;
            if(small)
                b=c-'a';
            else
                b=c-'A';
            if(temp[b].x>0)
                temp=temp[b].next;
            else
                break;
            c=query[i];
            i++;
        }
        if(c=='\0')
        {
            if(temp2[b].x==3)
                printf("\n\t\"%s\" is PRESENT in the file\n\n",query);
            else if(temp2[b].x==1)
                printf("\n\t\"%s\" is present as a PREFIX of string(s) in the file\n\n",query);
        }
        else
            printf("\n\t\"%s\" is NOT present in the file\n\n",query);

        printf("Enter the word to search(-1 to exit) : ");
        scanf("%s",query);
    }
    return 0;
}
