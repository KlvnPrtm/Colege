/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dua;

/**
 *
 * @author supcs
 */
public class CheckLogin {

    public boolean Check() {
        GetSet gs = new GetSet();
        String user = gs.getUserInput();
        String pass = gs.getPassInput();
        if (user.equals("Admin")) {
            if (pass.equals("Admin")) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}
