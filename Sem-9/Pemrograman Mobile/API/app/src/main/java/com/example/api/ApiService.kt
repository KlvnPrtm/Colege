package com.example.api

import retrofit2.http.GET
import retrofit2.http.Path // <-- TAMBAHKAN IMPORT INI

interface ApiService {

    @GET("users")
    suspend fun getUsers(): UserResponse

    // HAPUS FUNGSI getProducts() YANG LAMA DAN GANTI DENGAN INI
    // Fungsi ini untuk mengambil satu produk berdasarkan ID-nya
    // Contoh: "products/1", "products/2", dst.
    @GET("products/{id}")
    suspend fun getProductById(@Path("id") productId: Int): Product
}