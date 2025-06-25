package com.example.api

import retrofit2.http.GET
import retrofit2.http.Path

interface ApiService {

    @GET("users")
    suspend fun getUsers(): UserResponse
    @GET("products/{id}")
    suspend fun getProductById(@Path("id") productId: Int): Product
}