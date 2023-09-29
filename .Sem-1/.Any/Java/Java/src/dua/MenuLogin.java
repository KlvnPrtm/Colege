/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dua;

import java.util.Scanner;

/**
 *
 * @author supcs
 */
public class MenuLogin {

    public static void MenuLogin() {
        GetSet gs = new GetSet();
        CheckLogin cl = new CheckLogin();
        Scanner scanner = new Scanner(System.in);
        boolean ulang = false;
        do {
            System.out.println("Belajar Coding Login");
            System.out.println("********************");
            System.out.print("Username anda : ");
            String user = scanner.nextLine();
            System.out.print("Password anda : ");
            String pass = scanner.nextLine();
            gs.setUsername(user);
            gs.setPassword(pass);

            if (cl.Check() == true) {
                System.out.println("Login Admin Sukses");
                System.out.println("Selamat Datang Admin");
            } else {
                System.out.println("Login Gagal!");
                System.out.println();
                System.out.println("Apakah anda akan mengulang? (Y/T)");
                System.out.print("Jawab : ");
                String jawab = scanner.nextLine();
                if (jawab.equalsIgnoreCase("Y")) {
                    System.out.println("");
                    ulang = true;
                } else if (jawab.equalsIgnoreCase("T")) {
                    ulang = false;
                }
            }
        } while (ulang);
    }
}
