import java.util.InputMismatchException;
import java.util.Scanner;


public class App {
    public static void main(String[] args) throws Exception {
        // System.out.println("Hello, World!");
        
        //compile error
        // String a=5;

        //runtime error
        // int s;
        // Scanner scanner = new Scanner(System.in);
        // try {
        //     System.out.println("Masukan Sebuah Bilangan");
        //     s = scanner.nextInt();
            
        // } catch (InputMismatchException e) {
        //     System.err.println("Terjadi Kesalahan, input tidak boleh string");
        //     e.printStackTrace();
        // } catch (Exception e) {
        //     System.err.println("Terjadi Kesalahan");
        // }

        // int[] kumpulan = {1,2,3};
        // try {
        //     System.out.println("Masukan index untuk diambil nilainya: ");
        //     int index = scanner.nextInt();
        //     System.out.println(kumpulan[index]);
        // } catch (ArrayIndexOutOfBoundsException e) {
        //     System.err.println("Anda mengakses index diluar batas");
        // }
        // catch (Exception e) {
        //     System.err.println("terjadi kesalahan");
        //     e.printStackTrace();
        // }
        Scanner Scanner = new Scanner(System.in);
        // Scanner StringScanner = new Scanner(System.in);

        Dog guguk;
        boolean isValid = false;
        do {
            try {
                String nama, jenis;
                int umur;
                System.out.print("Masukan nama: ");
                nama = Scanner.nextLine();
                System.out.print("Masukan umur: ");
                umur = Scanner.nextInt(); Scanner.nextLine();
                System.out.print("Masukan Jenis: ");
                jenis = Scanner.nextLine();
                guguk = new Dog(nama, umur, jenis);
                System.out.println("====Detail Anjing====");
                System.out.println("Nama: " + guguk.nama);
                System.out.println("Jenis: " + guguk.jenis);
                System.out.println("Umur: " + guguk.umur); 
                isValid = true;
            } catch(InputMismatchException e){
                System.err.println("Invalid input from user");
            } catch(IllegalArgumentException e){
                System.err.println(e.getMessage());
            }
            catch (Exception e) {
                System.err.println("Terjadi kesalahan :");
                e.printStackTrace();
            }
        } while (!isValid);
    }
}