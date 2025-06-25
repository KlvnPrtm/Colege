<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>

    <form method="post" action="/prosesupdate">
    @csrf

    @foreach($penduduk as $p)

    <input type="hidden" name="id" value="{{$p->id}}">

    NIK:<br>
    <input type="text" name="nik" value="{{$p->nik}}"><br>
    
    Nama:<br>
    <input type="text" name="nama" value="{{$p->nama}}"><br>
    
    Alamat:<br>
    <input type="text" name="alamat" value="{{$p->alamat}}"><br>
        
    @endforeach
    
    <input type="submit=" value= "Ubah"><br>
    <a href="/data">Batal</a>


    </form>
</body>
</html>