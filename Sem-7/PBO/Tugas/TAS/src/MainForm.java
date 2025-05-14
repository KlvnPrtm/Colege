import javax.swing.*;
import java.awt.event.*;

public class MainForm extends JFrame {
    public MainForm() {
        setTitle("Main Menu");
        setSize(600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(null);

        JButton btnMasterNegara = new JButton("Master Negara");
        btnMasterNegara.setBounds(50, 50, 200, 30);
        add(btnMasterNegara);
        btnMasterNegara.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new MasterNegaraForm().setVisible(true);
            }
        });

        JButton btnInputKontingen = new JButton("Input Kontingen");
        btnInputKontingen.setBounds(50, 100, 200, 30);
        add(btnInputKontingen);
        btnInputKontingen.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new InputKontingenForm().setVisible(true);
            }
        });

        JButton btnLihatData = new JButton("Lihat Data Atlit");
        btnLihatData.setBounds(50, 150, 200, 30);
        add(btnLihatData);
        btnLihatData.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new LihatDataForm().setVisible(true);
            }
        });
    }
}
