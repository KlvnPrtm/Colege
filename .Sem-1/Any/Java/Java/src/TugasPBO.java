import java.util.Scanner;
public class TugasPBO {
    public static void main(String[] args) {

        String[] Input = new String[3];
        String[] Input2 = new String[3];
        String[] Data = {"Masukan Nama Mahasiswa Ke - ", "Masukan NIM Mahasiswa Ke - ", "Masukan Asal Mahasiswa Ke - "};
        
        System.out.println("Selamat Datang di Program Data Array Mahasiswa PBO");
        System.out.println("Inputkan jumlah mahasiswa PBO yang datanya akan di-inputkan");
        System.out.println("==================================================");
        System.out.println("Silahkan input data sesuai dengan instruksi");
        Scanner scan = new Scanner(System.in);
        
        int i=0;
        int j=0;

        while (j<Input.length) {
            System.out.print(Data[j] + "1" + ": ");
            Input[j] = scan.nextLine();
            j++;
        }
        
        System.out.println("");
        System.out.println("");

        while (i<Input2.length) {
            System.out.print(Data[i] + "2" + ": ");
            Input2[i] = scan.nextLine();
            i++;
        }

            
        System.out.println();
        System.out.println("Terima kasih telah input data anda!");
        System.out.println("===================================");
        System.out.println("Berikut adalah inputan data anda : ");
        System.out.println("Mahasiswa bernama " + Input[0] + " memiliki NIM " + Input[1]+ " dan berasal dari " + Input[2]);
        System.out.println("Mahasiswa bernama " + Input2[0] + " memiliki NIM " + Input2[1]+ " dan berasal dari " + Input2[2]);
    }
    
}
