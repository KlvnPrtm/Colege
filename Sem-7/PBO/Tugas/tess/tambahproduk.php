<?php include 'connect.php'; ?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tambah Produk</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <h1>Tambah Produk Baru</h1>
    <form action="" method="post">
        <label for="id">ID:</label>
        <input type="text" name="id" required>
        <label for="namaproduk">Nama Produk:</label>
        <input type="text" name="namaproduk" required>
        <label for="deskripsi">Deskripsi:</label>
        <textarea name="deskripsi"></textarea>
        <label for="harga">Harga:</label>
        <input type="number" step="0.01" name="harga" required>
        <label for="stock">Stok:</label>
        <input type="number" name="stock" required>
        <button type="submit" name="submit">Simpan</button>
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $id = $_POST['id'];
        $namaproduk = $_POST['namaproduk'];
        $deskripsi = $_POST['deskripsi'];
        $harga = $_POST['harga'];
        $stock = $_POST['stock'];

        $sql = "INSERT INTO products (id, namaproduk, deskripsi, harga, stock)
                VALUES ('$id', '$namaproduk', '$deskripsi', '$harga', '$stock')";

        if ($conn->query($sql) === TRUE) {
            echo "<p>Produk berhasil ditambahkan!</p>";
        } else {
            echo "<p>Error: " . $sql . "<br>" . $conn->error . "</p>";
        }
    }
    ?>
</body>
</html>
