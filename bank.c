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
} data_login[100];

int idx_data_login = 0; // index lokasi data_login
int login_cond = 0; // kondisi login (1 = sudah login) (0 = belum login)
int coba = 2; // maks percobaan login
//

int main(){
    system("COLOR f1");
    if (!login_cond){
        main_1();
    }
    system("cls");
    printf("bisa login!!");
}

// bagian 1 (register & login)
int main_1(){ // main register & login
    int pilihan = menu_1();
    switch (pilihan){
    case 1: // registrasi
        menu_1_1();
        main_1();
        break;
    case 2: // login
        if (idx_data_login){
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
    printf("============================");
    gotoxy(0,1);
    printf("         REGISTRASI");
    gotoxy(0,2);
    printf("============================");
    gotoxy(0,3);
    printf("masukkan id       : ");
    scanf("%s", &id);
    strcpy(data_login[idx_data_login].nama,id);
    for (int i = 0; i < idx_data_login; i++){
        if (strcmp(data_login[i].nama, id) == 0){
            system("cls");
            printf("Id Telah Digunakan");
            Sleep(1000);
            return menu_1_1();
        }
    }
    printf("masukkan password : ");
    get_password(&data_login[idx_data_login]);
    idx_data_login ++;
    system("cls");
    printf("Registrasi Berhasil");
    Sleep(1000);
}

int menu_1_2(){ // menu login
    struct data_login login;
    system("cls");
    gotoxy(0,0);
    printf("============================");
    gotoxy(0,1);
    printf("           LOGIN");
    gotoxy(0,2);
    printf("============================");
    gotoxy(0,3);
    printf("masukkan id       : ");
    scanf("%s", &login.nama);
    gotoxy(0,4);
    printf("masukkan password : ");
    get_password(&login);
    system("cls");
    for (int i = 0; i < idx_data_login; i++){
        if(strcmp(login.nama, data_login[i].nama) == 0 && strcmp(login.password, data_login[i].password) == 0){
            printf("Berhasil Login");
            Sleep(1000);
            login_cond = 1;
            return 0;
        }
    }
    if (coba){
        printf("Maaf, id atau password salah!\nAnda masih punya %i kali kesempatan", coba);
        coba--;
        Sleep(1000);
        return menu_1_2();
    }
    else{
        printf("Maaf, kesempatan login anda telah habis.", coba);
        Sleep(1000);
        return system("exit");
    }
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