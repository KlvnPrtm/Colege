import javax.swing.*;
import java.awt.event.*;
import java.sql.*;

public class MasterNegaraForm extends JFrame {
    private JTextField txtNamaNegara;
    private JButton btnSimpan, btnLihat;

    public MasterNegaraForm() {
        setTitle("Master Negara");
        setSize(400, 300);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);

        JLabel lblNamaNegara = new JLabel("Nama Negara:");
        lblNamaNegara.setBounds(50, 50, 100, 30);
        add(lblNamaNegara);

        txtNamaNegara = new JTextField();
        txtNamaNegara.setBounds(150, 50, 200, 30);
        add(txtNamaNegara);

        btnSimpan = new JButton("Simpan");
        btnSimpan.setBounds(50, 100, 100, 30);
        add(btnSimpan);
        btnSimpan.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                simpanNegara();
            }
        });

        btnLihat = new JButton("Lihat Data");
        btnLihat.setBounds(200, 100, 100, 30);
        add(btnLihat);
        btnLihat.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new LihatNegaraForm().setVisible(true);
            }
        });
    }

    private void simpanNegara() {
        String namaNegara = txtNamaNegara.getText();
        if (namaNegara.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Nama negara tidak boleh kosong!");
            return;
        }

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement("INSERT INTO negara (nama_negara) VALUES (?)")) {
            stmt.setString(1, namaNegara);
            stmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Data negara berhasil disimpan!");
            txtNamaNegara.setText("");
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Gagal menyimpan data negara.");
        }
    }
}
