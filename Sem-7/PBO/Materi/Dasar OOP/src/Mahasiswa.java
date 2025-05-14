public class Mahasiswa {
    private int nim;
    private String nama;
    
    public Mahasiswa(int i, String n) {
        nim=i;
        nama=n;
    }

    public int getNim(){
        return nim;
    }

    public String getNama(){
        return nama;
    }
}
