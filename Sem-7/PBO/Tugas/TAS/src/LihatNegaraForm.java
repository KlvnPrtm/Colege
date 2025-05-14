import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;

public class LihatNegaraForm extends JFrame {
    private JTable tableNegara;
    private DefaultTableModel tableModel;

    public LihatNegaraForm() {
        setTitle("Lihat Data Negara");
        setSize(600, 400);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);

        String[] columnNames = { "ID", "Nama Negara" };
        tableModel = new DefaultTableModel(columnNames, 0);
        tableNegara = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(tableNegara);
        scrollPane.setBounds(20, 20, 550, 300);
        add(scrollPane);

        loadNegara();
    }

    private void loadNegara() {
        try (Connection conn = DatabaseConnection.getConnection();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT * FROM negara")) {
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("id"),
                    rs.getString("nama_negara")
                };
                tableModel.addRow(row);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Gagal memuat data negara.");
        }
    }
}
