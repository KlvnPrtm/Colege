import Konektor.Database;
import java.awt.*;
import java.sql.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class TiketApp extends JFrame {
    private JTable table;
    private DefaultTableModel model;
    private JTextField txtNama, txtTransportasi, txtTanggal, txtHarga;
    private JButton btnAdd, btnUpdate, btnDelete, btnRefresh;

    public static void main(String[] args) {
        new TiketApp();
    }

    public TiketApp() {
        setTitle("Pemesanan Tiket Transportasi");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Tabel
        model = new DefaultTableModel(new String[]{"ID", "Nama", "Transportasi", "Tanggal", "Harga"}, 0);
        table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        add(scrollPane, BorderLayout.CENTER);

        // Form
        JPanel panelForm = new JPanel(new GridLayout(5, 2));
        panelForm.add(new JLabel("Nama:"));
        txtNama = new JTextField();
        panelForm.add(txtNama);

        panelForm.add(new JLabel("Transportasi:"));
        txtTransportasi = new JTextField();
        panelForm.add(txtTransportasi);

        panelForm.add(new JLabel("Tanggal (YYYY-MM-DD):"));
        txtTanggal = new JTextField();
        panelForm.add(txtTanggal);

        panelForm.add(new JLabel("Harga:"));
        txtHarga = new JTextField();
        panelForm.add(txtHarga);

        add(panelForm, BorderLayout.NORTH);

        // Tombol
        JPanel panelButton = new JPanel();
        btnAdd = new JButton("Tambah");
        btnUpdate = new JButton("Update");
        btnDelete = new JButton("Hapus");
        btnRefresh = new JButton("Refresh");

        panelButton.add(btnAdd);
        panelButton.add(btnUpdate);
        panelButton.add(btnDelete);
        panelButton.add(btnRefresh);

        add(panelButton, BorderLayout.SOUTH);

        // Event Listener
        btnAdd.addActionListener(e -> tambahData());
        btnUpdate.addActionListener(e -> updateData());
        btnDelete.addActionListener(e -> hapusData());
        btnRefresh.addActionListener(e -> loadData());

        // Debugging connection
        try (Connection conn = Database.getConnection()) {
            if (conn == null) {
                System.err.println("Database connection failed! Please check Database.getConnection().");
                JOptionPane.showMessageDialog(this, "Database connection failed. Please check the configuration.");
                return;
            }
            System.out.println("Database connection successful.");
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error connecting to the database: " + e.getMessage());
        }

        loadData();
        setVisible(true);
    }

    private void loadData() {
        model.setRowCount(0);
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;

        try {
            // Establishing connection
            conn = Database.getConnection();
            if (conn == null) {
                JOptionPane.showMessageDialog(this, "Failed to connect to the database!");
                return;
            }

            // Create a statement and execute the query
            stmt = conn.createStatement();
            rs = stmt.executeQuery("SELECT * FROM tiket");

            while (rs.next()) {
                model.addRow(new Object[]{
                    rs.getInt("id"),
                    rs.getString("nama"),
                    rs.getString("transportasi"),
                    rs.getString("tanggal"),
                    rs.getDouble("harga")
                });
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to load data: " + e.getMessage());
        } finally {
            // Ensure proper cleanup of resources, even if an error occurred
            try {
                if (rs != null) rs.close();
                if (stmt != null) stmt.close();
                if (conn != null) conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }


    private void tambahData() {
        String nama = txtNama.getText();
        String transportasi = txtTransportasi.getText();
        String tanggal = txtTanggal.getText();
        try {
            double harga = Double.parseDouble(txtHarga.getText());

            try (Connection conn = Database.getConnection();
                 PreparedStatement pstmt = conn.prepareStatement("INSERT INTO tiket (nama, transportasi, tanggal, harga) VALUES (?, ?, ?, ?)")) {
                pstmt.setString(1, nama);
                pstmt.setString(2, transportasi);
                pstmt.setString(3, tanggal);
                pstmt.setDouble(4, harga);
                pstmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Data berhasil ditambahkan!");
                loadData();
            }
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Harga harus berupa angka!");
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to add data: " + e.getMessage());
        }
    }

    private void updateData() {
        int selectedRow = table.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Pilih data yang ingin diupdate!");
            return;
        }

        int id = (int) model.getValueAt(selectedRow, 0);
        String nama = txtNama.getText();
        String transportasi = txtTransportasi.getText();
        String tanggal = txtTanggal.getText();
        try {
            double harga = Double.parseDouble(txtHarga.getText());

            try (Connection conn = Database.getConnection();
                 PreparedStatement pstmt = conn.prepareStatement("UPDATE tiket SET nama = ?, transportasi = ?, tanggal = ?, harga = ? WHERE id = ?")) {
                pstmt.setString(1, nama);
                pstmt.setString(2, transportasi);
                pstmt.setString(3, tanggal);
                pstmt.setDouble(4, harga);
                pstmt.setInt(5, id);
                pstmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Data berhasil diupdate!");
                loadData();
            }
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Harga harus berupa angka!");
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to update data: " + e.getMessage());
        }
    }

    private void hapusData() {
        int selectedRow = table.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Pilih data yang ingin dihapus!");
            return;
        }

        int id = (int) model.getValueAt(selectedRow, 0);

        try (Connection conn = Database.getConnection();
             PreparedStatement pstmt = conn.prepareStatement("DELETE FROM tiket WHERE id = ?")) {
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Data berhasil dihapus!");
            loadData();
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to delete data: " + e.getMessage());
        }
    }
}