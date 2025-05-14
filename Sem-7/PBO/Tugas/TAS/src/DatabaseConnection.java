import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

// public class DatabaseConnection {
//     public static Connection getConnection() throws SQLException {
//         String url = "jdbc:mysql://localhost:3306/lomba";
//         String user = "root";
//         String password = ""; // Ganti dengan password MySQL Anda
//         return DriverManager.getConnection(url, user, password);
//     }
// }

public class DatabaseConnection {
    private static DatabaseConnection instance = new DatabaseConnection();
    private static Connection conn;

    public static DatabaseConnection getDatabaseConnection() {
        return instance;
    }

    public static Connection getConnection() {
        return conn;
    }

    private DatabaseConnection() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/lomba", "root", "");
        } catch (SQLException | ClassNotFoundException ex) {
            System.err.println(ex.getMessage());
        }
    }
}
