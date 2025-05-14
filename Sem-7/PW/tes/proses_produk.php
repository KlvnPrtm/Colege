<?php
// Koneksi ke database
$host = "localhost";      // Nama host, biasanya "localhost"
$user = "root";           // Username MySQL, sesuaikan dengan username Anda
$password = "";           // Password MySQL, sesuaikan dengan password Anda
$dbname = "toko";         // Nama database

$conn = new mysqli($host, $user, $password, $dbname);

// Cek koneksi
if ($conn->connect_error) {
    die("Koneksi gagal: " . $conn->connect_error);
}

// Ambil data dari form
$nama_produk = $_POST['nama_produk'];
$deskripsi = $_POST['deskripsi'];
$harga = $_POST['harga'];
$stok = $_POST['stok'];

// Query untuk memasukkan data ke tabel produk
$sql = "INSERT INTO produk (nama_produk, deskripsi, harga, stok) VALUES ('$nama_produk', '$deskripsi', '$harga', '$stok')";

// Eksekusi query
if ($conn->query($sql) === TRUE) {
    echo "Produk berhasil disimpan!";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

// Tutup koneksi
$conn->close();
?>
