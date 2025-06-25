package com.example.api

// Data class ini hanya menampung field yang kita butuhkan dari API
data class Product(
    val id: Int,
    val title: String,
    val price: Double // Kita gunakan Double karena harga bisa memiliki desimal
)