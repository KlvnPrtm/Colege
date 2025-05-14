import java.util.Scanner;

abstract class Pesanan {
    protected double hargaDasar;

    public Pesanan(double hargaDasar) {
        this.hargaDasar = hargaDasar;
    }

    public abstract void prosesPesanan();

    public abstract double hitungTotal(double tarifPajak, int jumlahItem);
}

public class App {
    private static Pesanan pesananSaatIni;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pilihan;

        do {
            System.out.println("===== Menu Pemesanan =====");
            System.out.println("1. Buat Pesanan Umum");
            System.out.println("2. Buat Pesanan Online");
            System.out.println("3. Buat Pesanan Toko");
            System.out.println("4. Proses Pesanan Saat Ini");
            System.out.println("5. Hitung Total Biaya");
            System.out.println("6. Keluar");
            System.out.print("Pilih opsi: ");
            pilihan = scanner.nextInt();

            switch (pilihan) {
                case 1:
                    System.out.print("Masukkan harga dasar untuk pesanan: ");
                    double hargaUmum = scanner.nextDouble();
                    pesananSaatIni = new PesananUmum(hargaUmum);
                    System.out.println("Pesanan umum dibuat.");
                    break;

                case 2:
                    System.out.print("Masukkan harga dasar untuk pesanan online: ");
                    double hargaOnline = scanner.nextDouble();
                    scanner.nextLine(); // Membersihkan newline
                    System.out.print("Masukkan alamat pengiriman: ");
                    String alamat = scanner.nextLine();
                    pesananSaatIni = new PesananOnline(hargaOnline, alamat);
                    System.out.println("Pesanan online dibuat.");
                    break;

                case 3:
                    System.out.print("Masukkan harga dasar untuk pesanan toko: ");
                    double hargaToko = scanner.nextDouble();
                    pesananSaatIni = new PesananToko(hargaToko);
                    System.out.println("Pesanan toko dibuat.");
                    break;

                case 4:
                    if (pesananSaatIni != null) {
                        pesananSaatIni.prosesPesanan();
                    } else {
                        System.out.println("Tidak ada pesanan saat ini untuk diproses.");
                    }
                    break;

                case 5:
                    if (pesananSaatIni != null) {
                        System.out.println("1. Hitung total dengan pajak saja");
                        System.out.println("2. Hitung total dengan pajak dan jumlah item");
                        System.out.print("Pilih opsi: ");
                        int opsiHitung = scanner.nextInt();

                        System.out.print("Masukkan tarif pajak (misalnya, 0.1 untuk 10%): ");
                        double tarifPajak = scanner.nextDouble();

                        double totalBiaya;
                        if (opsiHitung == 1) {
                            totalBiaya = pesananSaatIni.hitungTotal(tarifPajak, 1);
                        } else {
                            System.out.print("Masukkan jumlah item: ");
                            int jumlahItem = scanner.nextInt();
                            totalBiaya = pesananSaatIni.hitungTotal(tarifPajak, jumlahItem);
                        }

                        System.out.printf("Total Biaya: %.2f\n", totalBiaya);
                    } else {
                        System.out.println("Tidak ada pesanan saat ini untuk dihitung.");
                    }
                    break;

                case 6:
                    System.out.println("Keluar dari menu. Terima kasih!");
                    break;

                default:
                    System.out.println("Opsi tidak valid. Silakan coba lagi.");
            }
        } while (pilihan != 6);

        scanner.close();
    }
}