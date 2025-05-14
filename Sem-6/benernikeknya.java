1. Deklarasi Package dan Import
package ok1;

import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat;

Package yang digunakan adalah `ok1`, dan program mengimport beberapa kelas dari Java seperti `Scanner` untuk menerima input dari pengguna, `ArrayList` untuk menyimpan daftar treatment, pegawai, dan harga, `File` dan `FileWriter` untuk menulis data transaksi ke dalam file, dan `SimpleDateFormat` untuk mengatur format tanggal dan waktu.

2. Deklarasi Kelas dan Metode Main
public class benernikeknya {
    public static void main(String[] args) throws IOException {
        // Kode program
    }
}

Program ini memiliki kelas bernama `benernikeknya`, dan metode `main` sebagai entry point dari program. Metode `main` juga mendeklarasikan pengecualian `IOException` yang dapat terjadi saat menulis data ke dalam file.

3. Inisialisasi ArrayList
ArrayList<String> treatment = new ArrayList<>(Arrays.asList("Cukur Memek", "Creambath", "Cat Rambut"));
ArrayList<String> pegawai = new ArrayList<>(Arrays.asList("Lisa", "Jennie", "Rose"));
ArrayList<Integer> harga = new ArrayList<>(Arrays.asList(350000, 65000, 35000));

Tiga `ArrayList` diinisialisasi untuk menyimpan data treatment, pegawai, dan harga. Daftar treatment awal adalah "Cukur Memek", "Creambath", dan "Cat Rambut". Daftar pegawai awal adalah "Lisa", "Jennie", dan "Rose". Daftar harga awal adalah 350000, 65000, dan 35000.

4. Inisialisasi Scanner dan Variabel Lain
Scanner scanner = new Scanner(System.in);
Scanner strings = new Scanner(System.in);
boolean exit = false;
int nomornota = 1;

Dua objek `Scanner` diinisialisasi untuk menerima input dari pengguna, baik dalam bentuk angka (`scanner`) maupun string (`strings`). Variabel `exit` digunakan untuk mengontrol loop program, dan `nomornota` untuk menyimpan nomor nota transaksi.

5. Loop Utama Program
while (!exit) {
    // Kode program
}

Program memiliki sebuah loop `while` yang akan terus berjalan selama variabel `exit` bernilai `false`.

6. Menampilkan Menu Utama
System.out.println("============SALON PAS============");
System.out.println("Selamat datang di Salon PAS");
System.out.println("=================================");
System.out.println("1. List Treatment");
System.out.println("2. Tambah Treatment");
System.out.println("3. Transaksi");
System.out.println("4. Keluar");
System.out.println("");
System.out.print("Masukkan Pilihan : ");
System.out.print("");
Pilihan = scanner.nextInt();

Program menampilkan menu utama dengan empat opsi: (1) List Treatment, (2) Tambah Treatment, (3) Transaksi, dan (4) Keluar. Pengguna diminta untuk memasukkan pilihan melalui `scanner.nextInt()`.

7. Logika Pemilihan Opsi
if (Pilihan == 1) {
    // Kode untuk menampilkan list treatment
} else if (Pilihan == 2) {
    // Kode untuk menambah treatment baru
} else if (Pilihan == 3) {
    // Kode untuk melakukan transaksi
} else if (Pilihan == 4) {
    System.out.println("Terimakasih telah mampir ke Salon PAS");
    exit = true;
} else {
    System.out.println("");
    System.out.println("======Pilihan tidak valid======");
    System.out.println("Silahkan input ulang pilihan");
    System.out.println("");
}

Logika pemilihan opsi menggunakan struktur `if-else`. Jika pengguna memilih opsi 1, program akan menampilkan daftar treatment. Jika opsi 2, program akan meminta pengguna untuk menambahkan treatment baru. Jika opsi 3, program akan melakukan transaksi. Jika opsi 4, program akan keluar dari loop utama. Jika pilihan tidak valid, program akan meminta pengguna untuk memasukkan pilihan yang benar.

8. Menampilkan Daftar Treatment
System.out.println("");
System.out.println("====List Treatment====");
System.out.println("Menu Pilihan :");
for (int j = 0; j < treatment.size(); j++) {
    System.out.println((j + 1) + ". Treatment: " + treatment.get(j) + " || Pegawai : " + pegawai.get(j) + " || Harga : " + harga.get(j));
    System.out.println("");
}

Untuk menampilkan daftar treatment, program menggunakan perulangan `for` untuk mengakses setiap elemen pada `ArrayList` treatment, pegawai, dan harga. Setiap elemen ditampilkan dengan format tertentu.

9. Menambah Treatment Baru
System.out.println("");
System.out.println("");
System.out.println("++Tambah Treatment++");
System.out.print("\nMasukkan Nama Treatment : ");
String nama = strings.nextLine();
System.out.print("Masukkan Nama Pegawai : ");
String peg = strings.nextLine();
System.out.print("Masukkan Harga Treatment : ");
int hrg = scanner.nextInt();

treatment.add(nama);
pegawai.add(peg);
harga.add(hrg);

System.out.println("");
System.out.println("Data berhasil ditambahkan");
System.out.println("");

Untuk menambah treatment baru, program meminta pengguna untuk memasukkan nama treatment, nama pegawai, dan harga treatment. Data-data baru ini kemudian ditambahkan ke masing-masing `ArrayList` treatment, pegawai, dan harga menggunakan metode `add()`.

10. Melakukan Transaksi
System.out.println("");
System.out.println("==========KASIR==========");

System.out.print("Masukkan nama pelanggan : ");
String namapel = strings.nextLine();

System.out.print("Masukkan nama treatment : ");
String treatmentbeli = strings.nextLine();

// Kode untuk mencari treatment yang dipilih
// Kode untuk melakukan transaksi
// Kode untuk menulis data transaksi ke dalam file

Untuk melakukan transaksi, program meminta pengguna untuk memasukkan nama pelanggan dan nama treatment yang ingin dibeli. Selanjutnya, program akan mencari treatment yang dipilih dalam daftar treatment dan melakukan transaksi jika treatment tersedia.

11. Mencari Treatment yang Dipilih (Lanjutan)
int NoTreatment = treatment.indexOf(treatmentbeli);
for (int j = 0; j < treatment.size(); j++) {
    if (treatment.get(j).equalsIgnoreCase(treatmentbeli)) {
        NoTreatment = j;
    }
}
if (NoTreatment == -1) {
    System.out.println("Treatment tidak tersedia");
} else if (treatment.get(NoTreatment).equals("SOLD")) {
    System.out.println("Maaf, treatment tersebut sudah dipilih, silahkan pilih treatment yang lain");
} else {
    // Kode untuk melanjutkan transaksi
}


Program mencari treatment yang dipilih oleh pelanggan dalam daftar treatment menggunakan dua cara:

1. Menggunakan metode `indexOf()` dari `ArrayList`:
int NoTreatment = treatment.indexOf(treatmentbeli);

Metode `indexOf()` akan mencari indeks elemen pertama dalam `ArrayList` yang sama dengan `treatmentbeli`. Jika treatment tidak ditemukan, metode ini akan mengembalikan nilai -1.

2. Melakukan perulangan untuk mencari treatment secara case-insensitive:
for (int j = 0; j < treatment.size(); j++) {
    if (treatment.get(j).equalsIgnoreCase(treatmentbeli)) {
        NoTreatment = j;
    }
}

Perulangan ini akan memeriksa setiap elemen dalam `ArrayList` treatment. Metode `equalsIgnoreCase()` digunakan untuk membandingkan string secara case-insensitive (tidak membedakan huruf besar dan kecil). Jika ditemukan treatment yang sama (tidak peduli huruf besar atau kecil), variabel `NoTreatment` akan diisi dengan indeks treatment tersebut.

Setelah mencari treatment, program akan memeriksa beberapa kondisi:

1. Jika `NoTreatment == -1`, artinya treatment yang diminta tidak ditemukan dalam daftar. Program akan menampilkan pesan "Treatment tidak tersedia".

2. Jika `treatment.get(NoTreatment).equals("SOLD")`, artinya treatment yang diminta sudah terjual sebelumnya. Program akan menampilkan pesan "Maaf, treatment tersebut sudah dipilih, silahkan pilih treatment yang lain".

3. Jika treatment tersedia dan belum terjual, program akan melanjutkan proses transaksi.

Dengan cara pencarian ini, program dapat menangani treatment yang dicari baik dengan menggunakan pencarian langsung menggunakan `indexOf()` maupun pencarian case-insensitive dengan perulangan. Ini memungkinkan pengguna untuk memasukkan nama treatment dengan huruf besar atau kecil, dan program tetap dapat menemukan treatment yang dimaksud.

12. Mengecek Ketersediaan Treatment dan Melakukan Transaksi
if (NoTreatment == -1) {
    System.out.println("Treatment tidak tersedia");
} else if (treatment.get(NoTreatment).equals("SOLD")) {
    System.out.println("Maaf, treatment tersebut sudah dipilih, silahkan pilih treatment yang lain");
} else {
    String purchasedTreatment = treatment.get(NoTreatment);
    String assignedEmployee = pegawai.get(NoTreatment);
    Integer treatmentPrice = harga.get(NoTreatment);

    treatment.set(NoTreatment, "SOLD");
    pegawai.set(NoTreatment, "SOLD");
    harga.set(NoTreatment, -1);

    int hargaTreatment = harga.get(NoTreatment);
    int total = hargaTreatment;

    System.out.println("");
    System.out.println("TOTAL : Rp. " + total);

    int totalUangBayar = 0;
    int kembalian = 0;
    while (true) {
        System.out.print("Masukkan Total Uang Bayar: Rp. ");
        totalUangBayar = scanner.nextInt();
        if (totalUangBayar < total) {
            System.out.println("===Jumlah bayar tidak mencukupi===");
        } else if (totalUangBayar >= total) {
            kembalian = totalUangBayar - total;
            System.out.println("Kembalian= Rp " + kembalian);
            System.out.println("");
            break;
        }
    }
}

Jika treatment tidak tersedia (NoTreatment == -1), program akan menampilkan pesan bahwa treatment tidak tersedia. Jika treatment sudah terjual (treatment.get(NoTreatment).equals("SOLD")), program akan meminta pengguna untuk memilih treatment lain.

Jika treatment tersedia, program akan menyimpan data treatment yang dibeli (purchasedTreatment), pegawai yang melayani (assignedEmployee), dan harga treatment (treatmentPrice). Kemudian, program akan menandai treatment, pegawai, dan harga sebagai "SOLD" dan -1 dalam daftar masing-masing.

Setelah itu, program akan menampilkan total harga yang harus dibayar dan meminta pengguna untuk memasukkan jumlah uang yang dibayarkan. Jika jumlah uang yang dibayarkan kurang dari total, program akan meminta pengguna untuk memasukkan jumlah yang cukup. Jika jumlah uang yang dibayarkan cukup atau lebih, program akan menghitung kembalian dan mencetak jumlah kembalian.

13. Menyimpan Data Transaksi ke dalam File
Date tglwktu = new Date();
SimpleDateFormat tanggaljam = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss", new Locale("id", "ID"));
String date = tanggaljam.format(tglwktu);

String namaFile = "Nota_Transaksi_" + nomornota + ".txt";
nomornota++;

try {
    String path = "E:\\" + namaFile;
    File file = new File(path);
    FileWriter fileWriter = new FileWriter(file);
    BufferedWriter createWriter = new BufferedWriter(fileWriter);

    // Kode untuk menulis data transaksi ke dalam file
    createWriter.close();
    System.out.println("Struk berhasil disimpan ke dalam file " + path);
    System.out.println("");
} catch (IOException e) {
    System.out.println("Terjadi kesalahan saat menulis file");
    e.printStackTrace();
}

Setelah transaksi selesai, program akan menyimpan data transaksi ke dalam file dengan format "Nota_Transaksi_[nomor].txt". Program menggunakan kelas `Date` dan `SimpleDateFormat` untuk mendapatkan tanggal dan waktu saat ini. Kemudian, program membuat objek `File` dengan path yang sesuai dan menggunakan `FileWriter` dan `BufferedWriter` untuk menulis data transaksi ke dalam file tersebut.

Data yang ditulis ke dalam file meliputi:
* Header "Nota Transaksi Salon PAS"
* Nomor struk transaksi
* Tanggal dan waktu transaksi
* Nama pelanggan
* Treatment yang dibeli, pegawai yang melayani, dan harga
* Total belanja
* Total uang yang dibayarkan
* Kembalian