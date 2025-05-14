import javax.swing.*;
import java.awt.event.*;
import java.sql.*;

public class InputKontingenForm extends JFrame {
    private JTextField txtNama, txtPasangan;
    private JComboBox<String> cmbNegara, cmbKategori;
    private JButton btnSimpan;
    private JFileChooser fileChooser;
    private JLabel lblFoto;

    public InputKontingenForm() {
        setTitle("Input Kontingen");
        setSize(500, 400);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);

        JLabel lblNama = new JLabel("Nama Atlit:");
        lblNama.setBounds(50, 50, 100, 30);
        add(lblNama);

        txtNama = new JTextField();
        txtNama.setBounds(150, 50, 200, 30);
        add(txtNama);

        JLabel lblKategori = new JLabel("Kategori:");
        lblKategori.setBounds(50, 100, 100, 30);
        add(lblKategori);

        cmbKategori = new JComboBox<>(new String[] { "Single", "Ganda" });
        cmbKategori.setBounds(150, 100, 200, 30);
        add(cmbKategori);
        cmbKategori.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (cmbKategori.getSelectedItem().equals("Ganda")) {
                    txtPasangan.setEnabled(true);
                } else {
                    txtPasangan.setEnabled(false);
                    txtPasangan.setText("");
                }
            }
        });

        JLabel lblPasangan = new JLabel("Pasangan:");
        lblPasangan.setBounds(50, 150, 100, 30);
        add(lblPasangan);

        txtPasangan = new JTextField();
        txtPasangan.setBounds(150, 150, 200, 30);
        txtPasangan.setEnabled(false);
        add(txtPasangan);

        JLabel lblNegara = new JLabel("Negara:");
        lblNegara.setBounds(50, 200, 100, 30);
        add(lblNegara);

        cmbNegara = new JComboBox<>();
        cmbNegara.setBounds(150, 200, 200, 30);
        add(cmbNegara);
        loadNegara();

        JLabel lblFotoLabel = new JLabel("Foto:");
        lblFotoLabel.setBounds(50, 250, 100, 30);
        add(lblFotoLabel);

        lblFoto = new JLabel();
        lblFoto.setBounds(150, 250, 200, 100);
        lblFoto.setBorder(BorderFactory.createEtchedBorder());
        add(lblFoto);

        JButton btnUpload = new JButton("Upload");
        btnUpload.setBounds(360, 250, 80, 30);
        add(btnUpload);
        btnUpload.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                fileChooser = new JFileChooser();
                int returnValue = fileChooser.showOpenDialog(null);
                if (returnValue == JFileChooser.APPROVE_OPTION) {
                    lblFoto.setText(fileChooser.getSelectedFile().getName());
                }
            }
        });

        btnSimpan = new JButton("Simpan");
        btnSimpan.setBounds(150, 370, 100, 30);
        add(btnSimpan);
        btnSimpan.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                simpanKontingen();
            }
        });
    }

    private void loadNegara() {
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement("SELECT nama_negara FROM negara");
             ResultSet rs = stmt.executeQuery()) {
            while (rs.next()) {
                cmbNegara.addItem(rs.getString("nama_negara"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void simpanKontingen() {
        // Implementasi simpan data kontingen
    }
}
