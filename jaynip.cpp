#include "jaynip.h"

void createListPustakawan(listPustakawan &LP) {
    /* I.S -
       F.S terbentuk list pustakawan */

    first(LP) = NULL;
    last(LP) = NULL;
}

void createListBuku(listBuku &LB) {
    /* I.S -
       F.S terbentuk list buku */
    
    first(LB) = NULL;
}

void createListRelasi(listRelasi &LR) {
    /* I.S -
       F.S terbentuk list relasi */

    first(LR) = NULL;
}

adrPustakawan alokasiPustakawan(infotypePustakawan x) {
    /* I.S terdefinisi x yang bertipe infotypePustakawan
       F.S mengembalikan adrPustakawan yang berisi info = x, next = NULL, dan prev = NULL */

    adrPustakawan p = new elmPustakawan;

    next(p) = NULL;
    prev(p) = NULL;
    info(p) = x;

    return p;
}

adrBuku alokasiBuku(infotypeBuku x) {
    /* I.S terdefinisi x yang bertipe infotypeBuku
       F.S mengembalikan adrBuku yang berisi info = x dan next = NULL */
       
    adrBuku p = new elmBuku;

    next(p) = NULL;
    info(p) = x;

    return p;
}

void insertFirstPustakawan(listPustakawan &LP, adrPustakawan P) {
    /* I.S list pustakawan mungkin kosong
       F.S list pustakawan bertambah dari kiri (first) */

    if (first(LP) != NULL && last(LP) != NULL) {
        next(P) = first(LP);
        prev(first(LP)) = P;
        first(LP) = P;
    } else {
        first(LP) = P;
        last(LP) = P;
    }
}

void insertLastPustakawan(listPustakawan &LP, adrPustakawan P) {
    /* I.S list pustakawan mungkin kosong
       F.S list pustakawan bertambah dari kanan (last) */

    if (first(LP) != NULL && last(LP) != NULL) {
        prev(P) = last(LP);
        next(last(LP)) = P;
        last(LP) = P;
    } else {
        first(LP) = P;
        last(LP) = P;
    }
}

void showPustakawan(listPustakawan LP) {
    /* I.S sudah tersedia list Pustakawan
       F.S ditampilkan list pustakawan, jika kosong akan output "List pustakawan kosong" */
    
    adrPustakawan p = first(LP);

    if (first(LP) == NULL && last(LP) == NULL) {
        cout << "List pustakawan kosong" << endl;
    } else {
        printf("----------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-20s | %-30s | %-15s | \n", "Kode", "Nama", "Email", "No. Telepon");
        printf("----------------------------------------------------------------------------------------\n");
        while (p != NULL) {
            printf("| %-10s | %-20s | %-30s | %-15s | \n", info(p).kodePustakawan.c_str(), info(p).namaPustakawan.c_str(), info(p).email.c_str(), info(p).noTelepon.c_str());

            p = next(p);
        }
        printf("----------------------------------------------------------------------------------------\n");
    }
}

void deletePustakawanRelasi(listPustakawan &LP, listRelasi &LR, string kodePustakawan) {
    /* I.S terdefinisi kodePustakawan yang akan dihapus
       F.S menghapus pustakawan yang bernilai sama dengan kodePustakawan dalam list pustakawan serta list relasi */

    // Delete relasi yang menunjuk ke address kodePustakawans
    adrRelasi r = first(LR);
    adrRelasi prec = NULL;

    while (r != NULL) {
        if (info(pustakawan(r)).kodePustakawan == kodePustakawan) {
            if (r == first(LR)) {           // Data pertama
                first(LR) = next(r);
                delete r;
                r = first(LR);
            } else {                        // Data tengah/akhir
                next(prec) = next(r);
                delete r;
                r = next(prec);
            }
        } else {
            prec = r;
            r = next(r);
        }
    }

    // Delete pustakawan yang memiliki kode pustakawan == kodePustakawan
    adrPustakawan p = first(LP);
    adrPustakawan precP = NULL;

    while (p != NULL) {
        if (info(p).kodePustakawan == kodePustakawan) {
            if (p == first(LP)) { // Pustakawan pertama
                first(LP) = next(p);
                delete p;
                p = first(LP);
            } else { // Pustakawan di tengah atau terakhir
                next(precP) = next(p);
                delete p;
                p = next(precP);
            }
        } else {
            precP = p;
            p = next(p);
        }
    }
}

adrPustakawan searchPustakawan(listPustakawan LP, string kodePustakawan) {
    /* I.S terdefinisi kodePustakawan yang akan di cari dalam sebuah listPustakawan
       F.S jika kodePustakawan tidak ditemukan maka mengembalikan NULL, sebaliknya mengembalikan alamat pustakawan */

    adrPustakawan p = first(LP);

    while (p != NULL) {
        if (info(p).kodePustakawan == kodePustakawan) {
            return p;
        }
        p = next(p);
    }

    return NULL;
}

adrBuku searchBuku(listBuku LB, string kodeBuku) {
    /* I.S terdefinisi kodeBuku yang akan di cari dalam sebuah listBuku
       F.S jika kodeBuku tidak ditemukan maka mengembalikan NULL, sebaliknya mengembalikan alamat buku */

    adrBuku p = first(LB);

    while (p != NULL) {
        if (info(p).kodeBuku == kodeBuku) {
            return p;
        }
        p = next(p);
    }

    return NULL;
}

void addBuku(listBuku &LB, adrBuku B) {
    /* I.S list buku mungkin kosong
       F.S list buku bertambah dari kanan (last) */

    adrBuku p = first(LB);

    if (first(LB) == NULL) {
        first(LB) = B;
    } else {
        while (next(p) != NULL) {
            p = next(p);
        }
        next(p) = B;
    }
}

void addRelasi(listRelasi &LR, listPustakawan LP, listBuku LB, string kodePustakawan, string kodeBuku) {
    /* I.S list relasi mungkin kosong
       F.S list buku bertambah dari kanan (last), menghubungkan data pustakawan (by kodePustakawan) ke data buku (by kodeBuku) */

    adrRelasi p = new elmRelasi;
    adrPustakawan pus = searchPustakawan(LP, kodePustakawan);
    adrBuku buk = searchBuku(LB, kodeBuku);

    if (pus == NULL || buk == NULL) {
        cout << "Data pustakawan atau buku tidak tersedia" << endl;
    } else {
        next(p) = NULL;
        pustakawan(p) = pus;
        buku(p) = buk;

        adrRelasi q = first(LR);

        if (first(LR) == NULL) {
            first(LR) = p;
        } else {
            while (next(q) != NULL) {
                q = next(q);
            }
            next(q) = p;
        }
    }
}

void showPustakawanBuku(listPustakawan LP, listRelasi LR) {
    /* I.S sudah tersedia list pustakawan dan buku
       F.S ditampilkan list pustakawan beserta bukunya */

    adrPustakawan p = first(LP);
    
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-25s | %-30s | %-15s |\n", "Kode Pustakawan", "Nama Pustakawan", "Email", "No. Telepon");
    printf("--------------------------------------------------------------------------------------------------\n");
    while (p != NULL) {
        printf("| %-15s | %-25s | %-30s | %-15s |\n", info(p).kodePustakawan.c_str(), info(p).namaPustakawan.c_str(), info(p).email.c_str(), info(p).noTelepon.c_str());
        adrRelasi r = first(LR);

        while (r != NULL) {
            if (pustakawan(r) == p) {
                adrBuku b = buku(r);

                printf("    - Kode Buku: %s, Judul: %s, Penulis: %s, Penerbit: %s\n", info(b).kodeBuku.c_str(), info(b).judulBuku.c_str(), info(b).penulis.c_str(), info(b).penerbit.c_str());
            }
            r = next(r);
        }
        p = next(p);
    }
}

void searchBukuByPustakawan(listBuku LB, listRelasi LR, listPustakawan LP, string kodePustakawan) {
    /* I.S terdefinisi list relasi, list pustakawan, dan kodePustakawan
       F.S menampilkan semua buku berdasarkan kodePustakawan seorang pustakawan yang mengurusnya */
    
    adrPustakawan p = searchPustakawan(LP, kodePustakawan);

    // Pustakawan tidak ditemukan
    if (p == NULL) {
        cout << "Pustakawan dengan kode " << kodePustakawan << " tidak ditemukan" << endl;
        return;
    }

    printf("--------------------------------------------------------------------------------------------\n");
    cout << "Kode Pustakawan : " << info(p).kodePustakawan << endl;
    cout << "Nama            : " << info(p).namaPustakawan << endl;
    cout << "Email           : " << info(p).email << endl;
    cout << "No. Telepon     : " << info(p).noTelepon << endl;
    printf("--------------------------------------------------------------------------------------------\n");

    adrRelasi r = first(LR);

    while (r != NULL) {
        if (info(pustakawan(r)).kodePustakawan == kodePustakawan) {
            adrBuku b = buku(r);

            printf("Kode Buku: %s, Judul: %s, Penulis: %s, Penerbit: %s\n", info(b).kodeBuku.c_str(), info(b).judulBuku.c_str(), info(b).penulis.c_str(), info(b).penerbit.c_str());
        }
        r = next(r);
    }
    printf("--------------------------------------------------------------------------------------------\n");
}

void deleteBukuRelasi(listBuku &LB, listRelasi &LR, string kodeBuku) {
    /* I.S terdefinisi kodeBuku yang akan dihapus
       F.S menghapus buku yang bernilai sama dengan kodeBuku dalam list buku serta list relasi */

    // Delete relasi yang menunjuk ke address kodeBuku
    adrRelasi r = first(LR);
    adrRelasi precR = NULL;

    while (r != NULL) {
        if (info(buku(r)).kodeBuku == kodeBuku) {
            if (r == first(LR)) { // Relasi pertama
                first(LR) = next(r);
                delete r;
                r = first(LR);
            } else { // Relasi di tengah atau terakhir
                next(precR) = next(r);
                delete r;
                r = next(precR);
            }
        } else {
            precR = r;
            r = next(r);
        }
    }

    // Delete buku yang memiliki kode buku == kodeBuku
    adrBuku b = first(LB);
    adrBuku precB = NULL;

    while (b != NULL) {
        if (info(b).kodeBuku == kodeBuku) {
            if (b == first(LB)) { // Buku pertama
                first(LB) = next(b);
                delete b;
                b = first(LB);
            } else { // Buku di tengah atau terakhir
                next(precB) = next(b);
                delete b;
                b = next(precB);
            }
        } else {
            precB = b;
            b = next(b);
        }
    }
}

int totalBukuByPustakawan(listBuku LB, listRelasi LR, listPustakawan LP, string kodePustakawan) {
    /* I.S terdefinisi list buku, list relasi, list pustakawan, dan kodePustakawan
       F.S menghitung total buku yang berelasi dengan pustakawan tertentu */

    adrPustakawan p = searchPustakawan(LP, kodePustakawan);
    adrRelasi r = first(LR);
    int tot = 0;

    while (r != NULL) {
        if (info(pustakawan(r)).kodePustakawan == kodePustakawan) {
            tot++;
        }
        r = next(r);
    }

    return tot;
}

void showBuku(listBuku LB) {
    /* I.S sudah tersedia list buku
       F.S ditampilkan list buku, jika kosong akan output "List buku kosong" */
    
    adrBuku b = first(LB);

    if (first(LB) == NULL) {
        cout << "List buku kosong" << endl;
    } else {
        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-30s | %-25s | %-25s | \n", "Kode", "Judul", "Penulis", "Penerbit");
        printf("-------------------------------------------------------------------------------------------------------\n");
        while (b != NULL) {
            printf("| %-10s | %-30s | %-25s | %-25s | \n", info(b).kodeBuku.c_str(), info(b).judulBuku.c_str(), info(b).penulis.c_str(), info(b).penerbit.c_str());

            b = next(b);
        }
        printf("-------------------------------------------------------------------------------------------------------\n");
    }
}