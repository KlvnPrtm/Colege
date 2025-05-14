import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumn;

import models.Mahasiswa;

public class FormMahasiswa extends JFrame {

    private JTextField fieldNama;
    private JTextField fieldNim;
    private JCheckBox checkBoxBeasiswa;
    private JRadioButton radioBtnLakiLaki;
    private JRadioButton radioBtnPerempuan;
    private ButtonGroup radioButtonGroup;
    private JComboBox<String> dropdownProgdi;
    private List<Mahasiswa> mahasiswaList;
    private DefaultTableModel tableModel;
    private JTable table;
    private DAO api = new DAO();

    public FormMahasiswa() {
        mahasiswaList = new ArrayList<>();
        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints layout = new GridBagConstraints();
        JLabel namaLabel = new JLabel("Nama");
        layout.gridx = 0;
        layout.gridy = 0;
        layout.anchor = GridBagConstraints.WEST;
        panel.add(namaLabel, layout);

        fieldNama = new JTextField(20);
        layout.gridx = 1;
        layout.gridy = 0;
        layout.fill = GridBagConstraints.HORIZONTAL;
        panel.add(fieldNama, layout);

        JLabel nimLabel = new JLabel("NIM: ");
        layout.gridx = 0;
        layout.gridy = 1;
        layout.fill = GridBagConstraints.NONE;
        panel.add(nimLabel, layout);

        fieldNim = new JTextField(20);
        layout.gridx = 1;
        layout.gridy = 1;
        layout.fill = GridBagConstraints.HORIZONTAL;
        panel.add(fieldNim, layout);

        JLabel jkJLabel = new JLabel("Jenis Kelamin: ");
        layout.gridx = 0;
        layout.gridy = 2;
        layout.fill = GridBagConstraints.NONE;
        panel.add(jkJLabel, layout);

        radioBtnLakiLaki = new JRadioButton("Laki-laki");
        layout.gridx = 1;
        layout.gridy = 2;
        layout.fill = GridBagConstraints.HORIZONTAL;
        panel.add(radioBtnLakiLaki, layout);

        radioBtnPerempuan = new JRadioButton("Perempuan");
        layout.gridx = 1;
        layout.gridy = 3;
        layout.fill = GridBagConstraints.HORIZONTAL;
        panel.add(radioBtnPerempuan, layout);
        radioButtonGroup = new ButtonGroup();
        radioButtonGroup.add(radioBtnLakiLaki);
        radioButtonGroup.add(radioBtnPerempuan);

        JLabel dropdownLabel = new JLabel("Pilih Prodi: ");
        layout.gridx = 0;
        layout.gridy = 4;
        layout.fill = GridBagConstraints.NONE;
        panel.add(dropdownLabel, layout);

        String[] options = { "TI", "DKV", "SI", "PTIK" };
        dropdownProgdi = new JComboBox<>(options);
        layout.gridx = 1;
        layout.gridy = 4;
        layout.fill = GridBagConstraints.HORIZONTAL;
        panel.add(dropdownProgdi, layout);

        JLabel checkBoxJLabel = new JLabel("Penerima Beasiswa");
        layout.gridx = 0;
        layout.gridy = 5;
        layout.fill = GridBagConstraints.NONE;
        panel.add(checkBoxJLabel, layout);

        checkBoxBeasiswa = new JCheckBox("");
        layout.gridx = 1;
        layout.gridy = 5;
        layout.fill = GridBagConstraints.HORIZONTAL;
        panel.add(checkBoxBeasiswa, layout);

        JButton submiButton = new JButton("Submit");
        submiButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                handleSubmit();
            }
        });
        layout.gridx = 1;
        layout.gridy = 6;
        layout.fill = GridBagConstraints.NONE;
        panel.add(submiButton, layout);

        // String[] columns = { "Nama", "NIM", "Progdi", "Beasiswa", "Jenis Kelamin" };
        // String[][] data = new String[5][5];
        table = new JTable();
        tableModel = new DefaultTableModel();
        tableModel.addColumn("Nama");
        tableModel.addColumn("NIM");
        tableModel.addColumn("Progdi");
        tableModel.addColumn("Jenis Kelamin");
        tableModel.addColumn("Beasiswa");
        table.setModel(tableModel);
        JScrollPane tabScrollPane = new JScrollPane(table);
        tabScrollPane.setPreferredSize(new Dimension(500, 150));
        layout.gridx = 0;
        layout.gridy = 7;
        layout.gridwidth = 2;
        panel.add(tabScrollPane, layout);

        add(panel);
        setTitle("Data Mahasiswa");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 500);
        setLocationRelativeTo(null);
        setResizable(false);
        updateTable();
    }

    private void handleSubmit() {
        String nama = fieldNama.getText();
        String nim = fieldNim.getText();
        String prodi = dropdownProgdi.getSelectedItem().toString();
        boolean beasiswa = checkBoxBeasiswa.isSelected();
        boolean jenisKelamin = radioBtnLakiLaki.isSelected() ? false :
        radioBtnPerempuan.isSelected() ? true : false;
        Mahasiswa dataBaru = new Mahasiswa(null, nim, nama, jenisKelamin, prodi, beasiswa);
        api.insertOne(dataBaru);
        clearInput();
        updateTable();
    }
    private void clearInput() {
        fieldNama.setText("");
        fieldNim.setText("");
        dropdownProgdi.setSelectedIndex(0);
        checkBoxBeasiswa.setSelected(false);
        radioButtonGroup.clearSelection();
    }

    private void updateTable() {
        tableModel.setRowCount(0);
        List<Mahasiswa> listMahasiswa = api.readAll();
        for(Mahasiswa mhs: listMahasiswa){
            tableModel.addRow(new Object[]{
                mhs.getNama(),
                mhs.getNim(),
                mhs.getProdi(),
                mhs.isJenisKelamin() ? "Perempuan" : "Laki-laki",
                mhs.isBeasiswa()? "Ya" : "Tidak"
            });
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                FormMahasiswa form = new FormMahasiswa();
                form.setVisible(true);
            }
        });
    }
}
