<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class AplikasiKasir extends Controller
{

    public $menu1= [
        "minuman" => "Es Teh",
        "makanan" => "Nasi Padang",
        "harga" => 10000
    ];
    public $menu2= [
        "minuman" => "Es Jeruk",
        "makanan" => "Nasi Goreng",
        "harga" => 15000
    ];
    public $menu3= [
        "minuman" => "Es Degan",
        "makanan" => "Nasi Kucing",
        "harga" => 5000
    ];


    public function cekHarga(Request $request)
    {
        if($request->kode == 001) {
            $harga=5000;
        }else if($request->kode == 002){
            $harga=10000;
        }else if($request->kode == 003){
            $harga=15000;
        }else {
            $harga=0;}
            return view(view: 'HasilHarga',data: ["hg"=> $harga]);
    }

    public function cekMakanan(Request $request){
        //Daftar Makanan dr Database
        // $menu1= [
        //     "minuman" => "Es Teh",
        //     "makanan" => "Nasi Padang",
        //     "harga" => 10000
        // ];
        // $menu2= [
        //     "minuman" => "Es Jeruk",
        //     "makanan" => "Nasi Goreng",
        //     "harga" => 15000
        // ];
        // $menu3= [
        //     "minuman" => "Es Degan",
        //     "makanan" => "Nasi Kucing",
        //     "harga" => 5000
        // ];
        // if($request->kode == 001) $hasil = $menu1;
        // else if($request->kode == 002) $hasil = $menu2;
        // else if($request->kode == 003) $hasil = $menu3;
        // else $hasil = ["keterangan" => "Tidak ada menu"];
        if($request->kode == 001) $hasil = $this->menu1;
        else if($request->kode == 002) $hasil = $this->menu2;
        else if($request->kode == 003) $hasil = $this->menu3;
        else $hasil = ["keterangan" => "Tidak ada menu"];

        return view('HasilMakanan', ["menu" => $hasil]);
    }
}
