package models;

public class Mahasiswa {
    private String id;
    private String nim;
    private String nama;
    private boolean jenisKelamin;
    private String prodi;
    private boolean isBeasiswa;

    public Mahasiswa(String id, String nim, String nama, boolean jenisKelamin, String prodi, boolean isBeasiswa) {
        this.id = id;
        this.nim = nim;
        this.nama = nama;
        this.jenisKelamin = jenisKelamin;
        this.prodi = prodi;
        this.isBeasiswa = isBeasiswa;
    }

    public String getId() {
        return id;
    }

    public String getNim() {
        return nim;
    }

    public String getNama() {
        return nama;
    }

    public boolean isJenisKelamin() {
        return jenisKelamin;
    }

    public String getProdi() {
        return prodi;
    }

    public boolean isBeasiswa() {
        return isBeasiswa;
    }
}