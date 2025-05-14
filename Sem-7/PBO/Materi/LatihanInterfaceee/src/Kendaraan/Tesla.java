package Kendaraan;

import Interfaces.Mobil;

public class Tesla implements Mobil{
    int kecepatan=0;
    int listrik;
    final int MAX_LISTRIK=120;
    public Tesla (int listrik){
        this.listrik = listrik;
    }

    @Override
    public boolean isiBahanBakar(int bahanBakar) {
        if(this.listrik + bahanBakar > MAX_LISTRIK){
            System.out.println("kapasitas melebihi batas maksimal tesla");
            return false;
        }
        this.listrik += bahanBakar;
        return true;
    }

    @Override
    public void tampilkanSisaBahanBakar() {
        System.out.println("sisa listrik tesla :" + listrik + "watt");
    }

    @Override
    public void tambahKecepatan(int kecepatan) {
        this.kecepatan += kecepatan;
    }

    @Override
    public void kurangiKecepatan(int kecepatan) {
        this.kecepatan -= kecepatan;

    }

}
