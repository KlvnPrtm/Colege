import java.util.Scanner;

public class Tugas_2_672022302_PBO {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Masukkan sebuah bilangan: ");
        int number = input.nextInt();

        int[][] faktorPrima = new int[100][2];
        int index = 0;

        for (int i = 2; i <= number; i++) {
            int count = 0;
            while (number % i == 0) {
                number /= i;
                count++;
            }
            if (count > 0) {
                faktorPrima[index][0] = i;
                faktorPrima[index][1] = count;
                index++;
            }
        }

        System.out.println("Faktorisasi primanya adalah ");
        for (int i = 0; i < index; i++) {
            System.out.print(faktorPrima[i][0] + "^" + faktorPrima[i][1]);
            if (i < index - 1) {
                System.out.print(" * ");
            }
        }

        input.close();
    }
}
