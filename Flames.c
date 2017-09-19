#include<stdio.h>
#include<String.h>
char result;
void DisplayRelation();
int main()
{
    char name1[200],name2[200];
    int len1,len2;
    int i,j,count=0,distinct=0;

    printf("\t***FLAMES PROGRAM***\n");
    printf("\nEnter your name : " );
    scanf(" %s",name1);
    printf("\nEnter your crush name : ");
    scanf(" %s",name2);

    len1=strlen(name1);
    len2=strlen(name2);

    for(i=0;i<len1;i++)
        for(j=0;j<len2;j++)
            if(name1[i]==name2[j]&&name1[i]!='0'&&name2[j]!='0')
    {
        count++;
        name1[i]='0';
        name2[j]='0';
    }
    count=len1+len2-2*count;
    //printf("\nDistinct letters count: %d",count);
    findRelation(count);
    return 0;
}

int removeFirst(char word[],int shiftStatic)
{
    int i,n=strlen(word);
    //printf("\nStrlen(word):%d",n);
    for(i=0;i<n;i++)
    word[i]=word[i+1];
    word[n-1]='\0';
    if(n==2)
    {
    DisplayRelation(word);
    return 1;
    }
    if(n>2)
    leftrotation(word,n-1,shiftStatic-1,shiftStatic);
}
void leftrotation(char word[],int n,int shift,int shiftStatic)
{
    int i;
    char initial=word[0];
    //printf("\nshift:%d",shift);
    if(shift>0)
        {
        for(i=0;i<n;i++)
        word[i]=word[i+1];
        word[n-1]=initial;
        leftrotation(word,n,shift-1,shiftStatic);
        }
    else
    {
    //printf("Entered elseloop");
    removeFirst(word,shiftStatic);
    }
}
int findRelation(int count)
{
char word[10]="FLAMES";
int shift,shiftStatic;
//scanf(" %s",word);
//scanf("%d",&shift);
shift=count;
shiftStatic=shift;
leftrotation(word,strlen(word),shift-1,shiftStatic);
return 0;
}

void DisplayRelation(char word[])
{
    char relation=word[0];
    printf("\nRelationship between you and your crush will end in ");
    switch(relation)
    {
        case 'F':printf("Friendship\n\n");
        break;
        case 'L':printf("Love\n\n");
        break;
        case 'A':printf("Affection\n\n");
        break;
        case 'M':printf("Marriage\n\n");
        break;
        case 'S':printf("Brother and Sister\n\n");
        break;
        case 'E':printf("Enmity\n\n");
        break;
        default:
            printf("Invalid");

    }
     printf("\t***THE END***\n\n");
}

