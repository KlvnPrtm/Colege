import java.util.Scanner;

public class Tugas_1_672022302_PBO {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int choice;
        do {
            System.out.println("Menu:");
            System.out.println("1. Menghitung Luas Jajar Genjang");
            System.out.println("2. Menghitung Volume Bola");
            System.out.println("3. Mengecek Angka Ganjil atau Genap");
            System.out.println("4. Melakukan Operasi Bitwise (AND, OR)");
            System.out.println("5. Keluar");
            System.out.print("Pilih menu (1-5): ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Masukkan alas jajar genjang: ");
                    double alas = input.nextDouble();

                    System.out.print("Masukkan tinggi jajar genjang: ");
                    double tinggi = input.nextDouble();

                    double luas = alas * tinggi;
                    System.out.println("Luas jajar genjang adalah: " + luas);
                    break;
                case 2:
                    System.out.println("Pilih metode perhitungan volume bola:");
                    System.out.println("1. Menggunakan Diameter");
                    System.out.println("2. Menggunakan Jari-jari");
                    System.out.print("Pilih metode (1-2): ");
                    int pilihan = input.nextInt();

                    switch (pilihan) {
                        case 1:
                            System.out.print("Masukkan diameter bola: ");
                            double diameter = input.nextDouble();

                            double jariJarii = diameter / 2;
                            double volume = (4.0 / 3.0) * 22.0/7.0 * Math.pow(jariJarii, 3);
                            System.out.println("Volume bola adalah: " + volume);
                            break;
                        case 2:
                            System.out.print("Masukkan panjang jari-jari bola: ");
                            double jariJari = input.nextDouble();

                            double volumee = (4.0 / 3.0) * 22.0/7.0 * Math.pow(jariJari, 3);
                            System.out.println("Volume bola adalah: " + volumee);
                            break;
                        default:
                            System.out.println("Pilihan tidak valid! Kembali ke menu utama.");
                    }
                    break;
                case 3:
                    System.out.print("Masukkan sebuah angka: ");
                    int angka = input.nextInt();

                    if (angka % 2 == 0) {
                        System.out.println(angka + " adalah angka genap!");
                    } else {
                        System.out.println(angka + " adalah angka ganjil!");
                    }
                    break;
                case 4:
                    System.out.println("Pilih Operasi Biner:");
                    System.out.println("1. Operasi AND");
                    System.out.println("2. Operasi OR");
                    System.out.print("Pilih 1-2: ");
                    int operationChoice = input.nextInt();
            
                    System.out.print("Masukan Nilai 1: ");
                    int nilai1 = input.nextInt();
                    System.out.print("Masukan Nilai 2: ");
                    int nilai2 = input.nextInt();
            
                    String binaryNilai1 = Integer.toBinaryString(nilai1);
                    String binaryNilai2 = Integer.toBinaryString(nilai2);
            
                    int hasilBiner = 0;
                    if (operationChoice == 1) {
                        hasilBiner = nilai1 & nilai2;
                    } else if (operationChoice == 2) {
                        hasilBiner = nilai1 | nilai2;
                    } else {
                        System.out.println("Pilihan operasi tidak valid.");
                        return;
                    }
            
                    String hasilBinerString = Integer.toBinaryString(hasilBiner);
            
                    System.out.println("Biner Nilai 1: " + binaryNilai1);
                    System.out.println("Biner Nilai 2: " + binaryNilai2);
                    System.out.println("Hasil Operasi Biner: " + hasilBinerString);
                    break;
                case 5:
                    System.out.println("Terima kasih! Program selesai.");
                    break;
                default:
                    System.out.println("Pilihan menu tidak ada!");
            }
            System.out.println();
        } while (choice != 5);
        input.close();
    }

}
