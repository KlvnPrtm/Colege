// User.kt
package com.example.api

import com.google.gson.annotations.SerializedName

data class User (
    val id: Int,
    @SerializedName("firstName")
    val firstName: String,
    val lastName: String,
    val university: String,
    val image: String
)