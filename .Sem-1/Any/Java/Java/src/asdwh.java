// package asdwh;

/**
 *
 * @author ASUS
 */
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class asdwh {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String[] tujuan = {"Salatiga - Bandung", "Salatiga - Yogyakarta", "Salatiga - Surabaya"};
        String[] kelas = {"Ekonomi", "Eksekutif"};
        int[][] harga = {{120000, 200000}, {300000, 500000}, {400000, 600000}};
        int[][] kursi = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
        int nomorStruk = 0;
        int totalHarga = 0;

        while (true) {
            System.out.println("============================");
            System.out.println("   Aplikasi Pemesanan Tiket Bus");
            System.out.println("============================");
            System.out.println("1. Tambah Tujuan Bus");
            System.out.println("2. List Kursi");
            System.out.println("3. Transaksi Pembelian Tiket");
            System.out.println("4. Exit");
            System.out.println("============================");
            System.out.print("Pilih Menu: ");
           
            int menu = input.nextInt();

            if (menu == 1) {
                input.nextLine();
                System.out.print("Masukkan Nama Tujuan Baru: ");
                String tujuanBaru = input.nextLine();
                tujuan = addString(tujuan, tujuanBaru);
                int[] hargaBaru = new int[kelas.length];
                for (int i = 0; i < hargaBaru.length; i++) {
                    System.out.print("Harga " + kelas[i] + " Baru: Rp ");
                    hargaBaru[i] = input.nextInt();
                }
                harga = addArray(harga, hargaBaru);
                kursi = addArray(kursi, new int[10]);
                System.out.println("Tujuan Baru Berhasil Ditambahkan!");
            } else if (menu == 2) {
                System.out.println("List Kursi");
                for (int i = 0; i < tujuan.length; i++) {
                    System.out.println("Tujuan: " + tujuan[i]);
                    for (int j = 0; j < kelas.length; j++) {
                        System.out.println("Kelas: " + kelas[j]);
                        for (int k = 0; k < kursi[i].length; k++) {
                            if (kursi[i][k] == 1) {
                                System.out.print((k+1) + " ");
                            } else {
                                System.out.print("X ");
                            }
                            if ((k+1) % 5 == 0) {
                                System.out.println();
                            }
                        }
                        System.out.println();
                    }
                    System.out.println();
                }
            } else if (menu == 3) {
                System.out.println("Pilih Tujuan Bus:");
                for (int i = 0; i < tujuan.length; i++) {
                    System.out.println((i+1) + ". " + tujuan[i]);
                }
                System.out.print("Pilih Nomor Tujuan: ");
                int nomorTujuan = input.nextInt() - 1;

                System.out.println("Pilih Kelas:");
                for (int i = 0; i < kelas.length; i++) {
                    System.out.println((i+1) + ". " + kelas[i] + " (Rp " + harga[nomorTujuan][i] + ")");
                }
                System.out.print("Pilih Nomor Kelas: ");
                int nomorKelas = input.nextInt() - 1;

                System.out.println("Jumlah Penumpang:");
                int jumlahPenumpang = input.nextInt();

                boolean found = false;
                for (int i = 0; i < kursi[nomorTujuan].length; i++) {
                    if (kursi[nomorTujuan][i] == 1) {
                        System.out.print((i+1) + " ");
                    } else {
                        System.out.print("X ");
                    }
                    if ((i+1) % 5 == 0) {
                        System.out.println();
                    }
                }

                boolean[] temp = new boolean[kursi[nomorTujuan].length];
                for (int i = 0; i < jumlahPenumpang; i++) {
                    System.out.print("Pilih Nomor Kursi " + (i+1) + ": ");
                    int nomorKursi = input.nextInt() - 1;
                    if (kursi[nomorTujuan][nomorKursi] == 1) {
                        temp[nomorKursi] = true;
                    } else {
                        System.out.println("Kursi tidak tersedia!");
                        i--;
                    }
                }

                for (int i = 0; i < temp.length; i++) {
                    if (temp[i]) {
                        kursi[nomorTujuan][i] = 0;
                    }
                }

                nomorStruk++;
                totalHarga += harga[nomorTujuan][nomorKelas] * jumlahPenumpang;

                System.out.println("Transaksi Berhasil!");
                System.out.println("Total Harga: Rp " + totalHarga);
                System.out.println("Nomor Struk: " + nomorStruk);
                System.out.println("Struk Pembayaran Berhasil Disimpan!");
                System.out.println("Terima kasih telah memesan tiket di Aplikasi Pemesanan Tiket Bus Keren sekali banget!");

                FileWriter writer = null;
                try {
                    writer = new FileWriter("transaksi.txt", true);
                    writer.write("Nomor Struk: " + nomorStruk + "\n");
                    writer.write("Tanggal Transaksi: " + java.time.LocalDate.now() + "\n");
                    writer.write("Tujuan: " + tujuan[nomorTujuan] + "\n");
                    writer.write("Kelas: " + kelas[nomorKelas] + "\n");
                    writer.write("Jumlah Penumpang: " + jumlahPenumpang + "\n");
                    writer.write("Total Harga: Rp " + totalHarga + "\n");
                    writer.write("--------------------\n");
                    writer.close();
                } catch (IOException e) {
                    System.out.println("Terjadi kesalahan dalam penulisan file.");
                }
                  } else if (menu == 4) {
                break;
            } else {
                System.out.println("Menu tidak valid!");
            }
        }
    }

    public static String[] addString(String[] arr, String element) {
        String[] newArray = new String[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            newArray[i] = arr[i];
        }
        newArray[arr.length] = element;
        return newArray;
    }

    public static int[][] addInt(int[][] arr, int[] element) {
        int[][] newArray = new int[arr.length + 1][];
        for (int i = 0; i < arr.length; i++) {
            newArray[i] = arr[i];
        }
        newArray[arr.length] = element;
        return newArray;
    }

    private static int[][] addArray(int[][] harga, int[] hargaBaru) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}