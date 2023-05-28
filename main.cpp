#include <iostream>
#include "banksampah.h"

using namespace std;

int main()
{
    mllTDU LTDU;

    mllUser LUser;
    mllUser temp;

    createTDU(LTDU);
    createUser(LUser);
    createUser(temp);

    adrTDU P;
    adrTDU cariTDU;
    adrTDU cariT;

    adrUser Q;
    adrUser cariUser;
    adrUser prec;

    TDU dataT;
    user dataU;

    string nama, alamat;
    float kapasitas;
    bool cekT;

    string pembuang, jenis, tempat, alamatB;
    float berat;
    bool cekU;

    cout << "================= BANK SAMPAH =================" << endl;

    string Back = "Y";
    string pilihan;

 //   preLoadData(LTDU, LUser);     // Uncomment line ini jika ingin terdapat data banyak tanpa harus input lagi ^_^

    while (Back != "t" || Back != "T") {
        if (Back == "y" || Back == "Y") {
            pilihan = selectMenu();
            cout << endl;

            if (pilihan == "0") { // Keluar dari Program

                cout << endl;
                cout << "Thank you!" << endl;
                break;

            } else if (pilihan == "1") { // Tambah data TDU

                    cout << "Nama Tempat Daur Ulang                     : TDU ";
                    cin >> nama;
                    cout << "Alamat Tempat Daur Ulang                   : ";
                    cin.ignore();
                    getline(cin, alamat);
                    cout << "Kapasitas Sampah di Tempat Daur Ulang (kg) : ";
                    cin >> kapasitas;
                    cout << endl;

                    cekT = findDuplicateTDU(LTDU, nama);

                    if(cekT) {
                        cout << "Data yang diinput sudah terdaftar!" << endl;
                    } else {
                        dataT = newTDU(nama, alamat, kapasitas);
                        P = createElemenTDU(dataT);
                        insertLastTDU(LTDU, P);
                    }

            } else if (pilihan == "2") { // Delete data TDU

                    cout << "Masukkan nama TDU yang ingin dihapus       : TDU ";
                    cin.ignore();
                    getline(cin, nama);

                    cekT = findDuplicateTDU(LTDU, nama);

                    if (cekT) {
                        cariTDU = findparent(LTDU, nama);

                        deleteTDU(LTDU, cariTDU);
                    } else {
                        cout << "Tidak ada TDU dengan nama tersebut!" << endl;
                    }

            } else if (pilihan == "3") { // Show data TDU

                showDataTDU(LTDU);

            } else if (pilihan == "4") { // Find TDU

                    cout << "Masukkan nama TDU yang ingin dicari    : TDU ";
                    cin >> nama;

                    cekT = findDuplicateTDU(LTDU, nama);
                    cariTDU = findparent(LTDU, nama);

                    if (cekT) {
                        cout << endl;
                        cout << "Tempat Daur Ulang Ditemukan!" << endl;
                        cout << endl;
                        cout << "Nama Tempat Daur Ulang                 : TDU " << info(cariTDU).nama << endl;
                        cout << "Alamat Tempat Daur Ulang               : " << info(cariTDU).alamat << endl;
                        cout << "Kapasitas Sampah di Tempat Daur Ulang  : " << info(cariTDU).kapasitas << " kg" << endl;
                    } else {
                        cout << "Tidak ada TDU dengan nama tersebut!" << endl;

                    }

            } else if (pilihan == "5") { // Insert User

                    cout << "Nama Pembuang Sampah               : ";
                    cin.ignore();
                    getline(cin, pembuang);
                    cout << "Jenis Sampah (Anorganik/Organik)   : ";
                    cin >> jenis;
                    cout << "Berat Sampah (kg)                  : ";
                    cin >> berat;
                    cout << endl;
                    cout << "Tempat Daur Ulang                  : TDU ";
                    cin >> tempat;
                    cout << endl;
                    cout << "Alamat Tempat Daur Ulang           : ";
                    cin.ignore();
                    getline(cin, alamatB);

                    cekU = findDuplicateUser(LTDU, pembuang);

                    if(cekU) {
                        cout << "Data yang diinput sudah terdaftar!" << endl;
                    } else {
                        dataU = newUser(pembuang, jenis, berat, tempat, alamatB);
                        Q = createElemenUser(dataU);
                        insertLastUser(LTDU, LUser, Q);
                    }

            } else if (pilihan == "6") { // Delete user

                    cout << "Masukkan user yang ingin dihapus   : ";
                    cin >> pembuang;

                    cekU = findDuplicateUser(LTDU, pembuang);

                    if (cekU) {
                        cariUser = findChild(LTDU, pembuang);

                        deleteUser(LTDU, cariUser);

                    } else {
                        cout << "Tidak ada user dengan nama tersebut!" << endl;

                    }

            } else if (pilihan == "7") { // Show data user

                showDataUser(LTDU);

            } else if (pilihan == "8") { // Cari tempat user mendaur ulang

                findPembuang(LTDU);

            } else if (pilihan == "9") { // Delete relation

                cout << "Masukkan nama tempat daur ulang        : TDU ";
                cin >> nama;

                cariT = findparent(LTDU, nama);

                prec = deleteRelasi(LTDU, temp, cariT);

            } else if (pilihan == "10") { // Create relation

                cout << "Masukkan nama tempat daur ulang        : TDU ";
                cin >> nama;
                cout << endl;

                cariT = findparent(LTDU, nama);
                createRelasi(LTDU, prec, cariT);

            } else if (pilihan == "11") { // Banyak pembuang pada TDU tertentu
                banyakUser(LTDU);

            } else if (pilihan == "12") { // Show TDU dari pembuang yg dicari
                infoUser(LTDU);

            } else if (pilihan == "13") { // Show all data

                showAllData(LTDU);

            } else { // Input selain 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0
                cout << "Input salah!" << endl;
                cout << endl;
            }
        }
        else   {
            cout << "Input Salah!" << endl <<endl;
        }
        cout << endl;
        cout << "=================== SELESAI ===================" << endl;
        cout << "Kembali ke menu utama? (Y/T): ";
        cin >> Back;
        cout << endl;

        if (Back == "t" || Back == "T"){
            cout << "OK Thank You!" << endl;
            break;
        }
    }

    cout << endl;
    cout << "Dadah!" << endl;

    return 0;
}
