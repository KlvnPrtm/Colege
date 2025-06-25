<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use app\Models\ModelPenduduk;


class ControllerPenduduk extends Controller
{
    //
    public function getAll(){
        $query=ModelPenduduk::select('id', 'nik', 'nama', 'alamat');
        $query=$query->get();
        return view ('ViewPenduduk', ['penduduk' => $query]);
    }

    public function add(Request $r){
        ModelPenduduk::insert([
            'nik' => $r->nik,
            'nama' => $r->nama,
            'alamat' => $r->alamat,
        ]);
        return redirect('/data');
    }

    //DELETE
    public function delete(Request$r){
        ModelPenduduk::where('id', $r->id)->delete();
        return redirect('/data');
    }

    //GET BY ID
    public function getById(Request $r){

        $query=ModelPenduduk::select('id', 'nik', 'nama', 'alamat');
        $query=$query->where('id', $r->id)->get();
        return view('UpdatePenduduk', ['penduduk' => $query]);
    }

    //UDATE
    public function update(Request $r){
        ModelPenduduk::where('id', $r->id)->update([
            'nik' => $r->nik,
            'nama' => $r->nama,
            'alamat' => $r->alamat
        ]);
        return Redirect('/data');
    }
}
