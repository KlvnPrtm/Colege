import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Tugas_3_672022302_PBO {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Menu:");
            System.out.println("1. Simpan Teks");
            System.out.println("2. Baca File");
            System.out.println("3. Filter Teks");
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
                    FilterText(scanner);
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

    public static void FilterText(Scanner scanner) {
        System.out.print("Masukkan nama file yang ingin difilter (contoh: file.txt): ");
        String fileName = scanner.nextLine();
        
        List<String> filterWords = new ArrayList<>();
        String filterWord;
        System.out.println("Masukkan kata-kata yang ingin difilter (tekan Enter pada baris kosong untuk selesai):");

        do {
            filterWord = scanner.nextLine();
            if (!filterWord.isEmpty()) {
                filterWords.add(filterWord);
            }
        } while (!filterWord.isEmpty());

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            StringBuilder newText = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                for (String word : filterWords) {
                    String replacement = "*".repeat(word.length());
                    line = line.replaceAll(word, replacement);
                }
                newText.append(line).append("\n");
            }

            System.out.print("Apakah Anda ingin menimpa file lama? (ya/tidak): ");
            String overwrite = scanner.nextLine();

            if (overwrite.equalsIgnoreCase("ya")) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
                    writer.write(newText.toString());
                    System.out.println("File berhasil diperbarui.");
                }
            } else {
                String newFileName = fileName.replace(".txt", "_filtered.txt");
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(newFileName))) {
                    writer.write(newText.toString());
                    System.out.println("File baru dengan nama " + newFileName + " berhasil dibuat.");
                }
            }

        } catch (IOException e) {
            System.out.println("File tidak ditemukan atau terjadi kesalahan saat membaca file.");
            e.printStackTrace();
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
