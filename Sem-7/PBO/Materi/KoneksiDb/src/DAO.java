import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import models.Mahasiswa;

public class DAO {
    //READ
    public List<Mahasiswa> readAll(){
        List<Mahasiswa> daftarMahasiswa = new ArrayList<>();
        try {
            Connection con = Koneksi.getConnection();
            String query = "SELECT * FROM mahasiswa";
            PreparedStatement pst = con.prepareStatement(query);
            ResultSet hasil = pst.executeQuery();
            //baca data
            while(hasil.next()){
                daftarMahasiswa.add(new Mahasiswa(
                    hasil.getString("id"),
                    hasil.getString("nim"),
                    hasil.getString("nama"),
                    hasil.getBoolean("jenis_kelamin"),
                    hasil.getString("progdi"),
                    hasil.getBoolean("beasiswa")
                ));
            }
            return daftarMahasiswa;
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
            return daftarMahasiswa;
        }
    }
    //CREATE
    public int insertOne(Mahasiswa mhs) {
        try {
            Connection con = Koneksi.getConnection();
            String query = "INSERT INTO mahasiswa (nim, nama, progdi, jenis_kelamin, beasiswa) VALUES (?, ?, ?, ?, ?)";

            PreparedStatement pst = con.prepareStatement(query);
            pst.setString(1, mhs.getNim());
            pst.setString(2, mhs.getNama());
            pst.setString(3, mhs.getProdi());
            pst.setBoolean(4, mhs.isJenisKelamin());
            pst.setBoolean(5, mhs.isBeasiswa());
            System.out.println(pst);
            return pst.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Insert error: " + e.getMessage());
            return 0;
        }
    }

    //UPDATE
    public int updateOne(Mahasiswa mhs){
        try {
            Connection con = Koneksi.getConnection();
            String query = "UPDATE mahasiswa SET nim=?, nama=?, progdi=? jenis_kelamin=? , beasiswa=? WHERE id=?";
            PreparedStatement pst = con.prepareStatement(query);
            pst.setString(1, mhs.getNim());
            pst.setString(2, mhs.getNama());
            pst.setString(3, mhs.getProdi());
            pst.setBoolean(4, mhs.isJenisKelamin());
            pst.setBoolean(5, mhs.isBeasiswa());
            pst.setInt(6, Integer.parseInt(mhs.getId()));
            return pst.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Update error: " + e.getMessage());
            return 0;
        }
    }
    //DELETE
    public int deleteOne(String id){
        try {
            Connection con = Koneksi.getConnection();
            String query = "DELETE FROM mahasiswa WHERE id=?";
            PreparedStatement pst = con.prepareStatement(query);
            pst.setInt(1,  Integer.parseInt(id));
            return pst.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Update error: " + e.getMessage());
            return 0;
        }
    }
}
