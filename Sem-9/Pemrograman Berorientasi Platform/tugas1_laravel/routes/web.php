<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\MenuController;

Route::get('/', function () {
    return view('menu');
});

// 2 link langsung ke view
Route::get('/halaman1', function () {
    return view('halaman1');
});

Route::get('/halaman2', function () {
    return view('halaman2');
});

// 2 link via controller
Route::get('/halaman3', [MenuController::class, 'halaman3']);
Route::get('/formulir', [MenuController::class, 'halamanForm']);

// (optional) route untuk proses form
Route::post('/proses-formulir', function (Illuminate\Http\Request $request) {
    return "Data diterima, Nama: " . $request->nama;
});
