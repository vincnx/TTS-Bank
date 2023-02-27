#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void login();

char pw1,uname1[100];
char password1[100] ="";

char pw2,uname2[100];
char password2[100] ="";

int coba = 2;

void regis() {

    char username[100];
    char pw[100];
    int i = 0, x = 10;

    printf("Sign Up \n\n");
    printf("Username : ");
    scanf(" %[^\n]s",&uname1);
    printf("Password : ");

    while((pw1=(char)_getch()) != '\r' ){
        if(pw1==8){
            password1[i]='\0';
            printf(" ");
            i--;
            x--;
        } else{
            password1[i] = pw1;
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

void login() {

     //====LOGIN=====

char username[100];
    char pw[100];
    int j = 0, y = 10;


    printf("LOGIN \n\n");
    printf("Username :");
    scanf(" %[^\n]s",&uname2);
    printf("Password :");

   // scanf(" %[^\n]s",&password2);


	while((pw2=(char)_getch()) != '\r' ){
        if(pw2==8){
            password2[j]='\0';
            printf(" ");
            j--;
            y--;
        } else{
            password2[j] = pw2;
            printf("*");
            y++;
            j++;
        }
    }

    //fflush(stdin);

    //strcpy(password2,pw);
    //strcpy(uname2,username);


    printf("\n");



    if((strcmp(uname1,uname2)==0) && (strcmp(password1,password2)==0) && (coba >= 0)) {
        system("cls");
        printf("\nlogin berhasil");
        getch();
        system("cls");
        //menuBANK();
    } else if((strcmp(uname1,uname2)!=0 || strcmp(password1,password2)!=0) && coba >= 0){
        if(coba != 0) {
            printf("\nPassword atau Username salah!\nAnda masih punya %d kesempatan", coba);
            coba--;
            getch();
            system("cls");
            login();
        } else {
            printf("\nMaaf, kesempatan login anda sudah habis");
            getch();
        }



    } else {
        printf("");
    }

}

int main () {

    system("COLOR f1");
    regis();

}
