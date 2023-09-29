import java.util.Scanner;
public class cok2 {
         public static void main(String[] args) {
            int n;
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter Array Size:");
            n=sc.nextInt();


            int[] array = new int[n];
            System.out.print("Enter Array elements:");
            for(int i=0; i<n; i++){
                array[i]=sc.nextInt();
            }
    
            for (int i=0; i<n; i++){
                System.out.println(array[i]);
            }
        }
    }

