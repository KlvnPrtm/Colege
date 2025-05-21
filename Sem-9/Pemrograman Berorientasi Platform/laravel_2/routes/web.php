<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/cek-harga', function () {
    return view('CekHarga');
});

Route::get('/cek-makanan', function () {
    return view('CekMakanan');
});
Route::post('/proses-cek',[App\Http\Controllers\AplikasiKasir::class,'cekHarga']);

Route::post('/proses-makanan',[App\Http\Controllers\AplikasiKasir::class,'cekMakanan']);