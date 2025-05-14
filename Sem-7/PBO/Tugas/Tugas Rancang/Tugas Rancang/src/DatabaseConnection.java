import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnection {
    private static final String URL = "jdbc:mysql://localhost:3306/pemesanan_tiket";
    private static final String USER = "root"; // Sesuaikan dengan user MySQL Anda
    private static final String PASSWORD = ""; // Sesuaikan dengan password MySQL Anda

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
}