import java.util.ArrayList;
import java.util.Scanner;

class User {
    private String name;
    private int age;
    private String address;
    private String accountNumber;
    private String pin;

    public User(String name, int age, String address, String accountNumber, String pin) {
        this.name = name;
        this.age = age;
        this.address = address;
        this.accountNumber = accountNumber;
        this.pin = pin;
    }

    // Getters
    public String getName() { return name; }
    public int getAge() { return age; }
    public String getAddress() { return address; }
    public String getAccountNumber() { return accountNumber; }
    public String getPin() { return pin; }
}

class BankAccount {
    private User user;
    private double balance;
    private double interestRate;

    public BankAccount(User user) {
        this.user = user;
        this.balance = 500000;
        this.interestRate = 0.05;
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Penarikan berhasil. Saldo anda sekarang: " + balance);
        } else {
            System.out.println("Penarikan gagal. Saldo tidak mencukupi atau jumlah tidak valid.");
        }
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit berhasil. Saldo anda sekarang: " + balance);
        } else {
            System.out.println("Deposit gagal. Jumlah tidak valid.");
        }
    }

    public void checkBalance() {
        System.out.println("Saldo anda saat ini: " + balance);
    }

    public void checkFutureBalance(int months) {
        double futureBalance = balance;
        for (int i = 0; i < months; i++) {
            futureBalance += futureBalance * interestRate;
        }
        System.out.println("Saldo anda setelah " + months + " bulan: " + futureBalance);
    }

    public User getUser() { return user; }
    public double getBalance() { return balance; }
}

class BankManager {
    private static ArrayList<BankAccount> accounts = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void register() {
        System.out.print("Masukkan Nama Lengkap Anda : ");
        String name = scanner.nextLine();

        int age = 0;
        while (true) {
            System.out.print("Masukkan Umur Anda : ");
            try {
                age = Integer.parseInt(scanner.nextLine());
                break;
            } catch (NumberFormatException e) {
                System.out.println("Input invalid, coba lagi.");
            }
        }

        System.out.print("Masukkan Alamat Anda : ");
        String address = scanner.nextLine();

        String accountNumber;
        while (true) {
            System.out.print("Masukkan nomor kartu ATM Anda : ");
            accountNumber = scanner.nextLine();
            if (accountNumber.matches("\\d+")) {
                break;
            }
            System.out.println("Input invalid, coba lagi : ");
        }

        String pin, confirmPin;
        do {
            System.out.print("Masukkan pin Anda : ");
            pin = scanner.nextLine();
            System.out.print("Konfirmasi pin Anda : ");
            confirmPin = scanner.nextLine();
            if (!pin.equals(confirmPin)) {
                System.out.println("Pin anda tidak sama dengan konfirmasi Pin, coba lagi");
            }
        } while (!pin.equals(confirmPin));

        User newUser = new User(name, age, address, accountNumber, pin);
        BankAccount newAccount = new BankAccount(newUser);
        accounts.add(newAccount);
        System.out.println("Registrasi berhasil!");
    }

    public static BankAccount login() {
        System.out.print("Masukkan nomor kartu ATM Anda : ");
        String accountNumber = scanner.nextLine();
        System.out.print("Masukkan pin Anda : ");
        String pin = scanner.nextLine();

        for (BankAccount account : accounts) {
            User user = account.getUser();
            if (user.getAccountNumber().equals(accountNumber) && user.getPin().equals(pin)) {
                return account;
            }
        }
        System.out.println("Invalid User");
        return null;
    }

    public static void deleteAccount(BankAccount account) {
        accounts.remove(account);
        System.out.println("Akun berhasil dihapus.");
    }
}

public class Tugas_4_672022302_PBO {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            System.out.println("1. Register");
            System.out.println("2. Login");
            System.out.println("3. Exit");
            System.out.print("Pilih menu (1-3): ");
            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    BankManager.register();
                    break;
                case "2":
                    BankAccount loggedInAccount = BankManager.login();
                    if (loggedInAccount != null) {
                        showLoggedInMenu(loggedInAccount);
                    }
                    break;
                case "3":
                    System.out.println("Terima kasih telah menggunakan ATM Bank Sentosa.");
                    System.exit(0);
                default:
                    System.out.println("Pilihan tidak valid. Silakan coba lagi.");
            }
        }
    }

    private static void showLoggedInMenu(BankAccount account) {
        while (true) {
            System.out.println("==============================");
            System.out.println("=======ATM BANK SENTOSA=======");
            System.out.println("==============================");
            System.out.println("Account Holder: " + account.getUser().getName());
            System.out.println("Account Number: " + account.getUser().getAccountNumber());
            System.out.println("Menu Pilihan:");
            System.out.println("1. Tarik Tunai");
            System.out.println("2. Deposit");
            System.out.println("3. Cek Saldo");
            System.out.println("4. Cek Biodata User");
            System.out.println("5. Hapus Akun");
            System.out.println("6. Keluar");
            System.out.print("Pilih 1-6: ");
            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    System.out.print("Masukkan jumlah penarikan: ");
                    double withdrawAmount = Double.parseDouble(scanner.nextLine());
                    account.withdraw(withdrawAmount);
                    break;
                case "2":
                    System.out.print("Masukkan jumlah deposit: ");
                    double depositAmount = Double.parseDouble(scanner.nextLine());
                    account.deposit(depositAmount);
                    break;
                case "3":
                    account.checkBalance();
                    System.out.print("Cek saldo masa depan? (Y/N): ");
                    if (scanner.nextLine().equalsIgnoreCase("Y")) {
                        System.out.print("Masukkan jumlah bulan: ");
                        int months = Integer.parseInt(scanner.nextLine());
                        account.checkFutureBalance(months);
                    }
                    break;
                case "4":
                    User user = account.getUser();
                    System.out.println("Nama: " + user.getName());
                    System.out.println("Umur: " + user.getAge());
                    System.out.println("Alamat: " + user.getAddress());
                    System.out.println("Nomor Rekening: " + user.getAccountNumber());
                    break;
                case "5":
                    System.out.print("Anda yakin ingin menghapus akun? (Y/N): ");
                    if (scanner.nextLine().equalsIgnoreCase("Y")) {
                        BankManager.deleteAccount(account);
                        return;
                    }
                    break;
                case "6":
                    return;
                default:
                    System.out.println("Pilihan tidak valid. Silakan coba lagi.");
            }
        }
    }
}