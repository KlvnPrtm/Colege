



import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Database {
    private static Database instance = new Database();
    private static Connection conn;
    private static final String URL = "jdbc:mysql://localhost:3306/pemesanan_tiket"; // Ganti "pemesanan_tiket" dengan nama database Anda
    private static final String USER = "root"; // Sesuaikan username MySQL
    private static final String PASSWORD = ""; // Sesuaikan password MySQL

    public static Database getKoneksi() {
        return instance;
    }
    
    public static Connection getConnection() {
        try {
            Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
            System.out.println("Koneksi berhasil!");
            return conn;
        } catch (SQLException e) {
            System.out.println("Koneksi gagal: " + e.getMessage());
            return null; // Pastikan metode mengembalikan null jika gagal
        }
    }

    private Database() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/pemesanan_tiket", "root", "");
        } catch (SQLException | ClassNotFoundException ex) {
            System.err.println(ex.getMessage());
        }
    }
}
