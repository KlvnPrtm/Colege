import java.util.Scanner;

import Hewan.Cow;
import Hewan.Lion;
import Hewan.Parrot;
import Zoo.Zoo;

public class ZooManagementApp {
    public static void main(String[] args) {
        Zoo zoo = new Zoo();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nZoo Management Menu:");
            System.out.println("1. Tambah Hewan Baru");
            System.out.println("2. Beri Makan Semua Hewan");
            System.out.println("3. Tidurkan Semua Hewan");
            System.out.println("4. Hitung Total Hewan");
            System.out.println("5. Keluar");
            System.out.print("Pilih opsi: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Pilih Jenis Hewan:");
                    System.out.println("1. Lion");
                    System.out.println("2. Cow");
                    System.out.println("3. Parrot");
                    int animalChoice = scanner.nextInt();

                    switch (animalChoice) {
                        case 1 -> zoo.addAnimal(new Lion());
                        case 2 -> zoo.addAnimal(new Cow());
                        case 3 -> zoo.addAnimal(new Parrot());
                        default -> System.out.println("Pilihan tidak valid.");
                    }
                    break;

                case 2:
                    zoo.feedAnimals();
                    break;

                case 3:
                    zoo.putAnimalsToSleep();
                    break;

                case 4:
                    zoo.countTotalAnimals();
                    break;

                case 5:
                    System.out.println("Keluar dari program.");
                    break;

                default:
                    System.out.println("Pilihan tidak valid.");
            }
        } while (choice != 5);

        scanner.close();
    }
}
