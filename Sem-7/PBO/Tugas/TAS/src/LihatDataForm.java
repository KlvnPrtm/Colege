import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.*;
import java.sql.*;

public class LihatDataForm extends JFrame {
    private JTable tableKontingen;
    private DefaultTableModel tableModel;
    private JLabel lblTotalKontingen;
    private JTextField txtFilter;
    private JButton btnFilter;

    public LihatDataForm() {
        setTitle("Lihat Data Kontingen");
        setSize(800, 500);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);

        String[] columnNames = { "ID", "Nama Atlit", "Kategori", "Pasangan", "Negara" };
        tableModel = new DefaultTableModel(columnNames, 0);
        tableKontingen = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(tableKontingen);
        scrollPane.setBounds(20, 70, 740, 300);
        add(scrollPane);

        lblTotalKontingen = new JLabel("Total Kontingen: 0");
        lblTotalKontingen.setBounds(20, 380, 200, 30);
        add(lblTotalKontingen);

        JLabel lblFilter = new JLabel("Filter Nama:");
        lblFilter.setBounds(20, 20, 100, 30);
        add(lblFilter);

        txtFilter = new JTextField();
        txtFilter.setBounds(100, 20, 200, 30);
        add(txtFilter);

        btnFilter = new JButton("Filter");
        btnFilter.setBounds(320, 20, 100, 30);
        add(btnFilter);
        btnFilter.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                filterData();
            }
        });

        tableKontingen.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) { // Klik dua kali
                    int selectedRow = tableKontingen.getSelectedRow();
                    if (selectedRow != -1) {
                        int kontingenId = (int) tableModel.getValueAt(selectedRow, 0);
                        new DetailKontingenForm(kontingenId).setVisible(true);
                    }
                }
            }
        });

        loadKontingen();
    }

    private void loadKontingen() {
        tableModel.setRowCount(0); // Reset data tabel
        int totalKontingen = 0;

        try (Connection conn = DatabaseConnection.getConnection();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(
                 "SELECT k.id, k.nama, k.kategori, k.pasangan, n.nama_negara " +
                 "FROM kontingen k " +
                 "LEFT JOIN negara n ON k.negara_id = n.id")) {
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("id"),
                    rs.getString("nama"),
                    rs.getString("kategori"),
                    rs.getString("pasangan"),
                    rs.getString("nama_negara")
                };
                tableModel.addRow(row);
                totalKontingen++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Gagal memuat data kontingen.");
        }

        lblTotalKontingen.setText("Total Kontingen: " + totalKontingen);
    }

    private void filterData() {
        String filterText = txtFilter.getText().trim();
        if (filterText.isEmpty()) {
            loadKontingen();
            return;
        }

        tableModel.setRowCount(0);
        int totalKontingen = 0;

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(
                 "SELECT k.id, k.nama, k.kategori, k.pasangan, n.nama_negara " +
                 "FROM kontingen k " +
                 "LEFT JOIN negara n ON k.negara_id = n.id " +
                 "WHERE k.nama LIKE ?")) {
            stmt.setString(1, "%" + filterText + "%");
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("id"),
                    rs.getString("nama"),
                    rs.getString("kategori"),
                    rs.getString("pasangan"),
                    rs.getString("nama_negara")
                };
                tableModel.addRow(row);
                totalKontingen++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Gagal memfilter data kontingen.");
        }

        lblTotalKontingen.setText("Total Kontingen: " + totalKontingen);
    }
}
