<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

use App\Http\Controllers\MatkulController;

Route::get('/matkul', [MatkulController::class, 'index'])->name('matkul');
