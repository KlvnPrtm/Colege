import java.util.Scanner;
public class asd {
    Scanner scan = new Scanner (System.in);
    public static void main(String[] args) {
        Scanner scan = new Scanner (System.in);
        System.out.println ("=============");
        System.out.println ("Bioskop Valen");
        System.out.println ("=============");
        System.out.println ("1. Turning Red");
        System.out.println ("2. Docter Strange In the Multiverse Of Madness");
        System.out.println ("3. Jalan Yang Jauh Jangan Lupa Pulang");
        System.out.println ("4. A Man Called Otto");
        System.out.println ("5. Avatar The Wat Of Water");
        System.out.print("Masukan Pilihan : ");
        int input = scan.nextInt();
        int a[]={40000,75000,55000,65000,70000};
        int hasil, tiket;

        if (input == 1) {
            System.out.println("Anda Memilih Film Turning Red"); System.out.print("Jumlah Tiket : ");
            tiket = scan.nextInt();
            hasil = a[0]*tiket;
            System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(a[0]*tiket);
        }
        else if(input == 2){
            System.out.println("Anda Memilih Film octer Strange In the Multiverse Of Madness"); System.out.print("Jumlah Tiket : ");
            tiket = scan.nextInt();
            hasil = a[1]*tiket;
            System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(a[1]*tiket);
        }
        else if(input == 3){
            System.out.println("Anda Memilih Film Jalan Yang Jauh Jangan Lupa Pulang"); System.out.print("Jumlah Tiket : ");
            tiket = scan.nextInt();
            hasil = a[2]*tiket;
            System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(a[2]*tiket);
        }
        else if(input == 4){
            System.out.println("Anda Memilih Film A Man Called Otto"); System.out.print("Jumlah Tiket : ");
            tiket = scan.nextInt();
            hasil = a[3]*tiket;
            System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(a[3]*tiket);
        }
        else if(input == 5){
            System.out.println("Anda Memilih Film Avatar The Wat Of Water"); System.out.print("Jumlah Tiket : ");
            tiket = scan.nextInt();
            hasil = a[4]*tiket;
            System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(a[4]*tiket);
        }
        else{
            System.out.print("NTNT");
        }
        
    }
}