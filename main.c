#include <stdio.h>
#include <stdlib.h>

struct info
{
    long long int num;
    char name[50],last[1000];
}contact[100];

void addcontact();
void dltcontact();
void list();
void search();

int main()
{
    for(int i=0;i<100;i++){
        contact[i].num=0;
    }
    int n;
    printf("hello.\nwhat can I do for you?");
    printf("\nyou can store up to 100 contacts\n\n");
    while(1)
    {
        printf("1 to add contact,\n2 for deleting a contact,\n3 for listing current contacts or \n4 for searching a specific contact");
        printf("\n0 for exiting the program\n");
        scanf("%d",&n);
        if(n==0){
            break;
        }
        switch (n){
            case 1:
            addcontact();
            break;
            case 2:
            dltcontact();
            break;
            case 3:
            list();
            break;
            case 4:
            search();
            break;
            default:
            printf("\nerror\n");
        }

    }
}

void addcontact()
{
    for(int i=0;i<100;i++){
        if(contact[i].num==0){
            printf("enter first name:\n");
            getchar();
            gets(contact[i].name);
            printf("\nenter last name:\n");
            gets(contact[i].last);
            printf("\nenter phone number:\n");
            scanf("%lld",&contact[i].num);
            break;
    }}
}

void dltcontact()
{
    int i,deletation;
    list();
    printf("\nwhich  one do you want to delete?");
    scanf("%d",&deletation);
    for(i=deletation;i<100;i++){
        if(contact[i].num!=0){
            strcpy(contact[i-1].name,contact[i].name);
            strcpy(contact[i-1].last,contact[i].last);
            contact[i-1].num=contact[i].num;
        }
        if (contact[i].num==0)
        {
            contact[i-1].num=0;
            break;
        }
    }

    list();
}

void search()
{
    int flag=0;
    char search_board[50];
    printf("\n==========================\n");
    printf("who are you looking for:\n");
    getchar();
    gets(search_board);
    for(int i=0;i<100;i++){
            char *p1=strstr(contact[i].name,search_board);
            char *p2=strstr(contact[i].last,search_board);
            if((p1||p2)&&contact[i].num!=0){
                printf("\n%s  %s",contact[i].name,contact[i].last);
                printf("\n0%lld\n",contact[i].num);
                flag++;
            }
    }
    if(flag==0){
        printf("\nthere is no contact named %s\n",search_board);
    }
    printf("\n==========================\n");
}

void list()
{
    printf("=====================");
    for(int i=0;i<100;i++){
        if(contact[i].num!=0){
            printf("\n%d",i+1);
            printf(":%s %s",contact[i].name,contact[i].last);
            printf("\n    0%lld\n",contact[i].num);
        }
    }
    printf("=====================\n");
}
