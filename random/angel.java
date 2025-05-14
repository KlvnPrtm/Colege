package random;
import java.util.Scanner;

public class angel {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Input panjang diagonal pertama dan kedua
        System.out.print("Masukkan panjang diagonal pertama (AB): ");
        double diagonal1 = input.nextDouble();
        System.out.print("Masukkan panjang diagonal kedua (BC): ");
        double diagonal2 = input.nextDouble();

        // Hitung luas dan keliling
        double luas = (diagonal1 * diagonal2) / 2;
        double keliling = 2 * (diagonal1 + diagonal2);

        // Tampilkan hasil
        System.out.println("Luas layang-layang: " + luas);
        System.out.println("Keliling layang-layang: " + keliling);

        input.close();
    }
    
}
