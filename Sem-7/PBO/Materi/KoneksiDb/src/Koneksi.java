import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Koneksi {
    private static Koneksi instance = new Koneksi();
    private static Connection conn;

    public static Koneksi getKoneksi() {
        return instance;
    }

    public static Connection getConnection() {
        return conn;
    }

    private Koneksi() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/pbo_b", "root", "");
        } catch (SQLException | ClassNotFoundException ex) {
            System.err.println(ex.getMessage());
        }
    }
}
