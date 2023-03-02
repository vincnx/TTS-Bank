#include <stdio.h>
#include <string.h>

struct Nama {
    char depan[50];
    char belakang[50];
};

void input_nama () {
    struct Nama nama;

    printf("Masukkan nama depan: ");
    scanf(" %[^\n]s", nama.depan);

    printf("Masukkan nama belakang: ");
    scanf(" %[^\n]s", nama.belakang);


}

void tampil_nama () {

    system("cls");

    struct Nama nama;

    printf("NAMA NASABAH :\n\n%s %s\n", nama.depan, nama.belakang);

}

int main() {

    input_nama();
    tampil_nama();

}
