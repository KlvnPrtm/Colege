public class Tiket {
    private int id;
    private String nama;
    private String transportasi;
    private String tanggal;
    private double harga;

    // Constructor
    public Tiket(int id, String nama, String transportasi, String tanggal, double harga) {
        this.id = id;
        this.nama = nama;
        this.transportasi = transportasi;
        this.tanggal = tanggal;
        this.harga = harga;
    }

    // Getters dan Setters (Encapsulation)
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getTransportasi() {
        return transportasi;
    }

    public void setTransportasi(String transportasi) {
        this.transportasi = transportasi;
    }

    public String getTanggal() {
        return tanggal;
    }

    public void setTanggal(String tanggal) {
        this.tanggal = tanggal;
    }

    public double getHarga() {
        return harga;
    }

    public void setHarga(double harga) {
        this.harga = harga;
    }
}
