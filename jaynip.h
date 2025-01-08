#ifndef jaynip_H
#define jaynip_H

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// define
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define pustakawan(P) P->pustakawan
#define buku(P) P->buku

// pustakawan
struct infotypePustakawan {
    string kodePustakawan, namaPustakawan, email, noTelepon;
};
typedef struct elmPustakawan* adrPustakawan;
struct elmPustakawan {
    infotypePustakawan info;
    adrPustakawan next;
    adrPustakawan prev;
};
struct listPustakawan {
    adrPustakawan first;
    adrPustakawan last;
};

// buku
struct infotypeBuku {
    string kodeBuku, judulBuku, penulis, penerbit;
};
typedef struct elmBuku* adrBuku;
struct elmBuku {
    infotypeBuku info;
    adrBuku next;
};
struct listBuku {
    adrBuku first;
};

// relasi
typedef struct elmRelasi* adrRelasi;
struct elmRelasi {
    adrRelasi next;
    adrPustakawan pustakawan;
    adrBuku buku;
};
struct listRelasi {
    adrRelasi first;
};

// create list
void createListPustakawan(listPustakawan &LP);
void createListBuku(listBuku &LB);
void createListRelasi(listRelasi &LR);

// alokasi
adrPustakawan alokasiPustakawan(infotypePustakawan x);
adrBuku alokasiBuku(infotypeBuku x);

// function dan procedure
void insertFirstPustakawan(listPustakawan &LP, adrPustakawan P);
void insertLastPustakawan(listPustakawan &LP, adrPustakawan P);
void showPustakawan(listPustakawan LP);
void deletePustakawanRelasi(listPustakawan &LP, listRelasi &LR, string kodePustakawan);
adrPustakawan searchPustakawan(listPustakawan LP, string kodePustakawan);
adrBuku searchBuku(listBuku LB, string kodeBuku);
void addBuku(listBuku &LB, adrBuku B);
void addRelasi(listRelasi &LR, listPustakawan LP, listBuku LB, string kodePustakawan, string kodeBuku);
void showPustakawanBuku(listPustakawan LP, listRelasi LR);
void searchBukuByPustakawan(listBuku LB, listRelasi LR, listPustakawan LP, string kodePustakawan);
void deleteBukuRelasi(listBuku &LB, listRelasi &LR, string kodeBuku);
int totalBukuByPustakawan(listBuku LB, listRelasi LR, listPustakawan LP, string kodePustakawan);

void showBuku(listBuku LB);

#endif