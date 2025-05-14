import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class LatihanFileHandling {
    public static void main(String[] args) throws Exception {
        
        //CRUD File
        /*
        Create
        Read
        Update
        Delete
        */

        //Create
        // File file = new File("contoh.txt");
        // Scanner keyboard = new Scanner(System.in);
        // try {
        //     if (file.createNewFile()){
        //         FileWriter writer = new FileWriter("contoh.txt");

        //         System.out.println("Masukan Beberapa Kata");
        //         // String Kata = keyboard.nextLine();
        //         // writer.write(Kata);
        //         while (true) {
        //             String input = keyboard.nextLine();
        //             if (input.isEmpty()) {
        //                 break;
        //             }
        //             if (input.equalsIgnoreCase("f")) {
        //                 break;
        //             }
        //             writer.write(input+"\n");
        //         }

        //         // writer.write("Kiw Kiw cukurukuk");
        //         System.out.println("File Telah Berhasil Dibuat");
        //         keyboard.close();
        //         writer.close();
        //     }else{
        //         System.out.println("File Gagal Dibuat");
        //     }
        // } catch (Exception e) {
        //     System.out.println("Ada Kesalahan Dalam Membuat File");
        //     e.printStackTrace();
        // }

        //READ

        // File file = new File("contoh.txt");
        // try {
        //     Scanner reader = new Scanner(file);
        //     while (reader.hasNextLine()) {
        //         String baris = reader.nextLine();
        //         System.out.println(baris);
        //     }
        //     reader.close();
            
        // } catch (Exception e) {
        //     System.err.println("Terjadi Kesalahan");
        //     e.printStackTrace();
        // }
        
        //DELETE

        File file = new File("contoh.txt");
        if (file.delete()) {
            System.out.println("File Berhasil Dihapus");
            
        }else {
            System.out.println("File gagal dihapus");
        }
    }
}
