//Nama :adinda denada
//NIM  :23343024

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct DataPenduduk {
    string nama;
    string alamat;
    string NIK;
    bool terdaftarDTKS;
};

const int MAX_PENDUDUK = 100;

string generateDTKSCode(int id) {
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int codeLength = 12;

    string DTKScode;
    for (int i = 0; i < codeLength; ++i) {
        int index = rand() % characters.length();
        DTKScode += characters.at(index);
    }

    return DTKScode + to_string(id);
}

void addData(DataPenduduk data_penduduk[], int &jumlah_penduduk) {
    if (jumlah_penduduk < MAX_PENDUDUK) {
        cout << "Masukkan nama penduduk           : ";
        cin >> data_penduduk[jumlah_penduduk].nama;
        cout << "Masukkan alamat penduduk         : ";
        cin >> data_penduduk[jumlah_penduduk].alamat;
        cout << "Masukkan nomor NIK               : ";
        cin >> data_penduduk[jumlah_penduduk].NIK;

        data_penduduk[jumlah_penduduk].terdaftarDTKS = false;
        jumlah_penduduk++;
        cout << "Data pelanggan berhasil ditambahkan." << endl;
    } else {
        cout << "Batas maksimum tercapai." << endl;
    }
}

void searchData(DataPenduduk data_penduduk[], int jumlah_penduduk) {
    string nama_dicari;
    bool ditemukan = false;
    cout << "Masukkan nama penduduk: ";
    cin >> nama_dicari;

    cout << "Data Penduduk " << nama_dicari << ":" << endl;
    for (int i = 0; i < jumlah_penduduk; ++i) {
        if (data_penduduk[i].nama == nama_dicari) {
            ditemukan = true;
            cout << "Penduduk " << i + 1 << ":" << endl;
            cout << "Nama  : " << data_penduduk[i].nama << endl;
            cout << "NIK   : " << data_penduduk[i].NIK << endl;
            cout << "Alamat: " << data_penduduk[i].alamat << endl;
            cout << "-------------------------" << endl;

            if (data_penduduk[i].terdaftarDTKS) {
                cout << nama_dicari << " terdaftar sebagai penerima bantuan DTKS" << endl;
            } else {
                cout << nama_dicari << " tidak terdaftar sebagai penerima bantuan DTKS" << endl;
            }
        }
    }

    if (!ditemukan) {
        cout << "Data Tidak Ditemukan" << endl;
    }
}

void displayDTKSPendaftar(DataPenduduk data_penduduk[], int jumlah_penduduk) {
    cout << "=== Data Pendaftar DTKS ===" << endl;
    for (int i = 0; i < jumlah_penduduk; ++i) {
        cout << "Pendaftar " << i + 1 << ":" << endl;
        cout << "Nama  : " << data_penduduk[i].nama << endl;
        cout << "NIK   : " << data_penduduk[i].NIK << endl;
        cout << "Alamat: " << data_penduduk[i].alamat << endl;
        cout << "Terdaftar DTKS: " << (data_penduduk[i].terdaftarDTKS ? "Ya" : "Tidak") << endl;
        cout << "-------------------------" << endl;

        if (data_penduduk[i].terdaftarDTKS) {
            cout << "Code DTKS: " << generateDTKSCode(i + 1) << endl;
        } else {
            cout << "Tidak terdaftar DTKS" << endl;
        }
    }
}

void pendaftaranDTKS(DataPenduduk data_penduduk[], int &jumlah_penduduk) {
    cout << "=== Pendaftaran DTKS ===" << endl;
    cout << "Masukkan NIK untuk pendaftaran DTKS: ";
    string NIK_pendaftar;
    cin >> NIK_pendaftar;

    for (int i = 0; i < jumlah_penduduk; ++i) {
        if (data_penduduk[i].NIK == NIK_pendaftar) {
            if (!data_penduduk[i].terdaftarDTKS) {
                data_penduduk[i].terdaftarDTKS = true;
                cout << "Pendaftaran DTKS berhasil." << endl;
            } else {
                cout << "NIK sudah terdaftar sebagai penerima bantuan DTKS." << endl;
            }
            return;
        }
    }

    cout << "NIK tidak terdaftar sebagai penduduk." << endl;
}

void bantuan(DataPenduduk data_penduduk[], int jumlah_penduduk) {
    string NIK_pendaftar;
    cout << "Masukkan NIK Anda: ";
    cin >> NIK_pendaftar;

    for (int i = 0; i < jumlah_penduduk; ++i) {
        if (data_penduduk[i].NIK == NIK_pendaftar) {
            if (data_penduduk[i].terdaftarDTKS) {
                cout << "Anda mendapatkan bantuan sembako dan uang sebesar Rp1.500.000" << endl;
            } else {
                cout << "Anda mendapatkan bantuan uang sebesar Rp300.000" << endl;
            }
            return;
        }
    }

    cout << "NIK tidak terdaftar sebagai penduduk." << endl;
}

int main() {
    srand(time(0));
    DataPenduduk data_penduduk[MAX_PENDUDUK];
    int jumlah_penduduk = 0;
    string ulang;

    do {
        cout << " Bantuan Sosial Pandemi Covid 19" << endl;
        cout << " ================================" << endl;
        cout << "1. Menambahkan data" << endl;
        cout << "2. Mencari data" << endl;
        cout << "3. Pendaptaran DTKS" << endl;
        cout << "4. Tampilkan Data Penduduk" << endl;
        cout << "5. Jumlah Bantuan Yang Didapatkan" << endl;

        int pilihan;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                addData(data_penduduk, jumlah_penduduk);
                break;

            case 2:
                searchData(data_penduduk, jumlah_penduduk);
                break;

            case 3:
                pendaftaranDTKS(data_penduduk, jumlah_penduduk);
                break;

            case 4:
                displayDTKSPendaftar(data_penduduk, jumlah_penduduk);
                break;

            case 5:
                bantuan(data_penduduk, jumlah_penduduk);
                break;
        }

        cout << "Ulang proses (Ya/Tidak) : ";
        cin >> ulang;

    } while (ulang == "Ya" || ulang == "ya");

    return 0;
}
