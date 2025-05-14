class PesananUmum extends Pesanan {
    public PesananUmum(double hargaDasar) {
        super(hargaDasar);
    }

    @Override
    public void prosesPesanan() {
        System.out.println("Memproses pesanan umum.");
    }

    @Override
    public double hitungTotal(double tarifPajak, int jumlahItem) {
        return hargaDasar * (1 + tarifPajak);
    }
}