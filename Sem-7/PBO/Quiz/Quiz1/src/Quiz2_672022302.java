import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Quiz2_672022302 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Menu:");
            System.out.println("1. Simpan Teks");
            System.out.println("2. Baca File");
            System.out.println("3. Frequency Teks");
            System.out.println("4. Hapus File");
            System.out.println("5. Keluar");
            System.out.print("Pilih opsi: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    SimpanTeks(scanner);
                    break;
                case 2:
                    BacaTeks(scanner);
                    break;
                case 3:
                    wordFrequency(scanner);
                    break;
                case 4:
                    HapusFile(scanner);
                    break;
                case 5:
                    System.out.println("Keluar dari program...");
                    break;
                default:
                    System.out.println("Pilihan tidak valid.");
            }
        } while (choice != 5);
        scanner.close();
    }

    public static void SimpanTeks(Scanner scanner) {
        System.out.print("Masukkan nama file (contoh: file.txt): ");
        String fileName = scanner.nextLine();
        StringBuilder text = new StringBuilder();
        String inputLine;

        System.out.println("Masukkan teks yang ingin disimpan (tekan Enter pada baris kosong untuk menyimpan):");

        do {
            inputLine = scanner.nextLine();
            if (!inputLine.isEmpty()) {
                text.append(inputLine).append("\n");
            }
        } while (!inputLine.isEmpty());

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            writer.write(text.toString());
            System.out.println("Teks berhasil disimpan di " + fileName);
        } catch (IOException e) {
            System.out.println("Terjadi kesalahan saat menyimpan file.");
            e.printStackTrace();
        }
    }

    public static void BacaTeks(Scanner scanner) {
        System.out.print("Masukkan nama file yang ingin dibaca (contoh: file.txt): ");
        String fileName = scanner.nextLine();

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            System.out.println("Isi dari file " + fileName + ":");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("File tidak ditemukan atau terjadi kesalahan saat membaca file.");
            e.printStackTrace();
        }
    }

    public static void wordFrequency(Scanner scanner) {
        System.out.print("Masukkan nama file yang ingin dicek frekuensi katanya (contoh: data.txt): ");
        String namaFile = scanner.nextLine();

        Map<String, Integer> jumlahKata = new HashMap<>();

        try (BufferedReader pembaca = new BufferedReader(new FileReader(namaFile))) {
            String baris;
            while ((baris = pembaca.readLine()) != null) {
                String[] kata = baris.split("\\s+");
                for (String k : kata) {
                    k = k.toLowerCase();
                    jumlahKata.put(k, jumlahKata.getOrDefault(k, 0) + 1);
                }
            }
            System.out.println("Frekuensi kata dalam file " + namaFile + ":");
            for (Map.Entry<String, Integer> entry : jumlahKata.entrySet()) {
                System.out.println(entry.getKey() + ": " + entry.getValue() + " kali.");
            }
        } catch (IOException e) {
            System.out.println("File tidak ditemukan atau terjadi kesalahan: " + e.getMessage());
        }
    }

    public static void HapusFile(Scanner scanner) {
        System.out.print("Masukkan nama file yang ingin dihapus (contoh: file.txt): ");
        String fileName = scanner.nextLine();

        File file = new File(fileName);
        if (file.delete()) {
            System.out.println("File " + fileName + " berhasil dihapus.");
        } else {
            System.out.println("File tidak ditemukan atau terjadi kesalahan saat menghapus file.");
        }
    }
}
