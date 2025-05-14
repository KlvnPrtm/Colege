public class PerulanganDoWhle {
    public static void main(String[] args) {
        int count=1;
        int i=0;

        do{
            int j=0;
            do{
                System.out.print(count);
                j++;
            }while (j<i+1);
            count++;
            System.out.println();
            i++;
        }while (i<0);
    }
}
