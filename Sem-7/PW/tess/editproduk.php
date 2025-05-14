<?php include 'connect.php'; ?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Produk</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <h1>Edit Produk</h1>
    <?php
    $id = $_GET['id'];
    $result = $conn->query("SELECT * FROM products WHERE id='$id'");
    $product = $result->fetch_assoc();
    ?>

    <form action="" method="post">
        <label for="namaproduk">Nama Produk:</label>
        <input type="text" name="namaproduk" value="<?php echo $product['namaproduk']; ?>" required>
        <label for="deskripsi">Deskripsi:</label>
        <textarea name="deskripsi"><?php echo $product['deskripsi']; ?></textarea>
        <label for="harga">Harga:</label>
        <input type="number" step="0.01" name="harga" value="<?php echo $product['harga']; ?>" required>
        <label for="stock">Stok:</label>
        <input type="number" name="stock" value="<?php echo $product['stock']; ?>" required>
        <button type="submit" name="submit">Update</button>
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $namaproduk = $_POST['namaproduk'];
        $deskripsi = $_POST['deskripsi'];
        $harga = $_POST['harga'];
        $stock = $_POST['stock'];

        $sql = "UPDATE products SET 
                namaproduk='$namaproduk', deskripsi='$deskripsi', harga='$harga', stock='$stock'
                WHERE id='$id'";

        if ($conn->query($sql) === TRUE) {
            echo "<p>Produk berhasil diupdate!</p>";
        } else {
            echo "<p>Error: " . $sql . "<br>" . $conn->error . "</p>";
        }
    }
    ?>
</body>
</html>
