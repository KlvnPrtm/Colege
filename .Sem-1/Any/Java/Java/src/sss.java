import java.util.Scanner;
public class sss {
    Scanner scan = new Scanner (System.in);
    static void Menu(){
        System.out.println("MENU PATTREN");
        System.out.println(">>>>>>>>>>>>>>>>");
        System.out.println("1. PATTREN A");
        System.out.println("2. PATTREN B");
        System.out.println("3. PATTREN C");
    }
    static void Pil1(int jumlah) {
        for(int i=2; i<jumlah; i++){
            for(int j=1; j<=i; j++){
                System.out.print(" ");
            }
            for(int k=4; k<=jumlah; k++){
                System.out.print("*"+i);
            }
            System.out.println();
        }
    }
    static void Pil2(int jumlah) {
        // int jumlah;
        for(int i=2; i<=jumlah; i++){
            for(int j=i; j<=jumlah; j++){
                System.out.print(" ");
            }
            for(int j=1; j<=i; j++){
                if(i==jumlah || j==1 || j==i){
                    System.out.print(j);
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
    static void Pil3(int jumlah) {
        int i=1,j,row=1;
        while(i<=jumlah){
        j=1;
            while(j<=i){
                System.out.print(row+" ");
                row++;
                j++;
            }
            System.out.println();
            i++;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int pilihan;
        int jumlah;
        Menu();
        System.out.print("Inputkan Pilihan : ");
        pilihan = sc.nextInt();
        if (pilihan == 1) {
            System.out.print("inputkan Jumlah Patren : ");
            jumlah = sc.nextInt();
            Pil1(jumlah);
        }else if (pilihan == 2) {
            System.out.print("inputkan Jumlah Patren : ");
            jumlah = sc.nextInt();
            Pil2(jumlah);
        }else if (pilihan == 3) {
            System.out.print("inputkan Jumlah Patren : ");
            jumlah = sc.nextInt();
            Pil3(jumlah);
        }
        else{
        System.out.println("Tidak Ada Pilihan");
        }
    }
}