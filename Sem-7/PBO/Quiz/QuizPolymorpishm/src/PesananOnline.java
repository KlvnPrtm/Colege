class PesananOnline extends Pesanan {
    private String alamatPengiriman;

    public PesananOnline(double hargaDasar, String alamatPengiriman) {
        super(hargaDasar);
        this.alamatPengiriman = alamatPengiriman;
    }

    @Override
    public void prosesPesanan() {
        System.out.println("Memproses pesanan online.");
    }

    @Override
    public double hitungTotal(double tarifPajak, int jumlahItem) {
        return hargaDasar * (1 + tarifPajak);
    }
}