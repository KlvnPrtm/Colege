import java.util.Scanner;
public class App {
Scanner scan = new Scanner (System.in);
public static void main(String[] args) {
Scanner scan = new Scanner(System.in);
System.out.println ("=============");
System.out.println ("Bioskop Valen");
System.out.println ("=============");
System.out.println ("1. Turning Red");
System.out.println ("2. Docter Strange In the Multiverse Of Madness");
System.out.println ("3. Jalan Yang Jauh Jangan Lupa Pulang");
System.out.println ("4. A Man Called Otto");
System.out.println ("5. Avatar The Wat Of Water");
System.out.print("Masukan Pilihan : "); int input = scan.nextInt();
int film1= 40000;
int film2= 75000;
int film3= 55000; int film4= 65000; int film5= 70000; int tr;
int hasil;

 if (input == 1){
System.out.println("Anda Memilih Film Turning Red"); System.out.print("Jumlah Tiket : ");
tr = scan.nextInt();
hasil = tr*film1;
System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(tr*film1);
}
else if (input == 2){
System.out.println("Anda Memilih Film Docter Strange In the Multiverse Of Madness"); System.out.print("Jumlah Tiket : ");
tr = scan.nextInt();
hasil = tr*film2;
System.out.print("Total harga tiket bioskop anda adalah Rp.");
System.out.print(tr*film2); }
else if (input == 3){
System.out.println("Anda Memilih Film Jalan Yang Jauh Jangan Lupa Pulang"); System.out.print("Jumlah Tiket : ");
tr = scan.nextInt();
hasil = tr*film3;
System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(tr*film3);
}
else if (input == 4){
System.out.println("Anda Memilih Film A Man Called Otto"); System.out.print("Jumlah Tiket : ");
tr = scan.nextInt();

 hasil = tr*film4;
System.out.print("Total harga tiket bioskop anda adalah Rp."); System.out.print(tr*film4);
}
else if (input == 5){
System.out.println("Anda Memilih Film Film Avatar The Wat Of Water"); System.out.print("Jumlah Tiket : ");
tr = scan.nextInt();
hasil = tr*film5;
System.out.print("Total harga tiket bioskop anda adalah Rp.");
System.out.print(tr*film5); }
else{
System.out.print("Pilihan Tidak Tersedia ! ! !");
}
}
}