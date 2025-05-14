import java.util.Scanner;
import Kendaraan.Tesla;
import Interfaces.Mobil;
import Kendaraan.Kijang;
        
public class App {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws Exception {
        Mobil m;
        int choice;
        final Scanner keyboard = new Scanner (System.in);
        System.out.println("1. Tesla");
        System.out.println("2. Kijang");
        System.out.println("Pilih: ");
        choice = keyboard.nextInt();
        switch (choice){
            case 1 -> {
                m=new Tesla(60);
            }
            case 2 -> {
                m=new Kijang(3);
            }
            default -> {
                m=new Kijang(0);
            }
        }
        m.isiBahanBakar(100);
        keyboard.close();


    }
    
}
