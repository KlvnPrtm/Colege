<!DOCTYPE html>
<html>
<head>
    <title>Formulir</title>
</head>
<body>
    <h1>Form Input Data</h1>
    <form method="post" action="/proses-formulir">
        @csrf
        Nama: <input type="text" name="nama"><br><br>
        <input type="submit" value="Kirim">
    </form>
</body>
</html>
