import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class TiketApp extends JFrame {
    private JTable table;
    private DefaultTableModel model;
    private JTextField txtNama, txtTransportasi, txtTanggal, txtHarga;
    private JButton btnAdd, btnUpdate, btnDelete, btnRefresh;

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

        loadData();
        setVisible(true);
    }

    private void loadData() {
        model.setRowCount(0);
        try (Connection conn = DatabaseConnection.getConnection();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT * FROM tiket")) {
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
        }
    }

    private void tambahData() {
        String nama = txtNama.getText();
        String transportasi = txtTransportasi.getText();
        String tanggal = txtTanggal.getText();
        double harga = Double.parseDouble(txtHarga.getText());

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement("INSERT INTO tiket (nama, transportasi, tanggal, harga) VALUES (?, ?, ?, ?)")) {
            pstmt.setString(1, nama);
            pstmt.setString(2, transportasi);
            pstmt.setString(3, tanggal);
            pstmt.setDouble(4, harga);
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Data berhasil ditambahkan!");
            loadData();
        } catch (SQLException e) {
            e.printStackTrace();
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
        double harga = Double.parseDouble(txtHarga.getText());

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement("UPDATE tiket SET nama = ?, transportasi = ?, tanggal = ?, harga = ? WHERE id = ?")) {
            pstmt.setString(1, nama);
            pstmt.setString(2, transportasi);
            pstmt.setString(3, tanggal);
            pstmt.setDouble(4, harga);
            pstmt.setInt(5, id);
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Data berhasil diupdate!");
            loadData();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void hapusData() {
        int selectedRow = table.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Pilih data yang ingin dihapus!");
            return;
        }

        int id = (int) model.getValueAt(selectedRow, 0);

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement("DELETE FROM tiket WHERE id = ?")) {
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Data berhasil dihapus!");
            loadData();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new TiketApp();
    }
}
