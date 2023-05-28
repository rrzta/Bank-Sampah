#include "banksampah.h"

// CREATE

void createTDU(mllTDU &L) {
    first(L) = nil;
    last(L) = nil;
}

adrTDU createElemenTDU(TDU dataBaru) {
    adrTDU P;
    P = new elmTDU;

    info(P).nama = dataBaru.nama;
    info(P).alamat = dataBaru.alamat;
    info(P).kapasitas = dataBaru.kapasitas;
    next(P) = nil;
    prev(P) = nil;
    nextUser(P) = nil;

    return P;
}

void createUser(mllUser &L) {
    first(L) = nil;
    last(L) = nil;
}

adrUser createElemenUser(user dataBaru) {
    adrUser P;
    P = new elmUser;

    info(P).pembuang = dataBaru.pembuang;
    info(P).jenis = dataBaru.jenis;
    info(P).berat = dataBaru.berat;
    info(P).nama = dataBaru.nama;
    info(P).alamat = dataBaru.alamat;

    next(P) = nil;
    prev(P) = nil;

    return P;
}

// TDU

TDU newTDU(string nama, string alamat, float kapasitas) {
    TDU x;

    x.nama = nama;
    x.alamat = alamat;
    x.kapasitas = kapasitas;

    return x;
}

void insertLastTDU(mllTDU &L, adrTDU P) {
    if (first(L) == nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void showDataTDU(mllTDU L) {
    adrTDU P;

    if (first(L) == nil) {
        cout << "Tidak ada data TDU!\n\n";
    } else {
        P = first(L);
        while (P != nil) {
            cout << "Nama TDU               : TDU " << info(P).nama << endl;
            cout << "Alamat TDU             : " << info(P).alamat << endl;
            cout << "Kapasitas Sampah di TDU: " << info(P).kapasitas << " kg" << endl;
            P = next(P);
        }
        cout << endl;
        cout << "Data TDU selesai ditampilkan!\n\n";
    }
}

adrTDU deleteFirstTDU(mllTDU &L) {
    adrTDU P;

    P = first(L);
    if (next(first(L)) == nil) {
        first(L) = nil;
        last(L) = nil;
    } else {
        first(L) = next(first(L));
        prev(first(L)) = nil;
        next(P) = nil;
    }

    return P;
}

adrTDU deleteLastTDU(mllTDU &L) {
    adrTDU P;

    P = last(L);

    if (prev(last(L)) != nil) {
        last(L) = prev(last(L));
        prev(P) = nil;
        next(last(L)) = nil;
    } else {
        first(L) = nil;
        last(L) = nil;
    }

    return P;
}

adrTDU deleteAfterTDU(adrTDU prec) {
    adrTDU P;

    P = next(prec);
    next(prec) = next(P);
    prev(next(P)) = prec;
    prev(P) = nil;
    next(P) = nil;

    return P;
}

void deleteTDU(mllTDU &L, adrTDU prec) {
    adrTDU P, Q;

    P = nil;
    Q = first(L);
    while (Q != nil){
        if (Q == prec){
            P = Q;
        }
        Q = next(Q);
    }
    if (P != nil){
        if (P == first(L)){
            deleteFirstTDU(L);
        } else if (next(P) == nil){
            deleteLastTDU(L);
        } else {
            prec = first(L);
            while (next(prec) != P){
                prec = next(prec);
            }
            deleteAfterTDU(prec);
        }
    }
}

// USER

user newUser(string pembuang, string jenis, float berat, string nama, string alamat) {
    user x;

    x.pembuang = pembuang;
    x.jenis = jenis;
    x.berat = berat;
    x.nama = nama;
    x.alamat = alamat;

    return x;
}

void insertLastUser(mllTDU &ListTDU, mllUser &ListUser, adrUser J) {
    adrUser P;
    adrTDU S;

    S = findDataEntry(ListTDU, info(J).nama, info(J).alamat);

    P = nextUser(S);

    if (nextUser(S) == nil) {
        nextUser(S) = J;
    } else {
        while (next(P) != nil) {
            P = next(P);
        }
        next(P) = J;
    }
}

void showDataUser(mllTDU L) {
    adrTDU P;
    adrUser Q;
    int i = 1;

    P = first(L);
    if (P != nil) {
        while (P != nil) {
            Q = nextUser(P);
            while (Q != nil) {
                cout << endl;
                cout << "Informasi Pembuang [" << i << "]" << endl;
                cout << "Nama Pembuang                      : " << info(Q).pembuang << endl;
                cout << "Jenis Sampah (Anorganik/Organik)   : " << info(Q).jenis << endl;
                cout << "Berat (kg)                         : " << info(Q).berat << " kg" << endl;
                cout << "Tempat Daur Ulang                  : TDU " << info(Q).nama << endl;
                cout << "Alamat Tempat Daur Ulang           : " << info(Q).alamat << endl;
                cout << endl;

                Q = next(Q);
                i++;
            }
            P = next(P);
        }
        cout << endl;
        if (Q == nil) {
            cout << "Data Kosong!" << endl;
        }
    } else {
        cout << "Data Kosong!" << endl;
    }
}

void deleteFirstUser(mllTDU &L, adrUser prec) {
    adrTDU P;
    adrUser Q;

    P = first(L);
    while (P != nil) {
        Q = nextUser(P);
        while (Q != nil) {
            if (Q == prec) {
                nextUser(P) = next(Q);
                next(Q) = nil;
                prev(Q) = nil;
            }
            Q = next(Q);
        }
        P = next(P);
    }
}

void deleteLastUser(mllTDU &L, adrUser prec) {
    adrTDU P;
    adrUser Q;
    adrUser R;

    P = first(L);
    while (P != nil) {
        Q = nextUser(P);
        while (Q != nil) {
            if (Q != prec) {
                if (next(Q) == prec) {
                    R = next(Q);
                    next(Q) = nil;
                    prev(R) = nil;
                    next(R) = nil;
                }
            }
            Q = next(Q);
        }
        P = next(P);
    }
}

void deleteAfterUser(mllTDU &L, adrUser prec) {
    adrTDU P;
    adrUser Q;
    adrUser R;

    P = first(L);
    while (P != nil) {
        Q = nextUser(P);
        while (Q != nil) {
            if (Q != prec) {
                if (next(Q) == prec) {
                    R = next(Q);
                    prev(next(Q)) = prev(Q);
                    next(Q) = next(R);
                    prev(R) = nil;
                    next(R) = nil;
                }
            }
            Q = next(Q);
        }
        P = next(P);
    }
}

void deleteUser(mllTDU &L ,adrUser prec) {
    adrTDU P;
    adrUser Q;

    P = first(L);

    while (P != nil) {
        Q = nextUser(P);
        while (Q != nil) {
            if (Q == prec) {
                if (Q != nil) {
                    if (Q == nextUser(P)) {
                        deleteFirstUser(L, prec);
                    } else if (next(Q) == nil) {
                        deleteLastUser(L, prec);
                    } else {
                        deleteAfterUser(L, prec);
                    }
                }
                break;
            }
            Q = next(Q);
        }
        P = next(P);
    }
}

// FIND

adrTDU findparent (mllTDU L, string nama) {
    adrTDU P = first(L);
    adrTDU Q;

    while (P != nil) {
        if (info(P).nama == nama) {
            Q = P;
        }
        P = next(P);
    }
    return Q;
}

adrTDU findDataEntry(mllTDU L, string nama, string alamat) {
    adrTDU P = first(L);
    adrTDU data;

    if (P != nil) {
        while (P != nil) {
            if (nama == info(P).nama && alamat == info(P).alamat) {
                data = P;
            }
            P = next(P);
        }
    }
    return data;
}

adrUser findChild(mllTDU L, string nama) {
    adrUser P, S;
    adrTDU Q;

    Q = first(L);
    while (Q != nil){
        P = nextUser(Q);
        while (P != nil){
            if (info(P).pembuang == nama) {
                S = P;
            }
            P = next(P);
        }
        Q = next(Q);
    }

    return S;
}

bool findDuplicateTDU(mllTDU L, string nama) {
    adrTDU P;
    bool cek = false;

    P = first(L);
    while(P != nil) {
        if(info(P).nama == nama) {
            cek = true;
            return cek;
        }
        P = next(P);
    }
    return cek;
}

bool findDuplicateUser(mllTDU L, string pembuang) {
    adrUser P, S;
    adrTDU Q;
    bool cek = false;

    S = findChild(L, pembuang);

    Q = first(L);
    while (Q != nil){
        P = nextUser(Q);
        while (P != nil){
            if (S == P) {
                cek = true;
                return cek;
            }
            P = next(P);
        }
        Q = next(Q);
    }
    return cek;
}

void findPembuang(mllTDU L) {
    adrUser P, S;
    adrTDU Q;
    bool cek;
    string x;

    cout << "Masukkan Nama Pembuang    : ";
    cin >> x;
    S = findChild(L, x);

    cek = findDuplicateUser(L, x);

    if (cek) {
        Q = first(L);
        while (Q != nil){
            P = nextUser(Q);
            while (P != nil){
                if (S == P) {
                    cout << endl;
                    cout << "Pembuang ditemukan!" << endl;
                    cout << endl;
                    cout << "Nama                       : " << info(P).pembuang << endl;
                    cout << "Jenis Sampah               : " << info(P).jenis << endl;
                    cout << "Berat (kg)                 : " << info(P).berat << " kg" << endl;
                    cout << "Tempat Daur Ulang          : TDU " << info(P).nama << endl;
                    cout << "Alamat Tempat Daur Ulang   : " << info(P).alamat << endl;
                    cout << endl;
                }
                P = next(P);
            }
            Q = next(Q);
        }
    } else {
        cout << "Nama Pembuang Tidak Ada!" << endl;
    }
}

void infoUser(mllTDU L) {
    adrUser P, S;
    adrTDU Q;
    bool cek;
    string x;

    cout << "Masukkan Nama Pembuang    : ";
    cin >> x;
    S = findChild(L, x);

    cek = findDuplicateUser(L, x);

    if (cek) {
        Q = first(L);
        while (Q != nil){
            P = nextUser(Q);
            while (P != nil){
                if (S == P) {
                    cout << "Nama Tempat Daur Ulang    : TDU " << info(Q).nama << endl;
                    cout << "Alamat Tempat Daur Ulang  : " << info(Q).alamat << endl;

                    cout << "Jenis Sampah              : " << info(P).jenis << endl;
                    cout << "Berat Sampah              : " << info(P).berat << " kg" << endl;

                }
                P = next(P);
            }
            Q = next(Q);
        }
    } else {
        cout << "Tidak Ada Informasi" << endl;
        cout << "Nama Pembuang Tidak Ditemukan" << endl;
    }
}


// RELASI

adrUser deleteRelasi(mllTDU &L, mllUser &temp, adrTDU S) {
    adrUser P, R;
    adrTDU Q = first(L);
    bool cek;

    cek = findDuplicateTDU(L, info(S).nama);

    if (cek) {
        while (Q != nil) {
            if (Q == S) {
                R = first(temp);
                P = nextUser(Q);
                R = P;
                nextUser(Q) = nil;
            }
            Q = next(Q);
        }
        cout << "Relasi Berhasil Dihapus!" << endl;

    } else {
        cout << "Relasi Gagal Dihapus!" << endl;

    }

    return R;
}

void createRelasi(mllTDU &L, adrUser P, adrTDU S) {
    adrTDU Q = first(L);
    bool cek;

    cek = findDuplicateTDU(L, info(S).nama);

    if (cek) {
        while (Q != nil) {
            if (Q == S) {
                nextUser(Q) = P;
            }
            Q = next(Q);
        }
        cout << "Relasi Telah Dibuat!" << endl;

    } else {
        cout << "Relasi Tidak Dapat Dibuat!" << endl;

    }
}

// LAINNYA

void hitungJenis(mllTDU L) {
    adrUser P;
    adrTDU R;

    float beratAn = 0;
    float beratOr = 0;

    R = first(L);
    if (R != nil) {
        while (R != nil){
            P = nextUser(R);
            while (P != nil){
                if (info(P).jenis == "Anorganik") {
                    beratAn = beratAn + info(P).berat;
                } else if (info(P).jenis == "Organik") {
                    beratOr = beratOr + info(P).berat;
                }
                P = next(P);
            }
            R = next(R);
        }
    }
    cout << "Berat Sampah Anorganik                 : " << beratAn << " kg" << endl;
    cout << "Berat Sampah Organik                   : " << beratOr << " kg" << endl;
}

void showAllData(mllTDU L) {
    adrUser P;
    adrTDU Q;
    int i = 1;

    Q = first(L);
    if (Q != nil) {
        while (Q != nil){
            cout << "Nama Tempat Daur Ulang                 : TDU " << info(Q).nama << endl;
            cout << "Alamat Tempat Daur Ulang               : " << info(Q).alamat << endl;
            cout << "Kapasitas Sampah (kg)                  : " << info(Q).kapasitas << " kg" << endl;

            P = nextUser(Q);
            i = 1;
            while (P != nil){
                cout << "Data Pembuang [" << i << "]" << endl;

                cout << "Nama Pembuang                          : " << info(P).pembuang << endl;
                cout << "Jenis Sampah (Anorganik/Organik)       : " << info(P).jenis << endl;
                cout << "Berat Sampah (kg)                      : " << info(P).berat << " kg" << endl;
                cout << "Tempat Daur Ulang                      : TDU " << info(P).nama << endl;
                cout << "Alamat Tempat Daur Ulang               : " << info(P).alamat << endl;

                P = next(P);
                i++;
            }
            cout << endl << endl;
            Q = next(Q);
        }
        hitungJenis(L);
    } else {
        cout << "Data kosong!" << endl;
    }
}

void preLoadData(mllTDU &ListTDU, mllUser &ListUser) {
    adrTDU dataTDU;

    adrUser dataUser;

    TDU dataT;
    user dataU;

    createTDU(ListTDU);
    createUser(ListUser);

    dataT = newTDU("Selamat", "Jl. Karangasem No. 13", 100);
    dataTDU = createElemenTDU(dataT);
    insertLastTDU(ListTDU, dataTDU);

    dataT = newTDU("Jaya", "Jl. Singaparna No. 20", 200);
    dataTDU = createElemenTDU(dataT);
    insertLastTDU(ListTDU, dataTDU);

    dataT = newTDU("Sentosa", "Jl. Durian No. 19", 300);
    dataTDU = createElemenTDU(dataT);
    insertLastTDU(ListTDU, dataTDU);

    dataT = newTDU("Indah", "Jl. Depok No. 34", 400);
    dataTDU = createElemenTDU(dataT);
    insertLastTDU(ListTDU, dataTDU);

    dataT = newTDU("Buaya", "Jl. Merak No. 41", 500);
    dataTDU = createElemenTDU(dataT);
    insertLastTDU(ListTDU, dataTDU);

    dataU = newUser("Siti", "Anorganik", 1, "Buaya", "Jl. Merak No. 41");
    dataUser = createElemenUser(dataU);
    insertLastUser(ListTDU, ListUser, dataUser);

    dataU = newUser("Alamanda", "Organik", 2, "Sentosa", "Jl. Durian No. 19");
    dataUser = createElemenUser(dataU);
    insertLastUser(ListTDU, ListUser, dataUser);

    dataU = newUser("Alan", "Anorganik", 3, "Buaya", "Jl. Merak No. 41");
    dataUser = createElemenUser(dataU);
    insertLastUser(ListTDU, ListUser, dataUser);

    dataU = newUser("Mark", "Organik", 4, "Sentosa", "Jl. Durian No. 19");
    dataUser = createElemenUser(dataU);
    insertLastUser(ListTDU, ListUser, dataUser);

    dataU = newUser("Azura", "Anorganik", 5, "Selamat", "Jl. Karangasem No. 13");
    dataUser = createElemenUser(dataU);
    insertLastUser(ListTDU, ListUser, dataUser);
}

void banyakUser(mllTDU L){
    adrUser P;
    adrTDU Q, R;
    string namaTDU;
    int totalUser = 0;
    float sisaKapasitas = 0;

    cout << "Masukkan Nama TDU              : TDU ";
    cin >> namaTDU;

    Q = findparent(L, namaTDU);

    R = first(L);
    if (R != nil) {
        while (R != nil){
            if(R == Q){
                cout << endl;
                cout << "INFORMASI USER PADA" << endl;
                cout << "Nama TDU                       : TDU " << info(R).nama << endl;
                cout << "Alamat TDU                     : " << info(R).alamat << endl;
                cout << "Kapasitas Sampah di TDU (kg)   : " << info(R).kapasitas << " kg" << endl;

                P = nextUser(R);

                if (P != nil){
                    while (P != nil){
                        totalUser++;
                        sisaKapasitas = info(R).kapasitas - info(P).berat;
                        P = next(P);
                }
                } else {
                    totalUser = 0;
                    sisaKapasitas = info(R).kapasitas;
                }

                cout << "Sisa Kapasitas (kg)            : " << sisaKapasitas << " kg" << endl;
                cout << "Banyak Pembuang                : " << totalUser << " orang" << endl;
                break;
            }
            R = next(R);
        }
        if (R != Q) {
            cout << "Tidak Ada User Pada TDU Ini!" << endl;
        }
    } else {
        cout << "Nama TDU Tidak Ditemukan Pada Database!" << endl;
    }
}


string selectMenu() {

    cout << "==================== MENU =====================" << endl;
    cout << "1.  Masukkan Data Tempat Daur Ulang            " << endl;
    cout << "2.  Hapus Data Tempat Daur Ulang               " << endl;
    cout << "3.  Perlihatkan Data Tempat Daur Ulang         " << endl;
    cout << "4.  Cari Tempat Daur Ulang                     " << endl;
    cout << "5.  Masukkan Data Pembuang                     " << endl;
    cout << "6.  Hapus Data Pembuang                        " << endl;
    cout << "7.  Perlihatkan Data Pembuang                  " << endl;
    cout << "8.  Cari Pembuang                              " << endl;
    cout << "9.  Hapus Relasi                               " << endl;
    cout << "10. Buat Relasi                                " << endl;
    cout << "11. Banyak Pembuang                            " << endl;
    cout << "12. Cari Info Tempat Pembuang Mendaur Ulang    " << endl;
    cout << "13. Perlihatkan Semua Data                     " << endl;
    cout << "0.  Keluar                                     " << endl;
    cout << "===============================================" << endl;
    cout << "Pilih menu: ";

    string input;
    cin >> input;

    return input;
}
