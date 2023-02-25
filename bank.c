#include <stdio.h>
#include <conio.h>
#include <windows.h>

// bagian 1 (register & login)
int main_1();
int menu_1();
int menu_1_1();
int menu_1_2();
// end bagian 1
// bagian 2

// tools
void gotoxy();
void get_password();

// struct & global variable
struct data_login{
    char nama[100];
    char password[8];
};
struct data_login data_login[100];

int idx = 0;
int login_cond = 0;
//

int main(){
    if (!login_cond){
        main_1();
    }
}

// bagian 1 (register & login)
int main_1(){
    int pilihan = menu_1();
    switch (pilihan){
    case 1: // registrasi
        menu_1_1();
        main_1();
        break;
    case 2: // login
        if (idx != 0){
            menu_1_2();
        }
        else{
            system("cls");
            printf("Harap Registrasi Terlebih Dahulu.");
            Sleep(1000);
            main_1();
        }
        break;
    }
}

int menu_1(){ // pilihan menu regis & login
    int pos = 3;
    while(1){
        system("cls");
        gotoxy(0,0);
        printf("==================");
        gotoxy(0,1);
        printf("REGISTRASI & LOGIN");
        gotoxy(0,2);
        printf("==================");
        gotoxy(5,3);
        printf("1. Registrasi");
        gotoxy(5,4);
        printf("2. Login");
        gotoxy(0,5);
        printf("==================");
        gotoxy(0, pos);
        printf("==>");
        int key = getch();
        if (key == 72){
            pos--;
        }
        else if (key == 80){
            pos++;
        }
        else if (key == 13){
            return pos - 2;
        }
        if (pos == 5){
            pos = 3;
        }
        else if (pos == 2){
            pos = 4;
        }
    }
}

int menu_1_1(){ // menu registrasi
    char key, id[100];
    system("cls");
    gotoxy(0,0);
    printf("========================");
    gotoxy(0,1);
    printf("       REGISTRASI");
    gotoxy(0,2);
    printf("========================");
    gotoxy(0,3);
    printf("masukkan id       : ");
    scanf("%s", &id);
    strcpy(data_login[idx].nama,id);
    for (int i = 0; i < idx; i++){
        if (strcmp(data_login[i].nama, id) == 0){
            printf("Id Telah Digunakan");
            Sleep(1000);
            return menu_1_1();
        }
    }
    printf("masukkan password : ");
    get_password(&data_login[idx]);
    idx ++;
    system("cls");
    printf("Registrasi Berhasil");
    Sleep(1000);
}

int menu_1_2(){ // menu login
    struct data_login login;
    system("cls");
    printf("masukkan id       : ");
    scanf("%s", &login.nama);
    printf("masukkan password : ");
    get_password(&login);
    system("cls");
    for (int i = 0; i < idx; i++){
        if(strcmp(login.nama, data_login[i].nama) == 0 && strcmp(login.password, data_login[i].password) == 0){
            printf("Berhasil Login");
            Sleep(1000);
            login_cond = 1;
            return 0;
        }
    }
    printf("Maaf, id atau password salah");
    Sleep(1000);
    return main_1();
}
// end bagian 1


// tools
void gotoxy(int x, int y){
    COORD coor;
    coor.X = x;
    coor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}

void get_password(struct data_login *target){
    int key;
    int i = 0;
    char pass[8];
    while ((key = getch()) != 13){
        if (i < 0){
            i = 0;
        }
        if (key == 8){
            if (i == 0){
                continue;
            }
            else{
                printf("\b \b");
                i--;
                continue;
            }
        }
        if (i == 8){
            continue;
        }
        printf("*");
        pass[i] = key;
        i++;
    }
    pass[i] = '\0';
    strcpy(target->password, pass);
}