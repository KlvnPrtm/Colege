<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class ModelPenduduk extends Model
{
    //
    use HasFactory;
    protected $table = "tbpenduduk";
    public $timestamps = false;
    public $fillable = ['id', 'nik', 'nama', 'alamat'];
}
