public class Nasabah {
    private String namaAwal;
    private String namaAkhir;
    private Tabungan tabungan;

    // Tabungan tabungan = new Tabungan();

    public Nasabah(String namaAwal, String namaAkhir){
        this.namaAwal = namaAwal;
        this.namaAkhir = namaAkhir;
    }

    public String getNamaAwal(){
        return this.namaAwal;
    }

    public String getNamaAkhir(){
        return this.namaAkhir;
    }
    
    public Tabungan getTabungan(){
        return this.tabungan;
    }

    public Tabungan setTabungan(Tabungan tabungan){
        this.tabungan = tabungan;
        return this.tabungan;
    }

    

}
