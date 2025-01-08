#include "jaynip.h"

int main () {
    listPustakawan LP;
    createListPustakawan(LP);
    listBuku LB;
    createListBuku(LB);
    listRelasi LR;
    createListRelasi(LR);

    printf("----------------------------------------\n");
    printf("                MAIN MENU               \n");
    printf("----------------------------------------\n");
    printf("1.  Tambah Pustakawan (First)           \n");
    printf("2.  Tambah Pusatakawan (Last)           \n");
    printf("3.  Tambah Buku                         \n");
    printf("4.  Tambah Relasi                       \n");
    printf("5.  Tampilkan Pustakawan                \n");
    printf("6.  Tampilkan Buku                      \n");
    printf("7.  Tampilkan Pustakawan dan Bukunya    \n");
    printf("8.  Tampilkan Buku dari Pustakawan      \n");
    printf("9.  Hapus Pustakawan berserta Relasi    \n");
    printf("10. Hapus Buku berserta Relasi          \n");
    printf("11. Jumlah Buku dari Pustakawan         \n");
    printf("12. Keluar                              \n");
    printf("----------------------------------------\n");

    int opsi;
    cout << "Pilih [1-12]: ";
    cin >> opsi;

    while (opsi != 12) {
        if (opsi == 1) {
            cout << "\033[2J\033[1;1H"; 
            cout << "Masukkan n: ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\033[2J\033[1;1H";
                infotypePustakawan pus;

                cout << "Kode Pustakawan: ";
                cin >> pus.kodePustakawan;
                cout << "Nama Pustakawan: ";
                cin >> pus.namaPustakawan;
                cout << "Email: ";
                cin >> pus.email;
                cout << "No. Telepon: ";
                cin >> pus.noTelepon;
                insertFirstPustakawan(LP, alokasiPustakawan(pus));
            }
        } else if (opsi == 2) {
            cout << "\033[2J\033[1;1H"; 
            cout << "Masukkan n: ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\033[2J\033[1;1H";
                infotypePustakawan pus;

                cout << "Kode Pustakawan: ";
                cin >> pus.kodePustakawan;
                cout << "Nama Pustakawan: ";
                cin >> pus.namaPustakawan;
                cout << "Email: ";
                cin >> pus.email;
                cout << "No. Telepon: ";
                cin >> pus.noTelepon;
                insertLastPustakawan(LP, alokasiPustakawan(pus));
            }
        } else if (opsi == 3) {
            cout << "\033[2J\033[1;1H"; 
            cout << "Masukkan n: ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\033[2J\033[1;1H";
                infotypeBuku buk;

                cout << "Kode Buku: ";
                cin >> buk.kodeBuku;
                cout << "Judul Buku: ";
                cin >> buk.judulBuku;
                cout << "Penulis: ";
                cin >> buk.penulis;
                cout << "Penerbit: ";
                cin >> buk.penerbit;
                addBuku(LB, alokasiBuku(buk));
            }
        } else if (opsi == 4) {
            cout << "\033[2J\033[1;1H"; 
            cout << "Masukkan n: ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\033[2J\033[1;1H";

                cout << "Masukkan kode pustakawan: ";
                string kodePustakawan;
                cin >> kodePustakawan;

                cout << "Masukkan kode buku: ";
                string kodeBuku;
                cin >> kodeBuku;

                addRelasi(LR, LP, LB, kodePustakawan, kodeBuku);
            }
        } else if (opsi == 5) {
            cout << "\033[2J\033[1;1H";

            showPustakawan(LP);

            cout << "Lanjut [y?]: ";
            char lanjut;
            cin >> lanjut;
        } else if (opsi == 6) {
            cout << "\033[2J\033[1;1H";

            showBuku(LB);

            cout << "Lanjut [y?]: ";
            char lanjut;
            cin >> lanjut;
        } else if (opsi == 7) {
            cout << "\033[2J\033[1;1H";

            showPustakawanBuku(LP, LR);

            cout << "Lanjut [y?]: ";
            char lanjut;
            cin >> lanjut;
        } else if (opsi == 8) {
            cout << "\033[2J\033[1;1H";

            cout << "Masukkan kode pustakawan: ";
            string kodePustakawan;
            cin >> kodePustakawan;
            searchBukuByPustakawan(LB, LR, LP, kodePustakawan);

            cout << "Lanjut [y?]: ";
            char lanjut;
            cin >> lanjut;
        } else if (opsi == 9) {
            cout << "\033[2J\033[1;1H";
            
            cout << "Masukkan kode pustakawan: ";
            string kodePustakawan;
            cin >> kodePustakawan;
            deletePustakawanRelasi(LP, LR, kodePustakawan);
        } else if (opsi == 10) {
            cout << "\033[2J\033[1;1H";
            
            cout << "Masukkan kode buku: ";
            string kodeBuku;
            cin >> kodeBuku;
            deleteBukuRelasi(LB, LR, kodeBuku);
        } else if (opsi == 11) {
            cout << "\033[2J\033[1;1H";
            
            cout << "Masukkan kode pustakawan: ";
            string kodePustakawan;
            cin >> kodePustakawan;
            cout << "Jumlah: " << totalBukuByPustakawan(LB, LR, LP, kodePustakawan) << endl;
            
            cout << "Lanjut [y/n]: ";
            char lanjut;
            cin >> lanjut;
        }

        cout << "\033[2J\033[1;1H"; 
        printf("----------------------------------------\n");
        printf("                MAIN MENU               \n");
        printf("----------------------------------------\n");
        printf("1.  Tambah Pustakawan (First)           \n");
        printf("2.  Tambah Pusatakawan (Last)           \n");
        printf("3.  Tambah Buku                         \n");
        printf("4.  Tambah Relasi                       \n");
        printf("5.  Tampilkan Pustakawan                \n");
        printf("6.  Tampilkan Buku                      \n");
        printf("7.  Tampilkan Pustakawan dan Bukunya    \n");
        printf("8.  Tampilkan Buku dari Pustakawan      \n");
        printf("9.  Hapus Pustakawan berserta Relasi    \n");
        printf("10. Hapus Buku berserta Relasi          \n");
        printf("11. Jumlah Buku dari Pustakawan         \n");
        printf("12. Keluar                              \n");
        printf("----------------------------------------\n");
        cout << "Pilih [1-12]: ";
        cin >> opsi;
    }
    
}