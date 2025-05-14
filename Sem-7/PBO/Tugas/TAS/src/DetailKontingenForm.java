import javax.swing.*;
import java.sql.*;

public class DetailKontingenForm extends JFrame {
    private JLabel lblNama, lblKategori, lblPasangan, lblNegara, lblFoto;

    public DetailKontingenForm(int kontingenId) {
        setTitle("Detail Kontingen");
        setSize(400, 300);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);

        JLabel lblNamaLabel = new JLabel("Nama:");
        lblNamaLabel.setBounds(20, 20, 100, 30);
        add(lblNamaLabel);

        lblNama = new JLabel();
        lblNama.setBounds(150, 20, 200, 30);
        add(lblNama);

        JLabel lblKategoriLabel = new JLabel("Kategori:");
        lblKategoriLabel.setBounds(20, 60, 100, 30);
        add(lblKategoriLabel);

        lblKategori = new JLabel();
        lblKategori.setBounds(150, 60, 200, 30);
        add(lblKategori);

        JLabel lblPasanganLabel = new JLabel("Pasangan:");
        lblPasanganLabel.setBounds(20, 100, 100, 30);
        add(lblPasanganLabel);

        lblPasangan = new JLabel();
        lblPasangan.setBounds(150, 100, 200, 30);
        add(lblPasangan);

        JLabel lblNegaraLabel = new JLabel("Negara:");
        lblNegaraLabel.setBounds(20, 140, 100, 30);
        add(lblNegaraLabel);

        lblNegara = new JLabel();
        lblNegara.setBounds(150, 140, 200, 30);
        add(lblNegara);

        lblFoto = new JLabel("Foto tidak ditampilkan");
        lblFoto.setBounds(20, 180, 300, 100);
        add(lblFoto);

        loadDetail(kontingenId);
    }

    private void loadDetail(int kontingenId) {
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(
                 "SELECT k.nama, k.kategori, k.pasangan, n.nama_negara " +
                 "FROM kontingen k " +
                 "LEFT JOIN negara n ON k.negara_id = n.id " +
                 "WHERE k.id = ?")) {
            stmt.setInt(1, kontingenId);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                lblNama.setText(rs.getString("nama"));
                lblKategori.setText(rs.getString("kategori"));
                lblPasangan.setText(rs.getString("pasangan"));
                lblNegara.setText(rs.getString("nama_negara"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Gagal memuat detail kontingen.");
        }
    }
}
