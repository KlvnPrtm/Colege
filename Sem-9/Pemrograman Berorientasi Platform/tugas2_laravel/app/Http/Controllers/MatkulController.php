<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class MatkulController extends Controller
{
    private $matkul = [
        ["kode" => "TC001", "nama" => "Menyanyi", "sks" => 5],
        ["kode" => "TC002", "nama" => "Pengantar Teknologi Layangan", "sks" => 4],
        ["kode" => "TC003", "nama" => "Dasar-Dasar Mancing", "sks" => 10],
        ["kode" => "TC004", "nama" => "Agama", "sks" => 3],
        ["kode" => "TC005", "nama" => "Pancasila", "sks" => 3],
    ];

    public function index(Request $request)
    {
        $kode = $request->input('kode');
        $data = $this->matkul;

        if ($kode) {
            $data = array_filter($this->matkul, function ($item) use ($kode) {
                return strtolower($item['kode']) === strtolower($kode);
            });
        }

        return view('matkul', ['data' => $data]);
    }
}
