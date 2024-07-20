#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi barang
struct Barang {
    int id;
    string nama;
    int jumlah;
    double harga;
};

// Class untuk mengelola gudang
class ManajemenGudang {
private:
    vector<Barang> daftarBarang; // Vector untuk menyimpan data barang

public:
    // Method untuk menambahkan data barang
    void tambahBarang() {
        Barang barang;
        cout << "Masukkan ID barang: ";
        cin >> barang.id;
        cin.ignore(); // untuk membersihkan buffer newline
        cout << "Masukkan nama barang: ";
        getline(cin, barang.nama);
        cout << "Masukkan jumlah barang: ";
        cin >> barang.jumlah;
        cout << "Masukkan harga per unit barang: ";
        cin >> barang.harga;

        daftarBarang.push_back(barang);
        cout << "Data barang berhasil ditambahkan.\n";
    }

    // Method untuk menghapus data barang berdasarkan ID
    void hapusBarang(int id) {
        for (auto it = daftarBarang.begin(); it != daftarBarang.end(); ++it) {
            if (it->id == id) {
                daftarBarang.erase(it);
                cout << "Data barang dengan ID " << id << " berhasil dihapus.\n";
                return;
            }
        }
        cout << "Data barang dengan ID " << id << " tidak ditemukan.\n";
    }

    // Method untuk mencari barang berdasarkan ID
    void cariBarang(int id) {
        for (const auto& barang : daftarBarang) {
            if (barang.id == id) {
                cout << "ID barang: " << barang.id << endl;
                cout << "Nama barang: " << barang.nama << endl;
                cout << "Jumlah barang: " << barang.jumlah << endl;
                cout << "Harga per unit: " << barang.harga << endl;
                return;
            }
        }
        cout << "Data barang dengan ID " << id << " tidak ditemukan.\n";
    }

    // Method untuk mengedit data barang berdasarkan ID
    void editBarang(int id) {
        for (auto& barang : daftarBarang) {
            if (barang.id == id) {
                cout << "Masukkan nama baru untuk barang dengan ID " << id << ": ";
                cin.ignore(); // untuk membersihkan buffer newline
                getline(cin, barang.nama);
                cout << "Masukkan jumlah baru untuk barang dengan ID " << id << ": ";
                cin >> barang.jumlah;
                cout << "Masukkan harga per unit baru untuk barang dengan ID " << id << ": ";
                cin >> barang.harga;
                cout << "Data barang berhasil diperbarui.\n";
                return;
            }
        }
        cout << "Data barang dengan ID " << id << " tidak ditemukan.\n";
    }

    // Method untuk menampilkan semua data barang
    void tampilkanSemuaBarang() {
        if (daftarBarang.empty()) {
            cout << "Gudang kosong.\n";
        } else {
            cout << "Daftar Barang:\n";
            for (const auto& barang : daftarBarang) {
                cout << "ID: " << barang.id << " | Nama: " << barang.nama
                          << " | Jumlah: " << barang.jumlah << " | Harga per unit: " << barang.harga << endl;
            }
        }
    }
};

int main() {
    ManajemenGudang gudang;
    int pilihan;
    int id;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Cari Barang\n";
        cout << "4. Edit Barang\n";
        cout << "5. Tampilkan Semua Barang\n";
        cout << "6. Keluar\n";
        cout << "\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                gudang.tambahBarang();
                break;
            case 2:
                cout << "Masukkan ID barang yang akan dihapus: ";
                cin >> id;
                gudang.hapusBarang(id);
                break;
            case 3:
                cout << "Masukkan ID barang yang akan dicari: ";
                cin >> id;
                gudang.cariBarang(id);
                break;
            case 4:
                cout << "Masukkan ID barang yang akan diedit: ";
                cin >> id;
                gudang.editBarang(id);
                break;
            case 5:
                gudang.tampilkanSemuaBarang();
                break;
            case 6:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 6);

    return 0;
}
