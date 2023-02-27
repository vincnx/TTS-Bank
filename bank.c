#include <stdio.h>
#include <conio.h>
#include <windows.h>

void login();

struct datauser
{
    char pw1, uname1[100];
    char password1[100];

    char pw2, uname2[100];
    char password2[100];
} datauser;

int coba = 2;

void regis()
{
    char username[100];
    char pw[100];
    int i = 0, x = 10;

    system("cls");
    printf("Sign Up \n\n");
    printf("Username : ");
    scanf(" %[^\n]s", &datauser.uname1);
    printf("Password : ");

    while ((datauser.pw1 = (char)_getch()) != '\r')
    {
        if (datauser.pw1 == 8)
        {
            datauser.password1[i] = '\0';
            printf(" ");
            i--;
            x--;
        }
        else
        {
            datauser.password1[i] = datauser.pw1;
            printf("*");
            x++;
            i++;
        }
    }

    printf("\n");

    system("cls");
    printf("Pendaftaran berhasil!");
    getch();
    system("cls");
    login();
}

void login()
{
    char username[100];
    char pw[100];
    int j = 0, y = 10;

    system("cls");
    printf("LOGIN \n\n");
    printf("Username :");
    scanf(" %[^\n]s", &datauser.uname2);
    printf("Password :");

    while ((datauser.pw2 = (char)_getch()) != '\r')
    {
        if (datauser.pw2 == 8)
        {
            datauser.password2[j] = '\0';
            printf(" ");
            j--;
            y--;
        }
        else
        {
            datauser.password2[j] = datauser.pw2;
            printf("*");
            y++;
            j++;
        }
    }

    printf("\n");

    if ((strcmp(datauser.uname1, datauser.uname2) == 0) && (strcmp(datauser.password1, datauser.password2) == 0) && (coba >= 0))
    {
        system("cls");
        printf("\nlogin berhasil");
        getch();
        system("cls");
        // menuBANK();
    }
    else if ((strcmp(datauser.uname1, datauser.uname2) != 0 || strcmp(datauser.password1, datauser.password2) != 0) && coba >= 0)
    {
        if (coba != 0)
        {
            printf("\nPassword atau Username salah!\nAnda masih punya %d kesempatan", coba);
            coba--;
            getch();
            system("cls");
            login();
        }
        else
        {
            printf("\nMaaf, kesempatan login anda sudah habis");
            getch();
        }
    }
    else
    {
        printf("");
    }
}

int main()
{

    system("COLOR f1");
    regis();
}
