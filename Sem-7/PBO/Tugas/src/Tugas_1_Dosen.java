import java.util.Scanner;

public class Tugas_1_Dosen {
    // SOAL NOMOR 1: Mencari indeks elemen pada array 2 dimensi
    public static void soal1() {
        Scanner scanner = new Scanner(System.in);
        
        // Input ukuran array
        System.out.print("Masukkan jumlah baris: ");
        int rows = scanner.nextInt();
        System.out.print("Masukkan jumlah kolom: ");
        int cols = scanner.nextInt();
        
        int[][] array = new int[rows][cols];
        
        // Input elemen array
        System.out.println("Masukkan elemen array:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                array[i][j] = scanner.nextInt();
            }
        }
        
        // Input elemen yang dicari
        System.out.print("Masukkan elemen yang dicari: ");
        int value = scanner.nextInt();
        
        // Mencari indeks elemen
        boolean found = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (array[i][j] == value) {
                    System.out.println("Elemen ditemukan pada indeks: [" + i + "][" + j + "]");
                    found = true;
                }
            }
        }
        
        if (!found) {
            System.out.println("Elemen tidak ditemukan.");
        }
        scanner.close();

    }

    // SOAL NOMOR 2: Total pelanggan tiap toko dan tiap hari
    public static void soal2() {
        String[] hari = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
        int[][] pelanggan = new int[2][5]; // 2 toko, 5 hari
        Scanner scanner = new Scanner(System.in);
        
        // Input data pelanggan
        for (int toko = 0; toko < 2; toko++) {
            System.out.println("Masukkan data pelanggan untuk Toko " + (toko + 1) + ":");
            for (int hariIndex = 0; hariIndex < 5; hariIndex++) {
                System.out.print(hari[hariIndex] + ": ");
                pelanggan[toko][hariIndex] = scanner.nextInt();
            }
        }
        
        // Hitung total pelanggan per toko
        for (int toko = 0; toko < 2; toko++) {
            int totalToko = 0;
            for (int hariIndex = 0; hariIndex < 5; hariIndex++) {
                totalToko += pelanggan[toko][hariIndex];
            }
            System.out.println("Total pelanggan Toko " + (toko + 1) + ": " + totalToko);
        }
        
        // Hitung total pelanggan per hari
        for (int hariIndex = 0; hariIndex < 5; hariIndex++) {
            int totalHari = 0;
            for (int toko = 0; toko < 2; toko++) {
                totalHari += pelanggan[toko][hariIndex];
            }
            System.out.println("Total pelanggan hari " + hari[hariIndex] + ": " + totalHari);
        }
        scanner.close();

    }

    // SOAL NOMOR 3: Saran nama anak
    public static void soal3() {
        Scanner scanner = new Scanner(System.in);
        
        // Input nama ayah, ibu, dan jenis kelamin
        System.out.print("Masukkan nama ayah: ");
        String namaAyah = scanner.nextLine();
        System.out.print("Masukkan nama ibu: ");
        String namaIbu = scanner.nextLine();
        System.out.print("Masukkan jenis kelamin anak (laki-laki/perempuan): ");
        String jenisKelamin = scanner.nextLine();
        
        String saranNama = "";
        if (jenisKelamin.equalsIgnoreCase("laki-laki")) {
            saranNama = namaAyah.substring(0, namaAyah.length() / 2) + 
                        namaIbu.substring(0, namaIbu.length() / 2);
        } else if (jenisKelamin.equalsIgnoreCase("perempuan")) {
            saranNama = namaIbu.substring(0, namaIbu.length() / 2) + 
                        namaAyah.substring(0, namaAyah.length() / 2);
        }
        
        System.out.println("Saran nama: " + saranNama.toUpperCase());
        scanner.close();

    }

    // SOAL NOMOR 4: Modifikasi Percobaan 11 ke Percobaan 12 untuk Title Case
    public static void soal4() {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Masukkan kalimat: ");
        String kalimat = scanner.nextLine();
        
        String[] words = kalimat.split(" ");
        StringBuilder titleCase = new StringBuilder();
        
        for (String word : words) {
            if (word.length() > 0) {
                titleCase.append(Character.toUpperCase(word.charAt(0)))
                          .append(word.substring(1).toLowerCase())
                          .append(" ");
            }
        }
        
        System.out.println("Kalimat Title Case: " + titleCase.toString().trim());
        scanner.close();
        
    }

    public static void main(String[] args) {
        // Uncomment the method corresponding to the task you want to test
        // soal1();  // Test soal 1
        // soal2();  // Test soal 2
        // soal3();  // Test soal 3
        soal4();  // Test soal 4 (Percobaan 12)

        
    }
}
