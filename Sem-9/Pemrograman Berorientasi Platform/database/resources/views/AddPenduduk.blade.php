<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>

    <form method="post" action="/prosesadd">
    @csrf

    
    NIK:<br>
    <input type="text" name="nik"><br>
    
    Nama:<br>
    <input type="text" name="nama"><br>
    
    Alamat:<br>
    <input type="text" name="alamat"><br>
    
    <input type="submit=" value= "Simpan"><br>
    <a href="/data">Batal</a>


    </form>
</body>
</html>