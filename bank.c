#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// bagian register & login
int main_1();
int menu_1();
int menu_1_1();
int menu_1_2();
// end bagian register & login
// bagian menu awal
int menu_awal();
// end menu awal
// bagian tampilkan nasabah
void tampil_nama();
// end tampilkan nasabah
// bagian input nasabah
void input_nama();
// end input nasabah
// bagian setor tarik
int milihSetor();
int setor();
int tarik();
// end setor tarik
// bagian cek saldo
int cek_saldo();
// end cek saldo
// bagian tampil nama
int anggota_kel();
// end tampil nama
// bagian rank nasabah
int main_rank();
int menu_rank();
int terkaya();
int terbokek();
// end rank nasabah

// tools
void gotoxy();
void get_password();
int get_int();

// struct & global variable
struct data_login
{
    char nama[100];
    char password[8];
} data_login[100];

struct Nama
{
    char depan[50];
    char belakang[50];
    int nomor;
    int saldo;
} data_diri[100];

int idx_data_login = 0; // index lokasi data_login
int login_cond = 0;     // kondisi login (1 = sudah login) (0 = belum login)
int coba = 2;           // maks percobaan login
int idx_data_diri = 0;  // index lokasi data_diri
int kesempatan = 2;     // kesempatan input nomor rekening di cek saldo
int len = 0;

int main()
{
    int pilihan;
    system("COLOR 1f");
    // if (!login_cond){
    //     main_1();
    // }
    pilihan = menu_awal();
    switch (pilihan)
    {
    case 1:
        tampil_nama();
        system("pause");
        main();
        break;
    case 2:
        input_nama();
        system("pause");
        main();
        break;
    case 3:
        milihSetor();
        break;
    case 4:
        cek_saldo();
        system("pause");
        main();
        break;
    case 5:
        anggota_kel();
        system("exit");
        break;
    case 6:
        main_rank();
        system("pause");
        main();
        break;
    }
}

// bagian menu awal
int menu_awal()
{
    int pos = 3;
    while (1)
    {
        system("cls");
        gotoxy(0, 0);
        printf("================================");
        gotoxy(0, 1);
        printf("            BANK");
        gotoxy(0, 2);
        printf("================================");
        gotoxy(5, 3);
        printf("1. Tampilkan daftar Nasabah");
        gotoxy(5, 4);
        printf("2. Tambah nasabah");
        gotoxy(5, 5);
        printf("3. Setor & Tarik Uang");
        gotoxy(5, 6);
        printf("4. Cek Saldo");
        gotoxy(5, 7);
        printf("5. Exit");
        gotoxy(5, 8);
        printf("6. Rank Nasabah");
        gotoxy(0, 9);
        printf("================================");
        gotoxy(0, pos);
        printf("==>");
        int key = getch();
        if (key == 72)
        {
            pos--;
        }
        else if (key == 80)
        {
            pos++;
        }
        else if (key == 13)
        {
            return pos - 2;
        }
        if (pos == 9)
        {
            pos = 3;
        }
        else if (pos == 2)
        {
            pos = 8;
        }
    }
}
// end menu awal

// bagian tampilkan nasabah
void tampil_nama()
{
    system("cls");
    gotoxy(0, 0);
    printf("=================================");
    gotoxy(0, 1);
    printf("       DAFTAR NAMA NASABAH");
    gotoxy(0, 2);
    printf("=================================");
    gotoxy(0, 3);
    if (idx_data_diri)
    {
        for (int i = 0; i < idx_data_diri; i++)
        {
            gotoxy(0, 3 + i);
            printf("%i. %s %s (%i)", i + 1, data_diri[i].depan, data_diri[i].belakang, data_diri[i].nomor);
        }
    }
    else
    {
        printf("Belum Ada Nasabah.");
    }
    printf("\n");
}
// end tampilkan nasabah

// bagian input nasabah
void input_nama()
{
    system("cls");
    gotoxy(0, 0);
    printf("==================================");
    gotoxy(0, 1);
    printf("          TAMBAH NASABAH");
    gotoxy(0, 2);
    printf("==================================");
    gotoxy(0, 3);
    printf("Masukkan nama depan   : ");
    scanf(" %[^\n]s", data_diri[idx_data_diri].depan);
    printf("Masukkan nama belakang: ");
    scanf(" %[^\n]s", data_diri[idx_data_diri].belakang);
    data_diri[idx_data_diri].nomor = 672022001 + len;
    printf("Nomor Rekening Anda   : %i\n", data_diri[idx_data_diri].nomor);
    idx_data_diri++;
    len++;
}
// end bagian input nasabah

// bagian register & login
int main_1()
{ // main register & login
    int pilihan = menu_1();
    switch (pilihan)
    {
    case 1: // registrasi
        menu_1_1();
        main_1();
        break;
    case 2: // login
        if (idx_data_login)
        {
            menu_1_2();
        }
        else
        {
            system("cls");
            printf("Harap Registrasi Terlebih Dahulu.");
            Sleep(1000);
            main_1();
        }
        break;
    }
}

int menu_1()
{ // pilihan menu regis & login
    int pos = 3;
    while (1)
    {
        system("cls");
        gotoxy(0, 0);
        printf("==================");
        gotoxy(0, 1);
        printf("REGISTRASI & LOGIN");
        gotoxy(0, 2);
        printf("==================");
        gotoxy(5, 3);
        printf("1. Registrasi");
        gotoxy(5, 4);
        printf("2. Login");
        gotoxy(0, 5);
        printf("==================");
        gotoxy(0, pos);
        printf("==>");
        int key = getch();
        if (key == 72)
        {
            pos--;
        }
        else if (key == 80)
        {
            pos++;
        }
        else if (key == 13)
        {
            return pos - 2;
        }
        if (pos == 5)
        {
            pos = 3;
        }
        else if (pos == 2)
        {
            pos = 4;
        }
    }
}

int menu_1_1()
{ // menu registrasi
    char key, id[100];
    system("cls");
    gotoxy(0, 0);
    printf("============================");
    gotoxy(0, 1);
    printf("         REGISTRASI");
    gotoxy(0, 2);
    printf("============================");
    gotoxy(0, 3);
    printf("masukkan id       : ");
    scanf("%s", &id);
    strcpy(data_login[idx_data_login].nama, id);
    for (int i = 0; i < idx_data_login; i++)
    {
        if (strcmp(data_login[i].nama, id) == 0)
        {
            system("cls");
            printf("Id Telah Digunakan");
            Sleep(1000);
            return menu_1_1();
        }
    }
    printf("masukkan password : ");
    get_password(&data_login[idx_data_login]);
    idx_data_login++;
    system("cls");
    printf("Registrasi Berhasil");
    Sleep(1000);
}

int menu_1_2()
{ // menu login
    struct data_login login;
    system("cls");
    gotoxy(0, 0);
    printf("============================");
    gotoxy(0, 1);
    printf("           LOGIN");
    gotoxy(0, 2);
    printf("============================");
    gotoxy(0, 3);
    printf("masukkan id       : ");
    scanf("%s", &login.nama);
    gotoxy(0, 4);
    printf("masukkan password : ");
    get_password(&login);
    system("cls");
    for (int i = 0; i < idx_data_login; i++)
    {
        if (strcmp(login.nama, data_login[i].nama) == 0 && strcmp(login.password, data_login[i].password) == 0)
        {
            printf("Berhasil Login");
            Sleep(1000);
            login_cond = 1;
            coba = 2;
            return 0;
        }
    }
    if (coba)
    {
        printf("Maaf, id atau password salah!\nAnda masih punya %i kali kesempatan", coba);
        coba--;
        Sleep(1000);
        return menu_1_2();
    }
    else
    {
        printf("Maaf, kesempatan login anda telah habis.", coba);
        Sleep(1000);
        coba = 2;
        return main();
    }
}
// end regis & login

// bagian 4 kalkulasi (setor dan tarik uang -debit)
int menusetor()
{
    int pos = 3;
    while (1)
    {
        system("cls");
        gotoxy(0, 0);
        printf("=========================");
        gotoxy(0, 1);
        printf("SETOR & TARIK UANG DEBIT");
        gotoxy(0, 2);
        printf("========================");
        gotoxy(5, 3);
        printf("1. SETOR");
        gotoxy(5, 4);
        printf("2. TARIK");
        gotoxy(5, 5);
        printf("3. KEMBALI");
        gotoxy(0, 6);
        printf("========================");
        gotoxy(0, pos);
        printf("==>");
        int key = getch();
        if (key == 72)
        {
            pos--;
        }
        else if (key == 80)
        {
            pos++;
        }
        else if (key == 13)
        {
            return pos - 2;
        }
        if (pos == 6)
        {
            pos = 3;
        }
        else if (pos == 2)
        {
            pos = 5;
        }
    }
}

// pilih setor/tarik
int milihSetor()
{
    int pilihan = menusetor();
    switch (pilihan)
    {
    case 1: // setor
        setor();
        break;
    case 2: // tarik
        tarik();
        break;
    case 3: // kembali
        main();
        break;
    }
}

int setor()
{
    int rek;
    system("cls");
    gotoxy(0, 0);
    printf("=================================");
    gotoxy(0, 1);
    printf("           MENU SETOR");
    gotoxy(0, 2);
    printf("=================================");
    if (idx_data_diri)
    {
        printf("\nMASUKAN NOMOR REKENING :");
        scanf("%d", &rek);
        fflush(stdin);
        system("cls");
        for (int i = 0; i < idx_data_diri; i++)
        {
            if (data_diri[i].nomor - rek == 0)
            {
                printf("Rekening %s %s.", data_diri[i].depan, data_diri[i].belakang);
                int anu = get_int("\nMasukkan Jumlah = ");
                if (anu <= 0)
                {
                    system("cls");
                    printf("Jumlah terlalu kecil.\n");
                    system("pause");
                    return setor();
                }
                else
                {
                    data_diri[i].saldo = data_diri[i].saldo + anu;
                    system("cls");
                    printf("Berhasil Setor!\n");
                    system("pause");
                    return main();
                }
            }
        }
        printf("NOMOR REKENING TIDAK DIKENAL!\n");
        system("pause");
        return main();
    }
    else
    {
        printf("\nBelum Ada Nasabah\n");
        system("pause");
        main();
    }
}

int tarik()
{
    int rek;
    system("cls");
    gotoxy(0, 0);
    printf("=================================");
    gotoxy(0, 1);
    printf("           MENU TARIK");
    gotoxy(0, 2);
    printf("=================================");
    if (idx_data_diri)
    {
        printf("\nMASUKAN NOMOR REKENING :");
        scanf("%d", &rek);
        fflush(stdin);
        system("cls");
        for (int i = 0; i < idx_data_diri; i++)
        {
            if (data_diri[i].nomor - rek == 0)
            {
                printf("Rekening %s %s.", data_diri[i].depan, data_diri[i].belakang);
                int anu = get_int("\nMasukkan Jumlah = ");
                if (anu <= 0)
                {
                    system("cls");
                    printf("Jumlah terlalu kecil.\n");
                    system("pause");
                    return tarik();
                }
                else
                {
                    if (data_diri[i].saldo - anu <= 0)
                    {
                        system("cls");
                        printf("Saldo anda tidak cukup.\n");
                        system("pause");
                        return milihSetor();
                    }
                    else
                    {
                        data_diri[i].saldo = data_diri[i].saldo - anu;
                        system("cls");
                        printf("Penarikan Berhasil!\n");
                        system("pause");
                        return main();
                    }
                }
            }
        }
        printf("NOMOR REKENING TIDAK DIKENAL!\n");
        system("pause");
        return main();
    }
    else
    {
        printf("\nBelum Ada Nasabah\n");
        system("pause");
        return main();
    }
}
// end bagian 4 kalkulasi (setor dan tarik uang -debit)

// bagian cek saldo
int cek_saldo()
{
    int sld;
    system("cls");
    gotoxy(0, 0);
    printf("=================================");
    gotoxy(0, 1);
    printf("            CEK SALDO");
    gotoxy(0, 2);
    printf("=================================");
    gotoxy(0, 3);
    if (idx_data_diri)
    {
        printf("MASUKAN NOMOR REKENING :");
        fflush(stdin);
        scanf("%d", &sld);
        system("cls");
        for (int i = 0; i < idx_data_diri; i++)
        {
            if (sld - data_diri[i].nomor == 0)
            {
                printf("%s %s", data_diri[i].depan, data_diri[i].belakang);
                printf("\nSaldo Anda : Rp.%i.00\n", data_diri[i].saldo);
                kesempatan = 2;
                return 0;
            }
        }
        if (kesempatan)
        {
            printf("NOMOR REKENING TIDAK DIKENAL!\nANDA MASIH PUNYA %i KESEMPATAN\n", kesempatan);
            kesempatan--;
            system("pause");
            return cek_saldo();
        }
        printf("MAAF KESEMPATAN ANDA SUDAH HABIS.\n");
        kesempatan = 2;
    }
    else
    {
        printf("Belum Ada Nasabah\n");
    }
}
// end cek saldo

// bagian tampil nama
int anggota_kel(){
    system("cls");
    printf("====================================\n");
    printf("         KELOMPOK 5 - BANK\n");
    printf("====================================\n");
    printf("ANGGOTA KELOMPOK :\n");
    Sleep(750);
    printf("CLAUDIO CANAVARO         (672022015)\n");
    Sleep(750);
    printf("VINCENT EXELCIO SUSANTO  (672022070)\n");
    Sleep(750);
    printf("HOSEA RAKA NARWASTUDJATI (672022160)\n");
    Sleep(750);
    printf("YOVIEA APRINDO TUMON     (672022070)\n");
    Sleep(750);
    printf("DIMAS IRSAD BAHARUDIN    (672022324)\n");
}
// end tampil nama

// bagian rank nasabah
int main_rank(){
    int pilihan = menu_rank();
    switch (pilihan){
        case 1:
            terkaya();
            break;
        case 2:
            terbokek();
            break;
    }
}

int menu_rank(){
    int pos = 3;
    while (1){
        system("cls");
        gotoxy(0, 0);
        printf("=================");
        gotoxy(0, 1);
        printf("  RANK NASABAH");
        gotoxy(0, 2);
        printf("=================");
        gotoxy(5, 3);
        printf("1. Terkaya");
        gotoxy(5, 4);
        printf("2. Terbokek");
        gotoxy(0, 5);
        printf("=================");
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

int terkaya(){
    system("cls");
    gotoxy(0, 0);
    printf("=================================");
    gotoxy(0, 1);
    printf("             TERKAYA");
    gotoxy(0, 2);
    printf("=================================");
    gotoxy(0, 3);
    if (idx_data_diri){
        int max = 0;
        int limit = 0;
        int cond = 1;
        int num = 1;
        while (cond){
            cond = 0;
            for (int i = 0; i < idx_data_diri; i++){
                if (limit){
                    if (data_diri[i].saldo > max && data_diri[i].saldo < limit){
                        max = data_diri[i].saldo;
                        cond = 1;
                    }
                }
                else{
                    if (data_diri[i].saldo > max){
                        max = data_diri[i].saldo;
                        cond = 1;
                    }
                }
            }
            for (int i = 0; i < idx_data_diri; i++){
                if (data_diri[i].saldo == max){
                    printf("%i. %s %s  saldo : Rp.%i.00\n", num, data_diri[i].depan, data_diri[i].belakang, data_diri[i].saldo);
                    num++;
                }
            }
            limit = max;
            max = 0;
        }
    }
    else{
        printf("Belum Ada Nasabah\n");
    }
}

int terbokek(){
    system("cls");
    gotoxy(0, 0);
    printf("================================");
    gotoxy(0, 1);
    printf("            TERBOKEK");
    gotoxy(0, 2);
    printf("================================");
    gotoxy(0, 3);
    if (idx_data_diri){
        int cond = 1;
        int limit = -1;
        int num = 1;
        int max = 0;
        for (int i = 0; i < idx_data_diri; i++){
            if (data_diri[i].saldo > max){
                max = data_diri[i].saldo;
            }
        }
        while (cond){
            int lowest = max;
            cond = 0;
            for (int i = 0; i < idx_data_diri; i++){
                if (data_diri[i].saldo < lowest && data_diri[i].saldo > limit){
                    lowest = data_diri[i].saldo;
                    cond = 1;
                }
            }
            limit = lowest;
            for (int i = 0; i < idx_data_diri; i++){
                if (data_diri[i].saldo == lowest){
                    printf("%i. %s %s saldo : Rp.%i.00\n", num, data_diri[i].depan, data_diri[i].belakang, data_diri[i].saldo);
                    num++;
                }
            }
        }
    }
    else{
        printf("Belum Ada Nasabah\n");
    }
}
// end rank nasabah

// tools
void gotoxy(int x, int y)
{
    COORD coor;
    coor.X = x;
    coor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}

void get_password(struct data_login *target)
{
    int key;
    int i = 0;
    char pass[8];
    while ((key = getch()) != 13)
    {
        if (i < 0)
        {
            i = 0;
        }
        if (key == 8)
        {
            if (i == 0)
            {
                continue;
            }
            else
            {
                printf("\b \b");
                i--;
                continue;
            }
        }
        if (i == 8)
        {
            continue;
        }
        printf("*");
        pass[i] = key;
        i++;
    }
    pass[i] = '\0';
    strcpy(target->password, pass);
}

int get_int(char *prompt)
{
    int num = 0, ch, count = 0;

    printf("%s", prompt);
    while (1)
    {
        ch = getch();
        if (ch == 13 && count)
        {
            break;
        }
        if (ch >= 48 && ch <= 57 && ch != 13)
        {
            num = num * 10 + (ch - 48);
            printf("%c", ch);
            count++;
        }
        else if ((ch == 8 && num) || (num == 0 && count))
        {
            num /= 10;
            printf("\b \b");
            count--;
        }
    }
    return num;
}