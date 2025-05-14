class PesananToko extends Pesanan {
    public PesananToko(double hargaDasar) {
        super(hargaDasar);
    }

    @Override
    public void prosesPesanan() {
        System.out.println("Memproses pesanan toko.");
    }

    @Override
    public double hitungTotal(double tarifPajak, int jumlahItem) {
        return (hargaDasar * (1 + tarifPajak)) * jumlahItem;
    }
}