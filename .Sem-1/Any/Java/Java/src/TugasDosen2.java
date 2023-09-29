import java.util.Scanner;

public class TugasDosen2 {
    Scanner scan = new Scanner (System.in);
    String inputUsername;
    String inputPassword;
    char c;
    int k=0;

    private String username;
    private String password;

    public TugasDosen2(String username, String password) {
        this.username = username;
        this.password = password;
    }
    public String getUsername() {
        return username;
    }
    public void setUsername(String username) {
        this.username = username;
    }
    public String getPassword() {
        return password;
    }
    public void setPassword(String password) {
        this.password = password;
    }
    public void displayMenu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to the login menu!");
        System.out.println("Please enter your username and password.");
        System.out.print("Username: ");
        inputUsername = sc.nextLine();
        System.out.print("Password: ");
        inputPassword = sc.nextLine();
         l();
        sc.close();
    }

    public void l(){
        if (inputUsername.equals(username) && inputPassword.equals(password)) {
            System.out.println("Login successful!");
        }
        else{
            if(k==0){
                System.out.println("Login failed. Apakah Anda Akan Mengulang? (Y/T)");
                c = scan.nextLine().charAt(0);
                p();
            }
            else{
                System.out.println("Apakah Anda Akan Mengulang? (Y/T)");
                c = scan.nextLine().charAt(0);
                p();
            }
        }
    }

    public void p(){
        if (c=='y'||c=='Y') {
            displayMenu();
        }
        else if (c=='t'||c=='T') {
            System.out.println("Terimakasih");
        }
        else{
            System.out.println("Tidak Ada Pilihan!!!");
            k=1;
            l();
        }
    }
    public static void main(String[] args) {
        TugasDosen2 lm = new TugasDosen2("admin", "admin");
        lm.displayMenu();
    }
}