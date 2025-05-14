// import javax.swing.*;
// import javax.swing.table.DefaultTableModel;

// import Konektor.Database;

// import java.awt.*;
// import java.awt.event.*;
// import java.sql.*;
import java.sql.Connection;
// import java.sql.DriverManager;
import java.sql.SQLException;

public class TestKoneksi {
    public static void main(String[] args) {
        try (Connection conn = Database.getConnection()) {
            if (conn != null) {
                System.out.println("Koneksi berhasil!");
            } else {
                System.out.println("Koneksi gagal!");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}