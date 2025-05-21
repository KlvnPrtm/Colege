<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
    <a href="/add">Tambah Data</a>
    <table border='1'>
        <tr>
            <td>ID</td>
            <td>NIK</td>
            <td>NAMA</td>
            <td>ALAMAT</td>
            <td>ACTION</td>

        </tr>
        @foreach($penduduk as $p)
        <tr>
            <td>{{$p->id}}</td>
            <td>{{$p->nik}}</td>
            <td>{{$p->nama}}</td>
            <td>{{$p->alamat}}</td>
            <td>
                <a href="/update/{{$p->id}}">Ubah</a>
                <a href="/delete/{{$p->id}}">Hapus</a>
            </td>
        </tr>
        @endforeach
    </table>
</body>
</html>