#include <stdio.h>
#include <stdlib.h>

// variabel global
int kodehalte[15] = {726, 625, 269, 945, 286, 174, 581, 307, 415, 270};
char halte[15][20] = {"Rajawali", "Jembatan Ijo", "Veteran", "Tugu Pahlawan", "Contong", "Siola Indah", "Tunjungan", "Simpang Dukuh", "Suryo Asti", "Sudirman"};
char jam[15][20] = {" 08.00 ", " 13.00 ", " 07.00 ", " 11.00 ", " 16.00 ", " 14.00 ", " 09.00 ", " 17.00 ", " 15.00 ", " 10.00 "};
int Harga[15] = {13000, 16000, 17000, 15000, 18000, 12000, 19000, 22000, 21000, 20000};
char username[20][20] = {"admin"};
char pass[20][20] = {"admin"};

void jadwal()
{
    system("cls");
    printf("=================================================================================\n");
    printf("=                                JADWAL HALTE!!!                                =\n");
    printf("=================================================================================\n\n");
    printf("KODE Halte\t\tHALTE   \t\tJAM OPERASI \t\tHARGA");
    printf("\n---------------------------------------------------------------------------------\n");
    for (int i = 0; kodehalte[i] != 0; i++)
    {
        printf("%d  \t\t    %s      \t\t%s \t\t\t Rp%d \n", kodehalte[i], halte[i], jam[i], Harga[i]);
    }
}

void tambahalte()
{
    int i = 0;
    int j = 0;
    int halt, kodeb, jams;
    char jawab;
    char nama, pas;
    do
    {
        i++;
    } while (kodehalte[i] != 0); // untuk mencari index yang kosong
ulang:
    system("cls");
    printf("=================================================================================\n");
    printf("            Masukan Username & Password Untuk Menambahkan Halte\n");
    printf("=================================================================================\n");
    printf("Masukan Username\t: ");
    scanf("%s", &nama);
    printf("Masukan Password\t: ");
    scanf("%s", &pas);

    if ((nama, username[j]) == 0 && strcmp(pas, pass[j]) == 0) // hanya admin yang bisa menambah jadwal
    {
        system("cls");
        printf("=================================================================================\n");
        printf("=                                TAMBAH JADWAL!!!                                =\n");
        printf("=================================================================================\n\n");
        printf("Masukan Kode Halte (Ex 276)\t : ");
        scanf("%i", &kodehalte[i]);
        printf("Masukan Nama Halte(Ex Sudirman)\t : ");
        scanf("%s", &halte[i]);
        printf("Tentukan Jam (Ex 00.00)\t\t : ");
        scanf("%s", &jam[i]);
        printf("Tentukan Harga(Ex 12000) \t : ");
        scanf("%i", &Harga[i]);
        printf("\n---------------------------------------------------------------------------------\n");
        printf("KODE Halte\t\tHALTE   \t\tJAM OPERASI \t\tHARGA");
        printf("\n---------------------------------------------------------------------------------\n");
        jadwal();
    }
    else
    {
        printf("Username / Password Anda Salah\n");
        printf("Apakah Anda Mau Mengulangi Lagi (y/n)? ");
        scanf("%s", &jawab);

        if (jawab == 'y' || jawab == 'Y')
        {
            goto ulang; // mengulangi memasukan password
        }
    }
}

void urut()
{
    system("cls");
    int k, tempkod, tempharga, menurut;
    char temphalte[20];
    char tempjam[20];
    int i = 0;
    do
    {
        i++;
    } while (kodehalte[i] != 0); // untuk menghitung berapa kode halte
    printf("=================================================================================\n");
    printf("=                             Mengurutkan Jadwal                                =\n");
    printf("=================================================================================\n\n");
    printf("<<< Urutkan Berdasarkan >>>\n");
    printf("01. Waktu paling Awal\n");
    printf("02. Waktu Paling Akhir\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Pilih Menu Untuk Mengurutkan\t: ");
    scanf("%d", &menurut);
    if (menurut == 1)
    {
        for (k = 1; kodehalte[k] != 0; k++)
        {
            for (int j = 0; j < i - k; j++)
            {
                if (strcmp(jam[j], jam[j + 1]) > 0) // mengurutkan secara ascending
                {
                    tempharga = Harga[j];
                    Harga[j] = Harga[j + 1];
                    Harga[j + 1] = tempharga;
                    tempkod = kodehalte[j];
                    kodehalte[j] = kodehalte[j + 1];
                    kodehalte[j + 1] = tempkod;
                    strcpy(temphalte, halte[j]);
                    strcpy(halte[j], halte[j + 1]);
                    strcpy(halte[j + 1], temphalte);
                    strcpy(tempjam, jam[j]);
                    strcpy(jam[j], jam[j + 1]);
                    strcpy(jam[j + 1], tempjam);
                }
            }
        }
    }
    else if (menurut == 2)
    {
        for (k = 1; kodehalte[k] != 0; k++)
        {
            for (int j = 0; j < i - k; j++)
            {
                if (strcmp(jam[j], jam[j + 1]) < 0) // mengurutkan secara descanding
                {
                    tempharga = Harga[j];
                    Harga[j] = Harga[j + 1];
                    Harga[j + 1] = tempharga;
                    tempkod = kodehalte[j];
                    kodehalte[j] = kodehalte[j + 1];
                    kodehalte[j + 1] = tempkod;
                    strcpy(temphalte, halte[j]);
                    strcpy(halte[j], halte[j + 1]);
                    strcpy(halte[j + 1], temphalte);
                    strcpy(tempjam, jam[j]);
                    strcpy(jam[j], jam[j + 1]);
                    strcpy(jam[j + 1], tempjam);
                }
            }
        }
    }
    else
    {
        printf("Tidak Ada Menu Yang Anda Pilih");
    }
    jadwal();
}

void info()
{
    system("cls");
    int cari;
    int i = 0;
    printf("Masukan Kode Halte Untuk Mencari Halte\t: ");
    scanf("%d", &cari);
    int panjang = sizeof(kodehalte) / sizeof(kodehalte[0]); // untuk menghitung panjang array
    printf("=================================================================================\n");
    printf("=                       Selamat Datang Di Pusat Informasi                       =\n");
    printf("=================================================================================\n\n");
    for (i = 0; i <= panjang; i++)
    {
        if (cari == kodehalte[i])
        {
            printf("\n---------------------------------------------------------------------------------\n");
            printf("KODE Halte\t\tHALTE   \t\tJAM OPERASI \t\tHARGA");
            printf("\n---------------------------------------------------------------------------------\n");
            printf("%d  \t\t    %s      \t\t%s \t\t\t Rp%d \n", kodehalte[i], halte[i], jam[i], Harga[i]);
            break;
        }
    }

    if (cari != kodehalte[i])
    {
        system("cls");
        printf("\n---------------------------------------------------------------------------------");
        printf("\n                      Tidak Ada Halte Yang Tersedia\n\t\t\t   Terimakasih!!!");
        printf("\n---------------------------------------------------------------------------------\n");
    }
}

void kasir()
{
    char n;
    char y;
    char jawab;
    int pilih, uang, total, tiket, cetak, cetakhasil;
    int i = 0;
    system("cls");
    jadwal();
ulang:
    printf("\nPilih Kode Halte Untuk Membeli Tiket\t: ");
    scanf("%d", &pilih);
    int panjang = sizeof(kodehalte) / sizeof(kodehalte[0]);
    for (i = 0; i < panjang; i++)
    {
        if (pilih == kodehalte[i])
        {
            printf("----------------------------------------------------------------------------\n");
            printf("\n               Anda Memilih Halte %s Pada Pukul %s \n", halte[i], jam[i]);
            printf("\t              Harga Yang Harus Dibayar = Rp%d\n", Harga[i]);
            printf("\n----------------------------------------------------------------------------\n");
            printf("\nApakah Kamu Yakin?  (y/n): ");
            scanf("%s", &jawab);

            if (jawab == 'y' || jawab == 'Y')
            {
                int total;
                printf("\n----------------------------------------------------------------------------\n\n");
                printf("Tiket Yang Ingin Dibeli\t: ");
                scanf("%d", &tiket);
                total = Harga[i] * tiket;
                printf("Uang Yang Harus Anda Bayar Adalah = Rp%d", total);
            cetak:
                printf("\nMasukan Uang Anda\t= Rp");
                scanf("%d", &uang);
                if (uang > total)
                {

                    printf("Sisa Uang Anda Adalah\t= Rp%d ", uang - total);
                    break;
                }
                else if (uang == total)
                {
                    printf("\n----------------------------------------------------------------------------\n");
                    printf("                             Uang Anda Pas");
                    printf("\n                              TERIMAKASIH!!!\n");
                    printf("-----------------------------------------------------------------------------\n");
                    break;
                }

                else
                {
                    system("cls");
                    printf("\n----------------------------------------------------------------------------\n");
                    printf("        Uang Anda Kurang, Silahkan Masukkan sesuai Harga Yang Ditentukan\n");
                    printf("-----------------------------------------------------------------------------\n");
                    printf("\n               Anda Memilih Halte %s Pada Pukul %s \n", halte[i], jam[i]);
                    printf("                    Harga Yang Harus Dibayar = Rp%d \n", Harga[i]);
                    printf("                    Tiket Yang Anda Pesan Adalah %d \n", tiket);
                    goto cetak;
                }
            }
            else if (jawab == 'N' || jawab == 'n')
            {
                printf("--------------------------------------------\n");
                printf("           Silahkan Pilih Lagi!!!\n");
                printf("--------------------------------------------\n");
                goto ulang;
            }
        }
    }

    if (pilih != kodehalte[i])
    {
        printf("\n---------------------------------------------------------------------------------");
        printf("\n                      Tidak Ada Halte Yang Tersedia\n\t\t\t   Terimakasih!!!");
        printf("\n---------------------------------------------------------------------------------\n");
    }
}

int main()
{
    char y;
    do
    {
        system("cls");
        int menu;
        printf("\n============================================================");
        printf("\n                       SELAMAT DATANG             ");
        printf("\n                            Di                    ");
        printf("\n                        E-SUROBOYO                ");
        printf("\n                           BIS                    ");
        printf("\n============================================================\n");
        printf("Menu     Pilihan            ");
        printf("\n------------------------------------------------------------\n");
        printf("1.       Lihat Jadwal\n");
        printf("2.       Tambah Halte\n");
        printf("3.       Informasi Jadwal\n");
        printf("4.       Mengurutkan Jadwal\n");
        printf("5.       Beli Tiket\n");
        printf("6.       Exit\n");
        printf("============================================================\n");
        printf("Pilih Menu\t: ");
        scanf("%i", &menu);

        switch (menu)
        {
        case 1:
            jadwal();
            break;
        case 2:
            tambahalte();
            break;
        case 3:
            info();
            break;
        case 4:
            urut();
            break;

        case 5:
            kasir();
            break;

        case 6:
            goto keluar;
        default:
            printf("tidak ada pilihan yang kamu pilih\n");
        }
        printf("\n\nApakah Ingin Kembali Ke Menu? (y/n)\t : ");
        scanf("%s", &y);

    } while (y != 'n');
keluar:
    system("cls");
    printf("--------------------------------------------\n");
    printf("           Terimakasih!!!\n");
    printf("--------------------------------------------\n");

    return 0;
}