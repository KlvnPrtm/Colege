public class Bank {
    private Nasabah[] nasabah;
    private int jumlahNasabah;

    public Bank() {
        this.nasabah = new Nasabah[10];
        this.jumlahNasabah = 0;
    }

    public void tambahNasabah(String namaAwal, String namaAkhir) {
        Nasabah nasabahBaru = new Nasabah(namaAwal, namaAkhir);
        this.nasabah[this.jumlahNasabah] = nasabahBaru;
        this.jumlahNasabah++;
    }

    public int getJumlahNasabah() {
        return jumlahNasabah;
    }
    
    public Nasabah getNasabah(int indeks) {
        if (indeks >= 0 && indeks < jumlahNasabah) {
            return nasabah[indeks];
        }
        return null;
    }
}
