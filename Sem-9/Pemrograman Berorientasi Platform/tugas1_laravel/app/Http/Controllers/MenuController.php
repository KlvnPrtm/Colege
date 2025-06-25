<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class MenuController extends Controller
{
    public function halaman3()
    {
        return view('halaman3');
    }

    public function halamanForm()
    {
        return view('formulir');
    }
}
