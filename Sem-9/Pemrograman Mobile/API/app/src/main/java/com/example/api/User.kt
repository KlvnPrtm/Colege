// User.kt
package com.example.api

import com.google.gson.annotations.SerializedName

data class User (
    val id: Int,
    @SerializedName("firstName") // Anotasi ini memastikan nama cocok dengan JSON
    val firstName: String, // <-- PERBAIKI INI (dari firtsName)
    val lastName: String,
    val university: String,
    val image: String // <-- TAMBAHKAN INI untuk menampung URL gambar
)