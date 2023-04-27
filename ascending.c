#include <stdio.h>

// Fungsi untuk mengurutkan saldo dari terkecil ke terbesar
void sortSaldo(int saldo[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (saldo[j] > saldo[j + 1])
            {
                temp = saldo[j];
                saldo[j] = saldo[j + 1];
                saldo[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i, n;
    printf("Masukkan jumlah nasabah: ");
    scanf("%d", &n);

    int saldo[n];

    // Membaca input saldo dari setiap nasabah
    for (i = 0; i < n; i++)
    {
        printf("Masukkan saldo nasabah %d: ", i + 1);
        scanf("%d", &saldo[i]);
    }

    // Mengurutkan saldo dari terkecil ke terbesar
    sortSaldo(saldo, n);

    // Menampilkan saldo nasabah dari terkecil ke terbesar
    printf("\nSaldo nasabah dari terkecil ke terbesar:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", saldo[i]);
    }

    return 0;
}
