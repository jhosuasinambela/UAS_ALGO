#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Struktur untuk menyimpan informasi barang
struct Barang
{
    int id;
    string nama;
    int jumlah;
    double harga;
};

// Class untuk mengelola gudang
class ManajemenGudang
{
private:
    vector<Barang> daftarBarang; // Vector untuk menyimpan data barang

    bool isNumeric(const string &str)
    {
        for (char const &c : str)
        {
            if (std::isdigit(c))
                return true;
        }
        return false;
    }

public:
    // Method untuk menambahkan data barang
    void tambahBarang()
    {
        Barang barang;
        cout << "Masukkan ID barang: ";
        while (!(cin >> barang.id))
        {
            cout << "ID harus berupa angka!\nMasukkan ID barang: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // untuk membersihkan buffer newline
        cout << "Masukkan nama barang: ";
        getline(cin, barang.nama);
        while (isNumeric(barang.nama))
        {
            cout << "Nama tidak boleh mengandung angka!\nCoba lagi: ";
            getline(cin, barang.nama);
        }
        cout << "Masukkan jumlah barang: ";
        while (!(cin >> barang.jumlah))
        {
            cout << "Jumlah harus berupa angka!\nMasukkan jumlah barang: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Masukkan harga per unit barang: ";
        while (!(cin >> barang.harga))
        {
            cout << "Harga harus berupa angka!\nMasukkan harga per unit barang: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        daftarBarang.push_back(barang);
        cout << "Data barang berhasil ditambahkan.\n";
    }

    // Method untuk menghapus data barang berdasarkan ID
    void hapusBarang(int id)
    {
        for (auto it = daftarBarang.begin(); it != daftarBarang.end(); ++it)
        {
            if (it->id == id)
            {
                daftarBarang.erase(it);
                cout << "Data barang dengan ID " << id << " berhasil dihapus.\n";
                return;
            }
        }
        cout << "Data barang dengan ID " << id << " tidak ditemukan.\n";
    }

    // Method untuk mencari barang berdasarkan ID
    void cariBarang(int id)
    {
        for (const auto &barang : daftarBarang)
        {
            if (barang.id == id)
            {
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
    void editBarang(int id)
    {
        for (auto &barang : daftarBarang)
        {
            if (barang.id == id)
            {
                cout << "Masukkan nama baru untuk barang dengan ID " << id << ": ";
                cin.ignore(); // untuk membersihkan buffer newline
                getline(cin, barang.nama);
                while (isNumeric(barang.nama))
                {
                    cout << "Nama tidak boleh mengandung angka!\nCoba lagi: ";
                    getline(cin, barang.nama);
                }
                cout << "Masukkan jumlah baru untuk barang dengan ID " << id << ": ";
                while (!(cin >> barang.jumlah))
                {
                    cout << "Jumlah harus berupa angka!\nMasukkan jumlah baru untuk barang dengan ID " << id << ": ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Masukkan harga per unit baru untuk barang dengan ID " << id << ": ";
                while (!(cin >> barang.harga))
                {
                    cout << "Harga harus berupa angka!\nMasukkan harga per unit baru untuk barang dengan ID " << id << ": ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Data barang berhasil diperbarui.\n";
                return;
            }
        }
        cout << "Data barang dengan ID " << id << " tidak ditemukan.\n";
    }

    // Method untuk menampilkan semua data barang
    void tampilkanSemuaBarang()
    {
        if (daftarBarang.empty())
        {
            cout << "Gudang kosong.\n";
        }
        else
        {
            cout << "Daftar Barang:\n";
            for (const auto &barang : daftarBarang)
            {
                cout << "ID: " << barang.id << " | Nama: " << barang.nama
                     << " | Jumlah: " << barang.jumlah << " | Harga per unit: " << barang.harga << endl;
            }
        }
    }
};

int main()
{
    ManajemenGudang gudang;
    int pilihan;
    int id;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Cari Barang\n";
        cout << "4. Edit Barang\n";
        cout << "5. Tampilkan Semua Barang\n";
        cout << "6. Keluar\n";
        cout << "\n";
        cout << "Pilihan Anda: ";
        while (!(cin >> pilihan))
        {
            cout << "Pilihan harus berupa angka!\nPilihan Anda: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan)
        {
        case 1:
            gudang.tambahBarang();
            break;
        case 2:
            cout << "Masukkan ID barang yang akan dihapus: ";
            while (!(cin >> id))
            {
                cout << "ID harus berupa angka!\nMasukkan ID barang yang akan dihapus: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            gudang.hapusBarang(id);
            break;
        case 3:
            cout << "Masukkan ID barang yang akan dicari: ";
            while (!(cin >> id))
            {
                cout << "ID harus berupa angka!\nMasukkan ID barang yang akan dicari: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            gudang.cariBarang(id);
            break;
        case 4:
            cout << "Masukkan ID barang yang akan diedit: ";
            while (!(cin >> id))
            {
                cout << "ID harus berupa angka!\nMasukkan ID barang yang akan diedit: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
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
