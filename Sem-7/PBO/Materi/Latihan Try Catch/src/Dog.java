public class Dog {
    String nama;
    int umur;
    String jenis;

    public Dog (String nama, int umur, String jenis) throws IllegalArgumentException{
        this.nama=nama;
        
        this.umur=umur;
        if (umur<0) {
            throw new IllegalArgumentException("Umur tidak boleh minus");
        }
            
        this.jenis=jenis;

    }
}
