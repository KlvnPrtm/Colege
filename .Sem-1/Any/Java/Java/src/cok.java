import java.util.Scanner;
public class cok {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Selamat Datang di Program Data Array Mahasiswa PBO");
        System.out.print("Inputan Mahasiswa yang akan di input :");
        int o = sc.nextInt();
        // String[] Input = new String[3];
        // Input[o] = scan.nextLine();
        System.out.println("===================================================");
        String[] n = new String[o];
        String[] m = new String[o];
        String[] g = new String[o];


        for (int i = 0; i < o; i++) {
            System.out.print("Masukan Nama Mahasiswa Ke -" + (i + 1) + ": ");
            // n[i] = sc.next();
            n[i] = sc.nextLine();
            System.out.print("Masukan NIM Mahasiswa Ke -" + (i + 1) + ": ");
            // m[i] = sc.next();
            m[i] = sc.nextLine();
            System.out.print("Masukan Asal Mahasiswa Ke - " + (i + 1) + ": ");
            // g[i] = sc.next();
            g[i] = sc.nextLine();
            System.out.println("\n");
        }

        System.out.println();
        System.out.println("Terima kasih telah input data anda!");
        System.out.println("===================================");
        System.out.println("Berikut adalah inputan data anda : ");
        for (int i = 0; i < o; i++) {
            System.out.println("Mahasiswa bernama " + n[i] + " memiliki NIM " + m[i] + " dan berasal dari " + g[i]);
        }
}
}