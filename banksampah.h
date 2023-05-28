#ifndef BANKSAMPAH_H_INCLUDED
#define BANKSAMPAH_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextUser(P) (P)->nextUser
#define first(L) (L).first
#define last(L) (L).last
#define nil NULL

typedef struct elmTDU *adrTDU;
typedef struct elmUser *adrUser;

struct TDU {
    string nama;
    string alamat;
    float kapasitas;
};

struct elmTDU {
    TDU info;
    adrTDU prev;
    adrTDU next;
    adrUser nextUser;
};

struct mllTDU {
    adrTDU first;
    adrTDU last;
};

struct user {
    string pembuang;
    string jenis;
    float berat;
    string nama;
    string alamat;
};

struct elmUser {
    user info;
    adrUser next;
    adrUser prev;
};

struct mllUser {
    adrUser first;
    adrUser last;
};

// CREATE

void createTDU(mllTDU &L);
adrTDU createElemenTDU(TDU dataBaru);
void createUser(mllUser &L);
adrUser createElemenUser(user dataBaru);

// TDU

TDU newTDU(string nama, string alamat, float kapasitas);
void insertLastTDU(mllTDU &L, adrTDU P);
void showDataTDU (mllTDU L);

adrTDU deleteFirstTDU(mllTDU &L);
adrTDU deleteLastTDU(mllTDU &L);
adrTDU deleteAftertTDU(adrTDU prec);
void deleteTDU (mllTDU &L, adrTDU prec);

// USER

user newUser(string pembuang, string jenis, float berat, string nama, string alamat);
void insertLastUser(mllTDU &ListTDU, mllUser &ListUser, adrUser J);
void showDataUser(mllTDU L);
void deleteFirstUser(mllTDU &L, adrUser prec);
void deleteLastUser(mllTDU &L, adrUser prec);
void deleteAfterUser(mllTDU &L, adrUser prec);
void deleteUser(mllTDU &L ,adrUser prec);

// FIND

adrTDU findparent(mllTDU L, string nama);
adrTDU findDataEntry(mllTDU L, string nama, string alamat);
adrUser findChild(mllTDU L, string nama);
bool findDuplicateTDU(mllTDU L, string nama);
bool findDuplicateUser(mllTDU L, string pembuang);
void findPembuang(mllTDU L);
void infoUser(mllTDU L);

// RELASI

adrUser deleteRelasi(mllTDU &L, mllUser &temp, adrTDU S);
void createRelasi(mllTDU &L, adrUser P, adrTDU S);

// LAINNYA

void hitungJenis(mllTDU L);
void showAllData(mllTDU L);
void preLoadData(mllTDU &ListTDU, mllUser &ListUser);
void banyakUser(mllTDU L);
string selectMenu();

#endif // BANKSAMPAH_H_INCLUDED
