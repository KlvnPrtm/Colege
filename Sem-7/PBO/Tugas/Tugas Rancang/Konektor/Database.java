package Konektor;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Database {
    private static Database instance = new Database();
    private static Connection conn;
 
    public static Database getKoneksi() {
       return instance;
    }
 
    public static Connection getConnection() {
         try {
             if (conn == null || conn.isClosed()) {
                 // Reconnect if the connection is closed or null
                 conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/pemesanan_tiket", "root", "");
             }
         } catch (SQLException e) {
             System.err.println("Error while getting connection: " + e.getMessage());
         }
         return conn;
     }
 
    private Database() {
       try {
          Class.forName("com.mysql.cj.jdbc.Driver");
          conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/pemesanan_tiket", "root", "");
       } catch (ClassNotFoundException | SQLException var2) {
          System.err.println(var2.getMessage());
       }
 
    }
 }