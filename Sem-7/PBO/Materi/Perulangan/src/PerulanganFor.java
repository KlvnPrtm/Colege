public class PerulanganFor {
    public static void main(String[] args) throws Exception {
        int count=1;
        for (int i=0; i<9; i++) {
        for (int j=0; j<i+1; j++) {
            System.out.print(count);
            }
            count++;
            System.out.println();
        }
    }
}