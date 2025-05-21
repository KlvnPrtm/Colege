<?php

use App\Http\Controllers\ControllerPenduduk;
use Illuminate\Support\Facades\App;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/data', [ControllerPenduduk::class, 'gettAll']);

Route::post('/prosesadd',[ControllerPenduduk::class,'add']);

Route::post('/prosesupdate',[ControllerPenduduk::class,'update']);

Route::get('/delete/{id}',[ControllerPenduduk::class,'delete']);

Route::get('/update/{id}',[ControllerPenduduk::class,'getById']);

Route::get('/add', function () {
    return view('AddPenduduk');
});