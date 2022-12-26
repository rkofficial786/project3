#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct 
{
    char name[50];
    int roll;
    int class;
    char stream[50];
    char address[200];
    char date[20];
    int feetotal;
    int feepaid;
    int feeleft;
}student;
// struct student s1;
FILE *file;
student s1 = {0};
long(sz) = sizeof(s1);

// function--------

void addstudent();
void viewstudent();

int main()
{

    int choice;

  

    while (1)
    {

        system("cls");
        printf("\t \t \tMAIN MENU\n\n");
        printf("1. Add Student\n");
        printf("2. View Student\n");
        printf("3. Delete Student\n");
        printf("4. Sort Student\n");
        printf("5. Add Staff\n");
        printf("6. View Staff\n");
        printf("7. Manage Fees\n");
        printf("7. View Fees Status\n");
        printf("8. Exit\n");

        printf("ENTER YOUR CHOICE:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            addstudent();
            break;

        case 2:
            viewstudent();
            break;

            // case 3 :
            // deletestudent() ;
            // break ;

            // case 4:
            // sortstudent() ;
            // break;

            // case 5:
            // addstaff();
            // break ;

            // case 6:
            // viewstaff() ;
            // break ;

            // case 7:
            // managefees();
            // break ;

        default:
            printf("Enter valid choice\n");
        }
        printf("press any key to continue\n");
        getch();
    }

    return 0;
}

void addstudent()
{

    student s1 = {0};
    system("cls");
    char mydate[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(mydate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    // printf("%s" , mydate) ;
    strcpy(s1.date, mydate);
    // printf("%s",s1.date) ;

    file = fopen("record4.txt", "ab+");
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s1.name);
    printf("Enter Roll: ");
    scanf("%d", &s1.roll);
    printf("Enter Class: ");
    scanf("%d", &s1.class);
    printf("Enter Stream: ");
    fflush(stdin);
    gets(s1.stream);
    printf("Enter Adress: ");
    gets(s1.address);
    printf("Enter total fees: ");
    scanf("%d", &s1.feetotal);
    printf("Enter Fee paid: ");
    scanf("%d", &s1.feepaid);

    s1.feeleft = s1.feetotal - s1.feepaid;

    fwrite(&s1, sz, 1, file);

    if (fwrite)
    {
        printf("Records saved successfully\n");
    }
    else if (!fwrite)
    {
        printf("Error\n");
    }
    fclose(file);
}

void viewstudent()
{
   student s1 = {0};
    system("cls");
    printf("%-30s %-10s %-10s %-20s %-450s %-20s %-20s\n\n", "Name", "Roll", "Class", "Stream", "Adress", "TotalFee", "Feepaid");
    file = fopen("record4.txt", "r");
    while (fread(&s1, sz, 1, file))
    {
        printf("%-30s %-10d %-10d %-20s %-45s %-20d %-20d\n", s1.name, s1.roll, s1.class, s1.stream, s1.address, s1.feetotal, s1.feepaid);
    }
    fclose(file);
}
