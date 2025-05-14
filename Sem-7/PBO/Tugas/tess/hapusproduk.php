<?php
include 'connect.php';

$id = $_GET['id'];
$sql = "DELETE FROM products WHERE id='$id'";

if ($conn->query($sql) === TRUE) {
    echo "<script>alert('Produk berhasil dihapus!'); window.location.href='sembako_yonder.html';</script>";
} else {
    echo "Error deleting record: " . $conn->error;
}
?>
