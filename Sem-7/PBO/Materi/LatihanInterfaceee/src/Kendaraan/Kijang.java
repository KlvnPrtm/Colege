package Kendaraan;

import Interfaces.Mobil;

public class Kijang implements Mobil{
    int kecepatan=0;
    int bensin;
    final int MAX_KECEPATAN = 70;
    final int MAX_BENSIN = 10;

    public Kijang (int bensin){
        this.bensin = bensin;
    }

    @Override
    public boolean isiBahanBakar(int bahanBakar) {
        if(this.bensin + bahanBakar > MAX_BENSIN){
            System.out.println("Tidak bisa mengisi bensin karena melebihi kapasitas maksimal");
            return false;
        }
        this.bensin += bensin;
        return true;
    }

    @Override
    public void tampilkanSisaBahanBakar() {
        System.out.println("Sisa bensin :" + bensin + " liter");
    }

    @Override
    public void tambahKecepatan(int kecepatan) {
        if(this.kecepatan + kecepatan > MAX_KECEPATAN){
            System.out.println("jangan dipaksa bang, mobil lama");
        }else{
            this.kecepatan += kecepatan;
        }
    }

    @Override
    public void kurangiKecepatan(int kecepatan) {
        this.kecepatan -= kecepatan;
    }

}
