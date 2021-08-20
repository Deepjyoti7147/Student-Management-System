#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
void check_marksheet();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
    int phy;
    int chem;
    int maths;
    int computer;
};
int main()
{
    system("color A");

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|                    |\n\t\t\t\t\t|\tWelcome      |\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|\t\t     |\n\n\n");
    printf("                                    This Project is done by Group 5 \n\t\t\t\t      Press any key to continue...");
    getch();
    system("cls");
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--: MENU :-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete.");
    gotoxy(10,12);
    printf("6 : Check Marksheet.");
    gotoxy(10,13);
    printf("7 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        check_marksheet();
        break;

    case 7:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("!!!Error opening file!!!");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name : ");
        gets(std.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Course : ");

        gets(std.course);
        gotoxy(10,11);
        printf("Enter Branch : ");
        gets(std.branch);
        gotoxy(10,12);
        printf("Enter Marks of Physics : ");
        scanf("%d",&std.phy);
        gotoxy(10,13);
        printf("Enter Marks of Chemistry : ");
        scanf("%d",&std.chem);
        gotoxy(10,14);
        printf("Enter Marks of Maths : ");
        scanf("%d",&std.maths);
        gotoxy(10,15);
        printf("Enter Marks of Computer : ");
        scanf("%d",&std.computer);



        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,16);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,20);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of Student       Mobile No   Roll No    Course     Branch");
    gotoxy(10,6);
    printf("----------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("!!!Error opening file.!!!");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-14s%-9d%-11s%-11s",i,std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    
    int r;
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter Roll No. of student : ");
    fflush(stdin);
    scanf("%d",&r);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("!!!Error opening file!!!");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(r==std.rollno){
            gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("Roll No : %d",std.rollno);
            gotoxy(10,11);
            printf("Course : %s",std.course);
            gotoxy(10,12);
            printf("Branch : %s",std.branch);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    
    int r;
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<---:MODIFY RECORD:--->");
    gotoxy(10,5);
    printf("Enter Roll No. of student to modify: ");
    fflush(stdin);
    
    
    scanf("%d",&r);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(r==std.rollno){
            gotoxy(10,7);
            printf("Enter name: ");
            gets(std.name);
            gotoxy(10,8);
            printf("Enter mobile number : ");
            gets(std.mobile);
            gotoxy(10,9);
            printf("Enter roll no : ");
            scanf("%d",&std.rollno);
            gotoxy(10,10);
            printf("Enter Course : ");
            fflush(stdin);
            gets(std.course);
            gotoxy(10,11);
            printf("Enter Branch : ");
            fflush(stdin);
            gets(std.branch);
            fseek(fp ,sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    
    
    int r;
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<---:DELETE RECORD:--->");
    gotoxy(10,5);
    printf("Enter Roll No. of student to delete record : ");
    fflush(stdin);
    
    
    scanf("%d",&r);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("!!!Error opening file!!!");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("!!!Error opening file!!!");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(r!=std.rollno)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void check_marksheet()
{
    FILE *fp;
    struct student std;
    
    int r;
    system("cls");
    gotoxy(10,3);
    printf("<--:CHECK MARKSHEET:-->");
    gotoxy(10,5);
    printf("Enter Roll No. of student : ");
    fflush(stdin);
    
    
    scanf("%d",&r);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("!!!Error opening file!!!");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(r==std.rollno){
            gotoxy(10,8);
            printf("<---: MARKSHEET :--->");
            gotoxy(10,10);
            printf("Name : %s",std.name);
            gotoxy(10,11);
            printf("Roll No : %d",std.rollno);
            gotoxy(10,13);
            printf("SUBJECT   :   MARKS  ");
            gotoxy(10,14);
            printf("-------------------");
            gotoxy(10,15);
            printf("PHYSICS   :     %d",std.phy);
            gotoxy(10,16);
            printf("CHEMISTRY :     %d",std.chem);
            gotoxy(10,17);
            printf("MATHS     :     %d",std.maths);
            gotoxy(10,18);
            printf("COMPUTER  :     %d\n",std.computer);
        }
    }
    fclose(fp);
    gotoxy(10,25);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
