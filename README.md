# Manajemen Gudang

Program ini adalah contoh sederhana dari sistem manajemen gudang menggunakan bahasa pemrograman C++. Program ini memungkinkan pengguna untuk menambahkan, menghapus, mencari, mengedit, dan menampilkan data barang yang ada di gudang.

## Fitur

1. **Tambah Barang**: Menambahkan data barang ke dalam gudang.
2. **Hapus Barang**: Menghapus data barang dari gudang berdasarkan ID.
3. **Cari Barang**: Mencari data barang dalam gudang berdasarkan ID.
4. **Edit Barang**: Mengedit data barang dalam gudang berdasarkan ID.
5. **Tampilkan Semua Barang**: Menampilkan semua data barang yang ada di gudang.

## Struktur Data

Barang disimpan dalam struktur `Barang` yang memiliki atribut berikut:
- `id`: integer, ID unik dari barang
- `nama`: string, nama barang
- `jumlah`: integer, jumlah barang yang tersedia
- `harga`: double, harga per unit dari barang

## Kelas ManajemenGudang

Kelas `ManajemenGudang` mengelola daftar barang menggunakan vektor dan menyediakan metode untuk melakukan operasi CRUD (Create, Read, Update, Delete) pada data barang.

### Metode

- `void tambahBarang()`: Menambahkan data barang baru ke dalam gudang.
- `void hapusBarang(int id)`: Menghapus data barang berdasarkan ID.
- `void cariBarang(int id)`: Mencari data barang berdasarkan ID dan menampilkannya.
- `void editBarang(int id)`: Mengedit data barang berdasarkan ID.
- `void tampilkanSemuaBarang()`: Menampilkan semua data barang yang ada di gudang.

## Cara Menggunakan

1. Clone repositori ini atau salin kode sumber ke dalam file `main.cpp`.
2. Kompilasi kode dengan perintah:
    ```sh
    g++ main.cpp -o ManajemenGudang
    ```
3. Jalankan program:
    ```sh
    ./ManajemenGudang
    ```
4. Ikuti instruksi pada menu untuk menambahkan, menghapus, mencari, mengedit, atau menampilkan data barang.

## Contoh Penggunaan

Berikut adalah contoh interaksi dengan program:


Menu:

Tambah Barang
Hapus Barang
Cari Barang
Edit Barang
Tampilkan Semua Barang
Keluar
Pilihan Anda: 1
Masukkan ID barang: 101
Masukkan nama barang: Paku
Masukkan jumlah barang: 100
Masukkan harga per unit barang: 500

Data barang berhasil ditambahkan.

Menu:

Tambah Barang
Hapus Barang
Cari Barang
Edit Barang
Tampilkan Semua Barang
Keluar
Pilihan Anda: 5

Daftar Barang:
ID: 101 | Nama: Paku | Jumlah: 100 | Harga per unit: 500


## Kontribusi

Jika Anda ingin berkontribusi pada proyek ini, silakan fork repositori ini, buat branch baru untuk perubahan Anda, dan buat pull request. Kami akan meninjau perubahan Anda dan mempertimbangkannya untuk penggabungan.

