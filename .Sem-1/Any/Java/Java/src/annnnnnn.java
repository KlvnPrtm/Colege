import java.util.Scanner;

public class annnnnnn {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Selamat Datang di program Data Array Mahasiswa PBO");
        System.out.print("Input Mahasiswa PBO yang datanya akan di-inputkan ke array : ");
        int jumlah = sc.nextInt();
        System.out.println("=================================================================");
        System.out.println("Silakan input data sesuai dengan instruksi!!");
        String[] nama = new String[500];
        String[] nim = new String[500];
        String[] asal = new String[500];
        
        for (int i = 0; i < jumlah; i++) {
            System.out.print("Masukan Nama Mahasiswa ke " + (i + 1) + ": ");
            nama[i] = sc.next();
            System.out.print("Masukan NIM Mahasiswa ke  "+ (i + 1) + ": ");
            nim[i] = sc.next();
            System.out.print("Masukan Asal Mahasiswa ke " + (i + 1) + ": ");
            asal[i] = sc.next();
            System.out.println("\n");
        }
        
        System.out.println("Terima kasih telah input data anda!");
        System.out.println("==========================================================");
        System.out.println("Berikut adalah inputan data anda!");
        for (int i = 0; i < 500; i++) {
            System.out.println("Mahasiswa bernama " + nama[i] + " memiliki NIM " + nim[i] + " dan berasal dari " + asal[i]);
        }
        
        
    }
    
}